#include "authorization.h"
#include "data_organization.h"

using namespace std;




int main() {

	setlocale(LC_ALL, "ru");
	createAdmin();

	vector<Student> stVec;
	vector<Account> acc;
	vector<Account> reg;

	readFileStud(stVec);	// чтение из файла --
	readFileAcc(acc);
	readFileReg(reg);

	mainMenu(acc, reg, stVec);

	writeFileStud(stVec);	// запись в файл -- 
	writeFileAcc(acc);
	writeFileReg(reg);
	

	return 0;
}