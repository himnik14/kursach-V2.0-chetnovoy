#include "HairMasters.h"
#include "lineSeparator.h"
#include <windows.h>
#include <fstream>
#include "ConsoleOutput.h"
#include "FileManager.h"
#include "AddData.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<HairMasters> Masters;
	ifstream fout;
	ofstream f;
	Masters = ReadFile1(fout, ";");
	char re;
	bool T = true;
	cout << "Добро пожаловать в Админ Панель\n\n\n\n\n";
	do
	{
		cout << "Выберите действие, которое хотите соврешить\n1.Посмотреть все учетные записи\n2.Добавить учетную запись\n3.Отредактировать учетную запись\n4.Удалить учетную запись\n5.Завершить сеанс\n";
		re = _getch();
		switch (re)
		{
		case '1':
			ConsoleOutput(Masters);
			break;
		case '2':
			AddData(Masters, f);
			break;
		case '3':
			EditPost(Masters, f);
			break;
		case '4':
			DeletePost(Masters, f);
			break;
		case '5':
			T = false;
			break;
		default:
			break;
		}
	} while (T);
	

	
	
}

