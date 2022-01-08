#ifndef menu_H
#define menu_H
#include "login.h"
#include "kategori.h"

//nested struct data menu
typedef struct{
	char nMenu[51];//variabel nama menu
	int hMenu;//variable harga menu
	int sMenu;//variable status menu
	char kMenu[5];//variabel kategori menu
	Kategori kategori;//struct data kategori
}menu;

Kategori searchKategori(char kode_kategori[]);//proses input kategori ke file menu
void indexMenu(User dt);//menu utama dari pengolahan menu
void createMenu();//write file menu, isi file sebelumnya akan hilang(bila file tidak ada akan dibuat)
void addMenu();//append file menu, menambah isi menu tanpa menghapus data sebelumnya
void deleteMenu();//menghapus 1 line file yang diinginkan user
void viewMenu();//melihat isi file menu
void update();// mengubah isi menu yang ada
void readKategori();//menampilkan kategori yang akan dipilih


#endif
