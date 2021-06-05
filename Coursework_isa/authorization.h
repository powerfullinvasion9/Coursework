#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

const std::string FILE_OF_ACC = "AccFile.txt";
const std::string FILE_OF_REG = "RegFile.txt";

struct Account
{
	std::string login;
	std::string password;
	int access;
};


void createAdmin(std::ofstream &fout);

void writeVectorToFileAcc(std::vector<Account>& acc,std::ofstream &fout);

void writeVectorToFileReg(std::vector<Account>& acc, std::ofstream& fout);

void addAccountToVector(std::vector<Account>& acc, Account user);

void readFileToVectorAcc(std::vector<Account>& acc,std::ifstream &fin);

void readFileToVectorReg(std::vector<Account>& acc, std::ifstream& fin);

bool isEmpty(std::ifstream& file);

