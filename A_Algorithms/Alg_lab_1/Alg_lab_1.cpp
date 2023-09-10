
#include <iostream>
#include<vector>
#include<string>
#include<Windows.h>

/*(Задача состоит из двух пунктов, но вы можете не париться и делать сразу второй)
На вход подаётся строка, состоящая из скобок. Программа должна определить правильность введённого скобочного выражения. Савкин сказал, что программа должна работать на русском языке: "Введите строку", "Строка не существует", "Строка существует" и т.п.
Пункт 1: В строке будут скобки только одного типа: или "()" , или "{}", или "[]"
Пункт 2: В строке будут все три вида скобок
Для успешной сдачи лабы оба пункта программа должна выполнять корректно (можно сделать отдельные программы на каждый пункт)

Пример входа:
()[({}())]
*/

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
    //system messeges
	std::string start_mes = "Введите строку: ";
	std::string false_mes = "Строка не существует";
	std::string true_mes = "Строка существует";
	std::string mes = "";
	// 
	std::string input;
	bool flag = true;

	std::cout << start_mes <<std::endl;
	std::cin >> input;
	
	std::vector<char> stack;

	for (int x = 0; x < input.length(); x++)
	{
		if (flag != false) 
		{
			switch (input[x])
			{
			case '(':
				stack.push_back(input[x]);
				break;
			case '{':
				stack.push_back(input[x]);
				break;
			case '[':
				stack.push_back(input[x]);
				break;
				/// 

			case ')':
				if (x == 0)
				{
					flag = false;
					break;
				}
				if (stack.back() == '(') { stack.pop_back();}
				else if (stack.back() != '(') { flag = false; }
				break;

			case '}':
				if (x == 0) 
				{
					flag = false;
					break;
				}
				if (stack.back() == '{') { stack.pop_back(); }
				else if (stack.back() != '{') { flag = false; }
				break;

			case ']':
				if (x == 0) 
				{
					flag = false;
					break;
				}
				if (stack.back() == '[') { stack.pop_back(); }
				else if (stack.back() != '[') { flag = false; }
				break;
			}
		}

		if (flag == false) 
		{ 
			mes = false_mes;
			break;
		}
	}
	if (stack.empty() and (flag != false)) { mes = true_mes;}
	else { mes = false_mes;}

	std::cout << mes << std::endl;
	
}


