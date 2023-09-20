//6. Создать функцию, позволяющую удалять элементы блока, начиная с последовательного индекса массива.
#include <iostream>
#include <vector>

// Функция для удаления блока элементов из массива, начиная с указанного индекса
void removeBlock(std::vector<int>& array, int index, int blockSize) {
    if (index < 0 || index >= array.size() || blockSize <= 0) {
        std::cerr << "Некорректные параметры для удаления блока." << std::endl;
        return;
    }

    // Используем метод erase для удаления элементов из массива
    array.erase(array.begin() + index, array.begin() + index + blockSize);
}

int main() {
    std::vector<int> myArray = {1, 2, 3, 4, 5, 6, 7, 8};
    int removeIndex = 2; // Произвольный индекс начала удаления
    int blockSize = 3;   // Размер блока для удаления

    // Вызываем функцию для удаления блока из массива
    removeBlock(myArray, removeIndex, blockSize);

    // Выводим обновленный массив
    for (int element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}