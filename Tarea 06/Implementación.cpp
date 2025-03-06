/*
GRUPO 6
Ccahuana Quiñones Judith Valeria
Jimenez Vera Angie Danna 
*/

#include <iostream>
using namespace std;

class CVector {
private:
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

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

    void CopyTo(CVector& other) {
        other.m_nCount = m_nCount;
        other.m_nMax = m_nMax;
        delete[] other.m_pVect;
        other.m_pVect = new int[m_nMax];
        for (int i = 0; i < m_nCount; i++) {
            other.m_pVect[i] = m_pVect[i];
        }
    }


    void SelectionSort() {
        for (int i = 0; i < m_nCount - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < m_nCount; j++) {
                if (m_pVect[j] < m_pVect[minIndex]) {
                    minIndex = j;
                }
            }
            swap(m_pVect[i], m_pVect[minIndex]);
        }
    }

    int Partition(int low, int high) {
        int pivot = m_pVect[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (m_pVect[j] < pivot) {
                i++;
                swap(m_pVect[i], m_pVect[j]);
            }
        }
        swap(m_pVect[i + 1], m_pVect[high]);
        return i + 1;
    }

    void QuickSort(int low, int high) {
        if (low < high) {
            int pi = Partition(low, high);
            QuickSort(low, pi - 1);
            QuickSort(pi + 1, high);
        }
    }

    void QuickSort() {
        QuickSort(0, m_nCount - 1);
    }

    void InsertionSort() {
        for (int i = 1; i < m_nCount; i++) {
            int key = m_pVect[i];
            int j = i - 1;
            while (j >= 0 && m_pVect[j] > key) {
                m_pVect[j + 1] = m_pVect[j];
                j--;
            }
            m_pVect[j + 1] = key;
        }
    }

    int GetCount() const {
        return m_nCount;
    }

    ~CVector() {
        delete[] m_pVect;
    }
};


int main() {
    CVector original;
    original.Insert(10);
    original.Insert(20);
    original.Insert(30);
    original.Insert(5);
    original.Insert(50);
    original.Insert(15);

    cout << "Antes de ordenar: ";
    original.Display();


    CVector selectionSortVector;
    original.CopyTo(selectionSortVector);
    selectionSortVector.SelectionSort();
    cout << "Despues de Selection Sort: ";
    selectionSortVector.Display();


    CVector quickSortVector;
    original.CopyTo(quickSortVector);
    quickSortVector.QuickSort();
    cout << "Despues de Quick Sort: ";
    quickSortVector.Display();


    CVector insertionSortVector;
    original.CopyTo(insertionSortVector);
    insertionSortVector.InsertionSort();
    cout << "Despues de Insertion Sort: ";
    insertionSortVector.Display();

    return 0;
}

