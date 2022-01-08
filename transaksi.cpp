//Author : Jeremia Edwin Hamonangan - 211511039

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <time.h>
#include <conio.h>
#include <iostream>
#include "transaksi.h"
#include "login.h"
using namespace std;

void transaksiIndex(User dt){
	
	system("cls");
	int pilih = 0;
	for(;;)
	{
		printf("\tTransaksi\t\n");
		printf(" 1. Masukkan Transaksi\n");
		printf(" 2. Lihat daftar transaksi\n");
		printf(" 3. Kembali\n");
		printf("\n\t Pilihan : "); 
		scanf("%d", &pilih); 
		
		switch(pilih)
		{
			case 1: 
			{
				inputTransaksi(dt);
				break;
			}
			case 2: 
			{
				viewTransaksi();
				break;
			}
			
			default : { return;}
		}
	}
	int n = 1;
}

void inputTransaksi(User dt){
	system("cls");
	// pendefinisian kamus data
	Pembayaran dt_pembayaran; 
	Date tgl; 
	time_t t = time(NULL); //Variabel library date
	struct tm tm = *localtime(&t); //Struct library date
	FILE *f_transaksi; // Variabel file
	int i=0;
	char kode_menu[6];
	char again;	
	int sumHarga=0;
	int kuantitas;
	int totHarga;
	char confirm;
	char ulangInput;
	bool statusKode;
	
	// Menampilkan daftar menu
	viewMenu();
	printf("\n\n");
	while(true){
		printf("Masukkan Kode Transaksi: ");
		fflush(stdin);
		scanf("%s", dt_pembayaran.kode_transaksi);
		statusKode = validasiKode(dt_pembayaran.kode_transaksi);
		fflush(stdin);
		if(statusKode == false){
			break;
		}
	}
	
	strcpy(dt_pembayaran.kode_user, dt.user_id);	
	//Input kode kasir yang menangani transaksi, data diambil dari siapa yang login	
	strcpy(dt_pembayaran.kode_user, dt.user_id);
	dt_pembayaran.tanggal_pembelian.tanggal = tm.tm_mday;
	dt_pembayaran.tanggal_pembelian.bulan = tm.tm_mon+1;
	dt_pembayaran.tanggal_pembelian.tahun = tm.tm_year+1900;
	
	do{
		fflush(stdin);
		printf("Masukkan Kode Menu : ");
		scanf("%s", kode_menu);
		fflush(stdin);
		dt_pembayaran.dt_menu[i] = searchMenu(kode_menu, dt);
		
		while(true){
			fflush(stdin);
			printf("Masukkan kuantitas : ");
			if(scanf("%d", &dt_pembayaran.dt_menu[i].qty) != 1){
				printf("Input bukan angka!\n");
				fflush(stdin);
			}else{
				break;
			}
		}
		
		
		fflush(stdin);
		printf("Entry data lagi ? (Y/T) "); 
		again = toupper(getche());
		i++;
		printf("\n");
	}while((again=='Y'));
	
	dt_pembayaran.jMenu=i;
	
	hitungHarga(dt_pembayaran, &totHarga,&sumHarga,i);		
	
	printf("Harga = %d \n", sumHarga);
	printf("Total = %d", totHarga);
	dt_pembayaran.total_harga = totHarga;
	
	//Input uang yang dimasukkan
	printf("\nUang masuk : ");
	scanf("%d", &dt_pembayaran.uangMasuk);
	
	//Proses hitung uang kembalian
	if(dt_pembayaran.total_harga<=dt_pembayaran.uangMasuk){
		dt_pembayaran.kembalian = dt_pembayaran.uangMasuk-dt_pembayaran.total_harga;
	}else{
		dt_pembayaran.kembalian=0;
	}
	printf("\nUang kembalian : %d\n", dt_pembayaran.kembalian);
	
	printf("Konfirmasi Pembayaran (Y/N)?");
	confirm = toupper(getche());
	if(confirm == 'Y'){
		if((f_transaksi=fopen("f_transaksi.DAT", "ab"))==NULL){
			printf ("File tidak dapat dibuka\n"); 
			exit(1);
		}
		fwrite(&dt_pembayaran, sizeof(dt_pembayaran), 1, f_transaksi);
		fclose(f_transaksi);
		viewTransaksi();
	}else{
		printf("Ulangi Input (Y/N)");
		ulangInput = toupper(getche());
		if(ulangInput == 'Y'){
			inputTransaksi(dt);
		}else{
			system("cls");
			return;
		}
	}


	
}

Keranjang searchMenu(char kode_menu[6],User dt){
	FILE *f_menu; //Variabel file menu 
	menu data_menu; //Variabel struct menu
	Keranjang dt_keranjang; //Variabel struct menu yang akan direturn
	Pembayaran dt_pembayaran;
	if ((f_menu=fopen("dataMenu.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	int i = 1;
	bool find = true;
	// Proses pencarian data menu
	while(fread(&data_menu, sizeof(data_menu),1, f_menu)){
		//Jika kode menu yang diinput ditemukan
		if(strcmp(kode_menu,data_menu.kMenu)==0 && data_menu.sMenu==1){
			strcpy(dt_keranjang.kMenu, data_menu.kMenu);
			strcpy(dt_keranjang.nMenu, data_menu.nMenu);
			dt_keranjang.hMenu = data_menu.hMenu;
			find = true;
			return dt_keranjang;	
		}else{
			find = false;
		}
		
	}
	//Jika kode menu tidak dapat ditemukan
	if(!find){
		printf("\nMenu tidak tersedia");
			printf("\nUlangi input (y/n)?");
			char again;
			scanf("%s", &again);
			if(again == 'Y' || again == 'y'){
				inputTransaksi(dt);
			}else{
				transaksiIndex(dt);	
			}
	}
	fclose(f_menu);
	
}

void hitungHarga(Pembayaran dt, int *total,int *sum, int n){
	int count; // Variabel untuk menghitung jumlah harga per menu
	int j; // index j
	int k; // index
	int tmpHarga[n]; //Penampung jumlah harga menu
	
	// Proses perhitungan jumlah harga per menu
	for(j = 0; j<n; j++){
		tmpHarga[j] = dt.dt_menu[j].qty*dt.dt_menu[j].hMenu;
		count = j;
	}
	
	// Proses menjumlahkan tiap jumlah harga permenu
	for(k = 0; k<=count; k++){
		*sum = *sum + tmpHarga[k];
	}
	
	// Proses perhitungan total harga 
	int ppn = *sum*10/100;
	int service = *sum*5/100;
	*total = *sum+ppn+service;
}

void viewTransaksi(){
	system("cls");
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
		printf("Tanggal Pembelian : %d - %d - %d \n", dt_pembayaran.tanggal_pembelian.tanggal, dt_pembayaran.tanggal_pembelian.bulan, dt_pembayaran.tanggal_pembelian.tahun);
		printf("Kode Kasir        : %s \n", dt_pembayaran.kode_user);
		printf("Total Harga       : %d \n", dt_pembayaran.total_harga);
		printf("Uang Masuk        : %d \n", dt_pembayaran.uangMasuk);
		printf("Uang Kembalian    : %d \n", dt_pembayaran.kembalian);
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

//void readMenu(){
//	menu m;
//	FILE *f_menu;
//	
//	
//	if((f_menu=fopen("dataMenu.DAT", "rb"))==NULL){
//			printf ("File tidak dapat dibuka\n"); 
//			exit(1);
//		}
//	printf("------------------------------------------------------------------------------\n");
//	printf("|%-10s|%-20s|%-20s|%-12s|%-10s|\n", "Kode Menu" ,"Nama Menu", "Kategori", "Harga", "Status");
//	printf("------------------------------------------------------------------------------\n");
//	while ((fread(&m, sizeof(m),1, f_menu))==1)
//	{
//		if(m.sMenu == 1){
//			printf("|%-10s|%-20s|%-20s|%-12d|%-10s|\n", m.kMenu, m.nMenu, m.kategori.nama_kategori, m.hMenu, "Tersedia");
//		}
//		
//	}
//	printf("------------------------------------------------------------------------------");
//	fclose(f_menu);
//}

bool validasiKode(char kodeTransaksi[6]){
	Pembayaran dt_pembayaran;
	FILE *f_transaksi;
	bool find = false;
	if((f_transaksi = fopen("f_transaksi.DAT", "rb+"))==NULL){
		printf("File gagal dibuka!");
		exit(1);
	}
	
	while((fread(&dt_pembayaran, sizeof(dt_pembayaran),1,f_transaksi))==1){
		if(strcmp(kodeTransaksi, dt_pembayaran.kode_transaksi)==0){
			printf("Kode sudah digunakan!\n");
			find = true;
			break;
		}
	}
	return find;
	fclose(f_transaksi);
}

