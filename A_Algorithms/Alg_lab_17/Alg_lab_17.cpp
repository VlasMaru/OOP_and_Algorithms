#include <iostream>
#include <string>
#include <vector>
#include <stack>

struct Tree //бинарного дерева
{
    int data;
    int level;  //уровень узладерева 
    Tree* left;
    Tree* right;
    Tree* parent;
};

Tree* RootMaker(int data, Tree* p)
{
    Tree* temp = new Tree;
    temp->data = data;
    temp->level = (p == nullptr ? 0 : p->level + 1);
    temp->left = nullptr;
    temp->right = nullptr;
    temp->parent = p;
    return temp;
}

void AddEl(int data, Tree*& root)    // добавление элемента (по данным и указателю на указатель нужного корня)
{
    if (root == nullptr) { root = RootMaker(data, nullptr); return; } //при пустом корне - создаём его

    Tree* child = root;
    //помещаем элемент в левый или правый потомок
    while (((data < child->data) && (child->left != nullptr)) || ((data > child->data) && (child->right != nullptr)))
    {
        if (data < child->data) { child = child->left; }
        else { child = child->right; }
    }

    if (data == child->data) { return; }  //при дубле значения родителя ничего не делаем

    Tree* new_v = RootMaker(data, child);  //новая вершина  
    if (data < child->data) { child->left = new_v; }
    else { child->right = new_v; }
}

void AddBracEl(int data, Tree*& root, bool left_flag)  // добавлениe элемента по скобочной записи
{
    Tree* a = root;
    Tree* b = RootMaker(data, a);
    if (left_flag) { a->left = b; }
    else { a->right = b; }
}

void TreeFiller(std::string& str, int& i, Tree*& root)   // заполнения бинарного дерева 
{
    int value = 0;
    while (str[i] != '\0')
    {
        switch (str[i])
            //Разбираем введённую запись на разные случаи
        {
        case ',':                       //, => вправо по дереву
        {
            i++;
            value = 0;
            while ((str[i] >= '0') && (str[i] <= '9'))
            {
                value = value * 10 + str[i] - '0';
                i++;
            }

            if (value != 0)
            {
                AddBracEl(value, root, false);
                if (str[i] == '(')
                {
                    TreeFiller(str, i, root->right);
                }
            }
            value = 0;
            break;
        }

        case '(':                   //( =>  влево по дереву
        {
            i++;
            value = 0;
            while ((str[i] >= '0') && (str[i] <= '9'))  // проверка на цифру
            {
                value = value * 10 + str[i] - '0'; i++;
            }

            if (value != 0)
            {
                AddBracEl(value, root, true);     //добавляем элемент
                if (str[i] == '(')      //если после скобки стоит еще одна то рекурсивно вызываем данную функцию
                {
                    TreeFiller(str, i, root->left);
                }
            }
            value = 0;
            break;
        }


        case ')':
            i++;
            return;
        default:
            break;
        }
    }
}

void Pass(Tree* v)   //Обход дерева (прямой)
{
    if (v == nullptr) { return; } // nullptr check
    Pass(v->left);
    std::cout << v->data << std::endl;
    Pass(v->right);
}

Tree* TreeSearch(int data, Tree* tree)  // El search
{
    if (tree == nullptr) {return tree;}

    if (tree->data == data) { return tree; }

    if (data < tree->data) { return TreeSearch(data, tree->left); }
    else { return TreeSearch(data, tree->right); }
}

void ElDelete(int data, Tree*& root)
{
    Tree* tr = TreeSearch(data, root);
    if (tr == nullptr)
    {
        return;
    }

    if (tr->left == nullptr && tr->right == nullptr && tr == root) // элемент — корень, значит удаляем его
    {
        delete root;
        root = nullptr;
        return;
    }

    if (tr->left == nullptr && tr->right != nullptr && tr == root) //  существуют правый потомoк => меняем этот элемент с самым маленьким элементом  справа
    {
        Tree* t = tr->right;
        while (t->left != nullptr)
        {
            t = t->left;
        }
        tr->data = t->data;
        tr = t;
    }

    if (tr->left != nullptr && tr->right == nullptr && tr == root) //существуют левый потомoк =>  то меняем этот элемент с самым большим элементом слева
    {
        Tree* t = tr->left;
        while (t->right != nullptr)
        {
            t = t->right;
        }
        tr->data = t->data;
        tr = t;
    }

    if (tr->left != nullptr && tr->right != nullptr) // существуют оба потомка => меняем этот элемент с самым маленьким элементом  справа
    {
        Tree* t = tr->right;
        while (t->left != nullptr) { t = t->left; }
        tr->data = t->data;
        tr = t;
    }
    Tree* t;                    // удаление элемента
    if (tr->left == nullptr) { t = tr->right; }
    else { t = tr->left; }
    if (tr->parent->left == tr) { tr->parent->left = t; }
    else { tr->parent->right = t; }
    if (t != nullptr) { t->parent = tr->parent; }
    delete tr;
}

void TreeClear(Tree*& tree)           //Очистка дерева
{
    if (tree == nullptr) { return; }  //Удаление узлов
    TreeClear(tree->left);
    TreeClear(tree->right);
    delete tree;
    tree = nullptr;
}

// вывод дерева на экран
void Print(Tree* root)
{
    if (root == nullptr)
    {
        std::cout << std::endl;
        return;
    }

    // выводим дерева на экран справа налево (в консоли оно будет лежать на левом боку)
    Print(root->right);

    for (int i = root->level; i > 0; i--)
    {
        std::cout << '\t';
    }
    std::cout << root->data << std::endl;

    Print(root->left);
}

void Menu(Tree* root)   //Реализация меню выбора
{
    int input;
    bool flag = false;
    while (!flag)
    {
        std::cout << "Select transaction number:" << std::endl;
        std::cout << "Add - 1, Delete - 2, Find - 3, Exit program - 4" << std::endl;
        std::cin >> input;
        switch (input)
        {
        case 1:
        {
            int value;
            std::cout << "Enter the value to be added: ";
            std::cin >> value;
            AddEl(value, root);
            break;
        }
        case 2:
        {
            int value;
            std::cout << "Enter the value to be deleted: ";
            std::cin >> value;
            ElDelete(value, root);
            break;
        }
        case 3:
        {
            int value;
            std::cout << " Enter the value you want to find:";
            std::cin >> value;

            Tree* element = nullptr;
            element = TreeSearch(value, root);
            std::cout << "Element " << (element == nullptr ? "Not found!" : "found.") << std::endl;
            break;
        }
        case 4:
            flag = true;
            break;
        default:
            break;
        }
    }
    Print(root);
}


int main()
{
    std::string str;
    std::cout << "Enter the expression in bracket form!" << std::endl;
    std::cin >> str;

    Tree* root = nullptr;

    int value = 0, i = 0;
    while ((str[i] >= '0') && (str[i] <= '9'))  //Если в строке число, пишем его в значение узла
    {
        value = value * 10 + str[i] - '0';
        i++;
    }
    AddEl(value, root);
    TreeFiller(str, i, root);
    Menu(root);
    TreeClear(root);

}

//8(3(1,6(4,7)),10(,14(13,)))