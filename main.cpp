/*
Nama Aplikasi 	: Invoice Restaurant
Author			: Jeremia Edwin Hamonangan (211511039) & Panji Judha Fadhilla (211511053)
Kelas			: 1B
Deskripsi 		: aplikasi untuk memudahkan kasir dalam pemesanan dan transaksi pelanggan. 
				  Aplikasi ini dapat digunakan oleh 3 level user yang berbeda yaitu kasir,  
				  manajer dan admin. Aplikasi ini berfungsi untuk melakukan pengelolaan menu, 
				  pembayaran dan laporan
*/
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "login.h"
#include "menu.h"
#include "kategori.h"
#include "transaksi.h"
#include "rekap.h"

int main(){
// Deklarasi variabel
	int opsi;
	User dt;
//	regist();	
	login(&dt);
	
	printf("\nLevel User :%d\n",dt.level);

	for(;;){
		system("cls");
		switch(dt.level){
			case 1 :
				printf("\nLevel User :%d\n",dt.level);
				printf("Selamat Datang %s!\n",dt.nama);
				printf("\n1. Menu");
				printf("\n2. Transaksi");
				printf("\n3. Kategori ");
				printf("\n4. Keluar");
				printf("\nPilih : ");
				scanf("%d",&opsi);
				switch(opsi){
					case 1 :
						indexMenu(dt);
						break;
					case 2 :
						transaksiIndex(dt);
						break;
					case 3 :
						indexKategori(dt);
						break;
					default :
						return 0;
				}
				break;
			case 2 :
				printf("\nLevel User :%d\n",dt.level);
				printf("Selamat Datang %s!\n",dt.nama);
				printf("\n1. Menu");
				printf("\n2. Kategori");				
				printf("\n3. Transaksi");
				printf("\n4. Laporan");
				printf("\n5. Keluar");
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
						transaksiIndex(dt);
						break;
					case 4 :
						indexRekap();
						break;
					default :
						return 0;
					}
				break;
			case 3 :
				printf("\nLevel User :%d\n",dt.level);
				printf("Selamat Datang %s!\n",dt.nama);
				printf("\n1. Menu");
				printf("\n2. Transaksi");
				printf("\n3. Laporan");
				printf("\n4. Manajemen Akun");
				printf("\n5. Kategori");
				printf("\n6. Keluar");
				printf("\nPilih : ");
				scanf("%d",&opsi);
				switch(opsi){
					case 1 :
						indexMenu(dt);
						break;
					case 2 :
						transaksiIndex(dt);
						break;
					case 3 :
						indexRekap();
						break;
					case 4 :
						indexLogin(dt);
						break;
					case 5 :
						indexKategori(dt);
						break;
					default :
						return 0;
				}
				break;
			default :
				printf("Terjadi kesalahan!\nLevel akun tidak ada!");
				exit(1);
		}
	}
}
