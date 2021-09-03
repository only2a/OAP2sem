
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <time.h>

using namespace std;
int main(){
    setlocale(LC_CTYPE, "Russian");
    
    int a1, a2, b1, b2, sum = 0, num1, num2;
    int g[100][100], z[100][100], l[100][100],s,d;
      FILE* A, * B, * C;        
      cout << "Даны два файла вещественных чисел с именами fA и fB, содержащие элементы прямоугольных матриц M1 и M2 по строкам, причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы. Создать файл той же структуры с именем fC, содержащий произведение матриц M1·M2. Если матрицы M1 и M2 нельзя перемножать, то оставить файл fC пустым." << endl;
      cout << "Введите размеры первой матрицы: ";
      cin >> a1 >> a2;
      cout << "Введите размеры второй матрицы: ";
      cin >> b1 >> b2;

      if (a2 == b1)
      {
          fopen_s(&A, "A.txt", "w");
          for (int i = 0; i < a1; i++)
          {
              for (int j = 0; j < a2; j++)
              {
                  if (i == 0 && j == 0)
                  {
                      fprintf(A, "%d ", a2);
                      fprintf(A, "\n");
                  }
                  s = rand() % 10;
                  fprintf(A, "%d ",s);
                  g[i][j] = s;
              }
              fprintf(A, "\n");
          }
          fclose(A);

          fopen_s(&B, "B.txt", "w");
          for (int i = 0; i < b1; i++)
          {
              for (int j = 0; j < b2; j++)
              {
                  if (i == 0 && j == 0)
                  {
                      fprintf(B, "%d ", b2);
                      fprintf(B, "\n");
                  }
                  d = rand() % 10;
                  fprintf(B, "%d ", d);
                  z[i][j] = d;
              }
              fprintf(B, "\n");
          }
          fclose(B);

          fopen_s(&A, "A.txt", "r");
          fopen_s(&B, "B.txt", "r");
          fopen_s(&C, "C.txt", "w");
          fprintf(C, "%d ", b2);
          fprintf(C, "\n");
          for (int i = 0; i < a1; i++)
          {
              for (int j = 0; j < b2; j++)
              {
                  fseek(A, 0, SEEK_SET);
                  for (int q = 0; q < i *a1 + 1; q++)
                  {
                      fscanf_s(A, "%d", &num1);
                  }

                  for (int k = 0; k < b1; k++)
                  {
                      fseek(B, 0, SEEK_SET);
                      for (int q = 0; q < k * b2 + j + 1 ; q++)
                      {
                          fscanf_s(B, "%d", &num1);
                      }

                      fscanf_s(A, "%d", &num1);
                      fscanf_s(B, "%d", &num2);
                      sum += g[i][k]*z[k][j];
                  }
                  fprintf(C, "%d ", sum);
                  sum = 0;
              }
              fprintf(C, "\n");
          }
          fclose(C);
      }
      else
      {
          cout << "Данные матрицы нельзя перемножить" << endl;
          fopen_s(&A, "A.txt", "w");
          fopen_s(&B, "B.txt", "w");
      }
                  fclose(A);
                  fclose(B);
         return 0;}

