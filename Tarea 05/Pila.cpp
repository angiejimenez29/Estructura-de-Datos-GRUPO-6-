/* 
INTEGRANTES GRUPO 6:
 - Ccahuana Quiñones, Judith Valeria
 - Jimenez Vera, Angie Danna
 */

#include <iostream>
using namespace std;

struct NODE 
{
	int m_data;
	NODE* m_pNext;
};

class Stack 
{
private:
	NODE* m_pTop;  

public:
	Stack() : m_pTop(NULL) {}

	void Push(int data) 
	{
		NODE* newNode = new NODE;
		newNode->m_data = data;
		newNode->m_pNext = m_pTop;  
		m_pTop = newNode;           
	}

	void Pop() 
	{
		if (m_pTop == NULL)
		{
			cout << "La pila está vacia, no se puede hacer pop." << endl;
			return;
		}
		NODE* temp = m_pTop;
		m_pTop = m_pTop->m_pNext;
		delete temp;               
	}

	int Top() const {
		if (m_pTop == NULL)  
		{
			cout << "La pila esta vacia." << endl;
			return -1;  
		}
		return m_pTop->m_data;
	}

	bool IsEmpty() const {
		return m_pTop == NULL;
	}

	void Print() const 
	{
		if (m_pTop == NULL) {  
			cout << "La pila esta vacia." << endl;
			return;
		}

		NODE* current = m_pTop;
		while (current != NULL)  
		{
			cout << current->m_data << " -> ";
			current = current->m_pNext;
		}
		cout << "NULL" << endl;  
	}
};

int main() 
{
	Stack stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(5);

	cout << "Contenido de la pila: ";
	stack.Print();

	cout << "Valor superior de la pila: " << stack.Top() << endl;

	cout << "Haciendo pop de la pila." << endl;
	stack.Pop();
	stack.Print();

	cout << "Valor superior de la pila despues de hacer pop: " << stack.Top() << endl;

	if (stack.IsEmpty()) {
		cout << "La pila esta vacia." << endl;
	} else {
		cout << "La pila no esta vacia." << endl;
	}

	return 0;
}

