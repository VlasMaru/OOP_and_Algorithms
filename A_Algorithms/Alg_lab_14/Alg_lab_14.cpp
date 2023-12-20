#include <iostream>
#include <fstream>
#include <vector>
//“со списками”

class Htable {
private:
    int size;
    std::vector<std::vector<std::string>> test;

public:
    Htable(int s) : size(s)
    {
        for (int i = 0; i < size; i++) {test.push_back({});}
    }

    void Filler(const std::string& str)
    {
        int ind = Hash(str);
        test[ind].push_back(str);
    }

    int Hash(const std::string& s)
    {
        int hash_value = 0;
        for (char ch : s) { hash_value += static_cast<int>(ch);}
        return hash_value % size;
    }
    const std::vector<std::string>& operator[](int i) const { return test[i];}
    //Getter
    int GetSize() const {return size;}

   
};

int main()
{
    std::ifstream in;
    in.open("input.txt");
    std::string str;
    int testr = 0;
    while (in >> str) {testr++;}
    in.close();

    // заполнение хеш таблиц
    in.open("input.txt");
    std::string cur;

    Htable test(testr);

    while (in >> cur) {
        test.Filler(cur);
    }
    in.close();

    std::ofstream out;
    out.open("output.txt");

    out << "INDEX | VALUE" << std::endl;
    for (int i = 0; i < test.GetSize(); i++) {
        out << i << "        ";
        for (const auto& value : test[i]) {
            out << value << "  ";
        }
        out << '\n';
    }

    out.close();

    return 0;
}
