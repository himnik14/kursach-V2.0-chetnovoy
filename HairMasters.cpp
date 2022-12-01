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
	cout << "Введите дату совершения работы\n";
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
	if (name.empty())
		throw exception("Поле с ФИО не должно быть пустым!\n");
	this->name = name;
}

void HairMasters::SetType(string type)
{
	if (type.empty())
		throw exception("Поле с типом работы не должно быть пустым!\n");
	this->type = type;
}

void HairMasters::SetNumberClient(string numberClient)
{
	if (stoi(numberClient) <= 0 || stoi(numberClient) > 200)
		throw exception("Поле с номером клиента введено некоректно!\n");
	this->numberClient = (numberClient);
}

void HairMasters::SetPrice(string price)
{
	if (stoi(price) <= 400 || stoi(price) >= 100000)
		throw exception("Поле со стоимостью введено некорректно!\n");
	this->price = (price);
}

void HairMasters::SetTheData(string theData)
{
	if (theData.empty())
		throw exception("Поле с датой не должно быть пустым!\n");
	else if (theData.length() != 10)
		throw exception("Поле с датой должно иметь вид xx.xx.xxxx\n");
	this->theData = theData;
}