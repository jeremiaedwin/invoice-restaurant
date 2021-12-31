#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "login.h"
#include "menu.h"
#include "kategori.h"
#include "transaksi.h"
//char kode_kasir[25] = "KSR01";
int main(){
<<<<<<< HEAD
=======
// Deklarasi variabel
	int opsi;
>>>>>>> f9798e939b01af01a0b28a7105867a7cfcb003a7
	User dt;
	regist();
	login(&dt);
	listUser();
	int opsi;
	
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
<<<<<<< HEAD
						transaksiIndex();
=======
						indexKategori(dt);
						break;
					case 3 :
						
>>>>>>> f9798e939b01af01a0b28a7105867a7cfcb003a7
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
