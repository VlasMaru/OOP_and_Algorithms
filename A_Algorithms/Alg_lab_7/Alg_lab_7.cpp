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
	std::vector <int> fib{ 0, 1, 2, 3, 5, 8, 13, 21, 34, 55};
	int tempy(0);
	std::cout << "Enter your massive elements: " << std::endl;
	for (int x = 0; x < mas_size; x++)
	{
		std::cin >> tempy;
		mas.push_back(tempy);
	}
	PrintVec(mas);
	std::cout << std::endl;
	int b{ 1 };
	while (fib[b]+2 <= mas_size)
	{
		b++;
	}
	int start_step = fib[b - 1];
	////
	int n = 2;
	while (b-n>=0)
	{
			for (int i = 0; (i + start_step) < mas_size; i++)
			{
				if (mas[i] > mas[i + start_step])
				{
					std::swap(mas[i], mas[i + start_step]);
					PrintVec(mas);
					int g = i;

					while (g > 0)
					{
						if (mas[g] < mas[g-1])
						{
							std::swap(mas[g], mas[g-1]); PrintVec(mas);
							g--;
						}
						else{ g--;}
						
					}

					
				}
			}
		start_step = fib[b - n];
		n++;
	}
		

	////


	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);
}
