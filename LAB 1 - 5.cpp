//Создать функцию, позволяющую вставлять блок элементов, начиная с произвольного индекса массива.//
#include <iostream>
using namespace std;
void insertBlock(int*& arr, int& size, int* block, int blockSize, int index) {
    if (index < 0 || index > size) {
        cout << "Неверный индекс вставки!" << endl;
        return;
    }

    int* temp = new int[size + blockSize];

    // Копируем элементы до индекса
    for (int i = 0; i < index; i++) {
        temp[i] = arr[i];
    }

    // Вставляем блок
    for (int i = 0; i < blockSize; i++) {
        temp[index + i] = block[i];
    }

    // Копируем оставшуюся часть
    for (int i = index; i < size; i++) {
        temp[blockSize + i] = arr[i];
    }

    delete[] arr; // Освобождаем память, выделенную под старый массив
    arr = temp;   // Обновляем указатель
    size += blockSize; // Обновляем размер массива
}

int main() {
    int size = 5;
    int* arr = new int[size] {1, 2, 3, 4, 5};

    int blockSize = 3;
    int* block = new int[blockSize] {6, 7, 8};

    int index = 3; // вставить блок начиная с индекса 3

    insertBlock(arr, size, block, blockSize, index);

    cout << "Массив после вставки блока: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    delete[] block; 

    return 0;
}