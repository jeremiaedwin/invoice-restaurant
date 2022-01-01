#ifndef kategori_H
#define kategori_H
#include <string>
#include "login.h"
using namespace std;

typedef struct {
	char kode_kategori[3];
	char nama_kategori[50];
} Kategori;


void indexKategori(User dt); 
void create(); 
void read(); 
void updateKategori();
void destroy();

#endif
