//  Метод сортировки выбором
//

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
	int tempy(0);
	std::cout << "Enter your massive elements: " << std::endl;
	for (int x = 0; x < mas_size; x++)
	{
		std::cin >> tempy;
		mas.push_back(tempy);
	}
	PrintVec(mas);
	std::cout << std::endl;

	////

	int key(0);
	int lok_max{0};
	int max_x(0);

	while (key != mas_size)
	{
		for (int x = 0; x < mas_size - key; x++)
		{
			if (lok_max <= mas[x]) { lok_max = mas[x]; max_x = x; }
		}
		std::swap(mas[max_x], mas[mas_size - 1 - key]);
		PrintVec(mas);
		key++;
		lok_max = 0;
		max_x = 0;
	}

	








	////


	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);
}