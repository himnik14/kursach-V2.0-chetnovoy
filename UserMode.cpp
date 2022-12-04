#include "UserMode.h"
void UserMode::Search()
{
	regex reg("[А-Яа-я\\s]*");
	string name;
	vector<HairMasters> Mast;
	cout << "---------------------Поиск-----------------------------------------------------------------------------------------\n\n";
	while (true)
	{
		cout << "ФИО искомого мастера ";
		getline(cin, name);
		if (!regex_match(name.c_str(), reg) || name.empty())
		{
			cout << "Поле с ФИО не должно быть пустым и не может содержать ничего кроме символов кириллицы!\n";

			continue;
		}
		else
			break;
	}
	for (int i = 0; i < Masters.size(); i++)
	{
		if (Masters[i].GetName().find(name) != -1)
			Mast.push_back(Masters[i]);
	}
	if (Mast.size() > 0)
	{
		system("cls");
		cout << "---------------------Поиск-----------------------------------------------------------------------------------------\n\n";
		cout << "ФИО искомого мастера " << "\t   " << name << "\n\n";;
		cout << "\t\tИнформация о найденных мастерах " << name << "\n\n";
		ConsoleOutput(Mast);
	}
	else
		cout << "Мастеров с таким ФИО не найдено!\n";
}

map<string, int> MakeMap(map<string, int>::iterator it, vector<HairMasters> Masters, string date, map<string, int> mp)
{
	for (int i = 0; i < Masters.size(); i++)
	{
		if (Masters[i].GetTheData() == date) {
			it = mp.find(Masters[i].GetName());
			if (it == mp.end() || mp.empty())
			{
				mp.insert(make_pair(Masters[i].GetName(), stoi(Masters[i].GetPrice())));
			}
			else
				it->second += stoi(Masters[i].GetPrice());
		}
	}
	if (mp.empty())
		throw exception("В этот день ни один мастер не работал!\n");
	else
		return mp;
}

map<string, int>::iterator SearchMaxMoney(map<string, int>::iterator it1, map<string, int>::iterator it3, map<string, int>& mp)
{
	int Max = INT_MIN;
	it1 = mp.begin();
	for (int i = 0; it1 != mp.end(); i++, it1++)
	{
		if (it1->second > Max)
		{
			it3 = it1;
			Max = it1->second;
		}
	}
	return it3;
}

void UserMode::BestJob()
{
	map<string, int> mp;
	map<string, int>::iterator it1, it3;
	vector<HairMasters> Mast;	
	string day, mounth, year;
	while (true)
	{
		cout << "Введите день, за который нужно высчитать лучшего сотрудника\n";
		getline(cin, day);
		if (Test(day) ||( stoi(day)<0 || stoi(day) >31))
		{
			cout << "В поле с числом даты дня разрешены только числа от 1 до 31\n";
			continue;
		}
		else if (day.size() == 1)
			day = "0" + day;
		cout << "Введите месяц, за который нужно высчитать лучшего сотрудника\n";
		getline(cin, mounth);
		if (Test(mounth) || (stoi(mounth) < 0 || stoi(mounth) > 12))
		{
			cout << "В поле с числом месяца разрешены только числа от 1 до 12\n";
			continue;
		}
		else if (mounth.size() == 1)
			mounth = "0" + mounth;
		cout << "Введите год, за который нужно высчитать лучшего сотрудника\n";
		getline(cin, year);
		if (Test(year) || (stoi(year) < 2000 || stoi(year) > 2022))
		{
			cout << "В поле с номером года разрешены только числа от 2000 до 2022\n";
			continue;
		}
		else
			break;
	}
	day = day + "." + mounth + "." + year;
	try
	{
		mp = MakeMap(it1, Masters, day, mp);
		it3 = SearchMaxMoney(it1, it3, mp);
		cout << "----------------------------------------------------------------------------------------------------\n";
		cout << "Лучший работник за " << day << ": " << it3->first << " с доходом " << it3->second << endl;
		cout << "----------------------------------------------------------------------------------------------------\n";
	}
	catch (const std::exception&ex)
	{
		cout << ex.what();
	}
}

vector<HairMasters> UserMode::SortAlf(vector<HairMasters> M)
{
	for (int i = 0; i < M.size()-1; i++)
	{
		for (int j = i+1; j < M.size(); j++)
		{
			if (strcmp(M[i].GetName().c_str(), M[j].GetName().c_str()) > 0)
				swap(M[i], M[j]);
		}
	}
	return M;
}

void UserMode::Main()
{
	bool T = true;
	cout << "Добро пожаловать в панель управления с правами пользоветеля!\n\n";
	do
	{
		cout << "Выберите действие, которое хотите совершить\n1.Посмотреть все учетные записи, с сортировкой по порядку\n2.Отсортировать по алфавиту!\n3.Найти лучшего работника\n4.Выполнить поиск данных\n5.Завершить сеанс\n";
		switch (_getch())
		{
		case '1':
			system("cls");
			ConsoleOutput(Masters);
			break;
		case '2':
			system("cls");
			ConsoleOutput(SortAlf(Masters));
			break;
		case '3':
			system("cls");
			BestJob();
			break;
		case '4':
			system("cls");
			Search();
			break;
		case '5':
			T = false;
			break;
		default:
			break;
		}
	} while (T);
}