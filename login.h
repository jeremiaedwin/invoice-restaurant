#ifndef login_H
#define login_H

//struct data user
typedef struct{
	char username[21];
	char password[9];
	char nama[31];
	int level;//level user untuk menentukan akses aplikasi
	char user_id[12];

}User;

void indexLogin(User dt);//menu utama dari manajemen user
void regist();//prosedur untuk pembuatan user baru
int login(User *dt);//prosedur untuk login user
void listUser();//prosedur untuk menampilkan list user
void deleteUser(User dt);//prosedur untuk menghapus data user
User input(User dt);//function untuk menginput data user kedalam struct
void updateUser(User dt);//prosedur untuk mengubah data user

#endif
