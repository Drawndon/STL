//SequenceContainers
#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<iterator>
#include<forward_list>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "\n-------------------------------------------------------------\n"

template<typename T>void vector_info(const std::vector<T>& vec);
template<typename T>void deque_info(const std::deque<T>& deque);

//#define STL_ARRAY
#define STL_VECTOR
#define STL_DEQUE
//#define STL_LIST
//#define STL_FORWARD_LIST


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
	//cout << vec.front() << endl;
	//cout << vec.back() << endl;
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
	vector_info(vec);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	vec.erase(vec.begin() + index);
	for (int i : vec) cout << i << tab; cout << endl;
	vector_info(vec);

	vec.erase(vec.begin(), vec.begin() + index);
	for (int i : vec) cout << i << tab; cout << endl;
	vector_info(vec);
#endif // STL_VECTOR

#ifdef STL_DEQUE
	//deque - это контейнер, который хранит данные в виде списка Векторов.
	//Это позволяет обеспечить относительно быстрый доступ к элементам,
	//и относительно быстрое добавление/удаление элементов
	//deque - Double-ended queue (двунаправленная очередь).
	//deque по своим возможностям очень напоминает vector, и дополняет его методами push_front() и pop_front()
	std::deque<int> deque = { 3, 5, 8, 13, 21 };
	deque.push_back(34);
	deque.push_front(2);
	
	/*std::vector<int> vec;
	cout << typeid(vec.data()).name() << endl;*/

	deque_info(deque);
	deque.assign(vec.begin(), vec.end());
	for (int i : deque) cout << i << tab; cout << endl;
#endif // STL_DEQUE


#ifdef STL_LIST
	int n = 7;
	std::list<int> my_list; //list - это контейнер, который хранит данные в виде двусвязного списка
	std::list<int>::iterator it;
	
	for (int i = 0; i < n; i++)
		my_list.push_back(rand() % 100);
	//for(std::list<int>::iterator it = list.begin(); it != list.end(); ++it) cout << *it << tab; cout << endl; вывод вперед
	//for(std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it) cout << *it << tab; cout << endl; вывод наоборот
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;
	it = my_list.begin();
	my_list.insert(it, 15);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;
	++it;
	my_list.insert(it, 29);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;
	int value, index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	//my_list.insert(my_list.begin() + index, value); списки не поддерживают арифметику указателей
	//for (int i = 0; i < index; i++) it++; можно так сместить итератор, а можно как ниже
	it = my_list.begin();
	std::list<int>::reverse_iterator rit = my_list.rbegin();
	std::advance(rit, my_list.size() - index);
	it = rit.base();
	my_list.insert(it, value);
	//std::advance(it, index); //перемещает итератор на значение index
	//my_list.insert(it, value);
	for (int i : my_list) cout << i << tab; cout << endl;

	std::list<int>::iterator it1, it2;
	it1 = it2 = my_list.begin();
	advance(it2, 6);
	++it1;

	it1 = my_list.erase(it1);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;

	it2 = my_list.erase(it2);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;
	++it1;
	--it2;
	my_list.erase(it1, it2);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;

#endif // STL_LIST

#ifdef STL_FORWARD_LIST
	int n = 7;
	std::forward_list<int> my_list(n, 77); // можно std::forward_list<int> my_list = {3, 5, 8, 13, 21, 34};
	my_list.push_front(2);
	my_list.push_front(1);
	my_list.push_front(1);
	my_list.push_front(0);
;
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;

	std::forward_list<int>::iterator it;
	it = my_list.insert_after(my_list.before_begin(), 10);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;
	it = my_list.insert_after(it, 2, 20);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;

	it = my_list.begin();
	it = my_list.insert_after(it, { 1, 2, 3 });
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;

	it = my_list.erase_after(it);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;
	
	it = my_list.begin();
	++it;
	it = my_list.erase_after(it);
	for (int elem : my_list) cout << elem << tab; cout << endl;
	cout << delimiter;

#endif // STL_FORWARD_LIST

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
template<typename T>void deque_info(const std::deque<T>& deque)
{
	cout << "Size:\t " << deque.size() << endl;
	cout << "MaxSize: " << deque.max_size() << endl;
	cout << delimiter << endl;
}