#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iomanip>

const std::string FILE_OF_STD = "StudFile.txt";

struct Student
{
	// ФИО
	std::string name;
	std::string surename;
	std::string fathername;

	// форма обучения

	int educationForm;
	int groupNum;
	
	// недефференциальные предметы

	int logicOfset;
	int politOfset;
	int englishOfset;
	int historyOfset;
	int phylosOfset;

	// дефференциальные предметы

	int math;
	int physics;
	int chemistry;
	int programming;

};

void readFileStud(std::vector<Student>& vec);
void writeFileStud(std::vector<Student>& vec);
void addStudVector(std::vector<Student>& vec);
void showStudTable(std::vector<Student>& vec);
void deleteStud(std::vector<Student>& vec);
void dataOrgMenu(std::vector<Student>& vec);
void showStud(std::vector<Student>& vec, int i);
void showTableHeader();

// функции редактирования пользователя

void studRedMenu();
void studRed(std::vector<Student>& vec);