#ifndef login_H
#define login_H

typedef struct user{
	const char kode_user[8];
	const char username[16];
	const char password[10];
	const char nama_user[50];
	int level;
}user;


void setUser(char *username, char *password);
int getUser(char username[], char password[]);

#endif
