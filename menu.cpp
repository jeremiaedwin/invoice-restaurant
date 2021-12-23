#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "menu.h"

void indexMenu(){
		
	int option;
	for(;;){
		
		system("CLS");
		printf("1. Create Menu\n");
		printf("2. Add Menu\n");
		printf("3. Display Menu\n");
		printf("4. Update Menu\n");
		printf("5. Delete Menu\n");
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
				exit(1);
	}
}

}

void createMenu(){
	
	char jawab;
	char option;
	int i;
	menu m;
	FILE *f_menu;
	
	system("CLS");
	printf("Pembuatan menu akan membuat menu sebelumnya dihapus.");
	printf("\nLanjut ?(Y/N)");
	option = toupper(getch());
	
	if(option == 'N' || option == 'n'){
		indexMenu();
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
		printf("Input Stock : ");
		scanf("%d",&m.sMenu);
		fflush(stdin);
		printf("Input Kode Menu : ");
		scanf("%s",&m.kMenu);

		//Save user input kedalam file
		fwrite(&m,sizeof(m),1,f_menu);		
		printf("Input File again ?(Y/N)");
		jawab = toupper(getche());
		
	}while(jawab == 'Y');
	fclose(f_menu);
}

void addMenu(){
	int line = 1;
	char jawab;
	menu m;
	FILE *f_menu;
	
	if((f_menu=fopen("dataMenu.DAT","rb")) == NULL){
		printf("Gagal membuka file!\n");
	}
	while ((fread(&m,sizeof(m),line,f_menu)) == line){
	}
	if((f_menu=fopen("dataMenu.DAT","ab")) == NULL){
		printf("Gagal membuka file!");
	}
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
		printf("Input Stock : ");
		scanf("%d",&m.sMenu);
		fflush(stdin);
		printf("Input Kode Menu : ");
		scanf("%4s",&m.kMenu);

		//menambah user input kedalam file
		fwrite(&m,sizeof(m),1,f_menu);		
		printf("Input File again ?(Y/N)");
		jawab = toupper(getche());
		
	}while(jawab =='Y');
	
	fclose(f_menu);
}

void viewMenu(){
	//deklarasi variabel
	menu m;
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
	printf("No  Menu          Price   Stock  \n") ;
	while ((fread(&m,sizeof(m),line,f_menu)) == line){
		k = 12;
		i = 0;
		printf(" %d |",count);
		length = strlen(m.nMenu);
		printf(" %s",m.nMenu);
		k = k-length;
		while(i<k){
			printf(" ");
			i++;
		}
		printf("| %d",m.hMenu);
		sprintf(tempH,"%d",m.hMenu);
		length = strlen(tempH);
		k = 6;
		i = 0;
		k = k-length;
		while(i<k){
			printf(" ");
			i++;
		}
		printf("| %d\n",m.sMenu);
		count++;
	}
	for(;;){
		printf("Lanjut?(Y/N)");
		opsi = toupper(getche()); 
			break;
		}
	
	fclose(f_menu);
	if(opsi == 'N'|| opsi == 'n'){
		indexMenu();
	}
}
void deleteMenu(){
	// deklarasi variabel
	int line, count, i;
	menu m1, m2;
	FILE *f_menu1, *f_menu2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
	// input baris yang akan didelete
	viewMenu();
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
	char tempH[10];
	char tempS[10];
	menu m1, m2;
	FILE *f_menu1, *f_menu2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
	viewMenu();
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
	printf("3. Stock Menu\n");
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
			m2.hMenu = atoi(tempH);
			m2.sMenu = atoi(tempS);
			break;
			
		case 2 :
			printf("Input Harga Menu : ");
			scanf("%d",&m2.hMenu);
			fflush(stdin);
			strcpy(m2.nMenu,m1.nMenu);
			m2.sMenu = atoi(tempS);
			break;
			
		case 3 :
			printf("Input Stock Menu : ");
			scanf("%d",&m2.sMenu);
			fflush(stdin);
			strcpy(m2.nMenu,m1.nMenu);
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
}
