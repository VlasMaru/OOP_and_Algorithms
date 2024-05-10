//	5.	Найти в заданном орграфе количество и состав сильно связных компонент с помощью поиска в глубину.

//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>


class Graph
{
private:
    
    int vertex = 0;
    std::vector <std::vector <int>> graph;
    std::vector <std::vector <int>> graph_rev;
public:
    Graph(int v) : vertex(v)
    {
        graph_rev.resize(v);
        for (int x = 0; x < vertex; x++)
        {
            std::vector <int> temp;
            graph.push_back(temp);
        }

    };

    void connect_undir(int start, int fin)
    {
        if ((start < vertex) and (fin < vertex))
        {
            graph[start].push_back(fin);
            graph_rev[fin].push_back(start);
        }
    }

    std::vector <std::vector <int>> get_graph() {return graph;}
    std::vector <std::vector <int>> get_rev_graph() { return graph_rev; }

    int get_vertex() { return vertex; }


    void print_graph_paths()
    {
        for (int x = 0; x < vertex; x++)
        {
            std::cout << x << " :  ";
            for (int y = 0; y < graph[x].size(); y++)
            {
                std::cout << graph[x][y] << "  ";
            }
            std::cout << std::endl;
        }
    }




};



std::vector <int> DataCatcher(std::string exmpl, std::vector <int> ex_mas, int leng)
{
    std::string tempo = "";
    int counter = 0;
    bool len_fl = false;

    for (int x = 0; x <= exmpl.length(); x++)
    {
        bool flag = (exmpl[x] != ' ');

        if ((x == exmpl.length()) and (exmpl[x] == '\0'))
        {
            bool len_fl = true;
            if (tempo != "") { ex_mas[counter] = std::stoi(tempo); leng++; }
        }

        if ((x == exmpl.length()) and (exmpl[x] != '\0'))
        {
            tempo += exmpl[x];
            ex_mas[counter] = std::stoi(tempo);
            leng++;
            bool len_fl = true;
        }

        if (flag == true)
        {
            tempo += exmpl[x];
        }

        else if (flag == false)
        {
            if (tempo != "")
            {
                ex_mas[counter] = std::stoi(tempo);
                leng++;
                tempo = "";
                counter += 1;
            }

            else if (len_fl != true)
            {
                tempo += exmpl[x];
                ex_mas[counter] = std::stoi(tempo);
                leng++;
                tempo = "";
                counter += 1;
            }

        }
    }


    return ex_mas;
}


////////////////////


void DFS_Comps(Graph gr, std::vector <int>& visited, int start, std::set <int>& comp)
{
    std::vector <std::vector <int> > graph = gr.get_graph();

    visited[start] = 1;
    comp.insert(start);

    for (int x : graph[start]) // цикл foreach, перебор  строки  списка смежности для точки start
    {
        while (visited[x] != 1)
        {
            DFS_Comps(gr, visited, x, comp);
        }
        comp.insert(start);
    }

}

void DFS_Topol(Graph gr, std::vector <int> &visited, int start, std::vector <int> &order)
{
    std::vector <std::vector <int> > graph = gr.get_rev_graph();
    visited[start] = 1;

    for (int x : graph[start]) // цикл foreach, перебор  строки  списка смежности для точки start
    {
        while (visited[x] != 1)
        {
            DFS_Topol(gr, visited, x, order);
        }
    }
    order.push_back(start);

}



void PrintSet(std::set <int> d)
{
    std::set <int> ::iterator beg = d.begin();
    for (int x = 0; x < d.size(); x++) { std::cout << " " << *(beg++) << " "; }
}




int main()
{ //
    std::ifstream in;
    in.open("input.txt");
    std::vector <std::string> lines;
    std::string str = "";
    std::string num_of_ver_str = "";

    std::getline(in, num_of_ver_str); //первая стока - число - количество вершин
    int num_of_ver_int = std::stoi(num_of_ver_str);

    while (std::getline(in, str)) { lines.push_back(str); std::string str = ""; } //прочитали матрицу ПОСТРОЧНО
    in.close();


    Graph wh(num_of_ver_int);

    for (int x = 0; x < num_of_ver_int; x++)
    {
        std::vector <int> temp;
        for (int c = 0; c < num_of_ver_int; c++) { temp.push_back(-1); }
        temp = DataCatcher(lines[x], temp, num_of_ver_int);
        for (int y = 0; y < temp.size(); y++) { if (temp[y] == 1) wh.connect_undir(x, y); }


    }

    wh.print_graph_paths();

    std::cout << std::endl;
    std::cout << std::endl;

    std::vector <int> visited_topl(num_of_ver_int);
    std::vector <int> visited (num_of_ver_int);
    std::vector <std::set <int>> compss;
    std::set <int> temp_comp;
    std::vector <int> order;


    for (int y = 0; y < num_of_ver_int; y++)
    {
        if (visited_topl[y] != 1)
        {
            DFS_Topol(wh, visited_topl, y, order);
        }
    }
    std::reverse(order.begin(), order.end());
   

    for (int x : order)
    {
        if (visited[x] != 1)
        {
            DFS_Comps(wh, visited, x, temp_comp);
            compss.push_back(temp_comp);
            temp_comp.clear();
        }
    }




    std::cout << "Number of strongly connectivity component: " << compss.size() << std::endl;
    std::cout << "Connectivity components:" << std::endl;
    for (int d = 0; d < compss.size(); d++)
    {
        PrintSet(compss[d]);
        std::cout << std::endl;
    }

}




