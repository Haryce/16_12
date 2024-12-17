#include <iostream>
using namespace std;
void Mas(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 5; //размер массива b
    const int m = 6; //размер массива a
    int A[n] = { 1, 2, 3, 4, 5 };
    int B[m] = { 4, 5, 6, 7, 8, 9 };
    int* Union = new int[n + m];
    int index = 0;
    for (int i = 0; i < n; ++i) {
        Union[index++] = A[i];
    }
    for (int i = 0; i < m; ++i) {
        Union[index++] = B[i];
    }
    cout << "Все элементы: ";
    Mas(Union, index);
    //массив для oбщих элементов
    int* ARR = new int[n + m];
    int ind = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i] == B[j]) {

                int k;
                for (k = 0; k < ind; ++k) {
                    if (ARR[k] == A[i]) {
                        break;
                    }
                }
                if (k == ind) {
                    ARR[ind++] = A[i];
                }
                break;
            }
        }
    }
    cout << "Общие элементы: ";
    Mas(ARR, ind);

    int* uniqueA = new int[n];
    int uniqueAind = 0;

    for (int i = 0; i < n; ++i) {
        int found = 0;
        for (int j = 0; j < m; ++j) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            uniqueA[uniqueAind++] = A[i];
        }
    }
    cout << "Элементы в A которые не в B: ";
    Mas(uniqueA, uniqueAind);
    //массив для элементов b которые не входят в a
    int* uniqueB = new int[m];
    int uniqueBind = 0;
    for (int i = 0; i < m; ++i) {
        int found = 0;
        for (int j = 0; j < n; ++j) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) { 
            uniqueB[uniqueBind++] = B[i];
        }
    }
    cout << "Элементы в B которые не в A: ";
    Mas(uniqueB, uniqueBind);
    //массив для уникальных элементов
    int* unique = new int[uniqueAind + uniqueBind];
    int obs = 0;
    for (int i = 0; i < uniqueAind; ++i) {
        unique[obs++] = uniqueA[i];
    }
    for (int i = 0; i < uniqueBind; ++i) {
        unique[obs++] = uniqueB[i];
    }
    cout << "Уникальные элементы: ";
    Mas(unique, obs);
}