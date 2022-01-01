#ifndef menu_H
#define menu_H
#include "login.h"
#include "kategori.h"

typedef struct{
	char nMenu[51];
	int hMenu;
	int sMenu;
	char kMenu[5];
	Kategori kategori;
}menu;

Kategori searchKategori(char kode_kategori[]);
void indexMenu(User dt);
void createMenu();//write file menu, isi file sebelumnya akan hilang(bila file tidak ada akan dibuat)
void addMenu();//append file menu, menambah isi menu tanpa menghapus data sebelumnya
void deleteMenu();//menghapus 1 line file yang diinginkan user
void viewMenu();//melihat isi file menu
void update();// mengubah isi menu yang ada



#endif
