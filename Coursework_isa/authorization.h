#pragma once
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

const std::string FILE_OF_ACC = "AccFile.txt";
const std::string FILE_OF_REG = "RegFile.txt";

struct Account
{
	std::string login;
	std::string password;
	int access;
};


void createAdmin(std::vector<Account>& acc);

void writeVectorToFile(std::vector<Account>& acc,std::ofstream &fout);

void addAccountToVector(std::vector<Account>& acc, Account user);