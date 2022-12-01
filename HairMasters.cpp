#include "HairMasters.h"
#include <string>

HairMasters::HairMasters(string name, string type, string numberClient, string price, string theData)
{
	if (name.empty() || type.empty() || numberClient.empty() || price.empty() || theData.empty())
		throw exception("Нельзя вводить пустые поля!");
	this->name = name;
	this->numberClient = numberClient;
	this->type = type;
	this->theData = theData;
	this->price = price;
}

HairMasters::HairMasters()
{
	string name1;
	cout << "Введите ФИО мастера\n";
	getline(cin, name1);
	try
	{
		SetName(name1);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("Некоторые поля введены некоректно!\n");
	}
	cout << "Введите тип работ\n";
	getline(cin, name1);
	try
	{
		SetType(name1);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("Некоторые поля введены некоректно!\n");
	}
	cout << "Введите дату совершения работы в формате xx.xx.xxxx\n";
	getline(cin, name1);
	try
	{
		SetTheData(name1);

	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("Некоторые поля введены некоректно!\n");
	}
	cout << "Введите номер клиента\n";
	getline(cin, name1);
	try
	{
		SetNumberClient(name1);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("Некоторые поля введены некоректно!\n");
	}
	cout << "Введите стоимость работы, сделанной мастером\n";
	getline(cin, name1);
	try
	{
		SetPrice(name1);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		throw exception("Некоторые поля введены некоректно!\n");
	}
}

string HairMasters::GetName()
{
	return name;
}

string HairMasters::GetNumberClient()
{
	return numberClient;
}

string HairMasters::GetPrice()
{
	return price;
}

string HairMasters::GetTheData()
{
	return theData;
}

string HairMasters::GetType()
{
	return type;
}

void HairMasters::SetName(string name)
{
	regex r("[А-Яа-я\\s]*");
	if (name.empty())
		throw exception("Поле с ФИО не должно быть пустым!\n");
	else if (!regex_match(name.c_str(), r))
		throw exception("В поле ФИО допустимы только кириллические символы!\n");
	this->name = name;
}

void HairMasters::SetType(string type)
{
	regex r("[А-Яа-я\\s\\d]*");
	if (type.empty())
		throw exception("Поле с типом работы не должно быть пустым!\n");
	else if (!regex_match(type.c_str(), r))
		throw exception("В поле тип работы допустимы только кириллические символы и цифры!\n");
	this->type = type;
}

void HairMasters::SetNumberClient(string numberClient)
{
	regex r("[0-9\\s]*");
	if (!regex_match(numberClient.c_str(), r))
	throw exception("В поле номера клиента допустимы только цифры!\n");
	else if (stoi(numberClient) <= 0 || stoi(numberClient) > 200)
		throw exception("Поле с номером клиента введено некоректно!\n");
	this->numberClient = (numberClient);
}

void HairMasters::SetPrice(string price)
{
	regex r("[0-9\Q.,\E]*");
	if (!regex_match(price.c_str(), r))
		throw exception("В поле цены допустимы только цифры!\n");
	else if (stof(price) <= 400 || stof(price) >= 100000)
		throw exception("Поле со стоимостью введено некорректно!\n");
	this->price = (price);
}

void HairMasters::SetTheData(string theData)
{
	regex r("[0-9\Q.\E]*");
	if (!regex_match(theData.c_str(), r))
		throw exception("В поле даты допустимы только цифры!\n");
	else if (theData.empty())
		throw exception("Поле с датой не должно быть пустым!\n");
	else if (theData.length() != 10)
		throw exception("Поле с датой должно иметь вид xx.xx.xxxx\n");
	else if (stoi(theData.substr(0, 2)) > 31 || stoi(theData.substr(0, 2)) <= 0)
		throw exception("В месяце максимум 31 день!\n");
	else if (stoi(theData.substr(3, 5)) > 12 || stoi(theData.substr(3, 5)) <= 0)
		throw exception("В году 12 месяцев!\n");
	else if (stoi(theData.substr(6, 9)) > 2022 || stoi(theData.substr(6, 9)) <= 2000)
		throw exception("Наш салон красоты ведёт учёт работ с 2000-го года!\n");
	this->theData = theData;
}