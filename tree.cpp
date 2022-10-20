#include "tree.h"

Tree::Tree()
{
    head = nullptr;
}

Tree::~Tree()
{
    DeleteNode(head);
    if (head){
        delete head;
    }
}

void Tree::DeleteNode(Node *node){ //освобождение памяти
    if (node->right){
        DeleteNode( node->right);
        delete node->right;
    }
    if (node->left){
        DeleteNode(node->left);
        delete node->left;
    }
}

void Tree::PrintNode(Node *node, int column, int count){        //Ищем строчку и выводим ее
    if (count > column){
        if (node){
            cout << node->id << " ";
        }
        else{
            cout << "n ";
        }
    }

    if (!node){
        return;
    }

    if (count <= column){
        PrintNode(node->right, column, count * 2);
        PrintNode(node->left, column, count * 2);
    }
}

void Tree::Print(){                                             //начало рекурсии PrintNode
    if (head){
        cout << head->id << "\n";
        int height = 1;                                         //узнам колличество строчек
        int t      = SearcHeight(head, 1);
        for (int i = 0; i < t - 1; i++){
            height = height * 2;
        }
        for (int i = 1; i < height;  i = i * 2){                //выводим строчки
            PrintNode(head, i, 1);
            cout << "\n";
        }
    }
}

int Tree::SearcHeight(Node *node, int height){                  //поиск максимальной глубины дерева
    int height_left = 0;
    int height_right = 0;

    if (node->right){
        height_right = SearcHeight(node->right, height + 1);
    }
    else{
        height_right = height;
    }
    if (node->left){
        height_left = SearcHeight(node->left, height + 1);
    }
    else height_left = height;

    if (height_right > height_left) return height_right;
    else return height_left;
}

Node *Tree::Search(Node *node, int id){
    if (node->id == id){
        return node;
    }
    Node *supNode = nullptr;
    if (node->right){
        supNode = Search(node->right, id);
    }
    if (supNode) return supNode;
    else if (node->left){
        supNode = Search(node->left, id);
    }
    return supNode;

}

void Tree::Insert(int id, int right, int left){
    Node *node = nullptr;
    if (head == nullptr){                       //если дерево пустое, надо создать
        head = new Node;
        head->id = id;
        node = head;
    }
    else {
        node = Search(head, id);                //находим нужный листок для присоединения
    }

    if (node){
        if (right != -1){                       //присоединяем
            node->right = new Node;
            node->right->id = right;
            node->right->right = nullptr;
            node->right->left = nullptr;
        }
        else{
            node->right = nullptr;
        }
        if (left != -1){
            node->left = new Node;
            node->left->id = left;
            node->left->right = nullptr;
            node->left->left = nullptr;
        }
        else{
            node->left = nullptr;
        }
   }
}

void Tree::LogicNode(Node *node){                   //рассматриваем каждый четный элемент и меняем с четным сыном
    if (!node){
        return;
    }
    if (node->id % 2 == 0){
        if (node->right && node->right->id % 2 == 0){
            int t = node->id;
            node->id = node->right->id;
            node->right->id = t;
        }
        else if(node->left && node->left->id % 2 == 0){
            int t = node->id;
            node->id = node->left->id;
            node->left->id = t;
        }
    }
    LogicNode(node->right);
    LogicNode(node->left);
}

void Tree::Logic(){
    if (head){
        LogicNode(head);
    }
}


/*void Tree::Add(int value){
    if (size == 0){
        head        = new Node;
        head->left  = nullptr;
        head->right = nullptr;
        head->value = value;
    }
    else{
        AddNode(head, value, 2);
    }
    size++;
}

bool Tree::AddNode(Node *node, int value, int column)
{
    if (column > size + 1){
        return 0;
    }
    if (node->right == nullptr){
        node->right        = new Node;
        node->right->value = value;
        node->right->right = nullptr;
        node->right->left  = nullptr;
        return 1;
    }
    else if (node->left == nullptr){
        node->left        = new Node;
        node->left->value = value;
        node->left->right = nullptr;
        node->left->left  = nullptr;
        return 1;
    }
    if (AddNode(node->right, value, column * 2)){
        return 1;
    }
    return AddNode(node->left, value, column * 2);
}*/



