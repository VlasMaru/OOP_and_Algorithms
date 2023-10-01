//  Метод сортировки Шелла
// Будем пользоваться эмпирической последовательностью Марцина Циура (на числах Фибоначчи)


#include <iostream>
#include <vector>


void PrintVec(std::vector <int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "  ";
	}
	std::cout << std::endl;
}

int main()
{
	int mas_size = 0;
	std::cout << "Enter your massive size: " << std::endl;
	std::cin >> mas_size;
	std::vector <int> mas{};
	std::vector <int> fib{ 1, 4, 10, 23, 57, 123, 301, 701, 1750};
	int tempy(0);
	std::cout << "Enter your massive elements: " << std::endl;
	for (int x = 0; x < mas_size; x++)
	{
		std::cin >> tempy;
		mas.push_back(tempy);
	}
	PrintVec(mas);
	std::cout << std::endl;
	int b{ 0 };
	while (fib[b] <= mas_size)
	{
		b++;
	}
	int start_step = fib[b-1];
	////
	int n = 1;
	for (int x = 0; x < mas_size; x++)
	{
		if (n <= b)
		{
			for (int i = 0; (i + b-1) < mas_size; i++)
			{
				if (mas[i] > mas[i + start_step]) { std::swap(mas[i], mas[i + start_step]); PrintVec(mas); }
			}
			start_step = fib[b - n];
			n++;
		}


	}


	////


	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);
}