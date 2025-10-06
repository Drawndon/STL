#include<iostream>
#include<map>
#include<list>
#include<fstream>
#include<string>
#include<locale>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------------------------------------------\n"


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
	class Crime
	{
		int violation;
		std::string place;
	public:
		int get_violation()const
		{
			return violation;
		}
		const std::string& get_place()const
		{
			return place;
		}
		void set_violation(int violation)
		{
			this->violation = violation;
		}
		void set_place(const std::string& place)
		{
			this->place = place;
		}
		Crime(int violation, const std::string& place)
		{
			set_violation(violation);
			set_place(place);
		}

	};
	std::ostream& operator<<(std::ostream& os, const Crime& obj)
	{
		os.width(44);
		os << std::left;
		return os << VIOLATIONS.at(obj.get_violation()) << obj.get_place(); //Берем at(), а не [], так как константный экземпляр map
	}

	void print(const std::map<std::string, std::list<Crime>>& base);
	void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);

void main()
{
	setlocale(LC_ALL, "");
	std::map<std::string, std::list<Crime>> base =
	{
		{"a777aa", {Crime(4, "ул. Ленина"), Crime(5, "ул. Ленина"), Crime(7, "ул. Энтузиастов"), Crime(8, "ул. Энтузиастов")} },
		{"a123bb", {Crime(2, "ул. Пролетарская"), Crime(3, "ул. Ватутина")} },
		{"a001eg", {Crime(5, "ул. Октябрьская"), Crime(5, "ул. Октябрьская"), Crime(7, "ул. Космическая"), Crime(8, "ул. Энтузиастов")} },
	};
	print(base);
	save(base, "base.txt");

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
	std::wofstream fout(filename);
	//std::locale utf8_locale(std::locale(), new utf8cvt<false>);
	//fout.imbue(utf8_locale);
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate) //const_iterator, т.к. функция принимает const экземпляр
	{
		fout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			fout << "\t" << *violation << endl;
		}
		fout << delimiter;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());
}
