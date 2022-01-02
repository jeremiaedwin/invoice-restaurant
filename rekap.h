#ifndef rekap_H
#define rekap_H
#include "login.h"
#include "transaksi.h"

typedef struct{
	char kode_rekap[7];
	int total_transaksi;
	int total_pemasukan;
}Rekap;

void indexRekap();
void rekapHarian();
void rekapBulanan();
void rekapTahunan();
void cariRekap();
#endif
