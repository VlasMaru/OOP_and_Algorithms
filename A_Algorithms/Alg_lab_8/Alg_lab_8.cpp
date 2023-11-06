// Метод сортировки: поразрядная
//

#include <iostream>
#include <vector>
#include <string> 
#include <cmath> 


void PrintVec(std::vector <int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "  ";
	}
	std::cout << std::endl;
}


int DigitNumber(int dig, int num)
{
	for (int y = 0; y < num - 1; y++)
	{
		dig = dig / 10;
	}
	return dig % 10;
}

bool SameLenght(int a, int b)
{
	bool flag = false;
	int a_counter{ 1 };
	int b_counter{ 1 };
	while (a > 0)
	{
		a = a / 10; ++a_counter;
	}
	while (b > 0)
	{
		b = b / 10; ++b_counter;
	}
	if (a_counter == b_counter) { return true; }
	return false;
}

int main()
{
	//pokets
	std::vector <std::vector <int>> sup_mas{};
	 for (int x = 0; x < 10; x++) { std::vector <int> temp{}; sup_mas.push_back(temp); } 
	//entering massive + max
	 int mas_size = 0;
	 std::vector <int> mas{};
	 std::cout << "Enter your massive size: " << std::endl;
	 std::cin >> mas_size;
	std::cout << "Enter your massive elements: " << std::endl;
	int tempy(0);
	int max(0);
	for (int x = 0; x < mas_size; x++)
	{
		std::cin >> tempy;
		if (tempy >= max) { max = tempy;}
		mas.push_back(tempy);
	}
	PrintVec(mas);
	std::cout << std::endl;
	/// 
	int max_size(0);
	while (max != 0) { max = max / 10; max_size++;}

	std::cout << "MAX SIZE: " << max_size << std::endl;

	////
	int raz_count = 1;
	for (int x = 0; x < max_size; x++)
	{
		for (int y = 0; y < mas_size; y++)
		{
			int tempr = DigitNumber(mas[y], raz_count);
			sup_mas[tempr].push_back(mas[y]);
		}
		for (int c = 0; c < mas_size; c++) { mas[c] = -12;}
		int mas_counter = 0;
		for (int s = 0; s < 10; s++)
		{
			int counter = 0;
			//int g = sup_mas[s].size();
			while (counter != sup_mas[s].size())
			{
				mas[mas_counter] = sup_mas[s][counter];
				counter += 1; mas_counter += 1;
			}
			sup_mas[s].clear();
		}
		
		raz_count++;
	}


	

	////


	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);
}


/*std::string max_string = std::to_string(max);
	int max_range = max_string.length();

	//std::vector <int> mas_raz{};
	int n = max_range-1;


	while (n >= 0)
	{
		for (int x = 0; x < mas_size-1; x++)
		{
			if ((mas[x] / int(pow(10,n)) > (mas[x+1] / int(pow(10, n)))))
			{
				std::swap(mas[x], mas[x + 1]);
				PrintVec(mas);
				int tempp = x-1;
				while ((tempp >= 0) and (x >=0))
				{
					if ((mas[tempp] / int(pow(10, n)) > (mas[x] / int(pow(10, n)))))
					{
						std::swap(mas[tempp], mas[x]);
						PrintVec(mas);
						x--;
					}
					tempp--;
				}
			}
		}
		n--;
	}

	std::cout << "FIIINALL ROUUUUND!!!" << std::endl;
	for (int x = 0; x < mas_size - 1; x++)
	{
		if ((mas[x] % int(10)) > (mas[x + 1] % (int(10))) and SameLenght(mas[x], mas[x + 1]))
		{
			std::swap(mas[x], mas[x + 1]);
			PrintVec(mas);
			int tempp = x - 1;
			while ((tempp >= 0) and (x >= 0))
			{
				if ((mas[tempp] % int(10) > (mas[x] % int(10))) and SameLenght(mas[x], mas[tempp]))
				{
					std::swap(mas[tempp], mas[x]);
					PrintVec(mas);
					x--;
				}
				tempp--;
			}
		}
	}*/