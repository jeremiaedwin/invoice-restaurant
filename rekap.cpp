#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "rekap.h"
#include<string.h>

void indexRekap(){
	int opsi;
	
	printf("1. Rekap Hari ini\n");
	printf("2. Rekap Bulan ini\n");
	printf("3. Rekap Tahun ini\n");
	printf("4. Cari File\n");
	printf("5. Kembali");
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
		case 4:
			cariRekap();
			break;
		default:
			return;
	}
	
}

void rekapHarian(){
	system("cls");
	
//	Kamus data
	int i;
	int countTransaksi=0;
	int tmpPemasukan=0;
	int totPemasukan=0;	
	int menuTerjual=0;
	int	banyakBarang=0;
	int tmpQty=0;
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
			i=0;
			while(i<=dt_pembayaran.jMenu){
				menuTerjual++;
			}
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
	char isSave;	
	char nameFile[7];
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	Pembayaran dt_pembayaran;
	Rekap dt_rekap;
	FILE *f_transaksi;
	FILE *f_rekap;
	
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
	
	printf("Simpan Rekap ?");
	scanf("%s", &isSave);
	toupper(isSave);
	if(isSave='Y'){
		sprintf(nameFile, "%d-%d.DAT", tm.tm_mon+1, tm.tm_year+1900);
		if((f_rekap=fopen(nameFile,"wb"))==NULL){
			printf ("File tidak dapat dibuka\n"); 
			exit(1);
		}
		strcpy(dt_rekap.kode_rekap, nameFile);
		dt_rekap.total_transaksi = countTransaksi;
		dt_rekap.total_pemasukan = totPemasukan;
		
		fwrite(&dt_rekap, sizeof(dt_rekap), 1, f_rekap);
		printf("Berhasil disimpan");
		fclose(f_transaksi);

	}else{
		return;
	}
		
}

void rekapTahunan(){
	system("cls");
//	Kamus data
	int countTransaksi=0;
	int tmpPemasukan=0;
	int totPemasukan=0;
	char isSave;	
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char nameFile[11];
	Pembayaran dt_pembayaran;
	Rekap dt_rekap;
	FILE *f_transaksi;
	FILE *f_rekap;
	
	if((f_transaksi=fopen("f_transaksi.DAT","rb"))==NULL){
		printf ("File tidak dapat dibuka\n"); 
			exit(1);
	}
	
	printf("Rekap pembelian tahun ini\n");
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
	
	printf("Simpan Rekap ?");
	scanf("%s", &isSave);
	toupper(isSave);
	if(isSave='Y'){
		sprintf(nameFile, "%d.DAT",tm.tm_year+1900);
		if((f_rekap=fopen(nameFile,"wb"))==NULL){
			printf ("File tidak dapat dibuka\n"); 
			exit(1);
		}
		sprintf(dt_rekap.kode_rekap, "%d",tm.tm_year+1900);
		dt_rekap.total_transaksi = countTransaksi;
		dt_rekap.total_pemasukan = totPemasukan;
		
		fwrite(&dt_rekap, sizeof(dt_rekap), 1, f_rekap);
		printf("Berhasil disimpan");
		fclose(f_transaksi);

	}else{
		return;
	}
}

void cariRekap(){
	char namaFile[11];
	FILE *f_rekap;
	Rekap dt_rekap;
	
	printf("Cari File (cth: 1-2022.DAT) : ");
	scanf("%s", &namaFile);
	if((f_rekap = fopen(namaFile, "rb"))==NULL){
		printf("File Tidak Ada");
		exit(1);
	}
	while(fread(&dt_rekap, sizeof(dt_rekap),1,f_rekap)==1){
		printf("Kode Rekap      = %s \n", dt_rekap.kode_rekap);
		printf("Total Transaksi = %d \n", dt_rekap.total_transaksi);
		printf("Total Rekap     = %d", dt_rekap.total_pemasukan);
	}
	fclose(f_rekap);
	
	char keluar;
	printf("\nKeluar (Y/N)? ");
	scanf("%s", &keluar);
	toupper(keluar);
	if(keluar=='Y'){
		return;
	}
	
}
