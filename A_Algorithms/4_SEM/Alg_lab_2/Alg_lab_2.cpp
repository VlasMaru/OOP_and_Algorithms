// Поиск в ширину
//2.	Найти в заданном графе кратчайшие пути из заданной вершины до всех остальных вершин с помощью поиска в ширину

//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <string>


class Graph
{
private:
    //int edges = 0;
    int vertex = 0;
    std::vector <std::vector <int>> graph;
    std::vector <int> weight;
public:
    Graph(/*int e, */ int v) : /*edges(e) ,*/ vertex(v)
    {
        for (int x = 0; x < vertex; x++)
        {
            std::vector <int> temp;
            graph.push_back(temp);
            weight.push_back(-36);
           
        }
    
    };

    

    void connect_undir(int start, int fin)
    {
        if ((start < vertex) and(fin < vertex))
        {
            graph[start].push_back(fin);
            //graph[fin].push_back(start);
        }
    }

    void set_weight(int num, int w)
    {
        weight[num] = w;
    }


    std::vector <std::vector <int>> get_graph()
    {
        return graph;
    }
    
    int get_verrex() { return vertex; }


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

    void print_graph_weight()
    {
        for (int x = 0; x < vertex; x++)
        {
            std::cout << x << " :  " << weight[x] << std::endl;
          
        }
    }

    
};

std::vector <int> Rebuild_Path (std::vector<int> from, int fin )
{
    std::vector<int> path;
    for (int v = fin; v != -1; v = from[v]) { path.push_back(v); }
    std::reverse(path.begin(), path.end());
    if (path.size() == 1) { std::cout << "WAY DO NOT EXIST!!!"; exit(-100);}
    return path;
};

std::vector<int> ShortCut(std::vector <std::vector <int>> gr, int start)
{
    std::vector<int> vis (gr.size(), 0);
    std::vector<int> dist (gr.size(), -36);
    std::vector<int> from (gr.size(), -1);

    std::queue<int> qq;

    vis[start] = 1;
    dist[start] = 0;
    qq.push(start);

    while (!qq.empty())
    {
        int curr = qq.front();
        qq.pop();

        for (int neib : gr[curr])
        {
            if (vis[neib] != 1)
            {
                vis[neib] = 1;
                dist[neib] = dist[curr] + 1;
                from[neib] = curr;
                qq.push(neib);
            }
        }
    }

    return from;
}







///
/// /////////


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











int main()
{ //
    std::ifstream in;
    in.open("input.txt");
    std::vector <std::string> lines;
    std::string str = "";
    std::string num_of_ver_str = "";

    std::getline(in, num_of_ver_str); //первая стока- число - количество вершин
    int num_of_ver_int = std::stoi(num_of_ver_str);

    while (std::getline(in,str)) { lines.push_back(str); std::string str = "";} //прочитали матрицу ПОСТРОЧНО
    in.close();


    Graph wh(num_of_ver_int);
    
    for (int x = 0; x < num_of_ver_int; x++)
    {
        std::vector <int> temp;
        for (int c = 0; c < num_of_ver_int; c++) { temp.push_back(-1); }
       temp = DataCatcher(lines[x], temp, num_of_ver_int);
       for (int y = 0; y < temp.size(); y++) { if (temp[y] == 1) wh.connect_undir(x, y);}


    }

    wh.print_graph_paths();

    std::cout << std::endl;
    std::cout << std::endl;

    int froms = 0;
    int tos = 0;
    std::cout << "You want to know shortest way from ..." << std::endl;
    std::cin >> froms;
    std::cout << "... to ..." << std::endl;
    std::cin >> tos;


    std::vector<int> answ = Rebuild_Path(ShortCut(wh.get_graph(), froms), tos);
    for (int i : answ)
    {
        std::cout << i << " ";
    }






    /*

    Graph dsd (4, 6);
    dsd.connect_undir(0, 1);
    dsd.connect_undir(1, 3);
    dsd.connect_undir(3, 2);
    dsd.connect_undir(3, 4);

    dsd.print_graph_paths();

    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<int> answ = Rebuild_Path(ShortCut(dsd.get_graph(), 0), 2);
    for (int i : answ)
    {
        std::cout << i << " ";
    }*/
}

