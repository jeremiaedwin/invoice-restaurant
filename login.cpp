/*
Judul : login.cpp
Author : Panji Judha Fadhilla
NIM : 211511053
Sebuah modul yang fungsinya membuat user,delete user
dan login.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "login.h"



void indexLogin(User dt){
	//Deklarasi variabel lokal
	char confirm;
	int opsi;//penammpung opsi user
	for(;;){
		if(dt.level <3){
			return;
		}
		system("CLS");
		printf("1. Create Account\n");
		printf("2. List Account\n");
		printf("3. Delete Account\n");
		printf("4. Update Account\n");
		printf("5. Back\n");
		printf("Choose : ");
		scanf("%d",&opsi);
		
		switch(opsi){
			case 1 :
				regist();
				break;
			case 2 :
				for(;;){
					system("cls");
					listUser();
					printf("\nKembali?(Y/T)");
					confirm = toupper(getche());
					if(confirm == 'Y'){
						break;
					}
				}
				break;
			case 3 :
				deleteUser(dt);
				break;
			case 4 :
				updateUser(dt);
				break;
				
			case 5 :
				return;
			default :
				break;
		}
	}
	
}

void regist(){

//Deklarasi Variabel Lokal
	User dt;//struct data user
	time_t tempID;
	int line;
	FILE *f_user;
	
	if((f_user=fopen("dataUser.DAT","ab"))==NULL){
		printf("File gagal dibuat/dibuka!");
		exit(1);
	}
	printf("Input Nama : ");
	fflush(stdin);
	gets(dt.nama);
	fflush(stdin);
	printf("Input Username : ");
	scanf("%s",&dt.username);
	fflush(stdin);
	printf("Input Password : ");
	scanf("%s",&dt.password);
	fflush(stdin);
	for(;;){
		printf("Input Level (1 - 3): ");
		scanf("%d",&dt.level);
		fflush(stdin);
		if(dt.level >= 1 && dt.level <= 3){
			break;
		}
		system("cls");
		printf("\nInput level salah !");
	}
	time(&tempID);
	sprintf(dt.user_id,"%d",tempID);

	

	fwrite(&dt,sizeof(dt),1,f_user);
	fclose(f_user);

}

int login(User *dt){
	
	char tempU[21];
	char tempP[9];
	int count = 0;
	bool userFind = true;
	int line = 1;
	FILE *f_user;
	User dt1;
	
	do{
	printf("Username : ");
	scanf("%s",&tempU);
	printf("Password : ");
	scanf("%s",&tempP);
	if((f_user = fopen("dataUser.DAT","rb"))==NULL){
		printf("File gagal dibuka!");
		exit(1);
	}
	while((fread(&dt1,sizeof(dt1),line,f_user))==line){
		if((strcmp(dt1.username,tempU))==0 && (strcmp(dt1.password,tempP)) == 0){
			userFind = false;
			*dt = input(dt1);
		}
	}
	
	if(userFind){
		system("CLS");
		printf("Data user tidak ada!\n");
	}
	
	count++;
	}while((userFind)&&count<5);
	fclose(f_user);
	system("cls");
	return count;
}
User input(User dt){
	return dt;
}


void listUser(){

	//deklarasi variabel
	User U;
	FILE *f_user;
	char opsi;
	int line = 1;
	int length;
	int i,k,count;
	char tempH[15];
	
	//Buka file
	if ((f_user=fopen("dataUser.DAT", "rb"))==NULL){
		
		printf ("File Gagal Dibuka!\n"); 
		exit(1);		 
	}
	
	count = 1;
	//Display file ke layar
	printf("---------------------------------------------------------------------------------------------\n");
	printf("|%-5s|%-20s|%-20s|%-20s|%-8s|%-5s|\n","No", "Nama User" ,"User ID", "Username", "Password","Level");
	printf("---------------------------------------------------------------------------------------------\n");

	while ((fread(&U,sizeof(U),line,f_user)) == line){
		printf("|%-5d|%-20s|%-20s|%-20s|%-8s|%-5d|\n",count, U.nama, U.user_id, U.username, U.password,U.level);
		count++;
	}
	printf("---------------------------------------------------------------------------------------------\n");
	
	fclose(f_user);
	}

void deleteUser(User dt){
	// deklarasi variabel
	int line, count, i;
	char opsi;
	User dt1,dt2;
	FILE *f_user1, *f_user2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
	// input baris yang akan didelete
	listUser();
	printf("\n\n");
	printf("\nLanjut?(Y/T)");
	opsi = toupper(getche());
	if(opsi == 'T'){
		return;
	}
	printf("\nMasukkan baris data mana yang akan di delete : ");
	scanf("%d", &line);
	fflush(stdin);
	
	//membuka file
	if ((f_user1=fopen("dataUser.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	
	if ((f_user2=fopen("dataUser_2.DAT", "ab+"))==NULL)
	{
		printf ("File tidak dapat dibuat\n"); 
		exit(1);
	}
	i = 1;
	while ((fread(&dt1, sizeof(dt1),i, f_user1)) == i){
		count++;
		if(count == line){
			if((strcmp(dt.user_id,dt1.user_id))==0){
				printf("User sedang digunakan!");
				fclose(f_user1);
				fclose(f_user2);
				return;
			}
		}
	}
	rewind(f_user1);
	count = 0;
	while ((fread(&dt1, sizeof(dt1),i, f_user1)) == i)
	{
		count++;
		if(count != line){
			fwrite(&dt1, sizeof(dt1),i,f_user2);
		}
	}
		
	// Menutup kedua file
	fclose(f_user1);
	fclose(f_user2);
	
	// Merubah file copy menjadi original
	remove("dataUser.DAT");
	rename("dataUser_2.DAT", "dataUser.DAT");

}

void updateUser(User dt){
	// deklarasi variabel
	int line, count, i, pilihan;
	bool used = false;
	char opsi;
	char tempU[21];
	char tempP[9];
	char tempN[31];
	int tempL;
	int T;
	User dt1, dt2;
	FILE *f_user1, *f_user2; // kategori1 adalah file original dan kategori 2 adalah file copy nya
	
	listUser();
	printf("\nLanjut?(Y/T)");
	opsi = toupper(getche());
	if(opsi == 'T'){
		return;
	}
	printf("\nMasukkan baris data mana yang akan di update: ");
	scanf("%d", &line);
	
	if ((f_user1=fopen("dataUser.DAT", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n"); 
		exit(1);
	}
	i = 1;
	count = 0;
	while((fread(&dt1, sizeof(dt1),i, f_user1)) == i){
		count++;
		if(count == line){
			if((strcmp(dt.user_id,dt1.user_id))==0){
				used = true;
			}
			break;
		}
	}
	fflush(stdin);
	printf("Data apa yang akan diganti ?\n");
	printf("1. Nama User\n");
	printf("2. Username\n");
	printf("3. Password\n");
	printf("4. Level\n");
	printf("5. Semua\n");
	scanf("%d",&pilihan);
	fflush(stdin);
	
	switch(pilihan){
		case 1 :
			printf("Input Nama User :");
			gets(dt2.nama);
			fflush(stdin);
			dt2.level = dt1.level;
			strcpy(dt2.username,dt1.username);
			strcpy(dt2.password,dt1.password);
			break;
			
		case 2 :
			printf("Input Username : ");
			scanf("%s",&dt2.username);
			fflush(stdin);
			strcpy(dt2.password,dt1.password);
			strcpy(dt2.nama,dt1.nama);
			dt2.level = dt1.level;
			break;
			
		case 3 :
			printf("Input Password : ");
			scanf("%s",&dt2.password);
			fflush(stdin);
			strcpy(dt2.nama,dt1.nama);
			strcpy(dt2.username,dt1.username);
			dt2.level = dt1.level;
			break;
			
		case 4 :
			for(;;){
				printf("Input Level (1 - 3): ");
				scanf("%d",&dt2.level);
				fflush(stdin);
				if(dt.level >= 1 && dt.level <= 3){
					break;
				}
				system("cls");
				printf("\nInput level salah !");
			}
			strcpy(dt2.username,dt1.username);
			strcpy(dt2.password,dt1.password);
			strcpy(dt2.nama,dt1.nama);
			break;
		case 5 :
			fflush(stdin);
			printf("Input Nama User : "); 
			scanf("%30[^\n]",&dt2.nama);
			fflush(stdin);
			printf("Input Username : "); 
			scanf("%s",&dt2.username); 
			fflush(stdin);
			printf("Input Password : ");
			scanf("%s",&dt2.password);
			fflush(stdin);
			for(;;){
				printf("Input Level (1 - 3): ");
				scanf("%d",&dt2.level);
				fflush(stdin);
				if(dt.level >= 1 && dt.level <= 3){
					break;
				}
				system("cls");
				printf("\nInput level salah !");
			}
			break;
		
			
	}
	
	strcpy(dt2.user_id,dt1.user_id);
	
	rewind(f_user1);
	//membuka file
	if ((f_user2=fopen("dataUser_2.DAT", "ab"))==NULL)
	{
		printf ("File tidak dapat dibuat\n"); 
		exit(1);
	}

	i = 1;
	count = 0;
	while ((fread(&dt1, sizeof(dt1),i, f_user1)) == i){
		
		count++;
		if(count == line){
			fwrite(&dt2, sizeof(dt2),i,f_user2);
		}else{
			fwrite(&dt1, sizeof(dt1),i,f_user2);
		}
	} 
	
	fclose(f_user1);
	fclose(f_user2);
	remove("dataUser.DAT");
	rename("dataUser_2.DAT", "dataUser.DAT");

	if(used){
		exit(1);
	}
}
