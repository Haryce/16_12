#include <iostream>
using namespace std;
void Sort(int* A, int n, int* B, int m, int* C) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (*(A + i) < *(B + j)) {
            *(C + k) = *(A + i);
            i++;
        }
        else {
            *(C + k) = *(B + j);
            j++;
        }
        k++;
    }
    while (i < n) {
        *(C + k) = *(A + i);
        i++;
        k++;
    }
    while (j < m) {
        *(C + k) = *(B + j);
        j++;
        k++;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 5;
    const int m = 4; 
    int A[n] = { 1, 3, 5, 7, 9 };
    int B[m] = { 2, 4, 6, 8 };
    int C[n + m]; // Массив для хранения результата
    Sort(A, n, B, m, C);

    cout << "Объединенный массив: \n";
    for (int i = 0; i < n + m; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;
    return 0;
}