#include "AdminMode.h"
#include "UserMode.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string path = "C:\\Games\\text.txt";
	cout << "Здравтсвуйте, с какими правами вы хотите использовать программу?\n1.С правами администратора\n2.С правами пользователя\n";
	AdminMode a(path);
	UserMode u(path);
	switch (_getch())
	{
	case '1':
		system("cls");
		a.Main();
		break;
	case'2':
		system("cls");
		u.Main();
		break;
	default:
		break;

	}
	
	
}

