#include <iostream>
#include <iomanip>
#include <algorithm>

#include "functions.h"

using namespace std;

//int Matrix_Smegh[N][N] =
//{
//    //           1    2    3    4    5    6    7    8    9   10
//    /*x1*/   {   0,   3,   4,   2, inf, inf, inf, inf, inf, inf },
//    /*x2*/   { inf,   0, inf, inf, inf,   3, inf, inf, inf, inf },
//    /*x3*/   { inf, inf,   0, inf, inf,   6, inf, inf, inf, inf },
//    /*x4*/   { inf, inf, inf,   0,   5,   2, inf, inf, inf, inf },
//    /*x5*/   { inf, inf, inf, inf,   0, inf,   6, inf,  12, inf },
//    /*x6*/   { inf, inf, inf, inf,   1,   0,  12,   7, inf, inf },
//    /*x7*/   { inf, inf, inf, inf, inf, inf,   0, inf, inf,   4 },
//    /*x8*/   { inf, inf, inf, inf, inf, inf, inf,   0, inf,   3 },
//    /*x9*/   { inf, inf, inf, inf, inf, inf, inf,   6,   0,  11 },
//    /*x10*/  { inf, inf, inf, inf, inf, inf, inf, inf, inf,   0 }
//};

int Matrix_Floyd[N][N] =
{
    //           1    2    3    4    5    6    7    8    9   10
    /*x1*/   {    0,   3,   1,   2, inf, inf, inf, inf, inf, inf },
    /*x2*/   {  inf,   0, inf, inf,   4, inf, inf, inf, inf, inf },
    /*x3*/   {  inf,   1,   0, inf, inf,   5,  10,  10, inf, inf },
    /*x4*/   {  inf, inf,   1,   0, inf,   2, inf, inf, inf, inf },
    /*x5*/   {  inf, inf,   2, inf,   0, inf,   1, inf,   2, inf },
    /*x6*/   {  inf, inf, inf, inf,   5,   0, inf,   5, inf,   6 },
    /*x7*/   {  inf, inf, inf, inf, inf, inf,   0,   3, inf, inf },
    /*x8*/   {  inf, inf, inf, inf, inf, inf, inf,   0, inf,   1 },
    /*x9*/   {  inf, inf, inf, inf, inf, inf,   1, inf,   0, inf },
    /*x10*/  {  inf, inf, inf, inf, inf, inf, inf, inf, inf,   0 }
};

int Matrix_Crusc[N][N]
{
    //           1    2    3    4    5    6    7    8    9   10
    /*x1*/   {    0,   3,   1,   2, inf, inf, inf, inf, inf, inf },
    /*x2*/   {    3,   0,   1, inf,   4, inf, inf, inf, inf, inf },
    /*x3*/   {    1,   1,   0,   1,   2,   5,  10,  10, inf, inf },
    /*x4*/   {    2, inf,   1,   0, inf,   2, inf, inf, inf, inf },
    /*x5*/   {  inf,   4,   2, inf,   0,   5,   1, inf,   2, inf },
    /*x6*/   {  inf, inf,   5,   2,   5,   0, inf,   5, inf,   6 },
    /*x7*/   {  inf, inf,  10, inf,   1, inf,   0,   3,   1, inf },
    /*x8*/   {  inf, inf,  10, inf, inf,   5,   3,   0, inf,   1 },
    /*x9*/   {  inf, inf, inf, inf,   2, inf,   1, inf,   0, inf },
    /*x10*/  {  inf, inf, inf, inf, inf,   6, inf,   1, inf,   0 }
};

//int Matrix_Smegh[N][N] =
//{
//    //           1    2    3    4    5    6    7    8    9   10
//    /*x1*/   {    0, inf,   2, inf, inf, inf, inf, inf, inf, inf },
//    /*x2*/   {    4,   0, inf, inf, 5,   inf, inf, inf, inf, inf },
//    /*x3*/   {  inf,   1,   0, inf, inf, inf, inf, inf, inf, inf },
//    /*x4*/   {  inf, inf,   3,   0, inf, inf, inf, inf, inf, inf },
//    /*x5*/   {  inf, inf, inf, inf,   0,   5, inf,   6, inf, inf },
//    /*x6*/   {    8, inf, inf, inf, inf,   0,   1, inf, inf, inf },
//    /*x7*/   {  inf, inf, inf, inf,   7, inf,   0, inf, inf,   3 },
//    /*x8*/   {  inf, inf, inf,   4, inf, inf, inf,   0,   5, inf },
//    /*x9*/   {  inf, inf, inf, inf,   2, inf, inf, inf,   0, inf },
//    /*x10*/  {  inf, inf, inf, inf, inf, inf, inf, inf,   1,   0 }
//};

int main()
{
    setlocale(LC_ALL, "Russian");
    //system("color F0");

    int Menu;

    cout << " Введите число " << endl
         << " 1 -- Алгоритм Флойда-Уоршелла " << endl
         << " 2 -- Алгоритм Крускала (Краскала) " << endl;
    cout << " Этап: "; cin >> Menu;

    //_____________________________ЭТАП 1__________________________________
    if (Menu == 1)      // Алгоритм Флойда_Уоршелла
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
                Shortest[u][v] = Matrix_Floyd[u][v];         // Копирование с матрицы смежностей
                if (Matrix_Floyd[u][v] < inf)
                    Pred[u][v] = u;
                else
                    Pred[u][v] = -2;
            }
        }

        // Печать массива смежностей
        cout << "\n\t\tИсходная матрица смежности" << endl;
        Print_Smegh(Matrix_Floyd);
        BotBorder();

        cout << "\t\t\tБыло:" << endl << endl;
        Print_Pred(Pred);                                                       // Печать матрицы Pred
        Print_Help_Matr(Shortest);                                       // Печать матрицы Shortest
        BotBorder();

        Floyd_Warshall(&Shortest, &Pred);                         // Алгоритм Флойда-Уоршелла                                                                                        
        BotBorder();

        cout << "\t\t\tСтало:" << endl << endl;                                                             
        Print_Pred(Pred);                                                       // Печать матрицы Pred      
        Print_Help_Matr(Shortest);                                       // Печать матрицы Shortest  
        BotBorder();

        Way(Pred);                                                              // Функция нахождения пути
        BotBorder();

    } // if
    //_____________________________ЭТАП 2__________________________________
    else // Алгоритм Крускала
    {
        // Инициализация двумерных динамичeского массива 10х10
        int** Ostov = new int* [N];
        for (int i = 0; i < N; i++) Ostov[i] = new int[N]();

        int R[N - 1][3];            // Массив для записи ребер и их веса

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
            } // for j
        } // for i

        cout << "\t\tИсходная матрица графа:" << endl;
        Print_Smegh(Matrix_Crusc);
        BotBorder();

        cout << "\t\tМатрица Ostov до алгоритма:" << endl;
        Print_Help_Matr(Ostov);
        BotBorder();

        cout << "\n Остовное  дерево  наименьшего  веса  по  Крускалу";
        Crusc(Matrix_Crusc, &Ostov, R);
        BotBorder();

        cout << "\n  Матрица  смежности  графа  с остовным  деревом : " << endl;
        Print_Help_Matr(Ostov);
        BotBorder();
    }
} // main()