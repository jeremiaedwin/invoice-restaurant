#ifndef login_H
#define login_H
#include <time.h>


typedef struct{
	char username[21];
	char password[9];
	char nama[31];
	char user_id[12];
	int level;
}User;

void indexLogin(User dt);
void regist();
void login(User *dt);
void searchUser();
void listUser();
void deleteUser();
User input(User dt);


#endif
