#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define inf 100000

const int N = 10;

using namespace std;

// Процедуры печати
void Print_Matr(int** Matrix);
void Static_Print_Matr(int Matrix[][N]);
// Вспомогательные методы
void Way(int** Pred);
int  mini(int value1, int value2);
void BotBorder();

// Методы для построения таблиц
void Shapka();
void Numberacya();
void Mid();
void Niz();

// Методы алгоритмов
void Floyd_Warshall(int*** Shotest); // Алгоритм Флойда-Уоршелла
void Crusc(int A[][N], int*** B, int  R[][3]); // Алгоритм Крускала


#endif