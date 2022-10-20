#include <iostream>
#include "tree.h"
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc < 2){
        cout << "not data" << "\n";
        return 0;
    }
    fstream file;
    file.open(argv[1],ios_base::in);

    Tree tree;
    int n;
    file >> n;
    if(file.fail()) {
            cout << "Error\n";
            return 0;
    }
    for (int i = 0; i < n; i++){
        int id, left, right;
        file >> id >> left >> right;
        if(file.fail() || id < 0 || left < -2 || right < -2) {
                cout << "Error\n";
                return 0;
        }
        tree.Insert(id, right, left);
    }
    tree.Print();

    tree.Logic();
    cout << "\n";

    tree.Print();

    file.close();
    return 0;
}
