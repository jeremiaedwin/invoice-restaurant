#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "login.h"



void indexLogin(User dt){
	int opsi;
	for(;;){
		if(dt.level <3){
			return;
		}
		system("CLS");
		printf("1. Create Account\n");
		printf("2. List Account\n");
		printf("Press any key beside 1 or 2 to get back!\n");
		printf("Choose : ");
		scanf("%d",&opsi);
		
		switch(opsi){
			case 1 :
				regist();
				break;
			case 2 :
				listUser();
				break;
			default :
				return;
		}
	}
	
}
void regist(){

	User dt;
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
	printf("Input Level (1 - 3): ");
	scanf("%d",&dt.level);
	time(&dt.user_id);
	

	fwrite(&dt,sizeof(dt),1,f_user);
	
	fclose(f_user);

}

void login(User *dt){
	
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
			printf("Selamat Datang %s!\n",dt1.nama);
			*dt = input(dt1);
		}
	}
	
	if(userFind){
		printf("Data user tidak ada!\n");
	}
	count++;
	}while((userFind)&&count<5);
	fclose(f_user);
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
	printf ("Menu \n");
	
	count = 1;
	//Display file ke layar
	printf("No  Nama                           level Username  \n") ;
	while ((fread(&U,sizeof(U),line,f_user)) == line){
		k = 30;
		i = 0;
		printf(" %d |",count);
		length = strlen(U.nama);
		printf(" %s",U.nama);
		k = k-length;
		while(i<k){
			printf(" ");
			i++;
		}
		printf("| %d ",U.level);
		sprintf(tempH,"%d",U.level);
		length = strlen(tempH);
		k = 1;
		i = 0;
		k = k-length;
		while(i<k){
			printf(" ");
			i++;
		}
	
		printf("| %s",U.username);
		length = strlen(U.username);
		k = 20;
		i = 0;
		k = k-length;
		while(i<k){
			printf(" ");
			i++;
		}
		printf("| %d",U.user_id);
		sprintf(tempH,"%d",U.user_id);
		length = strlen(tempH);
		k = 14;
		i = 0;
		while(i<k){
			printf(" ");
			i++;
		}
		printf("|\n");
		count++;
	}
	for(;;){
		printf("Lanjut?(Y/N)");
		opsi = toupper(getche()); 
			break;
		}
	
	fclose(f_user);
	if(opsi == 'Y'|| opsi == 'y'){
		return;
	}
}

