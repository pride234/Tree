#include <conio.h>
#include "TREE.h"


using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Tree* T1 = new Tree;
    T1->AddNode(3);
    T1->AddNode(6);
    T1->AddNode(2);
    T1->AddNode(0);
    T1->AddNode(5);
    T1->AddNode(-1);
    T1->AddNode(13);
    T1->AddNode(9);
    T1->AddNode(-233);

//    cout << *T1;
    delete T1;
    getch();
    return 0;
}