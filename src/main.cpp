#include <iostream>
#include <iomanip>
#include <algorithm>

#include "functions.h"

using namespace std;

//int Matrix_Smegh[N][N] =
//{
//    {   0,   3,   4,   2, inf, inf, inf, inf, inf, inf },
//    { inf,   0, inf, inf, inf,   3, inf, inf, inf, inf },
//    { inf, inf,   0, inf, inf,   6, inf, inf, inf, inf },
//    { inf, inf, inf,   0,   5,   2, inf, inf, inf, inf },
//    { inf, inf, inf, inf,   0, inf,   6, inf,  12, inf },
//    { inf, inf, inf, inf,   1,   0,  12,   7, inf, inf },
//    { inf, inf, inf, inf, inf, inf,   0, inf, inf,   4 },
//    { inf, inf, inf, inf, inf, inf, inf,   0, inf,   3 },
//    { inf, inf, inf, inf, inf, inf, inf,   6,   0,  11 },
//    { inf, inf, inf, inf, inf, inf, inf, inf, inf,   0 }
//};

int Matrix_Floyd[N][N] =
{
    {    0,   3,   1,   2, inf, inf, inf, inf, inf, inf },
    {  inf,   0, inf, inf,   4, inf, inf, inf, inf, inf },
    {  inf,   1,   0, inf, inf,   5,  10,  10, inf, inf },
    {  inf, inf,   1,   0, inf,   2, inf, inf, inf, inf },
    {  inf, inf,   2, inf,   0, inf,   1, inf,   2, inf },
    {  inf, inf, inf, inf,   5,   0, inf,   5, inf,   6 },
    {  inf, inf, inf, inf, inf, inf,   0,   3, inf, inf },
    {  inf, inf, inf, inf, inf, inf, inf,   0, inf,   1 },
    {  inf, inf, inf, inf, inf, inf,   1, inf,   0, inf },
    {  inf, inf, inf, inf, inf, inf, inf, inf, inf,   0 }
};

int Matrix_Crusc[N][N]
{
    {    0,   3,   1,   2, inf, inf, inf, inf, inf, inf },
    {    3,   0,   1, inf,   4, inf, inf, inf, inf, inf },
    {    1,   1,   0,   1,   2,   5,  10,  10, inf, inf },
    {    2, inf,   1,   0, inf,   2, inf, inf, inf, inf },
    {  inf,   4,   2, inf,   0,   5,   1, inf,   2, inf },
    {  inf, inf,   5,   2,   5,   0, inf,   5, inf,   6 },
    {  inf, inf,  10, inf,   1, inf,   0,   3,   1, inf },
    {  inf, inf,  10, inf, inf,   5,   3,   0, inf,   1 },
    {  inf, inf, inf, inf,   2, inf,   1, inf,   0, inf },
    {  inf, inf, inf, inf, inf,   6, inf,   1, inf,   0 }
};

//int Matrix_Smegh[N][N] =
//{
//    {    0, inf,   2, inf, inf, inf, inf, inf, inf, inf },
//    {    4,   0, inf, inf, 5,   inf, inf, inf, inf, inf },
//    {  inf,   1,   0, inf, inf, inf, inf, inf, inf, inf },
//    {  inf, inf,   3,   0, inf, inf, inf, inf, inf, inf },
//    {  inf, inf, inf, inf,   0,   5, inf,   6, inf, inf },
//    {    8, inf, inf, inf, inf,   0,   1, inf, inf, inf },
//    {  inf, inf, inf, inf,   7, inf,   0, inf, inf,   3 },
//    {  inf, inf, inf,   4, inf, inf, inf,   0,   5, inf },
//    {  inf, inf, inf, inf,   2, inf, inf, inf,   0, inf },
//    {  inf, inf, inf, inf, inf, inf, inf, inf,   1,   0 }
//};

int main()
{
    int menu; // Выбор действия

    cout << "Enter the number:" << endl
         << "1 -- Floyd-Warshall algorithm" << endl
         << "2 -- Kruskal's (Kruskal's) algorithm" << endl;
    cout << "Stage: "; cin >> menu;

    //_____________________________ЭТАП 1__________________________________
    if (menu == 1) // Алгоритм Флойда_Уоршелла
    {
        // Инициализация двумерных динамичeских массивов 10х10
        int** Shortest = new int* [N];
        for (int i = 0; i < N; i++) Shortest[i] = new int[N]();

        int** Pred = new int* [N];
        for (int i = 0; i < N; i++) Pred[i] = new int[N]();

        // Заполнение массивов
        for (int u = 0; u < N; u++)
        {
            for (int v = 0; v < N; v++)
            {
                Shortest[u][v] = Matrix_Floyd[u][v]; // Копирование с матрицы смежностей
                if (Matrix_Floyd[u][v] < inf)
                    Pred[u][v] = u;
                else
                    Pred[u][v] = -2;
            }
        }

        // Печать массива смежностей
        cout << "\n\t\tInitial Adjacency Matrix:" << endl;
        Print_Smegh(Matrix_Floyd);
        BotBorder();

        cout << "\t\t\tBefore:" << endl << endl;
        Print_Pred(Pred); // Печать матрицы Pred
        Print_Help_Matr(Shortest); // Печать матрицы Shortest
        BotBorder();

        Floyd_Warshall(&Shortest, &Pred); // Алгоритм Флойда-Уоршелла                                                                                        
        BotBorder();

        cout << "\t\t\tAfter:" << endl << endl;                                                             
        Print_Pred(Pred); // Печать матрицы Pred      
        Print_Help_Matr(Shortest); // Печать матрицы Shortest  
        BotBorder();

        Way(Pred); // Функция нахождения пути
        BotBorder();

    }
    //_____________________________ЭТАП 2__________________________________
    else // Алгоритм Крускала
    {
        // Инициализация двумерных динамичeского массива 10х10
        int** Ostov = new int* [N];
        for (int i = 0; i < N; i++) Ostov[i] = new int[N]();

        int R[N - 1][3]; // Массив для записи ребер и их веса

        // Заполнение массива
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // Копирование с матрицы смежностей
                if (Matrix_Crusc[i][j] == inf)
                    Ostov[i][j] = 0;
                else
                    Ostov[i][j] = Matrix_Crusc[i][j];
            }
        }

        cout << "\t\tSource graph matrix:" << endl;
        Print_Smegh(Matrix_Crusc);
        BotBorder();

        cout << "\t\tOstov matrix before algorithm:" << endl;
        Print_Help_Matr(Ostov);
        BotBorder();

        cout << "\nLeast Kruskal weight spanning tree:";
        Crusc(Matrix_Crusc, &Ostov, R);
        BotBorder();

        cout << "\nAdjacency matrix of graph with spanning tree:" << endl;
        Print_Help_Matr(Ostov);
        BotBorder();
    }
}