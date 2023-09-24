/*
Дана последовательность чисел. Отсортировать и вывести последовательность чисел, определённым методом.
№4 Сортировка методом прочесывания.
*/

#include <iostream>
#include <vector>


void PrintVec (std::vector <int> vec)
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
	std::vector <int> mas;
	int tempy(0);
	std::cout << "Enter your massive elements: " << std::endl;
	for (int x = 0; x < mas_size; x++)
	{
		std::cin >> tempy;
		mas.push_back(tempy);
	}
	PrintVec(mas);
	std::cout << std::endl;

	int step = mas_size - 1;

	for (int x = 0; x < mas_size ; x++)
	{
		if (step >= 1)
		{
			for (int i = 0; (i + step) < mas_size; i++)
			{
				if (mas[i] > mas[i + step]) { std::swap(mas[i], mas[i + step]); PrintVec(mas); }
			}
			step--;
		}
		

	}
	
	
	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);
}



/*
* 
* 
* 
* 
* int step = 1;
	for (int x = 0; x < mas_size; x++)
	{
		for (int i = 0; i < step; i++)
		{
		  if (mas[i] > mas[mas_size - step]) { std::swap(mas[i], mas[mas_size - step]); PrintVec(mas); } 
		}
		if ((step + 1) < mas_size) { step++; }
		else if ((step + 1) >= mas_size) { break;}
	}






	}*/

