#include <iostream>
#include <iomanip>
#include <algorithm>

#include "functions.h"

using namespace std;

int matrixFloydWarshall[N][N] = { // Матрица для работы с алгоритмом Флойда-Уоршелла
    {    0,   3,   1,   2, inf, inf, inf, inf, inf, inf},
    {  inf,   0, inf, inf,   4, inf, inf, inf, inf, inf},
    {  inf,   1,   0, inf, inf,   5,  10,  10, inf, inf},
    {  inf, inf,   1,   0, inf,   2, inf, inf, inf, inf},
    {  inf, inf,   2, inf,   0, inf,   1, inf,   2, inf},
    {  inf, inf, inf, inf,   5,   0, inf,   5, inf,   6},
    {  inf, inf, inf, inf, inf, inf,   0,   3, inf, inf},
    {  inf, inf, inf, inf, inf, inf, inf,   0, inf,   1},
    {  inf, inf, inf, inf, inf, inf,   1, inf,   0, inf},
    {  inf, inf, inf, inf, inf, inf, inf, inf, inf,   0}
};

int matrixKruskal[N][N] = { // Матрица для работы с алгоритмом Краскала
    {    0,   3,   1,   2, inf, inf, inf, inf, inf, inf},
    {    3,   0,   1, inf,   4, inf, inf, inf, inf, inf},
    {    1,   1,   0,   1,   2,   5,  10,  10, inf, inf},
    {    2, inf,   1,   0, inf,   2, inf, inf, inf, inf},
    {  inf,   4,   2, inf,   0,   5,   1, inf,   2, inf},
    {  inf, inf,   5,   2,   5,   0, inf,   5, inf,   6},
    {  inf, inf,  10, inf,   1, inf,   0,   3,   1, inf},
    {  inf, inf,  10, inf, inf,   5,   3,   0, inf,   1},
    {  inf, inf, inf, inf,   2, inf,   1, inf,   0, inf},
    {  inf, inf, inf, inf, inf,   6, inf,   1, inf,   0}
};

int main() {
    int menu; // Выбор действия
    cout << "Enter the number:" << endl
        << "1 -- Floyd-Warshall algorithm" << endl
        << "2 -- Kruskal algorithm" << endl;
    cout << "Stage: ";
    cin >> menu; // Ввод пользовательского действия
    if (menu == 1) { // Алгоритм Флойда-Уоршелла
        // Инициализация двумерных динамичeских массивов 10х10
        int** shortest = new int* [N];
        for (int i = 0; i < N; i++) shortest[i] = new int[N]();
        // Заполнение массивов
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                shortest[i][j] = matrixFloydWarshall[i][j]; // Копирование с матрицы смежностей
            }
        }
        // Печать массива смежностей
        cout << "Initial Adjacency Matrix:" << endl;
        printMatrixStatic(matrixFloydWarshall);

        // Печать матрицы Shortest
        cout << "Before:" << endl;
        printMatrix(shortest);

        floydWarshall(&shortest); // Алгоритм Флойда-Уоршелла

        // Печать матрицы Shortest 
        cout << "After:" << endl;
        cout << "Shortest" << endl;
        printMatrix(shortest); 
    }
    else { // Алгоритм Крускала
        // Инициализация двумерных динамичeского массива 10х10
        int** ostov = new int* [N];
        for (int i = 0; i < N; i++) ostov[i] = new int[N]();

        int R[N - 1][3]; // Массив для записи ребер и их веса

        // Заполнение массива
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // Копирование с матрицы смежностей
                if (matrixKruskal[i][j] == inf)
                    ostov[i][j] = 0;
                else
                    ostov[i][j] = matrixKruskal[i][j];
            }
        }

        cout << "Source graph matrix:" << endl;
        printMatrixStatic(matrixKruskal);

        cout << "Ostov matrix before algorithm:" << endl;
        printMatrix(ostov);

        cout << "Least Kruskal weight spanning tree:" << endl;
        kruskal(matrixKruskal, &ostov, R);

        cout << "Adjacency matrix of graph with spanning tree:" << endl;
        printMatrix(ostov);
    }
}