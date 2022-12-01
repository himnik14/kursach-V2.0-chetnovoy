#include "HairMasters.h"
#include "lineSeparator.h"
#include <windows.h>
#include <fstream>
#include "ConsoleOutput.h"
#include "FileManager.h"
#include "AddData.h"
#include "AdminMode.h"
int main()
{ //pizda
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string path = "C:\\Games\\text.txt";
	bool T = true;
	cout << "Здравтсвуйте, с какими правами вы хотите использовать программу?\n1.С правами администратора\n2.С правами пользователя\n";
	AdminMode a(path);
	do
	{
		switch (_getch())
		{
		case '1':
			system("cls");
			a.Main();
		default:
			break;
		}

	} while (T);
	
	
}

