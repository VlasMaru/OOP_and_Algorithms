#include<iostream>
#include<vector>
#include<string>
#include<fstream>

// с наложением

class Element
{
private:

	int el_key;
	std::string el_data;

public:

	Element(int key, std::string data) : el_key{ key }, el_data{ data } {};

	std::string GetData() { return el_data; }

	int GetKey() { return el_key; }
};



class HTable
{
private:

	std::vector<Element> m_table;
	unsigned int m_start_size{ 12 };

public:

	HTable()
	{
		for (int i = 0; i < m_start_size; ++i)
		{
			m_table.push_back(Element(i, ""));
		}
	};

	int HashFunc(const std::string& str)
	{
		int hash_code = 0;
		for (int i = 0; i < str.size(); i++) {hash_code += (str[i] - '0');}
		return (hash_code / 23);
	}

	void HashInsert(const std::string data)
	{
		int key = HashFunc(data);

		if (key >= m_table.size())
		{
			m_table.push_back(Element(key, data));
		}
		else
		{
			int i = key;
			bool flag = false;

			while (m_table[i].GetData() != "") { i++; }

			if (m_table.size() < i)
			{
				m_table.push_back(Element(key, data));
			}
			else
			{
				m_table[i] = Element(key, data);
			}
		}
	}
	

	Element operator[] (int key) { return m_table[key]; }

	int GetStartSize() { return m_start_size; }

	int GetSize() { return m_table.size(); }

	std::string GetData(const std::string& str)
	{
		int key = HashFunc(str);

		for (int i = key; i < m_table.size(); ++i)
		{
			if (m_table[i].GetData() == str)
			{
				return m_table[i].GetData();
			}
		}

		return "ERROR! VALUE NOT FOUND!";
	}

	

};
 
//

int main()
{
	HTable test;
	std::string str;
	int n = 1;

	std::ifstream inp("input.txt");
	std::ofstream out;

	if (inp.is_open())
	{
		while (getline(inp, str))
		{
			test.HashInsert(str);
			std::cout << n << " - " << test.GetData(str) << std::endl;
			n++;
		}
	}
	inp.close();

	out.open("output.txt", std::ios::out | std::ios::trunc);
	out << "INDEX / KEY / VALUE\n";
	int i = 0;
	for (; i < test.GetSize() - 1; ++i)
	{
		out << i << "    -    " << test[i].GetKey() << "    -    " << test[i].GetData() << "\n";
	}

	out << i << "    -    " << test[i].GetKey() << "    -    " << test[i].GetData();
	out.close();
}