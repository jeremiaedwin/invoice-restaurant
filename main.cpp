#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "login.h"
#include "menu.h"
#include "kategori.h"

int main(){
// Deklarasi variabel
	int opsi;
	User dt;
	
//	regist();
//Login user
	login(&dt);
	printf("\nLevel User :%d",dt.level);

	for(;;){
		
		switch(dt.level){
			case 1 :
				printf("\n1. Menu");
				printf("\n2. Kategori");
				printf("\n3. Transaksi");
				printf("\nPilih : ");
				scanf("%d",&opsi);
				switch(opsi){
					case 1 :
						indexMenu(dt);
						break;
					case 2 :
						indexKategori(dt);
						break;
					case 3 :
						
						break;
				}
				break;
			case 2 :
				printf("\n1. Menu");
				printf("\n2. Kategori");				
				printf("\n3. Transaksi");
				printf("\n4. Laporan");
				printf("\nPilih : ");
				scanf("%d",&opsi);
				
				switch(opsi){
					case 1 :
						indexMenu(dt);
						break;
					case 2 :
						indexKategori(dt);
						break;
					case 3 :
//						indexTransaksi(dt);
						break;
					case 4 :
//						indexLaporan(dt);
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
//						indexTransaksi(dt);
						break;
					case 3 :
//						indexLaporan(dt);
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
}
