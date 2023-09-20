//Создать функцию, позволяющую добавлять блок элементов в конец массива.
#include <iostream>
using namespace std;

// Функция для добавления блока в конец массива
void addBlock(int*& arr, int& size, int* block, int blockSize) {
    // Создаем новый массив, который больше на blockSize элементов
    int* temp = new int[size + blockSize];

    // Копируем элементы из оригинального массива в новый
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    // Копируем элементы блока в новый массив после элементов из оригинального массива
    for (int i = 0; i < blockSize; i++) {
        temp[size + i] = block[i];
    }

    // Освобождаем память, выделенную для оригинального массива
    delete[] arr;

    // Обновляем указатель на новый массив
    arr = temp;

    // Обновляем размер массива
    size += blockSize;
}

int main() {
    // Инициализируем размер и оригинальный массив
    int size = 5;
    int* arr = new int[size] {1, 2, 3, 4, 5};

    // Инициализируем блок элементов и его размер
    int blockSize = 3;
    int* block = new int[blockSize] {6, 7, 8};

    // Вызываем функцию addBlock для добавления блока в конец массива
    addBlock(arr, size, block, blockSize);

    // Выводим элементы массива после добавления блока
    cout << "Массив после добавления блока: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    // Освобождаем память, выделенную для массива и блока
    delete[] arr;
    delete[] block;

    return 0;
}