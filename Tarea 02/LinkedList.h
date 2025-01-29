#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class CLinkedList
{
private:
    struct NODE
    {
        T m_data;    
        NODE *m_pNext;
    };

    NODE *m_pRoot;

public:
    CLinkedList() : m_pRoot(nullptr) {}

    void Insert(T data)
    {
        NODE *newNode = new NODE{data, nullptr};

        if (!m_pRoot)
        {
            m_pRoot = newNode;
        }
        else
        {
            NODE *current = m_pRoot;
            while (current->m_pNext)
            {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
        }
    }

    void InsertBegin(T data)
    {
        NODE *newNode = new NODE{data, m_pRoot};
        m_pRoot = newNode;
    }

    // Imprimir la lista
    void Print() const
    {
        NODE *current = m_pRoot;
        while (current)
        {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }

    // Eliminar un nodo por valor
    void Delete(T data)
    {
        if (!m_pRoot)
            return;

        // Caso especial: eliminar el nodo raíz
        if (m_pRoot->m_data == data)
        {
            NODE *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
            return;
        }

        NODE *current = m_pRoot;
        while (current->m_pNext && current->m_pNext->m_data != data)
        {
            current = current->m_pNext;
        }

        if (current->m_pNext)
        {
            NODE *temp = current->m_pNext;
            current->m_pNext = current->m_pNext->m_pNext;
            delete temp;
        }
        else
        {
            cout << "Valor " << data << " no encontrado en la lista!" << endl;
        }
    }

    ~CLinkedList()
    {
        while (m_pRoot)
        {
            NODE *temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
        }
    }
};

#endif

