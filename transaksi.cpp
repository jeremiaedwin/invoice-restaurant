#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <conio.h>
#include <iostream>
#include <ctype.h> 
#include <time.h>
#include "transaksi.h"
#include "login.h"
//#include "main.cpp"
using namespace std;

void transaksiIndex(){

	system("cls");
	int pilih = 0;
	for(;;)
	{
		printf("\tTransaksi\t\n");
		printf("1. Masukkan Transaksi\n");
		printf("2. Lihat daftar transaksi\n");
		printf("4. Kembali\n");
		printf("\n\t Pilihan : "); 
		scanf("%d", &pilih); 
		
		switch(pilih)
		{
			case 1: 
			{
				inputTransaksi(kode_kasir1);
				break;
			}
			case 2: 
			{
				viewTransaksi();
				break;
			}
			
			case 3: 
			{
//				search();
				break;
			}
			default : { transaksiIndex();}
		}
	}
	int n = 1;
}

void inputTransaksi(char kode_kasir[6]){
	Pembayaran dt_pembayaran;
	time_t date_now;
	FILE *f_transaksi;
	int i=0;
	size_t size=1;
	char kode_menu[6];
	char again;	
	int sumHarga=0;

	printf("Masukkan Kode Transaksi: ");
	fflush(stdin);
	scanf("%s", dt_pembayaran.kode_transaksi);
	fflush(stdin);
	
	strcpy(dt_pembayaran.kode_user, kode_kasir);	
	time(&date_now);
	strcpy(dt_pembayaran.tanggal_pembelian,ctime(&date_now));
	
	do{
		fflush(stdin);
		printf("Masukkan Kode Menu : ");
		scanf("%s", kode_menu);
		fflush(stdin);
		dt_pembayaran.dt_menu[i] = searchMenu(kode_menu);
		
		fflush(stdin);
		printf("Masukkan kuantitas : ");
		scanf("%d", &dt_pembayaran.dt_menu[i].qty);
//		kuantitas = dt_pembayaran.dt_menu[i].qty;
		fflush(stdin);
		
		fflush(stdin);
		printf("Entry data lagi ? (Y/T) "); 
		again = toupper(getche());
		i++;
		printf("\n");
	}while((again=='Y'));
	
	dt_pembayaran.jMenu=i;
	
	int totHarga;
	hitungHarga(dt_pembayaran, &totHarga,&sumHarga,i);		
	
	printf("Harga = %d \n", sumHarga);
	printf("Total = %d", totHarga);
	dt_pembayaran.total_harga = totHarga;
	
	

	if((f_transaksi=fopen("f_transaksi.DAT", "ab"))==NULL){
			printf ("File tidak dapat dibuka\n"); 
			exit(1);
	}
	fwrite(&dt_pembayaran, sizeof(dt_pembayaran), 1, f_transaksi);
	fclose(f_transaksi);
	printf("Transaksi berhasil dibuat\n");
	transaksiIndex();
}

Keranjang searchMenu(char kode_menu[6]){
	FILE *f_menu;
	menu1 data_menu;
	Keranjang dt_keranjang;
	Pembayaran dt_pembayaran;
	if ((f_menu=fopen("dataMenu.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	int i = 1;
	bool find = false;
	while(fread(&data_menu, sizeof(data_menu),1, f_menu)){
		if(strcmp(kode_menu,data_menu.kMenu)==0){
			strcpy(dt_keranjang.kMenu, data_menu.kMenu);
			strcpy(dt_keranjang.nMenu, data_menu.nMenu);
			dt_keranjang.hMenu = data_menu.hMenu;
			find = true;
			return dt_keranjang;	
		}
		
	}
	if(!find){
		printf("\nMenu tidak dapat ditemukan");
			printf("\nUlangi input (y/n)?");
			char again;
			scanf("%s", &again);
			if(again == 'Y' || again == 'y'){
				inputTransaksi(kode_kasir1);
			}else{
				transaksiIndex();	
			}
	}
	fclose(f_menu);
	
}

int validateQty(int qty)
{
	
}

void validateKode(Pembayaran dt){
	FILE *f_transaksi;
	Pembayaran dt_pembayaran;
	if ((f_transaksi=fopen("f_transaksi.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	int i = 1;
	bool find = false;
	while(fread(&dt_pembayaran, sizeof(dt_pembayaran),1, f_transaksi)){
		if(strcmp(dt.kode_transaksi,dt_pembayaran.kode_transaksi)==0){
			inputTransaksi(kode_kasir1);
			dt=Pembayaran();
			printf("Kode transaksi sudah ada!\n");
		}
		
	}
	fclose(f_transaksi);
}

void hitungHarga(Pembayaran dt, int *total,int *sum, int n){
	int count;
	int j;
	int k;
	int tmpHarga[n];
	for(j = 0; j<n; j++){
		tmpHarga[j] = dt.dt_menu[j].qty*dt.dt_menu[j].hMenu;
		count = j;
	}
	for(k = 0; k<=count; k++){
		*sum = *sum + tmpHarga[k];
	}
	
	int ppn = *sum*10/100;
	int service = *sum*5/100;
	*total = *sum+ppn+service;
}

void viewTransaksi(){
	Pembayaran dt_pembayaran;
	FILE *f_transaksi;
	
	
	if((f_transaksi=fopen("f_transaksi.DAT", "rb"))==NULL){
			printf ("File tidak dapat dibuka\n"); 
			exit(1);
		}
	
	while ((fread(&dt_pembayaran, sizeof(dt_pembayaran),1, f_transaksi))==1)
	{
		
		int a=0;
		printf("========================================================\n");
		printf("Kode Transaksi    : %s \n", dt_pembayaran.kode_transaksi);
		printf("Kode Kasir        : %s \n", dt_pembayaran.kode_user);
		printf("Total Harga       : %d \n", dt_pembayaran.total_harga);
		printf("Tanggal Pembelian : %s \n", dt_pembayaran.tanggal_pembelian);
		printf("---------------------------------------------------------\n");
		printf("|%-10s|%-20s|%-12s|%-10s|\n", "Kode Menu" ,"Nama Menu", "Harga", "Kuantitas");
		printf("---------------------------------------------------------\n");
		do{
			printf("|%-10s|%-20s|%-12d|%-10d|\n", dt_pembayaran.dt_menu[a].kMenu ,dt_pembayaran.dt_menu[a].nMenu, dt_pembayaran.dt_menu[a].hMenu,  dt_pembayaran.dt_menu[a].qty);
		a++;
		}while(a<dt_pembayaran.jMenu);
		
		printf("---------------------------------------------------------\n\n");
		
	}
	fclose(f_transaksi);
}
