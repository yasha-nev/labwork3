#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

struct Node{    //струтктура дерева
  int id;       //номер
  Node *right;  //сыновья
  Node *left;
};

class Tree
{
private:
    Node *head;
    void DeleteNode(Node *node);
    //bool AddNode(Node *node, int id, int column);
    void PrintNode(Node *node, int column, int count);      //рекурсивный вывод элементов на экран
    int SearcHeight(Node *node, int height);                //поиск глубины дерева

    void LogicNode(Node *node);                             //рукурсивная функция в которая выполняет заданую задачу

public:
    //void Add(int value);
    void Print();                                           //вызов PrintNode
    void Insert(int id, int right, int left);               //вставка
    Node *Search(Node *node, int id);
    Tree();
    ~Tree();
    void Logic();                                           //вызов LogicNode
};

#endif // TREE_H
