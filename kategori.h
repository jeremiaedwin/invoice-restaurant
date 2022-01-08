#ifndef kategori_H
#define kategori_H
#include <string>
#include "login.h"
using namespace std;

typedef struct {
	char kode_kategori[3];
	char nama_kategori[50];
} Kategori;


void indexKategori(User dt); // menampilkan pilihan fitur yang ada di kategori
void create(); // modul untuk menambah data kategori baru
void read(); // modul untuk menampilkan data kategori
void updateKategori(); // modul untuk melakukan update data kategori
void destroy(); // modul untuk menghapus data kategori

#endif
