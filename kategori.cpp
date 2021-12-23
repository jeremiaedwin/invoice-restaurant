#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "kategori.h"

void indexKategori(){
	system("cls");
	int pilih = 0;
	for(;;)
	{
		printf("\tKategori Menu\t\n");
		printf("1. Masukkan data baru\n");
		printf("2. Lihat daftar kategori\n");
		printf("3. Cari Kategori\n");
		printf("4. Kembali\n");
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
			
			case 3: 
			{
//				search();
				break;
			}
			default : { exit(1);}
		}
	}
}

void create(){
	system("cls");
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
		fflush(stdin);
		printf("Kode Kategori : "); 
		scanf("%s",&dt.kode_kategori); 
		fflush(stdin);
		printf("Nama Kategori : "); 
		scanf("%49[^\n]",&dt.nama_kategori); 
		fflush(stdin);

//		fprintf(dt_kategori, "%s %s\n", dt.kode_kategori, dt.nama_kategori);
		fwrite(&dt, sizeof(dt), 1, dt_kategori);
		

		printf("Entry data lagi ? (Y/T) "); 
		again = getche();
		printf("\n");
		if (again == 't' || again == 'T') 
		break;
	}
	fclose(dt_kategori);
	indexKategori();
}

void read()
{
	system("cls");
	Kategori dt; //variabel struct
	FILE *f_kategori; //variabel file

	if ((f_kategori=fopen("f_kategori.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	printf ("-------------------------------------------------\n");
	printf ("|\t Daftar Kategori \t\t\t|\n");
	printf ("-------------------------------------------------\n");
	printf ("|\t Kode Kategori \t|\t Nama Kategori \t|\n");
	printf ("-------------------------------------------------\n");
	
	int line = 1; //baris file
	while ((fread(&dt, sizeof(dt),line, f_kategori))==line)
	{
		printf("|\t %s \t\t|%s \t|\n", dt.kode_kategori, dt.nama_kategori);
	}
	printf ("------------------------------------------------\n");
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
			indexKategori();
			break;
		}
		default: exit(1);
	}
}

void updateKategori(){
	// deklarasi variabel
	int line, count, i;
	Kategori kategori1, kategori2;
	FILE *f_kategori1, *f_kategori2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
	// input baris yang akan diedit
	printf("Masukkan baris data mana yang akan diedit: ");
	scanf("%d", &line);
	
	fflush(stdin);
	printf("Kode Kategori : "); 
	scanf("%s",&kategori2.kode_kategori); 
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
			fwrite(&kategori2, sizeof(kategori2),i,f_kategori2);
		}else{
			fwrite(&kategori1, sizeof(kategori1),i,f_kategori2);
		}
	}
	
	fclose(f_kategori1);
	fclose(f_kategori2);
	remove("f_kategori.DAT");
	rename("f_kategori_2.DAT", "f_kategori.DAT");
	
}

void destroy(){
	// deklarasi variabel
	int line, count, i;
	Kategori kategori1, kategori2;
	FILE *f_kategori1, *f_kategori2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
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
		}
	}
		
	// Menutup kedua file
	fclose(f_kategori1);
	fclose(f_kategori2);
	
	// Merubah file copy menjadi original
	remove("f_kategori.DAT");
	rename("f_kategori_2.DAT", "f_kategori.DAT");
}
