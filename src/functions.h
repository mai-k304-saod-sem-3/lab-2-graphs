#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define inf 100000

const int N = 10;

using namespace std;

// ��������� ������
void Print_Matr(int** Matrix);
void Static_Print_Matr(int Matrix[][N]);
// ��������������� ������
void Way(int** Pred);
int  mini(int value1, int value2);
void BotBorder();

// ������ ��� ���������� ������
void Shapka();
void Numberacya();
void Mid();
void Niz();

// ������ ����������
void Floyd_Warshall(int*** Shotest); // �������� ������-��������
void Crusc(int A[][N], int*** B, int  R[][3]); // �������� ��������


#endif