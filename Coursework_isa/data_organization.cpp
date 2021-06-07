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


			istringstream iss(line);

			iss >> name >> surename >> fathername 
				>> educationForm
				>> groupNum
				>> logicOfset >> politOfset >> englishOfset >> historyOfset >> phylosOfset
				>> math >> physics >> chemistry >> programming;
			
			temp.name = name; temp.surename = surename; temp.fathername = fathername;
			temp.logicOfset = logicOfset; temp.politOfset = politOfset; temp.englishOfset = englishOfset; temp.historyOfset = historyOfset; temp.phylosOfset = phylosOfset;
			temp.math = math; temp.physics = physics; temp.chemistry = chemistry; temp.programming = programming;
			temp.educationForm = educationForm; temp.groupNum = groupNum;

			vec.push_back(temp);
		}

	}
	else
	{
		cout << "Не удалось открыть файл!!!" << endl;
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
			<< vec[i].educationForm << "\t" << vec[i].groupNum << "\t"
			<< vec[i].logicOfset << "\t" << vec[i].politOfset << "\t" << vec[i].englishOfset << "\t" << vec[i].historyOfset << "\t" << vec[i].phylosOfset << "\t"
			<< vec[i].math << "\t" << vec[i].physics << "\t" << vec[i].chemistry << "\t" << vec[i].programming << endl;
	}
}

void addStudVector(vector<Student>& vec) {

	Student temp;

	cout << "Введите Имя студента: "; cin >> temp.name;
	cout << "Введите Фамилию стдудента: "; cin >> temp.surename;
	cout << "Введите Отчество студента: "; cin >> temp.fathername;

	cout << "Введите форму обучения(плат-1/будж-0):"; cin >> temp.educationForm;
	cout << "Введите номер группы: "; cin >> temp.groupNum;

	cout << "Введите оценку по Логике(зач - 1/незач - 0): "; cin >> temp.logicOfset;
	cout << "Введите оценку по Политологии(зач - 1/незач - 0): "; cin >> temp.politOfset;
	cout << "Введите оценку по Английскому(зач - 1/незач - 0): "; cin >> temp.englishOfset;
	cout << "Введите оценку по Истории(зач - 1/незач - 0): "; cin >> temp.historyOfset;
	cout << "Введите оценку по Философии(зач - 1/незач - 0): "; cin >> temp.phylosOfset;

	cout << "Введите оценку по Математике: "; cin >> temp.math;
	cout << "Введите оценку по Физике: "; cin >> temp.physics;
	cout << "Введите оценку по Химии: "; cin >> temp.chemistry;
	cout << "Введите оценку по Программированию: "; cin >> temp.programming;
	

	vec.push_back(temp);
}

// функции вывода таблицы студентов

void showStudTable(vector<Student>& vec) {

	cout << endl;
	showTableHeader();
	for (int i = 0; i < vec.size(); i++)
	{
		showStud(vec, i);
	}
}

void showTableHeader() {

	cout << setw(30) << left << "Ф.И.О" << "|"
		<< setw(12) << left << "Номер группы" << "|"
		<< setw(14) << left << "Форма обучения" << "|"
		<< setw(6) << left << "Логика" << "|"
		<< setw(11) << left << "Политология" << "|"
		<< setw(10) << left << "Английский" << "|"
		<< setw(7) << left << "История" << "|"
		<< setw(9) << left << "Философия" << "|"
		<< setw(10) << left << "Математика" << "|"
		<< setw(6) << left << "Физика" << "|"
		<< setw(5) << left << "Химия" << "|"
		<< setw(16) << left << "Программирование" << "|" << endl;
}

void showStud(vector<Student>& vec, int i) {

	string fullName = vec.at(i).name + " " + vec.at(i).surename + " " + vec.at(i).fathername;
	cout << setw(30) << left << fullName << "|"
		<< setw(12) << left << vec.at(i).groupNum << "|"
		<< setw(14) << vec.at(i).educationForm << "|"
		<< setw(6) << vec.at(i).logicOfset << "|"
		<< setw(11) << vec.at(i).politOfset << "|"
		<< setw(10) << vec.at(i).englishOfset << "|"
		<< setw(7) << vec.at(i).historyOfset << "|"
		<< setw(9) << vec.at(i).phylosOfset << "|"
		<< setw(10) << vec.at(i).math << "|"
		<< setw(6) << vec.at(i).physics << "|"
		<< setw(5) << vec.at(i).chemistry << "|"
		<< setw(16) << vec.at(i).programming << "|" << endl;

}

// -- конец )

void deleteStud(vector<Student>& vec) {
	
	string name, surename, fathername;
	cout << "Введите имя студента: "; cin >> name;
	cout << "Введите фамилию студента: "; cin >> surename;
	cout << "Введите отчество студента: "; cin >> fathername;

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
				cout << "Вы уверены что хотите удалить пользователя(Да - 1 / Нет - 0): "; cin >> ask;
				if (ask == 1)
				{
					vec.erase(vec.begin() + i);
					done = true;
				}
				else if (ask == 0)
				{
					cout << "Пользователь не удален: " << endl;
					done = true;
				}
				else
				{
					cout << "Вы ввели неверное число: " << endl;
				}
			}
			
		}
	}
}

void dataOrgMenu(vector<Student>& vec) {

	int option = -1;

	while (option != 0)
	{
		cout << "==================| Меню |==================" << endl;
		cout << "1 - Показаеть список студентов" << endl;
		cout << "2 - Добавить студента" << endl;
		cout << "3 - Удалить сдуента" << endl;
		cout << "4 - Редактировать студента" << endl;
		cout << "0 - Выход" << endl;

		cin >> option;
		
		switch (option)
		{
		case 1:
			showStudTable(vec);
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
		}
	}
}

// редактирование пользователя 

void studRedMenu() {
	cout << "Выберите поле редактирования: " << endl;
	cout << "1 - Имя" << endl;
	cout << "2 - Фамилия" << endl;
	cout << "3 - Отчество" << endl;
	cout << "4 - Номер группы" << endl;
	cout << "5 - Форма обучения" << endl;
	cout << "6 - Оценки по логике" << endl;
	cout << "7 - Оценки по политологии" << endl;
	cout << "8 - Оценки по английскому" << endl;
	cout << "9 - Оценки по истории" << endl;
	cout << "10 - Оценки по философия" << endl;
	cout << "11 - Оценки по математика" << endl;
	cout << "12 - Оценки по физике" << endl;
	cout << "13 - Оценки по химии" << endl;
	cout << "14 - Оценки по программированию" << endl;
	cout << "0 - Выход" << endl;
}

void studRed(vector<Student>& vec) {

	string name, surename, fathername;
	cout << "Введите имя студента: "; cin >> name;
	cout << "Введите фамилию студента: "; cin >> surename;
	cout << "Введите отчество студента: "; cin >> fathername;

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
					cout << "Введите новое имя студента" << endl;
					cin >> vec[i].name;
					break;
				case 2:
					system("cls");
					cout << "Введите новую фамилию студента" << endl;
					cin >> vec.at(i).surename;
					break;
				case 3:
					system("cls");
					cout << "Введите новое отчество студента" << endl;
					cin >> vec.at(i).fathername;
					break;
				case 4:
					system("cls");
					cout << "Введите новый номер группы" << endl;
					cin >> vec.at(i).groupNum;
					break;
				case 5:
					system("cls");
					cout << "Введите форму обучения(плат - 1 / будж - 0)" << endl;
					cin >> vec.at(i).educationForm;
					break;
				case 6:
					system("cls");
					cout << "Введите новую оценку по логике" << endl;
					cin >> vec.at(i).logicOfset;
					break;
				case 7:
					system("cls");
					cout << "Введите новую оценку по политологии" << endl;
					cin >> vec.at(i).politOfset;
					break;
				case 8:
					system("cls");
					cout << "Введите новую оценку по английскому" << endl;
					cin >> vec.at(i).englishOfset;
					break;
				case 9:
					system("cls");
					cout << "Введите новую оценку по истории" << endl;
					cin >> vec.at(i).historyOfset;
					break;
				case 10:
					system("cls");
					cout << "Введите новую оценку по философии" << endl;
					cin >> vec.at(i).phylosOfset;
					break;
				case 11:
					system("cls");
					cout << "Введите новую оценку по математике" << endl;
					cin >> vec.at(i).math;
					break;
				case 12:
					system("cls");
					cout << "Введите новую оценку по физике" << endl;
					cin >> vec.at(i).physics;
					break;
				case 13:
					system("cls");
					cout << "Введите новую оценку по химии" << endl;
					cin >> vec.at(i).chemistry;
					break;
				case 14:
					system("cls");
					cout << "Введите новую оценку по программированию" << endl;
					cin >> vec.at(i).programming;
					break;
				}
			}
		}
	}
	
}