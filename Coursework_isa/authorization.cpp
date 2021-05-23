#include "authorization.h"

using namespace std;


void createAdmin(vector<Account>& acc) {
	
	ifstream fin;
	fin.open(FILE_OF_ACC, ios::in);
	Account admin;
	admin.access = 1;
	admin.login = "admin";
	admin.password = "password";


	if (acc.empty())
	{
		acc.push_back(admin);
	}
	else
	{
		return;
	}
	
}

void writeVectorToFile(vector<Account>& acc,ofstream &fout) {

	
	for (int i = 0; i < acc.size(); i++)
	{
		fout << acc[i].login << " " << acc[i].password << " " << acc[i].access << endl;
	}

	fout.close();
}

void addAccountToVector(vector<Account>& acc,Account user) {

	acc.push_back(user);


}