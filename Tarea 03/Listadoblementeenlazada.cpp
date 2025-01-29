/* Integrantes GRUPO 6:
 - Ccahuana Quiñones, Judith Valeria
 - Jimenez Vera, Angie Danna 
 */

#include <iostream>
using namespace std;

template <typename T>
class CDoublyLinkedList {
private:
    struct NODE {
        T m_data;
        NODE* m_pNext;
        NODE* m_pPrev;
    };

    NODE* m_pRoot;
    NODE* m_pTail;

public:
    CDoublyLinkedList() : m_pRoot(NULL), m_pTail(NULL) {}

    ~CDoublyLinkedList() {
        NODE* current = m_pRoot;
        while (current != NULL) {
            NODE* temp = current;
            current = current->m_pNext;
            delete temp;
        }
    }

    void Insert(T data) {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = NULL;
        newNode->m_pPrev = NULL;

        if (m_pRoot == NULL) {
            m_pRoot = newNode;
            m_pTail = newNode;
        } else {
            m_pTail->m_pNext = newNode;
            newNode->m_pPrev = m_pTail;
            m_pTail = newNode;
        }
    }

    void Delete(T data) {
        NODE* current = m_pRoot;

        while (current != NULL) {
            if (current->m_data == data) {
                if (current == m_pRoot) {
                    m_pRoot = current->m_pNext;
                    if (m_pRoot != NULL) {
                        m_pRoot->m_pPrev = NULL;
                    }
                } else if (current == m_pTail) {
                    m_pTail = current->m_pPrev;
                    if (m_pTail != NULL) {
                        m_pTail->m_pNext = NULL;
                    }
                } else {
                    current->m_pPrev->m_pNext = current->m_pNext;
                    current->m_pNext->m_pPrev = current->m_pPrev;
                }

                delete current;
                return;
            }

            current = current->m_pNext;
        }
    }

    void Print() const {
        NODE* current = m_pRoot;
        while (current != NULL) {
            cout << current->m_data << " <-> ";
            current = current->m_pNext;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    CDoublyLinkedList<int> list;

    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(5);

    cout << "Lista inicial: " << endl;
    list.Print();

    cout << "Eliminando 20 de la lista." << endl;
    list.Delete(20);

    list.Print();

    return 0;
}

