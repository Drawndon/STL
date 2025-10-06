//Associa
#include <iostream>
#include<string>
#include<map>
#include<set>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------------------------------------\n"

//#define STL_MAP
#define STL_SET

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_MAP
	std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Воскресенье"),
		std::pair<int, std::string>(1, "Понедельник"),
		std::pair<int, std::string>(2, "Вторник"),
		std::pair<int, std::string>(3, "Среда"),
		{4, "Четверг"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{5, "Пятница"},
		{6, "Суббота"},
		{7, "Воскресенье"},
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
	cout << delimiter << endl;
	for (std::pair<int, std::string> i : week)
	{
		cout << i.first << tab << i.second << endl;
	}
	cout << delimiter << endl;

	std::map<std::string, std::list<std::string>> dictionary =
	{
		{"occasionally", {"иногда", "время от времени", "случайно", "изредка"}},
		{"causes", {"причина", "приводить к..."}},
		{"space", {"космос", "пространство", "пробел"}},
		{"void", {"пустота", "вакуум"}},
		{"sequence", {"последовательность", "ряд", "эпизод", "череда"}},
		{"consequence", {"следствие", "последствие", "вывод"}},
	};
	//Первый вариант
	for (std::pair<std::string, std::list<std::string>> i : dictionary)
	{
		cout << "Слово в словаре: " << i.first << endl;
		cout << "Перевод: ";
		int count = 0;
		for (std::string elem : i.second) cout << elem << (++count < i.second.size() ? ", " : ";"); cout << delimiter;
	}
	//Второй вариант
	/*for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout.width(15);
		cout << it->first + ":";
		for (std::list<std::string>::iterator word = it->second.begin(); word != it->second.end(); ++word)
		{
			cout << *word;
			cout << (word != --it->second.end() ? ", " : ";");
		}
		
		cout << endl;
	}*/

#endif // STL_MAP

#ifdef STL_SET
	/*set – это контейнер, который хранит данные в виде бинарного дерева поиска.
	В отличие от map, каждым элементом set является одно значение, но часто говорят, что set совмещает ключ и значение.*/
	std::set<int> set = { 1024, 512, 2048, 128, 3072, 768 };
	for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_SET

}