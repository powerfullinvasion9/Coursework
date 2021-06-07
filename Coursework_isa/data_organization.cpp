#include "data_organization.h"

using namespace std;

void readFileStud(vector<Student>& vec) {

	ifstream file(FILE_OF_STD);

	if (file.is_open())
	{
		string line;

		while (getline(file,line))
		{
			Student temp;
			string name, surename, fathername;
			int educationForm;
			int logicOfset, politOfset, englishOfset, historyOfset, phylosOfset;
			int math, physics, chemistry, programming;
			int groupNum;
			int active;
			double scolarship;

			istringstream iss(line);

			iss >> name >> surename >> fathername
				>> educationForm
				>> groupNum
				>> active
				>> scolarship
				>> logicOfset >> politOfset >> englishOfset >> historyOfset >> phylosOfset
				>> math >> physics >> chemistry >> programming;
			
			temp.name = name; temp.surename = surename; temp.fathername = fathername;
			temp.logicOfset = logicOfset; temp.politOfset = politOfset; temp.englishOfset = englishOfset; temp.historyOfset = historyOfset; temp.phylosOfset = phylosOfset;
			temp.math = math; temp.physics = physics; temp.chemistry = chemistry; temp.programming = programming;
			temp.educationForm = educationForm; temp.groupNum = groupNum; temp.active = active; temp.scolarchip = scolarship;

			vec.push_back(temp);
		}

	}
	else
	{
		cout << "�� ������� ������� ����!!!" << endl;
	}
	file.close();
	
	ofstream ofs;
	ofs.open(FILE_OF_STD, ofstream::out | ofstream::trunc);
	ofs.close();
}

void writeFileStud(vector<Student>& vec) {

	

	ofstream fout;
	fout.open(FILE_OF_STD, ofstream::app);

	for (int i = 0; i < vec.size(); i++)
	{
		fout << vec[i].name << "\t" << vec[i].surename << "\t" << vec[i].fathername << "\t" 
			<< vec[i].educationForm << "\t" << vec[i].groupNum << "\t" << vec[i].active << "\t" << vec[i].scolarchip << "\t"
			<< vec[i].logicOfset << "\t" << vec[i].politOfset << "\t" << vec[i].englishOfset << "\t" << vec[i].historyOfset << "\t" << vec[i].phylosOfset << "\t"
			<< vec[i].math << "\t" << vec[i].physics << "\t" << vec[i].chemistry << "\t" << vec[i].programming << endl;
	}
}

void addStudVector(vector<Student>& vec) {

	Student temp;

	cout << "������� ��� ��������: "; cin >> temp.name;
	cout << "������� ������� ���������: "; cin >> temp.surename;
	cout << "������� �������� ��������: "; cin >> temp.fathername;

	cout << "������� ����� ��������(����-1/����-0):"; cin >> temp.educationForm;
	cout << "������� ����� ������: "; cin >> temp.groupNum;
	cout << "������� �������� ����������(1 - ����� / 0 - �������): "; cin >> temp.active;

	cout << "������� ������ �� ������(��� - 1/����� - 0): "; cin >> temp.logicOfset;
	cout << "������� ������ �� �����������(��� - 1/����� - 0): "; cin >> temp.politOfset;
	cout << "������� ������ �� �����������(��� - 1/����� - 0): "; cin >> temp.englishOfset;
	cout << "������� ������ �� �������(��� - 1/����� - 0): "; cin >> temp.historyOfset;
	cout << "������� ������ �� ���������(��� - 1/����� - 0): "; cin >> temp.phylosOfset;

	cout << "������� ������ �� ����������: "; cin >> temp.math;
	cout << "������� ������ �� ������: "; cin >> temp.physics;
	cout << "������� ������ �� �����: "; cin >> temp.chemistry;
	cout << "������� ������ �� ����������������: "; cin >> temp.programming;

	temp.scolarchip = 0;

	vec.push_back(temp);
}

// ������� ������ ������� ���������

void showStudTable(vector<Student>& vec) {

	cout << endl;
	showTableHeader();
	for (int i = 0; i < vec.size(); i++)
	{
		showStud(vec, i);
	}
}

void showTableHeader() {

	cout << setw(30) << left << "�.�.�" << "|"
		<< setw(12) << left << "����� ������" << "|"
		<< setw(14) << left << "����� ��������" << "|"
		<< setw(19) << left << "�������� ����������" << "|"
		<< setw(12) << left << "���������" << "|"
		<< setw(9) << left << "������" << "|"
		<< setw(11) << left << "�����������" << "|"
		<< setw(10) << left << "����������" << "|"
		<< setw(7) << left << "�������" << "|"
		<< setw(9) << left << "���������" << "|"
		<< setw(10) << left << "����������" << "|"
		<< setw(6) << left << "������" << "|"
		<< setw(5) << left << "�����" << "|"
		<< setw(16) << left << "����������������" << "|" << endl;
}

void showStud(vector<Student>& vec, int i) {

	string fullName = vec.at(i).name + " " + vec.at(i).surename + " " + vec.at(i).fathername;
	cout << setw(30) << left << fullName << "|"
		<< setw(12) << left << vec.at(i).groupNum << "|";

		if (vec.at(i).educationForm == 1)
		{
			cout << setw(14) << "�������" << "|";
		}
		else
		{
			cout << setw(14) << "������" << "|";
		}
		
		if (vec.at(i).active == 1)
		{
			cout << setw(19) << "��������" << "|";
		}
		else
		{
			cout << setw(19) << "����������" << "|";
		}
	
	cout << setw(9) << setprecision(5) << vec.at(i).scolarchip << "���" << "|";
		if (vec.at(i).logicOfset == 1)
		{
			cout << setw(9) << "�����" << "|";
		}
		else
		{
			cout << setw(9) << "�������" << "|";
		}
		if (vec.at(i).politOfset == 1)
		{
			cout << setw(11) << "�����" << "|";
		}
		else
		{
			cout << setw(11) << "�������" << "|";
		}
		if (vec.at(i).englishOfset == 1)
		{
			cout << setw(10) << "�����" << "|";
		}
		else
		{
			cout << setw(10) << "�������" << "|";
		}
		if (vec.at(i).historyOfset == 1)
		{
			cout << setw(7) << "�����" << "|";
		}
		else
		{
			cout << setw(7) << "�������" << "|";
		}
		if (vec.at(i).phylosOfset == 1)
		{
			cout << setw(9) << "�����" << "|";
		}
		else
		{
			cout << setw(9) << "�������" << "|";
		}
		
	cout<< setw(10) << vec.at(i).math << "|"
		<< setw(6) << vec.at(i).physics << "|"
		<< setw(5) << vec.at(i).chemistry << "|"
		<< setw(16) << vec.at(i).programming << "|" << endl;

}

// -- ����� )

void deleteStud(vector<Student>& vec) {
	
	string name, surename, fathername;
	showStudTable(vec);
	cout << "������� ��� ��������: "; cin >> name;
	cout << "������� ������� ��������: "; cin >> surename;
	cout << "������� �������� ��������: "; cin >> fathername;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i).name == name && vec.at(i).surename == surename && vec.at(i).fathername == fathername)
		{
			int ask = -1;
			bool done = false;

			showTableHeader();
			showStud(vec,i);

			while (!done)
			{
				cout << "�� ������� ��� ������ ������� ������������(�� - 1 / ��� - 0): "; cin >> ask;
				if (ask == 1)
				{
					vec.erase(vec.begin() + i);
					done = true;
				}
				else if (ask == 0)
				{
					cout << "������������ �� ������: " << endl;
					done = true;
				}
				else
				{
					cout << "�� ����� �������� �����: " << endl;
				}
			}
			
		}
	}
}

void dataOrgMenu(vector<Student>& vec) {

	int option = -1;

	while (option != 0)
	{
		cout << "==================| ���� ������ � ������� |==================" << endl;
		cout << "1 - ��������� ������ ���������" << endl;
		cout << "2 - �������� ��������" << endl;
		cout << "3 - ������� �������" << endl;
		cout << "4 - ������������� ��������" << endl;
		cout << "5 - ����������� ���������" << endl;
		cout << "6 - ��������� �������������� �������" << endl;
		cout << "0 - �����" << endl;

		cin >> option;
		
		switch (option)
		{
		case 1:
			system("cls");
			showStudTable(vec);
			cout << endl;
			break;
		case 2:
			system("cls");
			addStudVector(vec);
			break;
		case 3:
			system("cls");
			deleteStud(vec);
			break;
		case 4:
			system("cls");
			studRed(vec);
			break;
		case 5:
			system("cls");
			sortMenu(vec);
			showStudTable(vec);
			break;
		case 6:
			system("cls");
			countScolarship(vec);
			showStudTable(vec);
			break;
		}
	}
}

// �������������� ������������ 

void studRedMenu() {
	cout << "�������� ���� ��������������: " << endl;
	cout << "1 - ���" << endl;
	cout << "2 - �������" << endl;
	cout << "3 - ��������" << endl;
	cout << "4 - ����� ������" << endl;
	cout << "5 - ����� ��������" << endl;
	cout << "6 - ������ �� ������" << endl;
	cout << "7 - ������ �� �����������" << endl;
	cout << "8 - ������ �� �����������" << endl;
	cout << "9 - ������ �� �������" << endl;
	cout << "10 - ������ �� ���������" << endl;
	cout << "11 - ������ �� ����������" << endl;
	cout << "12 - ������ �� ������" << endl;
	cout << "13 - ������ �� �����" << endl;
	cout << "14 - ������ �� ����������������" << endl;
	cout << "0 - �����" << endl;
}

void studRed(vector<Student>& vec) {

	string name, surename, fathername;
	cout << "������� ��� ��������: "; cin >> name;
	cout << "������� ������� ��������: "; cin >> surename;
	cout << "������� �������� ��������: "; cin >> fathername;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i).name == name && vec.at(i).surename == surename && vec.at(i).fathername == fathername)
		{	
			int option = -1;
			while (option != 0)
			{
				showTableHeader();
				showStud(vec, i);
				studRedMenu();
				cin >> option;
				switch (option)
				{
				case 1:
					system("cls");
					cout << "������� ����� ��� ��������" << endl;
					cin >> vec[i].name;
					break;
				case 2:
					system("cls");
					cout << "������� ����� ������� ��������" << endl;
					cin >> vec.at(i).surename;
					break;
				case 3:
					system("cls");
					cout << "������� ����� �������� ��������" << endl;
					cin >> vec.at(i).fathername;
					break;
				case 4:
					system("cls");
					cout << "������� ����� ����� ������" << endl;
					cin >> vec.at(i).groupNum;
					break;
				case 5:
					system("cls");
					cout << "������� ����� ��������(���� - 1 / ���� - 0)" << endl;
					cin >> vec.at(i).educationForm;
					break;
				case 6:
					system("cls");
					cout << "������� ����� ������ �� ������" << endl;
					cin >> vec.at(i).logicOfset;
					break;
				case 7:
					system("cls");
					cout << "������� ����� ������ �� �����������" << endl;
					cin >> vec.at(i).politOfset;
					break;
				case 8:
					system("cls");
					cout << "������� ����� ������ �� �����������" << endl;
					cin >> vec.at(i).englishOfset;
					break;
				case 9:
					system("cls");
					cout << "������� ����� ������ �� �������" << endl;
					cin >> vec.at(i).historyOfset;
					break;
				case 10:
					system("cls");
					cout << "������� ����� ������ �� ���������" << endl;
					cin >> vec.at(i).phylosOfset;
					break;
				case 11:
					system("cls");
					cout << "������� ����� ������ �� ����������" << endl;
					cin >> vec.at(i).math;
					break;
				case 12:
					system("cls");
					cout << "������� ����� ������ �� ������" << endl;
					cin >> vec.at(i).physics;
					break;
				case 13:
					system("cls");
					cout << "������� ����� ������ �� �����" << endl;
					cin >> vec.at(i).chemistry;
					break;
				case 14:
					system("cls");
					cout << "������� ����� ������ �� ����������������" << endl;
					cin >> vec.at(i).programming;
					break;
				}
			}
		}
	}
	
}

// -- ����� ������� ��������������
// -- ������� ����������

void sortStudByName(vector<Student>& vec) {

	sort(vec.begin(), vec.end(), sortNameComp);
}

bool sortNameComp(Student std_a, Student std_b) {

	return std_a.name < std_b.name;
}

void sortStudByGroup(vector<Student>& vec) {

	sort(vec.begin(), vec.end(), sortGroupComp);
}

bool sortGroupComp(Student std_a, Student std_b) {

	return std_a.groupNum > std_b.groupNum;
}

void sortStudByProg(vector<Student>& vec) {
	
	sort(vec.begin(), vec.end(), sortProgComp);
}
bool sortProgComp(Student std_a, Student std_b) {

	return std_a.programming > std_b.programming;
}

void sortMenu(vector<Student>& vec) {

	int itter = -1;

	while (itter != 0)
	{
		cout << "==================| ���� ���������� |====================" << endl;
		cout << "1 - ����������� �� �����" << endl;
		cout << "2 - ����������� �� ������ ������" << endl;
		cout << "3 - ����������� �� ������� �� ����������������" << endl;
		cout << "0 - �����" << endl;

		cin >> itter;
		switch (itter)
		{
		case 1:
			system("cls");
			sortStudByName(vec);
			showStudTable(vec);
			break;
		case 2:
			system("cls");
			sortStudByGroup(vec);
			showStudTable(vec);
			break;
		case 3:
			system("cls");
			sortStudByProg(vec);
			showStudTable(vec);
			break;
		}
	}
}

// --������� ��� ���������� ���������

bool exelStud(vector<Student>& vec, int i) {

	if (vec.at(i).math >= 9 && vec.at(i).physics >= 9 && vec.at(i).chemistry >= 9 && vec.at(i).programming >= 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int overageScore(vector<Student>& vec, int i) {

	return (vec.at(i).math + vec.at(i).physics + vec.at(i).chemistry + vec.at(i).programming) / 4;
}

void countScolarship(vector<Student>& vec) {

	double scolarship; 
	cout << "������� ������� �������� ��������� "; cin >> scolarship;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i).educationForm == 0)
		{
			if (exelStud(vec, i))
			{
				vec.at(i).scolarchip = scolarship + (scolarship * 0.5);
			}
			else if (overageScore(vec, i) > 5)
			{
				vec.at(i).scolarchip = scolarship + (scolarship * 0.25);
			}
			else
			{
				vec.at(i).scolarchip = scolarship;
			}
		}
	}
}