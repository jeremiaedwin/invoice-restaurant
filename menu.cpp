#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "menu.h"
#include "login.h"
#include "kategori.h"

void indexMenu(User dt){
		
	int option;
	for(;;){
	
		switch(dt.level){
			case 1 :
				system("CLS");
				printf("1. Display Menu\n");
				scanf("%d",&option);
				switch(option){
					case 1:
						viewMenu();
						break;			
					default :
						return;
					}	
				break;
			case 2 :
				system("CLS");
				printf("1. Create Menu\n");
				printf("2. Add Menu\n");
				printf("3. Display Menu\n");
				printf("4. Update Menu\n");
				printf("5. Delete Menu\n");
				printf("Pilih : ");
				scanf("%d",&option);
				switch(option){
					case 1:
						createMenu();
						break;
					case 2:
						addMenu();
						break;
					case 3:
						viewMenu();
						break;	
					case 4:
						update();
						break;
					case 5:
						deleteMenu();
						break;
					default :
						return;
			}
				break;
			
			case 3 :
				system("CLS");
				printf("1. Create Menu\n");
				printf("2. Add Menu\n");
				printf("3. Display Menu\n");
				printf("4. Update Menu\n");
				printf("5. Delete Menu\n");
				printf("Pilih : ");
				scanf("%d",&option);
				switch(option){
					case 1:
						createMenu();
						break;
					case 2:
						addMenu();
						break;
					case 3:
						viewMenu();
						break;	
					case 4:
						update();
						break;
					case 5:
						deleteMenu();
						break;
					default :
						return;
						break;
				}
			}
		}
	}



void createMenu(){
	
	char jawab;
	char option;
	int i;
	menu m;
	FILE *f_menu;
	int count;
	char kode_kategori[3];
	
	system("CLS");
	printf("Pembuatan menu akan membuat menu sebelumnya dihapus.");
	printf("\nLanjut ?(Y/N)");
	option = toupper(getch());
	
	if(option == 'N' || option == 'n'){
		return;
	}
	if((f_menu = fopen("dataMenu.DAT","wb"))==NULL){
		printf("Gagal membuka file!");
		exit(1);
	}
	do{
		system("CLS");
		//Meminta User input
		fflush(stdin);	
		printf("Input Nama Menu : ");
		gets(m.nMenu);
		fflush(stdin);
		printf("Input Harga : ");
		scanf("%d",&m.hMenu);
		fflush(stdin);
		printf("Input Status (1 = Tersedia/0 = Tidak Tersedia) : ");
		scanf("%d",&m.sMenu);
		fflush(stdin);
		printf("Input Kode Menu : ");
		scanf("%s",&m.kMenu);
		count = 0;
		for(;;){
			count++;
			readKategori();
			printf("\nMasukkan Kode Kategori : ");
			scanf("%s", &kode_kategori);
			m.kategori = searchKategori(kode_kategori);
			if((strcmp(m.kategori.kode_kategori, kode_kategori )==0)){
				break;
			} else if(count == 4){
				return;
			}
			
		}
		if(m.sMenu>1 && m.sMenu<0){
			break;
		}
		
		
		//Save user input kedalam file
		fwrite(&m,sizeof(m),1,f_menu);		
		printf("Input File again ?(Y/N)");
		jawab = toupper(getche());
		
	}while(jawab == 'Y');
	fclose(f_menu);
}

Kategori searchKategori(char kode_kategori[3]){
	FILE *f_kategori;
	menu data_menu;
	Kategori dt_kategori;
	if ((f_kategori=fopen("f_kategori.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	int i = 1;
	bool find = false;
	while(fread(&dt_kategori, sizeof(dt_kategori),1, f_kategori)){
		if(strcmp(kode_kategori,dt_kategori.kode_kategori)==0){
			find = true;
			return dt_kategori;	
		}
	}
	fclose(f_kategori);
	
}

void addMenu(){
	int line = 1;
	char jawab;
	menu m;
	FILE *f_menu;
	char kode_kategori[3];
	

	if((f_menu=fopen("dataMenu.DAT","ab")) == NULL){
		printf("Gagal membuka file!");
	}
	int count = 0;
	do{
		system("CLS");
		//Meminta user Input
		fflush(stdin);	
		printf("Input Nama Menu : ");
		gets(m.nMenu);
		fflush(stdin);
		printf("Input Harga : ");
		scanf("%d",&m.hMenu);
		fflush(stdin);
		printf("Input Status (1 = Tersedia/0 = Tidak Tersedia) : ");
		scanf("%d",&m.sMenu);
		fflush(stdin);
		printf("Input Kode Menu : ");
		scanf("%4s",&m.kMenu);
		int T;
		for(;;){
			count++;
			readKategori();
			printf("\nMasukkan Kode Kategori : ");
			scanf("%s", &kode_kategori);
			m.kategori = searchKategori(kode_kategori);
			if((strcmp(m.kategori.kode_kategori, kode_kategori )==0)){
				break;
			} else if(count == 4){
				return;
			}
		}
		
		if(m.sMenu>1 && m.sMenu<0){
			break;
		}

		//menambah user input kedalam file
		fwrite(&m,sizeof(m),1,f_menu);		
		printf("Input File again ?(Y/N)");
		jawab = toupper(getche());
		
	}while(jawab =='Y');
	
	fclose(f_menu);
}

bool viewMenu(){
	//deklarasi variabel
	menu m;
	bool pilihan = false;
	FILE *f_menu;
	char opsi;
	int line = 1;
	int length;
	int i,k,count;
	char tempH[10];
	
	//Buka file
	if ((f_menu=fopen("dataMenu.DAT", "rb"))==NULL){
		
		printf ("Failed to fetch the file!\n"); 
		exit(1);		 
	}
	printf ("Menu \n");
	
	count = 1;
	//Display file ke layar
	printf("----------------------------------------------------------------------------------------\n");
	printf("|%-10s|%-20s|%-20s|%-12s|%-20s|\n", "Kode Menu" ,"Nama Menu", "Kategori", "Harga", "Status");
	printf("----------------------------------------------------------------------------------------\n");
	while ((fread(&m,sizeof(m),line,f_menu)) == line){
		if(m.sMenu == 1){
			printf("|%-10s|%-20s|%-20s|%-12d|%-20s|\n", m.kMenu, m.nMenu, m.kategori.nama_kategori, m.hMenu,"Tersedia");
		}else{
			printf("|%-10s|%-20s|%-20s|%-12d|%-20s|\n", m.kMenu, m.nMenu, m.kategori.nama_kategori, m.hMenu,"Tidak Tersedia");
		}
		
		count++;
	}
	printf("----------------------------------------------------------------------------------------\n");
	fclose(f_menu);
	for(;;){
		printf("Lanjut?(Y/N)");
		opsi = toupper(getche()); 
		if(opsi == 'N'|| opsi == 'n'){
			pilihan = true;
			return pilihan;
		}
		break;
		}
	
	return pilihan;

}
void deleteMenu(){
	// deklarasi variabel
	int line, count, i;
	bool opsi;
	menu m1, m2;
	FILE *f_menu1, *f_menu2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
	// input baris yang akan didelete
	opsi = viewMenu();
	if(opsi){
		return;
	}
	printf("\nMasukkan baris data mana yang akan di delete : ");
	scanf("%d", &line);
	fflush(stdin);
	
	//membuka file
	if ((f_menu1=fopen("dataMenu.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	
	if ((f_menu2=fopen("dataMenu_2.DAT", "ab+"))==NULL)
	{
		printf ("File tidak dapat dibuat\n"); 
		exit(1);
	}
	
	i = 1;
	count = 0;
	while ((fread(&m1, sizeof(m1),i, f_menu1)) == i)
	{
		count++;
		if(count != line){
			fwrite(&m1, sizeof(m1),i,f_menu2);
		}
	}
		
	// Menutup kedua file
	fclose(f_menu1);
	fclose(f_menu2);
	
	// Merubah file copy menjadi original
	remove("dataMenu.DAT");
	rename("dataMenu_2.DAT", "dataMenu.DAT");

}

void update(){
	// deklarasi variabel
	int line, count, i, pilihan;
	bool opsi;
	char tempH[10];
	char tempS[10];
	char kode_kategori[6];
	int T;
	menu m1, m2;
	FILE *f_menu1, *f_menu2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
	opsi = viewMenu();
	if(opsi){
		return;
	}
	// input baris yang akan diedit
	printf("\nMasukkan baris data mana yang akan di update: ");
	scanf("%d", &line);
	
	if ((f_menu1=fopen("dataMenu.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	i = 1;
	count = 0;
	while((fread(&m1, sizeof(m1),i, f_menu1)) == i){
		count++;
		if(count == line){
			break;
		}
	}
	fflush(stdin);
	printf("Data apa yang akan diganti ?\n");
	printf("1. Nama Menu\n");
	printf("2. Harga Menu\n");
	printf("3. Status Menu\n");
	printf("4. Semua\n");
	scanf("%d",&pilihan);
	fflush(stdin);
	
	switch(pilihan){
		case 1 :
			printf("Input Nama Menu :");
			gets(m2.nMenu);
			fflush(stdin);
			sprintf(tempH,"%d",m1.hMenu);
			sprintf(tempS,"%d",m1.sMenu);
			strcpy(m2.kategori.kode_kategori,m1.kategori.kode_kategori);
			strcpy(m2.kategori.nama_kategori,m1.kategori.nama_kategori);
			m2.hMenu = atoi(tempH);
			m2.sMenu = atoi(tempS);
			break;
			
		case 2 :
			printf("Input Harga Menu : ");
			scanf("%d",&m2.hMenu);
			fflush(stdin);
			strcpy(m2.nMenu,m1.nMenu);
			strcpy(m2.kategori.kode_kategori,m1.kategori.kode_kategori);
			strcpy(m2.kategori.nama_kategori,m1.kategori.nama_kategori);
			m2.sMenu = atoi(tempS);
			break;
			
		case 3 :
			printf("Input Status Menu (1 = Tersedia/0 = Tidak Tersedia) : ");
			scanf("%d",&m2.sMenu);
			fflush(stdin);
			strcpy(m2.nMenu,m1.nMenu);
			strcpy(m2.kategori.kode_kategori,m1.kategori.kode_kategori);
			strcpy(m2.kategori.nama_kategori,m1.kategori.nama_kategori);
			sprintf(tempH,"%d",m1.hMenu);
			m2.hMenu = atoi(tempH);
			
			break;
			
		case 4 :
			fflush(stdin);
			printf("Input Nama Menu : "); 
			gets(m2.nMenu);
			fflush(stdin);
			printf("Input Harga : "); 
			scanf("%d",&m2.hMenu); 
			fflush(stdin);
			printf("Input Stock : ");
			scanf("%d",&m2.sMenu);
			fflush(stdin);
			
			for(;;){
				readKategori();
				printf("\nMasukkan Kode Kategori : ");
				scanf("%s", &kode_kategori);
				m2.kategori = searchKategori(kode_kategori);
				if(strcmp(m2.kategori.kode_kategori, kode_kategori )==0)
				break;
			}
			break;
		
			
	}
	
	strcpy(m2.kMenu,m1.kMenu);
	
	rewind(f_menu1);
	//membuka file
	if ((f_menu2=fopen("dataMenu_2.DAT", "ab"))==NULL)
	{
		printf ("File tidak dapat dibuat\n"); 
		exit(1);
	}
	
	i = 1;
	count = 0;
	while ((fread(&m1, sizeof(m1),i, f_menu1)) == i){
		
		count++;
		if(count == line){
			fwrite(&m2, sizeof(m2),i,f_menu2);
		}else{
			fwrite(&m1, sizeof(m1),i,f_menu2);
		}
	}
	
	fclose(f_menu1);
	fclose(f_menu2);
	remove("dataMenu.DAT");
	rename("dataMenu_2.DAT", "dataMenu.DAT");
	return;
}

void readKategori(){
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
}
