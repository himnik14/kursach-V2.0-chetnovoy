#include "AdminMode.h"

bool Test(string value)
{
	regex reg("[0-9\\s]*");
	return !regex_match(value.c_str(), reg);
}

AdminMode::AdminMode(string path)
{
	this->path = path;
	this->Masters = ReadFile1(f, ";", path);
}

void AdminMode::ConsoleOutput(vector<HairMasters> Master)
{

	cout << "----------------------------------------------------------------------------------------------------\n";
	std::cout
		<< "\t\t" << setw(29) << left << "ФИО" << "|"
		 << setw(23) << left << "        ТИП РАБОТЫ" << " | "
		<<  setw(4) << left << "#" << "|"
		<< setw(5) << left << "   ЦЕНА" << "   |"
		<< "    ДАТА   |"
		<< std::endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < Master.size(); i++)
	{

		cout << setw(44) << left
			<< Master[i].GetName()
			<< " | " << setw(22) << left << Master[i].GetType()
			<< " | " << setw(3) << left << Master[i].GetNumberClient()
			<< " | " << setw(8) << left << Master[i].GetPrice() << " | "
			<< Master[i].GetTheData() << "|";
		cout << endl;
	}
	cout << "----------------------------------------------------------------------------------------------------\n";
}

void AdminMode::AddData()
{
	string n;
	do
	{
		cout << "Сколько записей вы хотите создать?\n";
		getline(cin, n);
		if (Test(n) || n.empty())
		{
			cout << "Писать можно только цифры\n";
		}
		else
			break;
		
	} while (true);
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
			cout << "Запись не была создана!\n";
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
		do
		{
			cout << "Введите номер записи, которую хотите отредактировать\n";
			getline(cin, n);
			if (Test(n) || n.empty())
			{
				cout << "Писать можно только цифры\n";
			}
			else
				break;
		} while (true);
		if (stoi(n) > Masters.size() || stoi(n) <= 0) {
			cout << "Вы ввели номер записи, которой не существует!\n";
			break;
		}
		cout << "Что вы хотите изменить?\n1.ФИО\n2.Тип работы\n3.Номер клиента\n4.Цену\n5.Дату\n6.Назад\n";
		try
		{
			switch (_getch())
			{
			case '1':
				cout << "Введите ФИО, на которое хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetName(line);
				break;
			case '2':
				cout << "Введите тип работы, на который хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetType(line);
				break;
			case '3':
				cout << "Введите номер клиента, на который хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetNumberClient(line);
				break;
			case '4':
				cout << "Введите цену, на который хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetPrice(line);
				break;
			case '5':
				cout << "Введите дату, на которую хотите изменить\n";
				getline(cin, line);
				Masters[stoi(n) - 1].SetTheData(line);
				break;
			case '6':
				T = false;
				break;
			default:
				cout << "Ввод некоректен!\n";
				break;
			}
			if (T) {
				cout << "Чтобы закончить редактирование и сохранить данные введите 0\nЧтобы продолжить редактирование нажмите любую кнопку\n";
				if (_getch() == '0')
					T = false;
			}
		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
		}
	} while (T);
	FileOverwrite(Masters, fout, path);
}

void AdminMode::DeletePost()
{
	string number;
	while (true)
	{
		cout << "Какую запись вы хотите удалить?\n";
		getline(cin, number);
		if (Test(number))
			cout << "Можно вводить только цифры!\n";
		else
			break;
	}
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
			system("cls");
			ConsoleOutput(Masters);
			break;
		case '2':
			system("cls");
			AddData();
			break;
		case '3':
			system("cls");
			EditPost();
			break;
		case '4':
			system("cls");
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