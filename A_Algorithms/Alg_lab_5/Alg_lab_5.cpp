//  Метод сортировки вставками
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
	for (int x = 0; x < mas_size; x++)
	{
		for (int y = x; y < mas_size; y++)
		{
			if (mas[x] > mas[y]) 
			{ std::swap(mas[x], mas[y]);
			PrintVec(mas);}
			while (key != 0)
			{
				if (mas[y] > mas[key])
				{
					std::swap(mas[x], mas[y]);
					PrintVec(mas);
				}
				key--;
			}
		}
	}









	////
	

	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);
}