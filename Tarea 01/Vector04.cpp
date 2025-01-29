/*
Integrantes (GRUPO 6):
	- Ccahuana Quiñones Judith Valeria
	- Jimenez Vera Angie Danna
*/

#include <iostream>
using namespace std;

// Class CVector definition
class CVector
{
private:
    int *m_pVect;  // Pointer to the buffer
    int m_nCount;  // Control how many elements are actually used
    int m_nMax;    // Control how many are allocated as maximum
    int m_nDelta;  // To control the growing

    void Init(int delta); // Init our private variables, etc.
    void Resize();        // Resize the vector when occurs an overflow

public:
    CVector(int delta = 10);  // Constructor
    ~CVector();
    void Insert(int elem);   // Insert a new element
    void Display();
};

void CVector::Init(int delta) {
    m_nCount = 0; 
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new int[m_nMax];
}

CVector::CVector(int delta) {
    Init(delta); 
}

CVector::~CVector() {
    delete[] m_pVect;
}

void CVector::Resize() {
    int *pTemp = new int[m_nMax + m_nDelta];
    for (int i = 0; i < m_nCount; i++) {
        pTemp[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}

void CVector::Insert(int elem) {
    if (m_nCount == m_nMax) { // Verify if there is an overflow
        Resize();             // Resize the vector before inserting
    }
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Display() {
    cout << "Elementos en el vector: ";
    for (int i = 0; i < m_nCount; i++) {
        cout << m_pVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << m_nCount << endl;
}

int main(int argc, char *argv[]) {
    CVector myVector(5);

    myVector.Insert(10);
    myVector.Insert(20);
    myVector.Insert(30);

    myVector.Display();

    return 0;
}

/****************
Tarea 1 es insertar

gVect : 10, 20, 30


*****************/

