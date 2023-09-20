#include <iostream>

// Функция для проверки, является ли число простым
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Функция для удаления простых чисел из массива и возврата нового массива
int* removePrimes(int* arr, int& size) {
    int newSize = 0; // Новый размер массива без простых чисел

    // Считаем, сколько элементов не являются простыми
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    // Создаем новый массив без простых чисел
    int* newArr = new int[newSize];
    int newIndex = 0;

    // Копируем элементы, которые не являются простыми, в новый массив
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[newIndex] = arr[i];
            newIndex++;
        }
    }

    // Обновляем размер
    size = newSize;

    // Освобождаем память, выделенную для исходного массива
    delete[] arr;

    return newArr;
}

int main() {
    int size = 10;
    int* arr = new int[size] {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // Вызываем функцию для удаления простых чисел
    int* result = removePrimes(arr, size);

    // Выводим новый массив
    std::cout << "Массив без простых чисел: ";
    for (int i = 0; i < size; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память, выделенную для нового массива
    delete[] result;

    return 0;
}