/*
GRUPO 6
Ccahuana Quiñones Judith Valeria
Jimenez Vera Angie Danna 
*/


#include <iostream>
using namespace std;

class CVector {
private:
	int* m_pVect; // Puntero al arreglo
	int m_nCount; // Número de elementos en uso
	int m_nMax;   // Capacidad máxima del arreglo
	int m_nDelta; // Incremento para redimensionar
	
	
	void Init(int delta) {
		m_nCount = 0;
		m_nMax = delta;
		m_nDelta = delta;
		m_pVect = new int[m_nMax];
	}
	
	void Resize() {
		m_nMax += m_nDelta;
		int* temp = new int[m_nMax]; 
		for (int i = 0; i < m_nCount; i++) {
			temp[i] = m_pVect[i];
		}
		delete[] m_pVect;
		m_pVect = temp;
	}
	
public:
		CVector(int delta = 10) {
			Init(delta);
		}
		
		void Insert(int elem) {
			if (m_nCount == m_nMax) { 
				Resize();
			}
			m_pVect[m_nCount++] = elem;
		}

		void Display() {
			for (int i = 0; i < m_nCount; i++) {
				cout << m_pVect[i] << " ";
			}
			cout << endl;
		}
		
		// Función de búsqueda binaria recursiva
		int BinarySearchRecursive(int left, int right, int target) 
		{
			if (left <= right) 
			{
				int mid = left + (right - left) / 2;
				if (m_pVect[mid] == target) 
				{
					return mid; // Elemento encontrado
				}
				
				if (m_pVect[mid] > target) 
				{
					return BinarySearchRecursive(left, mid - 1, target);
				}
				// Si el elemento es mayor que el del medio, buscar en la mitad derecha
				return BinarySearchRecursive(mid + 1, right, target);
			}
			
			return -1; // Elemento no encontrado
		}
		
		// Función de búsqueda binaria iterativa
		int BinarySearchIterative(int target){
			int left = 0, right = m_nCount - 1;  // Definir los limites iniciales
			while(left <= right){
				int mid = left + (right - left)/2; // Calcular el indice medio
				 
				// Si el elemento en la posicion media es el objetivo, devuelve el indice
				if (m_pVect[mid] == target)
				{
					return mid;
				}
				
				// Si el elemento medio es mayor que el objetivo, buscar en la mitad izquierda
				if (m_pVect[mid] > target) 
				{
					right = mid - 1; // Mover el limite derecho
				} else {
					// Si el elemento medio es menor que el objetivo, buscar en la mitad derecha
					left = mid + 1; // Mover el limite izquierdo
				}
			}
			return -1;
		}
		
		int GetCount() const 
		{
			return m_nCount;
		}

		~CVector() {
			delete[] m_pVect;
		}
};

int main() {
	CVector gVect; 
	
	gVect.Insert(5);
	gVect.Insert(10);
	gVect.Insert(15);
	gVect.Insert(20);
	gVect.Insert(30);
	gVect.Insert(50);
	
	cout << "Elementos en el vector: ";
	gVect.Display(); 
	
	// Buscar un elemento (ejemplo: 20)
	int target = 20;
	
	// Búsqueda binaria recursiva
    int resultRecursive = gVect.BinarySearchRecursive(0, gVect.GetCount() - 1, target);
    if (resultRecursive != -1) {
        cout << "Recursiva -> Elemento " << target << " encontrado en la posicion: " << resultRecursive << endl;
    } else {
        cout << "Recursiva -> Elemento " << target << " no encontrado." << endl;
	}
	
    // Búsqueda binaria iterativa
    int resultIterative = gVect.BinarySearchIterative(target);
    if (resultIterative != -1) {
        cout << "Iterativa -> Elemento " << target << " encontrado en la posicion: " << resultIterative << endl;
    }else {
        cout << "Iterativa -> Elemento " << target << " no encontrado." << endl;
	}
	
    return 0;
}
