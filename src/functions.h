#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define inf 100000

const int N = 10;

using namespace std;

// Процедуры печати
void Print_Pred(int** Array);
void Print_Smegh(int Matrix[N][N]);
void Print_Help_Matr(int** Shortest);

// Вспомогательные методы
void Way(int **Pred);
int  mini(int value1, int value2);
void DeleteMas(int* Array);
void BotBorder();

// Методы для построения таблиц
void Shapka();
void Numberacya();
void Mid();
void Niz();

// Методы алгоритмов
void Floyd_Warshall(int ***Shotest, int ***Pred); // Алгоритм Флойда-Уоршелла
void Crusc(int A[][N], int***  B, int  R[][3]); // Алгоритм Крускала


#endif