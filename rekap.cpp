#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "rekap.h"

void indexRekap(){
	int opsi;
	
	printf("1. Rekap Harian\n");
	printf("2. Rekap Bulanan\n");
	printf("3. Rekap Tahunan\n");
	printf("4. Kembali");
	printf("\n\tPilih: ");
	scanf("%d", &opsi);
	
	switch(opsi){
		case 1:
			rekapHarian();
			break;
		case 2:
			rekapBulanan();
			break;
		case 3:
			rekapTahunan();
			break;
		default:
			return;
	}
	
}

void rekapHarian(){
	system("cls");
	
//	Kamus data
	int countTransaksi=0;
	int tmpPemasukan=0;
	int totPemasukan=0;	
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	Pembayaran dt_pembayaran;
	FILE *f_transaksi;
	
	if((f_transaksi=fopen("f_transaksi.DAT","rb"))==NULL){
		printf ("File tidak dapat dibuka\n"); 
			exit(1);
	}
	
	printf("Rekap pembelian hari ini\n");
	while ((fread(&dt_pembayaran, sizeof(dt_pembayaran),1, f_transaksi)))
	{
		if((dt_pembayaran.tanggal_pembelian.tanggal == tm.tm_mday) && (dt_pembayaran.tanggal_pembelian.tahun == tm.tm_year+1900)&&(dt_pembayaran.tanggal_pembelian.bulan == tm.tm_mon+1)){
			countTransaksi++; 
			tmpPemasukan = dt_pembayaran.total_harga;
			totPemasukan = totPemasukan + tmpPemasukan;
		}
	}
	fclose(f_transaksi);
	printf("Jumlah Transaksi = %d\n", countTransaksi);
	printf("Jumlah Pemasukan = Rp %d\n", totPemasukan);
}

void rekapBulanan(){
	system("cls");
//	Kamus data
	int countTransaksi=0;
	int tmpPemasukan=0;
	int totPemasukan=0;	
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	Pembayaran dt_pembayaran;
	FILE *f_transaksi;
	
	if((f_transaksi=fopen("f_transaksi.DAT","rb"))==NULL){
		printf ("File tidak dapat dibuka\n"); 
			exit(1);
	}
	
	printf("Rekap pembelian bulan ini\n");
	while ((fread(&dt_pembayaran, sizeof(dt_pembayaran),1, f_transaksi)))
	{
		if((dt_pembayaran.tanggal_pembelian.tahun == tm.tm_year+1900)&&(dt_pembayaran.tanggal_pembelian.bulan == tm.tm_mon+1)){
			countTransaksi++; 
			tmpPemasukan = dt_pembayaran.total_harga;
			totPemasukan = totPemasukan + tmpPemasukan;
		}
	}
	fclose(f_transaksi);
	printf("Jumlah Transaksi = %d\n", countTransaksi);
	printf("Jumlah Pemasukan = Rp %d\n", totPemasukan);
}

void rekapTahunan(){
	system("cls");
//	Kamus data
	int countTransaksi=0;
	int tmpPemasukan=0;
	int totPemasukan=0;	
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	Pembayaran dt_pembayaran;
	FILE *f_transaksi;
	
	if((f_transaksi=fopen("f_transaksi.DAT","rb"))==NULL){
		printf ("File tidak dapat dibuka\n"); 
			exit(1);
	}
	
	printf("Rekap pembelian bulan ini\n");
	while ((fread(&dt_pembayaran, sizeof(dt_pembayaran),1, f_transaksi)))
	{
		if(dt_pembayaran.tanggal_pembelian.tahun == tm.tm_year+1900){
			countTransaksi++; 
			tmpPemasukan = dt_pembayaran.total_harga;
			totPemasukan = totPemasukan + tmpPemasukan;
		}
	}
	fclose(f_transaksi);
	printf("Jumlah Transaksi = %d\n", countTransaksi);
	printf("Jumlah Pemasukan = Rp %d\n", totPemasukan);
}
