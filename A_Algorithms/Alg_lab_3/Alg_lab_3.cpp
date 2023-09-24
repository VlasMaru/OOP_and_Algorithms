/* Лаба №3 "Задача о простых множителях"
На вход дается одно число х, нужно вывести все числа от 1 до х, удовлетворяющие условию :
3 ^ K * 5 ^ L * 7 ^ M = xi

где K, L, M - натуральные числа или могут быть равны 0.

	for (int k = 1; k < ; k++)


*/

#include <iostream>
#include <string>

int main()
{
	double print = 0;
	int ex = 0;
	int add = 1;
	bool flag = false;
	std::cin >> print;

	int k_range = pow(print, 1 / 3.0) + 2;
	int l_range = pow(print, 1 / 5.0) + 2;
	int m_range = pow(print, 1 / 7.0) + 2;
	
		for (int k = 0; k < k_range; k++)
		{
				for (int l = 0; l < l_range; l++)
				{
					for (int m = 0; m < m_range; m++)
					{
						ex = pow(3, k) + pow(5, l) + pow(7, m);

						if (ex <= print) { std::cout << ex << ":  K = " << k << " L = " << l << " M = " << m << std::endl; add++; }
						
					}
				}
		}



	

}

