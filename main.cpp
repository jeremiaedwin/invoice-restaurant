#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "login.h"
#include "menu.h"
#include "kategori.h"

int main(){
	User dt;
//	regist();
	login(&dt);
	listUser();
	int opsi;
	User dt;
	
//	regist();
	login(&dt);
	printf("\nLevel User :%d",dt.level);

	for(;;){
		
		system("CLS");
		switch(dt.level){
			case 1 :
				printf("\n1. Menu");
				printf("\n2. Transaksi");
				printf("\nPilih : ");
				scanf("%d",&opsi);
				switch(opsi){
					case 1 :
						break;
					case 2 :
						break;
				}
				break;
			case 2 :
				printf("\n1. Menu");
				printf("\n2. Transaksi");
				printf("\n3. Laporan");
				printf("\nPilih : ");
				scanf("%d",&opsi);
				
				switch(opsi){
					case 1 :
						indexMenu(dt);
						break;
					case 2 :
						break;
					case 3 :
						break;
				}
				break;
			case 3 :
				printf("\n1. Menu");
				printf("\n2. Transaksi");
				printf("\n3. Laporan");
				printf("\n4. Manajemen Akun");
				printf("\nPilih : ");
				scanf("%d",&opsi);
				switch(opsi){
					case 1 :
						indexMenu(dt);
						break;
					case 2 :
						break;
					case 3 :
						break;
					case 4 :
						indexLogin(dt);
						break;
				}
				break;
			default :
				printf("Terjadi kesalahan!\nLevel akun tidak ada!");
				exit(1);
	}
	}
//		system("CLS");
//		printf("1. Menu\n");
//		printf("2. Kategori\n");
//		printf("3. Display M\n");
//		printf("4. Update Menu\n");
//		printf("5. Delete Menu\n");
//		scanf("%d",&opsi);
//	
//		switch(opsi){
//			case 1:
//				indexMenu();
//				break;
//			case 2:
//				indexKategori();
//				break;
//			case 3:
//				viewMenu();
//				break;	
//			case 4:
//				update();
//				break;
//			case 5:
//				deleteMenu();
//				break;
//			default :
//				return 0;
//	}
}
