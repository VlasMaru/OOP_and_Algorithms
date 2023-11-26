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
/*void QSort(std::vector <int>& mas, int mas_size, int from, int to)
{
	if (mas_size != 1)
	{
		int key = mas[from];
		std::vector <int> temp{};
		temp.push_back(key);
		int l_size = 0;
		int r_size = 0;
		for (int x = 0; x < mas_size; x++)
		{
			if ((mas[x] >= key) && (x != from))
			{
				temp.push_back(mas[x]);
				r_size++;
			}
			else if ((mas[x] < key) && (x != from))
			{
				temp.insert(temp.begin(), mas[x]);
				l_size++;
			}

		}
		for (int c = 0; c < mas_size; c++) { mas[c] = temp[c]; }
		QSort(mas, l_size, from, from + l_size);
		QSort(mas, r_size, from + l_size, to);

	}


	//////

	if (mas_size >= 2)
	{
		int key = mas[0];
		std::vector <int> left_side;
		std::vector <int> right_side;
		for (int x = 0; x < mas_size; x++)
		{
			if (mas[x] <= key) { left_side.push_back(mas[x]); }
			else if (mas[x] > key) { right_side.push_back(mas[x]);}
		}
		if (left_side.size() != 0) { QSort(left_side, left_side.size()); }
		if (right_side.size() != 0) { QSort(right_side, right_side.size()); }
		mas.clear();
		for (int c = 0; c < left_side.size(); c++) { mas.push_back(left_side[c]); }
		for (int g = 0; g < right_side.size(); g++) { mas.push_back(right_side[g]); }
	}
}*/

int NotMax(std::vector <int>& mas,int mas_size)
{
	for (int y = 1; y < mas_size; y++) { if (mas[y] > mas[0]) { return mas[0]; } }
	return mas[1];
}

void QSort(std::vector <int>& mas, int mas_size)
{
	if (mas_size >= 2)
	{
		int key = NotMax(mas,mas_size);
		std::vector <int> left_side;
		std::vector <int> right_side;
		std::vector <int> same;
		for (int x = 0; x < mas_size; x++)
		{
			if (mas[x] <= key) { left_side.push_back(mas[x]); }
			else if (mas[x] > key) { right_side.push_back(mas[x]);}
			else if (mas[x] == key) {same.push_back(mas[x]);}
		}
		if ((left_side.size() != 0) && (right_side.size() != 0)) 
		{ QSort(left_side, left_side.size());
		QSort(right_side, right_side.size());
		}
	
		mas.clear();
		for (int c = 0; c < left_side.size(); c++) { mas.push_back(left_side[c]); }
		for (int g = 0; g < right_side.size(); g++) { mas.push_back(right_side[g]); }
	}
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

	QSort(mas, mas_size);


	////

	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);



}