#include<iostream>
#include<map>
#include<list>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

void show_menu();
void print_base();
void print_data_by_number();
void print_data_by_range();
void save();
void load();


void main()
{
	std::map<int, std::string> violation =
	{
		{0, "Проезд на красный"},
		{1, "Обгон запрещен"},
		{2, "Разворот запрещен"},
		{3, "Превышение скорости"},
		{4, "Остановка запрещена"},
		{5, "Управление ТС в нетрезвом виде"},
		{6, "Учебная езда на магистрали"},
		{7, "Движение задним ходом на магистрали"},
		{8, "Поворот налево или разворот в нарушение требований"}
	};
	setlocale(LC_ALL, "");
	int key;
	do
	{
		show_menu();
	cout << "Введите пункт меню: "; cin >> key;
	switch (key)
	{
	case 1:
		print_base();
		break;
	case 2:
		print_data_by_number();
		break;
	case 3:
		print_data_by_range();
		break;
	case 4:
		save();
		break;
	case 5:
		load();
		break;
	case 0:
		cout << "Пока" << endl;
	}

	} while (key);
}

void show_menu()
{
	cout << "1. Вывести базу данных (по номерам машин и списку правонарушений, числящихся за ними);" << endl;
	cout << "2. Распечатка данных по заданному номеру;" << endl;
	cout << "3. Распечатка данных по диапазону номеров;" << endl;
	cout << "4. Сохранить информацию из файла." << endl;
	cout << "5. Загрузить информацию из файла." << endl;
	cout << "0. Выход" << endl;

}

void print_base()
{
	cout << "Print base" << endl;
}

void print_data_by_number()
{
	cout << "Print by number" << endl;
}

void print_data_by_range()
{
	cout << "Print by range" << endl;
}
void save()
{
	cout << "Saving data to file" << endl;
}

void load()
{
	cout << "Loading data from file" << endl;
}