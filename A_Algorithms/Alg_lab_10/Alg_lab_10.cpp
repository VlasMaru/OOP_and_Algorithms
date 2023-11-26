
#include <iostream>
#include <vector>




void MergSort(std::vector <int>& mas, int mas_size, int from,int to)
{
	if (mas_size == 2)
	{
		if ((mas[from] > mas[to])) { std::swap(mas[from], mas[to]); }
	}
	if ((mas_size != 2)&&(mas_size != 1))
	{
		int l_size = mas_size / 2;
		int r_size = mas_size - l_size;
		int l_ind = from;
		int r_ind = from + l_size;
		MergSort(mas, l_size, l_ind, l_ind + l_size-1);
		MergSort(mas, r_size, r_ind, to);
		std::vector <int> sup_mas;
		//for (int v = 0; v < mas_size; v++) { sup_mas.push_back(-873); }
		int counter = 0;
		int counter_l = l_ind;
		int counter_r = r_ind;
		int l_end = r_ind;
		int r_end = mas_size + from;
		while (counter != mas_size)
		{
			if (counter_l == l_end)
			{
				sup_mas.push_back(mas[counter_r]);
				counter++;
				counter_r++;
			}

			else if (counter_r == r_end)
			{
				sup_mas.push_back(mas[counter_l]);
				counter++;
				counter_l++;
			}

			else if ((counter_r != r_end) && (counter_l != l_end))
			{
				if (mas[counter_l] <= mas[counter_r])
				{
					sup_mas.push_back(mas[counter_l]);
					counter++;
					counter_l++;
				}

				else if (mas[counter_l] > mas[counter_r])
				{
					sup_mas.push_back(mas[counter_r]);
					counter++;
					counter_r++;
				}
			}
			
		}

		for (int c = 0; c < mas_size; c++)
		{
			mas[c+from] = sup_mas[c];
		}

		/*
		for (int x = 0; x < l_size; x++)
		{
			for (int y = 0; y < r_size; y++)
			{
				if (mas[l_ind+x] < mas[r_ind+y]) { std::swap(mas[l_ind + x],mas[r_ind + y]);}
			}
			
		}*/
	}
}
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
	std::cout << "Unsorted massive: " << std::endl;
	PrintVec(mas);
	std::cout << std::endl;

	////

	MergSort(mas, mas_size, 0, mas_size - 1);


	////

	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);



}