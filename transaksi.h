#ifndef transaksi_H
#define transaksi_H
#include "login.h"

int size=0;


//char kode_kasir1[25] = "KSR01"; 
typedef struct{
	char kMenu[5];
	char nMenu[51];
	int hMenu;
	int qty;
}Keranjang;

typedef struct{
	char kode_transaksi[6];
	char kode_user[6];
	char tanggal_pembelian[20];
	Keranjang dt_menu[10];
	int total_harga;
	int jMenu;
}Pembayaran;

typedef struct{
	char nMenu[51];
	int hMenu;
	int sMenu;
	char kMenu[5];
}menu1;

void transaksiIndex(User dt);
void viewMenu();
Keranjang searchMenu(char kodeMenu[6],User dt);
void inputTransaksi(User dt);
void hitungHarga(Pembayaran dt, int *total, int *sum, int n);
void viewTransaksi();
int validateQty(int qty);
void validateKode(Pembayaran dt);

#endif
