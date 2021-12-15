#include <iostream>
#include <stdio.h>
#include <string>
#include "login.h"
using namespace std;
int main(){

	user vLogin;
	getUser(&vLogin);
	printUser(vLogin);
	
	return 0;
}
