#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "login.h"
using namespace std;

void getUser(user* U){
	
	string UN,P;
	
	printf("==========LOGIN==========\n");
	cout << "Username :";
	cin >> UN;
	cout << "Password :";
	cin >> P;
	
	if(loginValid(UN,P)){
		*U = inputData(UN,P);
	}else {
		system("CLS");
		printf("Username atau password melebihi batas karakter\n");
		getUser(U);
	}
	
}


user inputData(string U, string P){
	user A;
	(A).username = U;
	(A).password = P;
	return A;
}



void printUser(user U){
	cout << "Username :"<<(U).username << " Password :" <<(U).password ;
//printf("Username : %s Passwword : %s",(U).username, (U).password);
}

int loginValid(string U,string P){
	int panjangU,panjangP,batasU,batasP;
	batasU = 16;
	batasP = 10;
	panjangU = U.length();
	panjangP = P.length();
	
	return ((panjangU <= batasU && panjangP <= batasP));
}
