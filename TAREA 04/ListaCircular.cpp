/*
GRUPO 6
Ccahuana Quiñones Judith Valeria
Jimenez Vera Angie Danna 
*/

#include <iostream>
using namespace std;

struct NODE
{
	int m_data; 
	struct NODE *m_pNext;
};

class CCircularLinkedList
{
private:
	NODE *m_pRoot; 

public:
	CCircularLinkedList() : m_pRoot(nullptr) {}
	
	void Insert(int data) 
	{
		NODE* newNode = new NODE;
		newNode->m_data = data;

		if (m_pRoot == nullptr) 
		{
			m_pRoot = newNode;
			newNode->m_pNext = m_pRoot;
		} 
		else 
		{
			NODE* current = m_pRoot;
			while (current->m_pNext != m_pRoot) 
			{
				current = current->m_pNext;
			}
			current->m_pNext = newNode;
			newNode->m_pNext = m_pRoot;
		}
	}
	
	
	void Print() const 
    {
        if (m_pRoot == nullptr)
        {
            cout << "La lista esta vacia" << endl;
            return;
        }

        NODE *current = m_pRoot;
        cout << "Lista Circular:" << endl;
        do
        {
            cout <<current->m_data << " -> ";
            current = current->m_pNext;
        } while (current != m_pRoot);
		cout << "Fin" << endl;
	}
	
	void Delete(int data)
	{
		if (m_pRoot == nullptr) 
			return; 
		
		NODE *current = m_pRoot, *prev = nullptr;
		
		if (m_pRoot->m_data == data) 
		{
			if (m_pRoot->m_pNext == m_pRoot)
            {
                delete m_pRoot;
                m_pRoot = nullptr;
            }
            else
            {
                NODE *last = m_pRoot;
                while (last->m_pNext != m_pRoot)
                    last = last->m_pNext;

                last->m_pNext = m_pRoot->m_pNext;
				NODE* temp = m_pRoot;
				m_pRoot = m_pRoot->m_pNext;
				delete temp;
			}
			return;
		}
		
		do
        {
            prev = current;
            current = current->m_pNext;
        } while (current != m_pRoot && current->m_data != data);

        if (current->m_data == data)
        {
            prev->m_pNext = current->m_pNext;
            delete current;
        }
        else
        {
            cout << "Numero " << data << " no encontrado en la lista" << endl;
        }
    }
};


int main(int argc, char *argv[]) 
{
	CCircularLinkedList list;

	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(5);

	list.Print();
	
	cout << "\nEliminando 20 de la lista\n" << endl;
	list.Delete(20);
	list.Print();
	
	return 0;
}
