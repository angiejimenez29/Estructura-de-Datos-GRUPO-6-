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

class Queue 
{
private:
	NODE* m_pFront;
	NODE* m_pRear;
	
public:
	Queue() : m_pFront(NULL), m_pRear(NULL) {}

	void Enqueue(int data) 
	{
		NODE* newNode = new NODE;
		newNode->m_data = data;
		newNode->m_pNext = NULL;
		
		if (m_pRear == NULL) 
		{
			m_pFront = newNode;
			m_pRear  = newNode;
		} 
		else 
		{
			m_pRear->m_pNext = newNode;
			m_pRear = newNode;  
		}
	}

	void Dequeue() 
	{
		if (m_pFront == NULL) 
		{
			cout << "La cola esta vacia, no se puede hacer dequeue." << endl;
			return;
		}
		NODE* temp = m_pFront;
		m_pFront = m_pFront->m_pNext;  
		delete temp; 
		
		if (m_pFront == NULL) 
		{
			m_pRear = NULL;
		}
	}

	int Front() const {
		if (m_pFront == NULL) {
			cout << "La cola esta vacia." << endl;
			return -1;
		}
		return m_pFront->m_data;
	}

	bool IsEmpty() const {
		return m_pFront == NULL;
	}

	void Print() const 
	{
		if (m_pFront == NULL) {
			cout << "La cola esta vacia." << endl;
			return;
		}
		
		NODE* current = m_pFront;
		while (current != NULL) {
			cout << current->m_data << " -> ";
			current = current->m_pNext;
		}
		cout << "NULL" << endl;
	}
};

int main() {
	Queue queue;

	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(5);

	cout << "Contenido de la cola: ";
	queue.Print();

	cout << "Valor del frente de la cola: " << queue.Front() << endl;

	cout << "Haciendo dequeue de la cola." << endl;
	queue.Dequeue();
	queue.Print();

	cout << "Valor del frente de la cola despues de hacer dequeue: " << queue.Front() << endl;
	
	if (queue.IsEmpty()) 
	{
		cout << "La cola esta vacia." << endl;
	} 
	else 
	{
		cout << "La cola no esta vacia." << endl;
	}
	
	return 0;
}
