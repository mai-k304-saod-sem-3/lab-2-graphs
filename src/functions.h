#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define inf 100000

const int N = 10;

using namespace std;

// Методы печати
void printMatrixStatic(int matrix[][N]); // Печать статической матрицы
void printMatrix(int** matrix); // Печать динамической матрицы

// Методы для построения таблиц
void tableHeader(); // Заголовок таблицы
void tableValues(); // Значения таблицы
void tableCenter(); // Центр таблицы
void tableBottom(); // Низ таблицы

// Методы алгоритмов
void floydWarshall(int*** shotest); // Алгоритм Флойда-Уоршелла
void kruskal(int A[][N], int*** B, int  R[][3]); // Алгоритм Краскала

#endif