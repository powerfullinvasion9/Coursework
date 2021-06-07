#include "authorization.h"
#include "data_organization.h"

using namespace std;




int main() {

	setlocale(LC_ALL, "ru");

	vector<Student> stVec;

	readFileStud(stVec);	// чтение из файла --

	dataOrgMenu(stVec);

	writeFileStud(stVec);	// запись в файл -- 

	

	return 0;
}