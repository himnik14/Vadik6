#include <iostream>
#include <windows.h>
#include <math.h>
#include <clocale>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int A, J;
    double a = INT_MAX,b;
    cout << "Введите количество строк в матрице: " << "\n";
    cin >> A;
    cout << "Введите количество столбцов в матрице: " << "\n";
    cin >> J;
    double** arr = new double* [A]; // Создаём динамический массив дабл формата
    for (int i = 0; i < A; i++) { // Выделяем память для столбцов матрицы
        arr[i] = new double[J];
    }
    srand(time(0)); // Указываем диапазон между генерациями случайных чисел
    for (int i = 0; i < A; i++) { // Заполняем массив случайными числами с одним знаком после запятой
        for (int j = 0; j < J; j++) {
            arr[i][j] = rand() % 10 / 1.25;
        }
    }
    cout << "Матрица A: " << "\n";
    for (int i = 0; i < A; i++) { // Выводим полученную матрицу
        for (int j = 0; j < J; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl; // Начало с новой строки
    }
    int c = 0; // Счётчик для записи минимумов в массив arr1
    double* arr1 = new double[A]; // Объявляем динамеский массив для записи в него минимумов каждой строки 
    for (int i = 0; i < A; i++) { // Ищем минимум в каждой строке матрицы путёс сравнивания каждого элемента строки с максимумом значений INT
        for (int j = 0; j < J; j++) {
            if (arr[i][j] < a) {
                a = arr[i][j]; // 
            }
        }
        arr1[c] = a; // Записываем в массив минимум строки i
        a = INT_MAX;
        c += 1;
    }
    for (int i = 0; i < A; i++) { // Выводим минимум каждой строки 
        cout << "Минимальный элемент в " << i + 1 << " строке: " << arr1[i] << "\n";
    }
}