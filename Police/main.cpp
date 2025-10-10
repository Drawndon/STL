#include<iostream>
#include<map>
#include<list>
#include<fstream>
#include<string>
#include<sstream>
#include<time.h>
//#include<locale>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------------------------------------------\n"
#define tab "\t"

	const std::map<int, std::string> VIOLATIONS =
	{
		{0, "N/A"},
		{1, "Парковка в неположенном месте"},
		{2, "Непристегнутый ремень безопасности"},
		{3, "Пересечение сплошной"},
		{4, "Превышение скорости"},
		{5, "Проезд на красный"},
		{6, "Выезд на встречную полосу"},
		{7, "Езда в нетрезвом состоянии"},
		{8, "Оскорбление офицера"}
	};

#define TAKE_TIME int min, int hour, int day, int month, int year
#define GIVE_TIME min, hour, day, month, year
	class Crime;
	std::stringstream& operator>>(std::stringstream& stream, Crime& obj);
	class Crime
	{
		int violation;
		std::string place;
		tm time;
	public:
		int get_violation()const
		{
			return violation;
		}
		const std::string& get_place()const
		{
			return place;
		}
		std::string get_time()const
		{
			char stringtime[256]{};
			strcpy(stringtime, asctime(&time));
			stringtime[strlen(stringtime) - 1] = 0;
			return stringtime;
		}
		void set_violation(int violation)
		{
			this->violation = violation;
		}
		void set_place(const std::string& place)
		{
			this->place = place;
		}
		void set_time(const std::string& time)
		{
			char timestring[256] = {};
			strcpy(timestring, time.c_str());
			//YYYY.MM.DD HH:MM
			int parts[5] = {};
			int n = 0;
			const char delimiters[] = "./- :";
			for (char* pch = strtok(timestring, delimiters); pch; pch = strtok(NULL, delimiters))
				//atoi - ASCII to INT, преобразует входную строку в целое число
				parts[n++] = std::atoi(pch);
			this->time = {};//cоздаем структуру с нулевыми значениями, иначе другие поля структуры содержат мусор
			this->time.tm_year = parts[0] - 1900;
			this->time.tm_mon = parts[1] - 1; //месяцы с нуля
			this->time.tm_mday = parts[2];
			this->time.tm_hour = parts[3];
			this->time.tm_min = parts[4];
		}

		Crime(int violation, const std::string& place, const std::string& time)
		{
			set_violation(violation);
			set_place(place);
			set_time(time);
		}
		explicit Crime(const std::string& str)
		{
			std::stringstream stream(str);
			stream >> *this;
		}

	};
	std::ostream& operator<<(std::ostream& os, const Crime& obj)
	{
		os.width(44);
		os << std::left;
		return os << obj.get_time() << VIOLATIONS.at(obj.get_violation()) << tab << obj.get_place(); //Берем at(), а не [], так как константный экземпляр map
	}

	std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
	{
		ofs << obj.get_violation() << " " << obj.get_place() << " " << obj.get_time(); //Сразу в ретёрн ошибка
		return ofs;
	}

	std::stringstream& operator>>(std::stringstream& stream, Crime& obj)
	{
		int violation;
		stream >> violation;
		std::string place;
		std::getline(stream, place);
		obj.set_violation(violation);
		obj.set_place(place);
		return stream;
	}

	void print(const std::map<std::string, std::list<Crime>>& base);
	void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
	std::map<std::string, std::list<Crime>> load(const std::string& filename);

//#define INIT_BASE
//#define INIT_BASE_2
#define LOAD_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INIT_BASE
	std::map<std::string, std::list<Crime>> base =
	{
		{"a777aa", {Crime(4, "ул. Ленина"), Crime(5, "ул. Ленина"), Crime(7, "ул. Энтузиастов"), Crime(8, "ул. Энтузиастов")} },
		{"a123bb", {Crime(2, "ул. Пролетарская"), Crime(3, "ул. Ватутина")}},
		{"a001eg", {Crime(5, "ул. Октябрьская"), Crime(5, "ул. Октябрьская"), Crime(7, "ул. Космическая"), Crime(8, "ул. Энтузиастов")} },
	};
	print(base);
	//save(base, "base.txt");
#endif // INIT_BASE

#ifdef INIT_BASE_2
	std::map<std::string, std::list<Crime>> base =
	{
		{"a777aa", {Crime(4, "ул. Ленина", "2024.04.04 16:04"), Crime(5, "ул. Ленина", "2024.04.04 16:14"), Crime(7, "ул. Энтузиастов", "2024.04.04 16:24"), Crime(8, "ул. Энтузиастов", "2024.04.04 16:34")}},
		{"a123bb", {Crime(2, "ул. Пролетарская", "2025.01.05 11:12"), Crime(3, "ул. Ватутина", "2025/01/06 15:25")}},
		{"a001eg", {Crime(5, "ул. Октябрьская", "2024.07.08 19:08"), Crime(5, "ул. Октябрьская", "2024.07.08 19:28"), Crime(7, "ул. Космическая", "2024.07.08 19:38"), Crime(8, "ул. Энтузиастов", "2024.07.08 19:48")} },
	};
	print(base);
	save(base, "base.txt");
#endif // INIT_BASE

#ifdef LOAD_CHECK
	std::map<std::string, std::list<Crime>> base = load("base.txt");
	print(base);
#endif // LOAD_CHECK

}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate) //const_iterator, т.к. функция принимает const экземпляр
	{
		cout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			cout << "\t" << *violation << endl;
		}
		cout << delimiter;
	}
}

void save(const std::map<std::string, std::list<Crime>>& base, const std::string&filename)
{
	std::ofstream fout(filename);
	std::locale mylocale("");
	fout.imbue(mylocale);
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate) //const_iterator, т.к. функция принимает const экземпляр
	{
		fout << plate->first << ":";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			fout << *violation << ",";
		}
		fout << endl;
	}
	fout.close();
	std::string cmd = "start notepad ";
	cmd += filename;
	system(cmd.c_str());
}

std::map<std::string, std::list<Crime>> load(const std::string& filename)
{
	std::map<std::string, std::list<Crime>> base;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			std::getline(fin, licence_plate, ':');
			cout << licence_plate << "\t";
			const int SIZE = 1024 * 500;
			char all_crimes[SIZE];
			fin.getline(all_crimes, SIZE);
			cout << all_crimes << endl;
			const char delimiters[] = ",";
			for (char* pch = strtok(all_crimes, delimiters); pch; pch = strtok(NULL, delimiters))
				base[licence_plate].push_back(Crime(pch)); //Написали конструктор принимающий строку
			{
				//Crime crime(0, "");
				//std::stringstream stream(pch);
				///*stringstream – это объект, который хранит строку, но позволяет работать с ней как с потоком,
				//а именно из строки прочитать различные ее элементы используя операторы перенаправления в поток
				//и потоковую функцию getline()*/
				////stream >> crime;
				//base[licence_plate].push_back(crime);
			}
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fin.close();
	return base;
}
