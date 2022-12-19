#include <iostream>
#include <iomanip>
#include <algorithm>

#include "functions.h"

using namespace std;

// Метод печати
void printMatrixStatic(int matrix [][N]) { // Печать статической матрицы
    tableHeader(); // Заголовок таблицы
    tableValues(); // Значения таблицы
    for (int i = 0; i < N; i++) {
        tableCenter(); // Центр таблицы
        cout << setfill(' ') << char(179) << setw(4) << i + 1 << char(179);
        for (int j = 0; j < N; j++) {
            switch (matrix[i][j]) {
                case -2: {
                    cout << setw(4) << "NULL" << char(179);
                    break;
                }
                case inf: {
                    cout << setw(4) << "NULL" << char(179);
                    break;
                }
                default: {
                    cout << setw(4) << matrix[i][j] << char(179);
                    break;
                }
            }
        }
    }
    tableBottom(); // Низ таблицы
    cout << endl;
}

void printMatrix(int** matrix) { // Печать динамической матрицы
    tableHeader(); // Заголовок таблицы
    tableValues(); // Значения таблицы
    for (int i = 0; i < N; i++) {
        tableCenter(); // Центр таблицы
        cout << setfill(' ') << char(179) << setw(4) << i + 1 << char(179);
        for (int j = 0; j < N; j++) {
            switch (matrix[i][j]) {
                case -2: {
                    cout << setw(4) << "NULL" << char(179);
                    break;
                }
                case 100000: {
                    cout << setw(4) << "NULL" << char(179);
                    break;
                }
                default: {
                    cout << setw(4) << matrix[i][j] << char(179);
                    break;
                }
            }
        }
    }
    tableBottom(); // Низ таблицы
    cout << endl;
}

// Методы для построения таблиц
void tableHeader() { // Заголовок таблицы
    cout << setfill(char(196)) << char(218) << setw(5); // "┌───────────"
    for (int i = 0; i < N; i++)
        cout << char(194) << setw(5); // "┬───────────"
    cout << char(191) << endl; // "┐"
}
void tableValues() { // Значения таблицы
    cout << setfill(' ');
    cout << char(179) << setw(4) << " "; // "│  "
    for (int i = 1; i <= N; i++)
        cout << char(179) << setw(4) << i; // "│ 1"
    cout << char(179); // "│"
}
void tableCenter() { // Центр таблицы
    cout << endl << setfill(char(196))
        << char(195) << setw(5);
    for (int i = 0; i < N; i++)
        cout << char(197) << setw(5); // "├───────────"
    cout << char(180) << endl; // "┤"
}
void tableBottom() { // Низ таблицы
    cout << endl << setfill(char(196))
        << char(192) << setw(5); // "└───────────"
    for (int i = 0; i < N; i++)
        cout << char(193) << setw(5); // "┴───────────"
    cout << char(217) << endl; // "┘"
}

// Методы алгоритмов
void floydWarshall(int*** shortest) { // Алгоритм Флойда-Уоршелла
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((*shortest)[i][j] >(*shortest)[i][k] + (*shortest)[k][j]) {
                    (*shortest)[i][j] = (*shortest)[i][k] + (*shortest)[k][j];
                }
            }
        }
        cout << "x = " << k + 1 << endl;
        printMatrix(*shortest); // Печать матрицы Shortest 
    }
}

void kruskal(int A[][N], int*** B, int  R[][3]) { // Алгоритм Краскала
    int k; // Счётчик
    int xmin; // Индекс ребра
    int min; // Минимальный вес
    int En = 0;
    int Cn = N; // Количество узлов
    int C[N]; // Для избежания повторов
    struct edge {
        int out;
        int in;
        int weight;
    };
    edge* Edge = new edge[N * (N - 1) / 2];
    for (int i = 0; i < Cn; i++)    // Заполнение массива
        C[i] = i;
    for (int i = 0; i < N; i++) {     // Заполнения матрицы -1
        for (int j = 0; j < N; j++) {
            (*B)[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if ((A[i][j]) && (A[i][j] != inf)) { // Если не 0 и не бесконечность 
                Edge[En].out = i; // Заполнение структуры
                Edge[En].weight = A[i][j];
                Edge[En++].in = j;
            }
        }
    }
    cout << "Edges of the original graph: "; // Вывод ребер
    cout << En << endl;
    for (int i = 0; i < En; i++) {
        cout << " " << Edge[i].out + 1 << " -- "
            << Edge[i].in + 1 << " = "
            << Edge[i].weight << endl;

    }
    while (Cn >= 0) {
        min = inf;
        for (int i = 0; i < En; i++) {
            if ((Edge[i].weight < min) && (C[Edge[i].out] != C[Edge[i].in])) {
                xmin = i; // Находит индекс минимального ребра
                min = Edge[i].weight; // Находит вес минимального ребра
            }
        }
        int u = Edge[xmin].out;
        int v = Edge[xmin].in;
        int weight = Edge[xmin].weight;
        (*B)[v][u] = (*B)[u][v] = weight; // Вставляет в матрицу
        C[u] = C[v] = std::min(C[u], C[v]);
        Cn--;
        cout << "Cn: " << Cn << endl
            << "Added " << Edge[xmin].out + 1 << " -- "
            << Edge[xmin].in + 1 << " = " << Edge[xmin].weight << endl;
        printMatrix((*B));
        for (int i = 0; i < N; i++)
            cout << " " << i + 1 << ": " << C[i] << endl;
    }
    k = 0;
    int Sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if ((*B)[i][j] > 0) {
                R[k][0] = i;
                R[k][1] = j;
                R[k++][2] = (*B)[i][j];
                cout << " " << R[k - 1][0] + 1 << " -- "
                    << R[k - 1][1] + 1 << " = " << R[k - 1][2] << endl;
                Sum += R[k - 1][2];
            }
        }
    }
    cout << "Total weight: " << Sum << endl;
}