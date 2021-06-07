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
#include "data_organization.h"

const std::string FILE_OF_ACC = "AccFile.txt";
const std::string FILE_OF_REG = "RegFile.txt";

struct Account
{
	std::string login;
	std::string password;
	int access;
};

// -- чтение и запись пользователей 

int isEmpty();
void createAdmin();
void readFileAcc(std::vector<Account>& acc);
void readFileReg(std::vector<Account>& acc);
void writeFileAcc(std::vector<Account>& acc);
void writeFileReg(std::vector<Account>& acc);

// -- меню входа и регистрации

void mainMenu(std::vector<Account>& acc, std::vector<Account>& reg, std::vector<Student>& vec);
void entrenceMenu(std::vector<Account>& acc, std::vector<Account>& reg, std::vector<Student>& vec);
void adminMenu(std::vector<Account>& acc, std::vector<Account>& reg, std::vector<Student>& vec);
void addUser(std::vector<Account>& acc, std::vector<Account>& reg);
void deleteUser(std::vector<Account>& acc);
void redUser(std::vector<Account>& acc);
void registrationMenu(std::vector<Account>& reg);

// -- таблица пользователей

void showUserHeader();
void showUser(std::vector<Account>& acc, int i);
void showUserTable(std::vector<Account>& acc);