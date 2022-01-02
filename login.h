#ifndef login_H
#define login_H


typedef struct{
	char username[21];
	char password[9];
	char nama[31];
	int level;
	char user_id[12];

}User;

void indexLogin(User dt);
void regist();
void login(User *dt);
void searchUser();
void listUser();
void deleteUser();
User input(User dt);


#endif
