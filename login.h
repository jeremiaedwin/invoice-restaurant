#ifndef login_H
#define login_H
#include <string>
using namespace std;

typedef struct {
	string username;
	string password;
}user;


void getUser(user* U);
user inputData(string U, string P);
void printUser(user U);
int loginValid(string U, string P);

#endif
