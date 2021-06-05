#include "authorization.h"

using namespace std;


void createAdmin(ofstream &fout) {
	
	fout.open(FILE_OF_ACC, ios::app);
	ifstream file;
	file.open(FILE_OF_ACC);

	if (isEmpty(file))
	{
		fout << "admin" << "\t" << "password" << "\t" << "1" << endl;
	}
	else
	{
		return;
	}	
}

void writeVectorToFileAcc(vector<Account>& acc,ofstream &fout) {

	fout.open(FILE_OF_ACC,std::ios::app);
	for (int i = 0; i < acc.size(); i++)
	{
		fout << acc[i].login << "\t" << acc[i].password << "\t" << acc[i].access << endl;
	}

	fout.close();
}

void writeVectorToFileReg(vector<Account>& acc, ofstream& fout) {

	fout.open(FILE_OF_REG, std::ios::app);
	for (int i = 0; i < acc.size(); i++)
	{
		fout << acc[i].login << "\t" << acc[i].password << "\t" << acc[i].access << endl;
	}

	fout.close();
}

void addAccountToVector(vector<Account>& acc,Account user) {

	acc.push_back(user);

}

void readFileToVectorAcc(vector<Account>& acc,ifstream &fin) {
	
	Account temp;
	fin.open(FILE_OF_ACC);

	if (fin.is_open())
	{
		string line;
		while (getline(fin,line))
		{
			string login, password;
			int access;

			istringstream iss(line);

			iss >> login >> password >> access;

			temp.login = login;
			temp.password = password;
			temp.access = access;

			acc.push_back(temp);
		}
	}
}

void readFileToVectorReg(vector<Account>& acc, ifstream& fin) {

	Account temp;
	fin.open(FILE_OF_REG);

	if (fin.is_open())
	{
		string line;
		while (getline(fin, line))
		{
			string login, password;
			int access;

			istringstream iss(line);

			iss >> login >> password >> access;

			temp.login = login;
			temp.password = password;
			temp.access = access;

			acc.push_back(temp);
		}
	}
}

bool isEmpty(ifstream& file) {

	return file.peek() == std::ifstream::traits_type::eof();
}