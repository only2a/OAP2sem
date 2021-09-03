#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#define n 100
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int d, min = 0, x, a[n], k, z, y;
    cout << "Компоненты файла fileA –  целые отличные от нуля числа: х, y1,... yn. Вывести на экран два члена этой последовательности, среднее арифметическое которых ближе всего к х" << endl;
    FILE* A, * B;
    cout << "Введите размер послеледовательности:";
    cin >> k;
    fopen_s(&A, "A.txt", "w");
    for (int i = 0; i < k; i++)
    {
        x = (rand() %  10);
        fprintf(A, "%d ", x);
        a[i] = x;
    }
    fclose(A);
    cout << "Введите x:";
    cin >> d;
    fopen_s(&A, "A.txt", "r");
    fopen_s(&B, "B.txt", "w");
    for (int i = 0; i < k-1; i++)
    {
        if ((abs((a[i] + a[i + 1]) / 2 - d)==0)||((abs((a[i] + a[i + 1]) / 2 - d)>0) &&(abs((a[i] + a[i + 1]) / 2 - d)<1))) {
            min = i;
            z = a[min];
            y = a[min + 1];
        }
    }
    fprintf(B, "%d ", z);
    fprintf(B, "%d ", y);
    fclose(A);
    fclose(B);

    return 0;
}
