#include "AdminMode.h"

AdminMode::AdminMode(string path)
{
	this->path = path;
	this->Masters = ReadFile1(f, ";", path);
}
void AdminMode::ConsoleOutput()
{
	std::cout
		<< "\t\t" << "ФИО"
		<< "\t\t    " << "ТИП РАБОТЫ"
		<< "\t    " << "#"
		<< "     ЦЕНА"
		<< "       ДАТА"
		<< std::endl;
	cout << "-----------------------------------------------------------------------------\n";
	for (int i = 0; i < Masters.size(); i++)
	{

		cout << setw(29) << left
			<< Masters[i].GetName()
			<< " | " << setw(16) << left << Masters[i].GetType()
			<< " | " << setw(3) << left << Masters[i].GetNumberClient()
			<< " | " << setw(8) << left << Masters[i].GetPrice() << " | "
			<< Masters[i].GetTheData();
		cout << endl;
	}
	cout << "-----------------------------------------------------------------------------\n";
}

void AdminMode::AddData()
{
	string n;
	do
	{
		cout << "Сколько записей вы хотите создать?\n";
		getline(cin, n);
	} while (n.empty());
	string separator = ";";
	fout.open(path, ios::app);
	for (int i = 0; i < abs(stoi(n)); i++)
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
	fout.close();
}


void AdminMode::EditPost()
{
	string n, line;
	bool T = true;
	do
	{
		cout << "Введите номер записи, которую хотите отредактировать\n";
		getline(cin, n);
		if (stoi(n) > Masters.size() || stoi(n) <= 0) {
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
	FileOverwrite(Masters, fout, path);
}

void AdminMode::DeletePost()
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
		case 'Y':
			Masters.erase(Masters.begin() + stoi(number) - 1);
			FileOverwrite(Masters, fout, path);
			cout << "Запись успешно удалена!\n";
			T = false;
			break;
		case 'N':
			cout << "Вы отказались удалять запись!\n";
			T = false;
			break;
		default:
			break;
		}
	} while (T);
}

void AdminMode::Main()
{
	bool T = true;
	cout << "Добро пожаловать в панель управления с правами администратора!\n\n";
	do
	{
		cout << "Выберите действие, которое хотите совершить\n1.Посмотреть все учетные записи\n2.Добавить учетную запись\n3.Отредактировать учетную запись\n4.Удалить учетную запись\n5.Завершить сеанс\n";
		switch (_getch())
		{
		case '1':
			ConsoleOutput();
			break;
		case '2':
			AddData();
			break;
		case '3':
			EditPost();
			break;
		case '4':
			DeletePost();
			break;
		case '5':
			T = false;
			break;
		default:
			break;
		}
	} while (T);
}