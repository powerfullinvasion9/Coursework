#include <iostream>
#include "authorization.h"

using namespace std;




int main() {

	vector<Account> acc;
	ofstream fout;
	fout.open(FILE_OF_ACC, ios::out);
	Account user;
	user.login = "Isa";
	user.password = "i7753191";
	user.access = 0;
	setlocale(LC_ALL, "ru");
	createAdmin(acc);
	addAccountToVector(acc, user);
	writeVectorToFile(acc,fout);


	//authorizationMenu();


	return 0;
}