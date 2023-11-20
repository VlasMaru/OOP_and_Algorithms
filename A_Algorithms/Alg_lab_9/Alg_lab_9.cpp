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

void Heapify(std::vector <int> &mas, int mas_size, int i)
{
	int max = i;
	int lef_k = 2 * i + 1;
	int rig_k = 2 * i + 2;

	if (lef_k < mas_size && mas[lef_k] > mas[max]) { max = lef_k; }
	if (rig_k < mas_size && mas[rig_k] > mas[max]) { max = rig_k; }

	if (max != i)
	{
		std::swap(mas[i], mas[max]);
		Heapify(mas, mas_size, max);
	}
}

void HeapSort(std::vector <int> &mas, int mas_size)
{
	int cur_size = mas_size;
	for (int y = 0; y < mas_size; y++)
	{
		for (int x = 0; x < cur_size; x++)
		{
			Heapify(mas, cur_size, cur_size-1-x);
			//std::cout << "Sorted Tree: " << std::endl;
			//PrintVec(mas);
		}
		std::cout << "Sorted Tree: " << std::endl;
		PrintVec(mas);
		if (cur_size != 1) { std::swap(mas[0], mas[cur_size - 1]); }
		cur_size--;
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

	HeapSort(mas, mas_size);


	////

	std::cout << "Sorted massive: " << std::endl;
	PrintVec(mas);



}