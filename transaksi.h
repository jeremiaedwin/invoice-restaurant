#ifndef transaksi_H
#define transaksi_H
#include "login.h"
#include "menu.h"

// Struct keranjang tempat menaruh menu yang diambil
typedef struct{
	char kMenu[5]; //kode menu
	char nMenu[51]; //nama menu
	int hMenu; //harga menu
	int qty; //kuantitas menu
}Keranjang;

// Struct tanggal pembelian
typedef struct{
	int tanggal; // tanggal pembelian
	int bulan; // bulan pembelian
	int tahun; // tahun pembelian
}Date;

// Struct data pembayaran
typedef struct{
	char kode_transaksi[6]; //kode transaksi
	char kode_user[6]; //kode kasir yang melakukan proses pembayaran
	Date tanggal_pembelian; //tanggal pembelian
	Keranjang m[10]; //menu yang akan dibeli
	int total_harga; //total harga yang harus dibayar
	int jMenu; //jumlah menu yang dibeli
	int uangMasuk; //uang yang dibayarkan
	int kembalian; //kembalian
}Pembayaran;

void transaksiIndex(User dt); //menampilkan pilihan menu untuk transaksi
void readMenu(); //void menampilkan menu ketika melakukan transaksi
void inputTransaksi(User dt); //modul transaksi
Keranjang searchMenu(char kodeMenu[6],User dt); //modul pencarian data menu
void hitungHarga(Pembayaran dt, int *total, int *sum, int n); //modul perhitungan total harga
void viewTransaksi(); //daftar transaksi


#endif


