#include "LinkedList.h"

int main()
{
    CLinkedList<int> list;

    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(5);

    cout << "Lista original:" << endl;
    list.Print();

    cout << "\nInsertando 100 al inicio:" << endl;
    list.InsertBegin(100);
    list.Print();

    cout << "\nEliminando 20 de la lista:" << endl;
    list.Delete(20);
    list.Print();

    return 0;
}

