#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "kategori.h"
#include "login.h"
#include "menu.h"

void indexKategori(User dt){
	system("cls");
//	Kamus data
	int pilih = 0;
	
//	menu fitru di kateogir
	for(;;)
	{
		switch(dt.level){
//			menu yang tersedia untuk user kasir
			case 1 :
				printf("1. Lihat daftar kategori\n");
				printf("2. Create Kategori\n");
				printf("3. Kembali\n");
				printf("\n\tPilih :");
				scanf("%d",&pilih);
				switch(pilih)
				{
					case 1: 
					{
						read();
						break;
					}
					case 2: 
					{
						create();
						break;
					}
					default :
					{
						return;
					}
				}
				break;
//			menu yang tersedia untuk user kasir
			case 2 :
				printf("1. Lihat daftar kategori\n");
				printf("2. Cari Kategori\n");
				printf("3. Kembali\n");
				printf("\n\tPilih :");
				scanf("%d",&pilih);
				switch(pilih)
				{
					case 1: 
					{
						read();
						break;
					}
					case 2: 
					{
						create();
						break;
					}
					default:
					{
						return;
					}
				break;
			}
//			menu yang tersedia untuk user kasir
			case 3 :
				printf("\tKategori Menu\t\n");
				printf("1. Masukkan data baru\n");
				printf("2. Lihat daftar kategori\n");
				printf("3. Kembali\n");
				printf("\n\t Pilihan : "); 
				scanf("%d", &pilih); 
				switch(pilih)
				{
					case 1: 
					{
						create();
						break;
					}
					case 2: 
					{
						read();
						break;
					}
					default : { return;}
				}
				break;
			
	
				
			default :
				printf("Data level tidak ada!");
				exit(1);
			}
		}
	}



void create(){
	system("cls");
	
//	Kamus data
	Kategori dt;
	char again;
	FILE *dt_kategori;
	
	if ((dt_kategori=fopen("f_kategori.DAT", "ab"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}

	for (;;)
	{
//		Proses input data
		fflush(stdin);
		printf("Kode Kategori : "); 
		scanf("%s",&dt.kode_kategori); 
		fflush(stdin);
		printf("Nama Kategori : "); 
		scanf("%49[^\n]",&dt.nama_kategori); 
		fflush(stdin);

//		Proses tulis data ke file
		fwrite(&dt, sizeof(dt), 1, dt_kategori);
		

		printf("Entry data lagi ? (Y/T) "); 
		again = getche();
		printf("\n");
		if (again == 't' || again == 'T') 
		break;
	}
	fclose(dt_kategori);
	return;
}

void read()
{
	system("cls");
	
//	Kamus data
	Kategori dt;
	FILE *f_kategori; 

	if ((f_kategori=fopen("f_kategori.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	printf ("--------------------------------------\n");
	printf ("|          Daftar Kategori           |\n");
	printf ("--------------------------------------\n");
	printf("|%-15s|%-20s|\n", "Kode Kategori" ,"Nama Kategori");
	printf("--------------------------------------\n");
	int line = 1; //baris file
	while ((fread(&dt, sizeof(dt),line, f_kategori))==line)
	{
		printf("|%-15s|%-20s|\n", dt.kode_kategori, dt.nama_kategori);
	}
	printf ("--------------------------------------\n");
	fclose(f_kategori);
	
	int pil = 0;
	printf("\tKategori Menu\t\n");
	printf("1. Edit Data\n");
	printf("2. Hapus Data\n");
	printf("3. Kembali ke Menu Utama\n");
	printf("\n\t Pilihan : "); 
	scanf("%d", &pil);
	switch(pil){
		case 1:
			{
				updateKategori();
				break;
			}
		case 2:
			{
				destroy();
				break;
			}
		case 3:
		{
			return;
			break;
		}
		default: exit(1);
	}
}

void updateKategori(){
	// deklarasi variabel
	int line, count, i;
	Kategori kategori1, kategori2, kategori3;
	FILE *f_kategori1, *f_kategori2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
	// input baris yang akan diedit
	printf("Masukkan baris data mana yang akan diedit: ");
	scanf("%d", &line);
	 
	fflush(stdin);
	printf("Nama Kategori : "); 
	scanf("%49[^\n]",&kategori2.nama_kategori); 
	printf("\n");
	fflush(stdin);
	
	//membuka file
	if ((f_kategori1=fopen("f_kategori.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	
	if ((f_kategori2=fopen("f_kategori_2.DAT", "ab+"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	
	i = 1;
	count = 0;
	while ((fread(&kategori1, sizeof(kategori1),i, f_kategori1)) == i)
	{
		count++;
		if(count == line){
			strcpy(kategori2.kode_kategori,kategori1.kode_kategori);
			fwrite(&kategori2, sizeof(kategori2),i,f_kategori2);
		}else{
			fwrite(&kategori1, sizeof(kategori1),i,f_kategori2);
		}
	}
	
	fclose(f_kategori1);
	fclose(f_kategori2);
	remove("f_kategori.DAT");
	rename("f_kategori_2.DAT", "f_kategori.DAT");
	return;
	
}

void destroy(){
	// deklarasi variabel
	int line, count, i;
	Kategori kategori1, kategori2, kategori3;
	menu dt_menu;
	FILE *f_kategori1, *f_kategori2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	FILE *f_menu, *f_menu2;
	
	// input baris yang akan diedit
	printf("Masukkan baris data mana yang akan dihapus: ");
	scanf("%d", &line);
	
	fflush(stdin);
	

	//membuka file
	if ((f_kategori1=fopen("f_kategori.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	
	if ((f_kategori2=fopen("f_kategori_2.DAT", "ab+"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	
	
	
	i = 1;
	count = 0;
	while ((fread(&kategori1, sizeof(kategori1),i, f_kategori1)) == i)
	{
		count++;
		if(count != line){
			fwrite(&kategori1, sizeof(kategori1),i,f_kategori2);
		}else{
			strcpy(kategori3.kode_kategori,kategori1.kode_kategori);
			strcpy(kategori3.nama_kategori,kategori1.nama_kategori);
		}
	}
	
	// Menutup kedua file
	fclose(f_kategori1);
	fclose(f_kategori2);
	
	
	// Merubah file copy menjadi original
	remove("f_kategori.DAT");
	rename("f_kategori_2.DAT", "f_kategori.DAT");
	
		//membuka file
	if ((f_menu=fopen("dataMenu.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	
	if ((f_menu2=fopen("dataMenu_2.DAT", "ab"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	
	
	while((fread(&dt_menu, sizeof(dt_menu), 1, f_menu)==1)){
		if((strcmp(kategori3.kode_kategori, dt_menu.kategori.kode_kategori)!=0) && (strcmp(kategori3.nama_kategori, dt_menu.kategori.nama_kategori)!=0)){
			fwrite(&dt_menu, sizeof(dt_menu), 1, f_menu2);
		}
	}
		
	fclose(f_menu);
	fclose(f_menu2);
	
	
	remove("dataMenu.DAT");
	rename("dataMenu_2.DAT", "dataMenu.DAT");
	return;
}
