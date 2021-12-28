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
	
		system("CLS");
		printf("1. Menu\n");
		printf("2. Kategori\n");
//		printf("3. Display M\n");
//		printf("4. Update Menu\n");
//		printf("5. Delete Menu\n");
		scanf("%d",&opsi);
	
		switch(opsi){
			case 1:
				indexMenu();
				break;
			case 2:
				indexKategori();
				break;
//			case 3:
//				viewMenu();
//				break;	
//			case 4:
//				update();
//				break;
//			case 5:
//				deleteMenu();
//				break;
			default :
				return 0;
	}
}
