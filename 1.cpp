#include <iostream>
using namespace std;
void Swap(int* a, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = *(a + i);
        *(a + i) = *(a + i + 1);
        *(a + i + 1) = temp;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 10; 
    int a[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 

    cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    Swap(a, size);
    cout << "Массив после замены: ";
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}