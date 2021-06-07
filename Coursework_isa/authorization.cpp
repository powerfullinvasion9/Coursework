#include "authorization.h"

using namespace std;

int isEmpty() {

	ifstream fin(FILE_OF_ACC);
	
	if (!fin.is_open())
	{
		cout << "������ ���� �� ���������� !!!" << endl;
	}

	if (fin.peek() == EOF)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	fin.close();
}

void createAdmin() {
	
	ofstream fout(FILE_OF_ACC, ios::app);
	if (isEmpty())
	{
		fout << "admin\tpassword\t1" << endl;
	}
	fout.close();
}

void readFileAcc(vector<Account>& acc) {

	ifstream fin(FILE_OF_ACC);

	if (fin.is_open())
	{
		string line;

		while (getline(fin, line))
		{
			Account temp;
			string login, password;
			int access;

			istringstream iss(line);

			iss >> login >> password >> access;

			temp.login = login; temp.password = password; temp.access = access;

			acc.push_back(temp);

		}
	}
	else
	{
		cout << "��������� ������� ����" << endl;
	}

	fin.close();

	ofstream ofs;
	ofs.open(FILE_OF_ACC, ofstream::out | ofstream::trunc);
	ofs.close();
}

void readFileReg(vector<Account>& acc) {

	ifstream fin(FILE_OF_REG);

	if (fin.is_open())
	{
		string line;

		while (getline(fin, line))
		{
			Account temp;
			string login, password;
			int access;

			istringstream iss(line);

			iss >> login >> password >> access;

			temp.login = login; temp.password = password; temp.access = access;

			acc.push_back(temp);

		}
	}
	else
	{
		cout << "��������� ������� ����" << endl;
	}

	fin.close();

	ofstream ofs;
	ofs.open(FILE_OF_REG, ofstream::out | ofstream::trunc);
	ofs.close();
}

void writeFileAcc(vector<Account>& acc) {

	ofstream fout;
	fout.open(FILE_OF_ACC, ofstream::app);

	for (int i = 0; i < acc.size(); i++)
	{
		fout << acc.at(i).login << "\t" << acc.at(i).password << "\t" << acc.at(i).access << endl;
	}
}

void writeFileReg(vector<Account>& acc) {

	ofstream fout;
	fout.open(FILE_OF_REG, ofstream::app);

	for (int i = 0; i < acc.size(); i++)
	{
		fout << acc.at(i).login << "\t" << acc.at(i).password << "\t" << acc.at(i).access << endl;
	}
}

// -- �������� ��������� �������������

void showUserHeader() {

	cout << setw(3) << left << "No" << "|" << setw(10) << left << "�����" << "|" << setw(10) << left << "������" << "|" << setw(13) <<left << "����� �������" << endl;
}

void showUser(vector<Account>& acc, int i) {

	cout << setw(3) << i << "|" << setw(10) << left << acc.at(i).login << "|" << setw(10) << left << acc.at(i).password << "|";
	if (acc.at(i).access == 1)
	{
		cout << setw(13) << left << "�������������" << endl;
	}
	else
	{
		cout << setw(13) << left << "������������" << endl;
	}
}

void showUserTable(vector<Account>& acc) {

	showUserHeader();
	for (int i = 0; i < acc.size(); i++)
	{
		showUser(acc, i);
	}
}

// �����

void entrenceMenu(vector<Account>& acc, vector<Account>& reg, vector<Student>& vec) {

	string login, password;
	cout << "������� �����: "; cin >> login;
	cout << "������� ������: "; cin >> password;

	for (int i = 0; i < acc.size(); i++)
	{
		if (acc.at(i).login == login && acc.at(i).password == password)
		{
			if (acc.at(i).access == 1)
			{
				system("cls");
				adminMenu(acc, reg, vec);
			}
			else if (acc.at(i).access == 0)
			{
				dataOrgMenu(vec);
			}
		}
	}
}

void addUser(vector<Account>& acc, vector<Account>& reg) {

	if (reg.empty())
	{
		cout << "������ ���������" << endl;
	}
	else
	{
		cout << "������� ������ ������������ �������� ������ ��������" << endl;
		showUserTable(reg);
		int index; cin >> index;

		showUser(reg, index);
		cout << "������������ ��������" << endl;
		acc.push_back(reg.at(index));
		reg.erase(reg.begin() + index);
	}
	

}

void deleteUser(vector<Account>& acc) {

	cout << "������� ������ ������������ �������� ������ �������" << endl;
	showUserTable(acc);
	int index; cin >> index;

	if (acc.at(index).access == 1)
	{
		cout << "���������� ������� ��������������" << endl;
	}
	else
	{
		showUser(acc, index);
		acc.erase(acc.begin() + index);
		cout << "������������ ������" << endl;
	}

}

void redUser(vector<Account>& acc) {

	cout << "������� ������ ������������ �������� ������ ���������������" << endl;
	showUserTable(acc);
	int index; cin >> index;
	int itter = -1;
	while (itter != 0)
	{
		cout << "1 - �������� �����" << endl;
		cout << "2 - �������� ����� �������" << endl;
		cout << "0 - �����" << endl;
		cin >> itter;
		switch (itter)
		{
		case 1:
			cout << "������� ����� �����: " << endl;
			cin >> acc.at(index).login;
			break;
		case 2:
			cout << "�� ������� ��� ������ �������� ����� �������(1 - ����� / 0 - ������������): " << endl;
			int yorn; cin >> yorn;
			if (yorn == 1)
			{
				acc.at(index).access = 1;
			}
			else
			{
				acc.at(index).access = 0;
			}
		}
	}
}

void adminMenu(vector<Account>& acc, vector<Account>& reg, vector<Student>& vec) {

	int itter = -1;
	while (itter != 0)
	{
		cout << "1 - ����������� ������� ������" << endl;
		cout << "2 - �������� ����� ������� ������" << endl;
		cout << "3 - ������������� ������� ������" << endl;
		cout << "4 - ������� ������� ������" << endl;
		cout << "5 - ���� ������ � �������" << endl;
		cout << "0 - �����" << endl;
		cin >> itter;
		
		switch (itter)
		{
		case 1:
			system("cls");
			showUserTable(acc);
			break;
		case 2:
			system("cls");
			addUser(acc, reg);
			break;
		case 3:
			system("cls");
			redUser(acc);
			break;
		case 4:
			system("cls");
			deleteUser(acc);
			break;
		case 5:
			system("cls");
			dataOrgMenu(vec);
			break;
		}
	}

}

void registrationMenu(std::vector<Account>& reg) {

	Account temp;

	cout << "������� �����: "; cin >> temp.login;
	cout << "������� ������: "; cin >> temp.password;
	temp.access = 0;

	if (temp.login.size() > 10 || temp.password.size() > 10)
	{
		cout << "������ ������� �� �����, ������������ �� ����� ��������: " << endl;
	}
	else
	{
		reg.push_back(temp);
	}
	
}

void mainMenu(vector<Account>& acc, vector<Account>& reg, vector<Student>& vec){

	int itter = -1;

	while (itter != 0)
	{
		cout << "1 - ����" << endl;
		cout << "2 - �����������" << endl;
		cout << "0 - �����" << endl;
		cin >> itter;
		switch (itter)
		{
		case 1:
			entrenceMenu(acc, reg ,vec);
			break;
		case 2:
			registrationMenu(reg);
			system("cls");
			cout << "�������� ���������� �� �����������" << endl;
			break;
		}

	}
}

