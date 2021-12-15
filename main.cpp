#include <iostream>
#include "login.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	char uname[16] = {};
	char pass[16] = {};
	
	setUser(&uname, &pass);
	printf("Username Anda %s, Password anda %s", uname, pass);
//	int user_id = getUser(uname, pass);
	
	return 0;
}
