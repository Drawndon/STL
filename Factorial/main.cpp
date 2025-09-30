//Factorial
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

size_t Factorial(int n);

void main()
{
	setlocale(LC_ALL, "");
	
	int n;
	cout << "Введите целое число, факториал которого необходимо вычислить: "; cin >> n;
	try
	{
	cout << n << "! = " << Factorial(n) << endl;
	}
	catch (const std::exception&e)
	{
		std::cerr << e.what() << endl << n << "! больше чем " << UINT_MAX << endl;
	}


}

size_t Factorial(int n)
{
	if (n > 12) throw std::exception("Арифметическое переполнение ");
	int res = 1;
	if (n == 0) res = 1;
	else
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}