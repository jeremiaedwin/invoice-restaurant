#ifndef rekap_H
#define rekap_H
#include "login.h"
#include "transaksi.h"

typedef struct{
	char kode_rekap[15];
	int total_transaksi;
	int total_pemasukan;
}Rekap;

void indexRekap(); // menampilkan menu fitur yang ada di dalam rekap
void rekapHarian(); // menampilkan rekapitulasi harian
void rekapBulanan(); // menampilkan rekapitulasi bulanan
void rekapTahunan(); // menampilkan rekapitulasi tahunan
void cariRekap(); // menampilkan data rekap yang disimpan
#endif
