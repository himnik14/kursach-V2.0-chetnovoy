#include "AddData.h"
#include <fstream> 
#include"FileManager.h"
void AddData(vector<HairMasters> &Masters, ofstream& fout)
{
	string path = "C:\\Games\\text.txt";
	string n;
	do
	{
		cout << "Сколько записей вы хотите создать?\n";
		getline(cin, n);
	} while (n.empty());

	cout << "Какой разделитель вы хотите использовать для записи данных в файл?\n";
	string separator;
	fout.open(path, ios::app);
	getline(cin, separator);
	for (int i = 0; i < stoi(n); i++)
	{
		cout << "Создание " << i + 1 << " записи!\n";
		cout << "============================\n";
		try
		{
			Masters.push_back(HairMasters());
		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
			continue;
		}
		cout << "Запись успешно создана!\n";
		cout << "============================\n";

		fout << Masters[Masters.size() - 1].GetName() << separator
			<< Masters[Masters.size() - 1].GetType() <<
			separator << Masters[Masters.size() - 1].GetNumberClient() 
			<< separator << Masters[Masters.size() - 1].GetPrice() << separator 
			<< Masters[Masters.size() - 1].GetTheData() << separator << "\n";
	}

}

void EditPost(vector<HairMasters>& Masters, ofstream& fout)
{
	string n, line;
	bool T = true;
	do
	{
		cout << "Введите номер записи, которую хотите отредактировать\n";
		getline(cin, n);
		if (stoi(n) >= Masters.size() || stoi(n) <= 0) {
			cout << "Вы ввели номер записи, которой не существует!\n";
			break;
		}
		cout << "Что вы хотите изменить?\n1.ФИО\n2.Тип работы\n3.Номер клиента\n4.Цену\n5.Дату\n6.Назад\n";
		switch (_getch())
		{
		case '1':
			try
			{
				cout << "Введите ФИО, на которое хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetName(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '2':
			try
			{
				cout << "Введите тип работы, на который хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetType(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '3':
			try
			{
				cout << "Введите номер клиента, на который хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetNumberClient(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '4':
			try
			{
				cout << "Введите цену, на который хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetPrice(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '5':
			try
			{
				cout << "Введите дату, на которую хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetTheData(line);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
			break;
		case '6':
			break;
		default:
			cout << "Ввод некоректен!\n";
			break;
		}
		cout << "Чтобы закончить редактирование и сохранить данные введите 0\nЧтобы продолжить редактирование нажмите любую кнопку\n";
		if (_getch() == '0')
			T = false;
	} while (T);
	FileOverwrite(Masters, fout, "fs");
}

void DeletePost(vector<HairMasters> &Masters, ofstream& fout)
{
	string number;
	cout << "Какую запись вы хотите удалить?\n";
	getline(cin, number);
	bool T = true;
	do
	{
		if (stoi(number) <= 0 || stoi(number) > Masters.size())
		{
			cout << "Такой записи не существует!\n";
			break;

		}
		cout << "Вы действительно хотите удалить " << number << " запись?\nY - да N - нет\n";
		switch (_getch())
		{
		case 'y':
			Masters.erase(Masters.begin() + stoi(number) - 1);
			FileOverwrite(Masters, fout, "fds");
			cout << "Запись успешно удалена!\n";
			T = false;
			break;
		case 'n':
			cout << "Вы отказались удалять запись!\n";
			T = false;
			break;
		default:
			break;
		}
	} while (T);
	
	
	
}
