#ifndef kategori_H
#define kategori_H
#include <string>
using namespace std;

typedef struct {
	char kode_kategori[3];
	char nama_kategori[50];
} Kategori;

#define BUFFER_SIZE 1000

void indexKategori(); 
void create(); 
void read(); 
void updateKategori();
void destroy();

#endif
