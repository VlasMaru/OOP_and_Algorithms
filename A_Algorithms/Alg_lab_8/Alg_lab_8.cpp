// Метод сортировки: поразрядная
//

#include <iostream>
#include <vector>
#include <string>


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
	int tempy(0);
	std::cout << "Enter your massive elements: " << std::endl;
	int max{ 0 };
	for (int x = 0; x < mas_size; x++)
	{
		std::cin >> tempy;
		if (tempy > max) { max = tempy;}
		mas.push_back(tempy);
	}
	PrintVec(mas);
	std::cout << std::endl;

	////
	std::string max_string = std::to_string(max);
	int max_range = max_string.length();

	//std::vector <int> mas_raz{};
	int n = max_range;


	while (n <= 0)
	{
		for (int x = 0; x < mas_size-1; x++)
		{
			if ((mas[x] / pow(10,n) > (mas[x+1] / pow(10, n))))
			{
				std::swap(mas[x], mas[x + 1]);
				PrintVec(mas);
				int tempp = x;
				while (tempp != 0)
				{
					if ((mas[tempp] / pow(10, n) > (mas[x] / pow(10, n))))
					{
						std::swap(mas[x], mas[x + 1]);
						PrintVec(mas);
						x--;
					}
					tempp--;
				}
			}
		}
		n--;
	}
	

	////


	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);
}
