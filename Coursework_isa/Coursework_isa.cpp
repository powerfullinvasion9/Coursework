#include "authorization.h"

using namespace std;

Account registrationUser() {

	Account user;
	string login;
	string password;
	int access;

	cout << "Введите логин" << endl;
	cin >> login;
	cout << "Введите пороль" << endl;
	cin >> password;

	user.login = login;
	user.password = password;
	user.access = 0;

	return user;
}



int main() {

	vector<Account> acc;
	vector<Account> regUser;

	ofstream fout;
	ifstream fin;


	setlocale(LC_ALL, "ru");

	createAdmin(fout);
	Account user = registrationUser();
	addAccountToVector(regUser, user); // файл должен записываться не в вектор а сразу в файл FIXME:



	writeVectorToFileAcc(acc,fout);
	readFileToVectorAcc(acc, fin);
	for (int i = 0; i < acc.size(); i++)
	{
		cout << acc[i].login << "\t" << acc[i].password << "\t" << acc[i].access << "\t" << endl;
	}
	writeVectorToFileReg(regUser, fout);
	readFileToVectorReg(regUser, fin);
	cout << endl;
	for (int i = 0; i < regUser.size(); i++)
	{
		cout << regUser[i].login << "\t" << regUser[i].password << "\t" << regUser[i].access << "\t" << endl;
	}

	return 0;
}