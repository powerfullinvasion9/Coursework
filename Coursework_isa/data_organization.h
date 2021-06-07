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
	// ���
	std::string name;
	std::string surename;
	std::string fathername;

	// ����� ��������

	int educationForm;
	int groupNum;
	
	// ������������������ ��������

	int logicOfset;
	int politOfset;
	int englishOfset;
	int historyOfset;
	int phylosOfset;

	// ���������������� ��������

	int math;
	int physics;
	int chemistry;
	int programming;

	// ���������� ��������

	int active;

	// ���������

	double scolarchip;
};

void readFileStud(std::vector<Student>& vec);
void writeFileStud(std::vector<Student>& vec);
void addStudVector(std::vector<Student>& vec);
void showStudTable(std::vector<Student>& vec);
void deleteStud(std::vector<Student>& vec);
void dataOrgMenu(std::vector<Student>& vec);
void showStud(std::vector<Student>& vec, int i);
void showTableHeader();
void countScolarship(std::vector<Student>& vec);
int overageScore(std::vector<Student>& vec, int i);
bool exelStud(std::vector<Student>& vec, int i);

// ������� �������������� ������������

void studRedMenu();
void studRed(std::vector<Student>& vec);

void sortStudByName(std::vector<Student>& vec);
bool sortNameComp(Student std_a, Student std_b);
void sortStudByGroup(std::vector<Student>& vec);
bool sortGroupComp(Student std_a, Student std_b);
void sortStudByProg(std::vector<Student>& vec);
bool sortProgComp(Student std_a, Student std_b);
void sortMenu(std::vector<Student>& vec);

