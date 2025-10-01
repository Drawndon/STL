//SequenceContainers
#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "\n-------------------------------------------------------------\n"

template<typename T>void vector_info(const std::vector<T>& vec);

//#define STL_ARRAY
#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива;
	throw;
	const int n = 5;
	std::array<int, n> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		arr.at(i) = rand() % 100;
	}
	try
	{
		for (int i = 0; i < arr.size() * 2; i++)
		{
			//cout << arr[i] << tab;
			cout << arr.at(i) << tab; //out_of_range exception, работает медленнее, но безопаснее
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	//catch (...) // Универсальный обработчик, лучше не использовать, так как непонятно что произошло
	//{
	//	std::cout << "Error: Something went wrong" << endl;
	//}
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;

	std::string str;
	
#endif // STL_ARRAY
#ifdef STL_VECTOR
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.push_back(55);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << tab;
	cout << endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		cout << *it << tab;
	cout << endl;
	vector_info(vec);
	//vec.shrink_to_fit(); //урезает capacity до фактического размера
	//vec.reserve(1600); //резервирует память на увеличение
	//vec.push_back(1024);
	//vec.resize(18); //меняет фактический размер
	for (int i : vec) cout << i << tab; cout << endl;
	vector_info(vec);
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	///////////////////////////////////////////////////////////////////////////////
	int index;
	int value;
	do
	{
		cout << "Введите индекс добавляемого элемента: "; cin >> index;
		cout << "Введите значение добавляемого элемента: "; cin >> value;
	} while (index>vec.capacity());
	vec.insert(vec.begin() + index, value);
	for (int i : vec) cout << i << tab; cout << endl;

#endif // STL_VECTOR


}

template<typename T>void vector_info(const std::vector<T>& vec)
{
	cout << "Size:\t " << vec.size() << endl;	//Фактический размер вектора, показывающий сколько элементов хранит Вектор
	cout << "MaxSize: " << vec.max_size() << endl; //Зависит от типа данных и архитектуры
	cout << "Capacity:" << vec.capacity() << endl;	//Объем зарезервированной памяти. При добавлении значений вектор резервирует
													//память
													//Зарезервированная память нужна чтобы ускорить процесс добавления элементов,
													//и избежать необходимости переопределять память при каждом добавлении элемента,
													//это экономит ресурсы процессорного времени, но расходует дополнитлеьные русурсы памяти.
													//Если у вектора есть свободная, зарезервированная память, то добавляемое значение просто
													//записывается в конец массива, но если зарезервированная память закончилась, то при 
													//добавлении элемента Вектор переопределяет (резервирует) новую память в половину
													//(в полтора раза) больше фактического размера.
	cout << delimiter << endl;
}