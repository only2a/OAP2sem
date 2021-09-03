// 12_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <time.h>
#define n 100

using namespace std;
//int minim(int a[] , int k) {
//    int min = 0,c;
//    for (int i = 0; i < k; i++) {
//        if (a[i] < a[min]) min = i;
//        c = a[min];
//    }
//    return c;
//}
int main() {
    setlocale(LC_CTYPE, "Russian");
    int  min = 0, x, a[n],b[n],c[n],d[n],k=7;
    cout << "Компоненты файла fileA –  целые отличные от нуля числа: х, y1,... yn. Вывести на экран два члена этой последовательности, среднее арифметическое которых ближе всего к х" << endl;
    FILE* A, * B, *C, *D;
    cout << "Введите размер послеледовательности:";
    cin >> k;
    //fopen_s(&A, "A.txt", "w");
    //for (int i = 0; i < k; i++)
    //{
    //    x = (rand() % 10);
    //    fprintf(A, "%d ", x);
    //    
    //}
    //fclose(A);

    //    fopen_s(&B, "B.txt", "w");
    //    for (int i = 0; i < k; i++)
    //    {
    //        x = (rand() % 10);
    //        fprintf(A, "%d ", x);
    //        
    //    }
    //    fclose(B);
    //    fopen_s(&C, "C.txt", "w");
    //    for (int i = 0; i < k; i++)
    //    {
    //        x = (rand() % 10);
    //        fprintf(A, "%d ", x);
    //     
    //    }
    //    fclose(C);
        fopen_s(&A, "A.txt", "r");
        fopen_s(&B, "B.txt", "r");
        fopen_s(&C, "C.txt", "r");
        fopen_s(&D, "D.txt", "w");
        int mina = 0, minb = 0, minc = 0;

            for (int i = 0; i < k; i++) {
                fscanf(A, "%d", &a[i]);
                fscanf(B, "%d", &b[i]);
                fscanf(C, "%d", &c[i]);
                d[i] = a[i]; d[i + 1] = b[i]; d[i + 2] = c[i];
                if (d[i] < d[min]) min = i;
                fprintf(D, " %d", d[min]);
                d[i] = 0;
               
            }
           
          

           
    
 
    fclose(A);
    fclose(B);
    fclose(C);
    fclose(D);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
