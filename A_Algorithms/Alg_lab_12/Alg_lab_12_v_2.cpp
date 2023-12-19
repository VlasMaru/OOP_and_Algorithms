#include <iostream>
#include <fstream>
//внешняя многофазная
//перефирийные устройства будут симулировать вспомогательные файлы

int main()
{
	int a, b = 0;
	int A_counter, B_counter, count = 0;
	std::ifstream input, input_a, input_b;
	bool a_flag, b_flag, flag = true;

	int size = 0;//Числа в файле (количество)

	std::ofstream output, output_a, output_b;

	input.open("input.txt");
	output.open("output.txt");

	while (input >> a) {
		output << a << " ";
		size++; //подсчёт чисел в файле
	}
	input.close();
	output.close();

	for (int x = 1; x < size; x *= 2) { //обработка одиночных чисел, пар, четвёрок и тд
		input.open("output.txt");
		output_a.open("A.txt");				//разбиение оригинального файла на два вспомогательных
		output_b.open("B.txt");
		count = 0;
		while (input >> a)
		{
			count++;
			if (flag) { output_a << a << " "; }
			else { output_b << a << " "; }

			if (count == x)
			{
				count = 0;
				flag = !flag;
			}
		}
		input.close();
		output_a.close();
		output_b.close();

		input_a.open("A.txt");
		input_b.open("B.txt");
		output.open("output.txt");

		if (input_a >> a) //соединение файлов в один
		{
			a_flag = true;
		}
		else { a_flag = false; }
		if (input_b >> b) b_flag = true;
		else { b_flag = false; }



		for (int i = 0; i < size; i += 2 * x) // пары в четвёрки
		{
			A_counter = 0; B_counter = 0;
			while (A_counter < x && a_flag && B_counter < x && b_flag)
				if (a < b)
				{
					output << a << " ";
					if (input_a >> a) { a_flag = true; }
					else { a_flag = false; }
					A_counter++;
				}
				else
				{
					output << b << " ";
					if (input_b >> b)
					{
						b_flag = true;
					}
					else
					{
						b_flag = false;
					}
					B_counter++;
				}

			while (A_counter < x && a_flag) //удвоение длины мёрджнутых последовательностей, пока не упорядочится
			{
				output << a << " ";
				if (input_a >> a)
				{
					a_flag = true;
				}
				else
				{
					a_flag = false;
				}
				A_counter++;
			}
			while (B_counter < x && b_flag)
			{
				output << b << " ";
				if (input_b >> b)
				{
					b_flag = true;
				}
				else
				{
					b_flag = false;
				}
				B_counter++;
			}
		}
		input_a.close();
		input_b.close();
		output.close();
		remove("A.txt");		//чистка ненужных доп файлов
		remove("B.txt");
	}
}

