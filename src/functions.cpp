#include <iostream>
#include <iomanip>
#include <algorithm>

#include "functions.h"

using namespace std;

// Процедуры печати
void Print_Pred(int **Array)
{
    cout << "\t\t\tPred" << endl;
    setlocale(LC_ALL, "C"); //ОТКЛЮЧЕНИЕ РУССКОГО ЯЗЫКА
    Shapka();
    Numberacya();
    for (int u = 0; u < N; u++)
    {
        Mid();
        cout << setfill(' ') << char(179) << setw(4) << u + 1 <<char(179);
        for (int v = 0; v < N; v++)
        {
           if(Array[u][v] > -1)
                cout  << setw(4) << Array[u][v] + 1 << char(179);
            else
                cout << setw(4) << "NULL" << char(179);
        }
    }
    Niz();
    setlocale(LC_ALL, "Rus");
    cout << endl;
}

void Print_Smegh(int Matrix[N][N])
{
    setlocale(LC_ALL, "C"); //ОТКЛЮЧЕНИЕ РУССКОГО ЯЗЫКА
    Shapka();
    Numberacya();
    for (int u = 0; u < N; u++)
    {
        Mid();
        cout << setfill(' ') << char(179) << setw(4) << u + 1 << char(179);
        for (int v = 0; v < N; v++)
        {
            if (Matrix[u][v] == inf)
                cout << setw(4) << "OO" << char(179);
            else
                cout << setw(4) << Matrix[u][v] << char(179);
        }
    }
    Niz();
    setlocale(LC_ALL, "Rus");
    cout << endl;
}
void Print_Help_Matr(int** Matrix)
{
   // cout << "\t\t\tShortest" << endl;
    Shapka();
    Numberacya();
    for (int u = 0; u < N; u++)
    {
        Mid();
        cout << setfill(' ') << char(179) << setw(4) << u + 1 << char(179);
        for (int v = 0; v < N; v++)
        {
            switch (Matrix[u][v])
            {
                case -1:
                {
                    cout << setw(4) << 0 << char(179);
                    break;
                }
                case inf:
                {
                    cout << setw(4) << "OO" << char(179);
                    break;
                }
                default:
                {
                    cout << setw(4) << Matrix[u][v] << char(179);
                    break;
                }
            }
        }
    }
    Niz();
    cout << endl;
}                                  
// Вспомогательные методы
void Way(int** Pred) // Метод вывода пути
{
    int k, m;                                                                        
    cout << " Введите откуда: ";   cin >> k;                                         
    cout << " Введите куда  : ";   cin >> m;                                         
                                                                                     
    cout << " Из " << k << " в " << m << ":" << endl;                                
    int Temp = m - 1;                                                                
    if (Pred[k - 1][Temp] > 0)                                                       
    {                                                                                
        cout << " " << m;                                                            
        while (Temp != k - 1)                                                        
        {                                                                            
            cout << "  <--  " << Pred[k - 1][Temp] + 1;                              
            Temp = Pred[k - 1][Temp];                                                
        }                                                                            
    }                                                                                
    else cout << " Ошибка: Пути из " << k << " в " << m << " нет";                   
    cout << endl;                                                                    
}
int  mini(int value1, int value2) {
    return ((value1 < value2) ? value1 : value2);
}
void DeleteMas(int* Array) {
    delete[] Array;
}
void BotBorder() {
    cout << "________________________________________________________" << endl;
}

// Методы для построения таблиц
void Shapka() {
    cout << setfill(char(196))
        << char(218) << setw(5);            // "┌───────────"
    for (int i = 0; i < N; i++)
        cout << char(194) << setw(5);       // "┬───────────"
    cout << char(191) << endl;              // "┐"
}
void Numberacya() {
    cout << setfill(' ');
    cout << char(179) << setw(4) << " ";    // "│  "
    for (int i = 1; i <= 10; i++)
        cout << char(179) << setw(4) << i;  // "│ 1"
    cout << char(179);                      // "│"

}
void Mid() {
    cout << endl << setfill(char(196))
         << char(195) << setw(5);
    for (int i = 0; i < N ; i++)
        cout << char(197) << setw(5);       // "├───────────"
    cout << char(180) << endl;              // "┤"
}
void Niz() {
    cout << endl << setfill(char(196))
        << char(192) << setw(5);            // "└───────────"
    for (int i = 0; i < N; i++)
        cout << char(193) << setw(5);       // "┴───────────"
    cout << char(217) << endl;              // "┘"
}

// Методы алгоритмов
void Floyd_Warshall(int*** Shortest, int*** Pred) // Алгоритм Флойда-Уоршелла
{
    for (int x = 0; x < 10; x++)
    {                                                                                                            
        for (int u = 0; u < 10; u++)                                                                             
        {                                                                                                        
            for (int v = 0; v < 10; v++)                                                                         
            {                                                                                                    
                if ((*Shortest)[u][x] + (*Shortest)[x][v] < (*Shortest)[u][v])                                   
                {                                                                                                
                    (*Shortest)[u][v] = (*Shortest)[u][x] + (*Shortest)[x][v];                                   
                    (*Pred)[u][v] = (*Pred)[x][v];                                                               
                }                                                                                                
            }                                                                                                    
        }                                                                                                        
        cout << "\t\t\tx = " << x + 1 << endl;                                                                   
        Print_Pred((*Pred));                                                          // Печать матрицы Pred     
        Print_Help_Matr(*Shortest);                                                   // Печать матрицы Shortest 
        cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;                             
    }                                                                                                            
}

void Crusc(int A[][N], int ***B, int  R[][3]) // Алгоритм Крускала
{
    int k;                          // Счётчик
    int xmin;                       // Индекс ребра
    int min;                        // Минимальный вес
    int En = 0;
    int Cn = N;                     // Количество узлов
    int C[N];                       // Для избежания повторов
    //int E[N * (N - 1) / 2][3];
    struct edge
    {
        int out;
        int in;
        int weight;
    };
    edge* Edge = new edge[N * (N - 1) / 2];

    for (int i = 0; i < Cn; i++)    // Заполнение массива
        C[i] = i;

    for (int i = 0; i < N; i++)     // Заполнения матрицы -1
    {
        for (int j = 0; j < N; j++)
        {
            (*B)[i][j] = -1;
        } // for j
    } // for i

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if ((A[i][j]) && (A[i][j] != inf))     // Если не 0 
            {                                      // и не бесконечность 
                Edge[En].out = i;                  // Заполнение структуры
                Edge[En].weight = A[i][j];
                Edge[En++].in = j;
            } // if
        } // for j
    } // for i

    cout << "\n Ребра  исходного  графа : \n";  // Вывод ребер
    cout << En << endl;
    for (int i = 0; i < En; i++)
    {
        cout << " " << Edge[i].out + 1 << " –– "
                    << Edge[i].in + 1  << " = "
                    << Edge[i].weight  << endl;

    } // for i

    while (Cn >= 0)
    {
        min = inf;
        for (int i = 0; i < En; i++)
        {
            if ((Edge[i].weight < min) && (C[Edge[i].out] != C[Edge[i].in]))
            {
                xmin = i;                   // Находит индекс минимального ребра
                min = Edge[i].weight;       // Находит вес минимального ребра
            } // if
        } // for i

        int u = Edge[xmin].out;
        int v = Edge[xmin].in;
        int weight = Edge[xmin].weight;
        (*B)[v][u] = (*B)[u][v] = weight;   // Вставляет в матрицу
        C[u] = C[v] = mini(C[u], C[v]);
        Cn--;

        //печать
        cout << "\t\t\tCn: " << Cn << endl
            << " \t\t Добавил " << Edge[xmin].out + 1 << " –– "
            << Edge[xmin].in + 1 << " = " << Edge[xmin].weight << endl;
        Print_Help_Matr((*B));

        for (int i = 0; i < N; i++)
            cout << " " << i + 1 << ": " << C[i] << endl;
    } // while

    k = 0;
    int Sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if ((*B)[i][j] > 0)
            {
                R[k][0] = i;  R[k][1] = j;
                R[k++][2] = (*B)[i][j];
                cout << " " << R[k - 1][0] + 1 << " -- " 
<< R[k-1][1] + 1 << " = " << R[k - 1][2] << endl;
                Sum += R[k - 1][2];            } // if
        } // for j
    } // for i
    cout << " Суммарный вес: " << Sum << endl;
} // Crusc()