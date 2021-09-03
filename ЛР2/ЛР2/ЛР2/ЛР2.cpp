// ЛР2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <time.h>
#define n 100
using namespace std;
int z1_1();
int z1_2();
int z2_1();
int z2_2();
int z5_1();
int z5_2();
int z10_1();
int z10_2();
int main(void)
{
    setlocale(LC_CTYPE, "Russian");
    srand(time(NULL));
    int c;
    do

    {

        cout << endl;

        cout << "Введите" << endl;

        cout << "1) Вар1_1" << endl;
        cout << "2) Вар1_2" << endl;
        cout << "3) Вар2_1" << endl;
        cout << "4) Вар2_2" << endl;
        cout << "5) Вар5_1" << endl;
        cout << "6) Вар5_2" << endl;
        cout << "7) Вар10_1" << endl;
        cout << "8) Вар10_2" << endl;
        cout << "9) Выход" << endl;

        cin >> c;

        switch (c)

        {

        case 1: z1_1(); break;
        case 2: z1_2(); break;
        case 3: z2_1(); break;
        case 4: z2_2(); break;
        case 5: z5_1(); break;
        case 6: z5_2(); break;
        case 7: z10_1(); break;
        case 8: z10_2(); break;

        case 9: break;

        }

    } while (c != 9);

}
int z1_1() {
    setlocale(LC_CTYPE, "Russian");
    cout << "Даны два файла вещественных чисел с именами fA и fB, содержащие элементы прямоугольных матриц M1 и M2 по строкам, причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы. Создать файл той же структуры с именем fC, содержащий произведение матриц M1·M2. Если матрицы M1 и M2 нельзя перемножать, то оставить файл fC пустым."<<endl;
    int a1, a2, b1, b2, sum = 0, num1, num2;
    int g[100][100], z[100][100], l[100][100], s, d;
    FILE* A, * B, * C;
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
                fprintf(A, "%d ", s);
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
                for (int q = 0; q < i * a1 + 1; q++)
                {
                    fscanf_s(A, "%d", &num1);
                }

                for (int k = 0; k < b1; k++)
                {
                    fseek(B, 0, SEEK_SET);
                    for (int q = 0; q < k * b2 + j + 1; q++)
                    {
                        fscanf_s(B, "%d", &num1);
                    }

                    fscanf_s(A, "%d", &num1);
                    fscanf_s(B, "%d", &num2);
                    sum += g[i][k] * z[k][j];
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
    return 0;
}
int z1_2()
{
    cout << "Компоненты файла f – целые двухзначные числа (положительные и отрицательные). Получить файл g, образованный из f включением только чисел кратных K." << endl;
    FILE* f, * g;
    int a[50], i, k;
    int K, t;
    f = fopen("f.txt", "r");
    if ((f == NULL))
        printf("Файл не создан\n");
    else {
        printf("Сколько чисел в файле?\n");
        scanf_s("%d", &k);
        for (i = 0; i < k; i++)
            fscanf_s(f, "%d", &a[i]);
        fclose(f);
    }
    printf("Введи число для проверки на кратность:\n");
    scanf_s("%d", &K);
    if ((g = fopen("g.txt", "w")) == NULL)
        printf("Файл не создан\n");
    else {
        for (i = 0; i < k; i++) {
            t = a[i];
            if (t % K == 0)
                fprintf(g, "%d", t);
            fprintf(g, "\n");
        }
    }
    printf("ЧИсла скопированы\n");
    fclose(g);
    return 0;
}
int z2_1()
{
   
    setlocale(LC_CTYPE, "Russian");
    int r, c, sum1, sum2;
    FILE* A, * B, * C;
    cout << "Даны два файла вещественных чисел с именами fA и fB, содержащие элементы прямоугольных матриц M1 и M2 по строкам, причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы. Создать файл той же структуры с именем fC, содержащий сумму M1+M2" << endl;
    cout << "Введите количество строк и столбцов: ";
    cin >> r >> c;
    fopen_s(&A, "A2.txt", "w");
    fopen_s(&B, "B2.txt", "w");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                fprintf(A, "%d ", c);
                fprintf(B, "%d ", c);
                fprintf(A, "\n");
                fprintf(B, "\n");
            }
            fprintf(A, "%d ", rand() % 10);
            fprintf(B, "%d ", rand() % 10);
        }
        fprintf(A, "\n");
        fprintf(B, "\n");
    }
    fclose(A);
    fclose(B);

    fopen_s(&A, "A2.txt", "r");
    fopen_s(&B, "B2.txt", "r");
    fopen_s(&C, "C2.txt", "w");
    fscanf_s(A, "%d", &sum1);
    fscanf_s(B, "%d", &sum2);
    fprintf(C, "%d ", sum1);
    fprintf(C, "\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fscanf_s(A, "%d", &sum1);
            fscanf_s(B, "%d", &sum2);
            fprintf(C, "%d ", sum1 + sum2);
        }
        fprintf(C, "\n");
    }
    fclose(A);
    fclose(B);
    fclose(C);
    return 0;
}
int z2_2()
{
    cout << "Компоненты файла f –  целые двухзначные (отличные от нуля) числа, причем 10 положительных чисел, 10 отрицательных, и т. д. Получить файл g, в котором записаны сначала 5 положительных чисел, затем 5 отрицательных и т. д" << endl;
    int count, x;
    FILE* A, * B;
    fopen_s(&A, "A2_2.txt", "w");

    for (int i = 1; i < 11; i++)

    {

        for (int j = 0; j < i; j++)

        {
            x = (rand() % 90 + 10) * (-1);
            fprintf(A, "%d ", x);
        }
        for (int q = 0; q < i; q++)

        {

            x = (rand() % 90 + 10) * (1);

            fprintf(A, "%d ", x);

        }

    }

    fclose(A);



    fopen_s(&A, "A2_2.txt", "r");

    fopen_s(&B, "B2_2.txt", "w");

    for (int i = 1; i < 6; i++)

    {

        for (int k = 0; k < i; k++)

        {

            fscanf_s(A, "%d ", &x);

            fprintf(B, "%d ", x);

        }

        for (int z = 0; z < i; z++)

        {

            fscanf_s(A, "%d ", &x);
            fprintf(B, "%d ", x);

        }

    }

    fclose(A);

    fclose(B);

    return 0;
}
int z5_1()
{
    cout << "Даны два файла целых чисел, содержащие элементы квадратных матриц с именами A и B по строкам, причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы. Создать файл той же структуры с именем C, содержащий произведение матриц А и В." << endl;
    setlocale(LC_CTYPE, "Russian");
    int l, n1, n2, s = 0;
    FILE* A2, * B2, * C2;
    cout << "Введите переменную n:";
    cin >> l;
    fopen_s(&A2, "A5_1.txt", "w");
    fopen_s(&B2, "B5_1.txt", "w");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            if (i == 0 && j == 0) {
                fprintf(A2, "%d ", l);
                fprintf(B2, "%d ", l);
                fprintf(A2, "\n");
                fprintf(B2, "\n");
            }
            fprintf(A2, "%d ", rand() % 10);
            fprintf(B2, "%d ", rand() % 10);
        }
        fprintf(A2, "\n");
        fprintf(B2, "\n");
    }
    fclose(A2);
    fclose(B2);
    fopen_s(&A2, "A5_1.txt", "r");
    fopen_s(&B2, "B5_1.txt", "r");
    fopen_s(&C2, "C5_1.txt", "w");
    fprintf(C2, "%d ", l);
    fprintf(C2, "\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            fseek(A2, 0, SEEK_SET);
            for (int q = 0; q < i * l + 1; q++) {
                fscanf_s(A2, "%d", &n1);
            }
            for (int k = 0; k < n; k++)
            {
                fseek(B2, 0, SEEK_SET);
                for (int q = 0; q < k * l + j + 1; q++) {
                    fscanf_s(B2, "%d", &n1);
                }
                fscanf_s(A2, "%d", &n1);
                fscanf_s(B2, "%d", &n2);
                s += n1 * n2;
            } fprintf(C2, "%d ", s);
            s = 0;
        } fprintf(C2, "\n");
    }
    fclose(A2);
    fclose(B2);
    fclose(C2);
    return 0;
}
int z5_2()
{
    cout << "Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию. Скопировать в файл F2 только те строки из F1, которые начинаются с буквы «А». " << endl;
    setlocale(LC_CTYPE, "Russian");
    int i; char str[50], dts[50]; 
    FILE* F1, * F2;
    F1 = fopen("file.txt", "wt");
    if (!F1)
    {
        printf("Error!");
        return 0;
    } fclose(F1);
    fopen_s(&F1, "file.txt", "w");

    for (i = 1; i < 6; i++) {

        cout << "Введите cтроку " << i << ":";   gets_s(str);

        fputs(str, F1); fputs("\n", F1);


    }

    fclose(F1);



    F1 = fopen("file.txt", "r");
    F2 = fopen("file2.txt", "w");

    if (!F2)
    {
        puts("Проблема с файлом F2.txt");
        return 1;
    }
    for (int i = 0; i < strlen(str); ++i) {

        fgets(str, sizeof(str), F1);

        if (str[0] == 'A' || str[0] == 'a')
            fputs(str, F2);

    }
    printf("Данные успешно записаны в файл F2.txt\n");
    fclose(F2);
    fclose(F1);
    return 0;
}
int z10_1()
{
    cout << "Компоненты файла fileA –  целые отличные от нуля числа: х, y1,... yn. Вывести на экран два члена этой последовательности, среднее арифметическое которых ближе всего к х" << endl;
    setlocale(LC_CTYPE, "Russian");
    int i; char str[50], dts[50]; int j[10] = { 1,0,2,3,4,5,6,7,8,9 };
    FILE* F1, * F2;
    F1 = fopen("file10_1.txt", "wt");
    if (!F1)
    {
        printf("Error!");
        return 0;
    } fclose(F1);
    fopen_s(&F1, "file10_1.txt", "w");

    for (i = 1; i < 6; i++) {

        cout << "Введите cтроку " << i << ":";   gets_s(str);

        fputs(str, F1); fputs("\n", F1);


    }

    fclose(F1);

    int k = 0;

    F1 = fopen("file10_1.txt", "r");
    F2 = fopen("file2(10_1).txt", "w");

    if (!F2)
    {
        puts("Проблема с файлом F2.txt");
        return 1;
    }
    while (!feof(F1))
    {
        fgets(str, sizeof(str), F1);
        for (int i = 0; i < strlen(str); ++i) {
            if (isdigit(str[i]))
                fputs(str, F2);
        }
    }
    printf("Данные успешно записаны в файл F2.txt\n");
    fclose(F2);
    fclose(F1);
    return 0;
}
int z10_2()
{
    cout << "Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию. Скопировать в файл F2 только строки из F1, которые содержат цифры. " << endl;
    setlocale(LC_CTYPE, "Russian");
    int d, min = 0, x, a[n], k, z, y;

    FILE* A, * B;



    cout << "Введите размер послеледовательности:";
    cin >> k;

    fopen_s(&A, "A10_2.txt", "w");

    for (int i = 0; i < k; i++)

    {



        x = (rand() % 10);

        fprintf(A, "%d ", x);
        a[i] = x;


    }

    fclose(A);

    cout << "Введите x:";
    cin >> d;

    fopen_s(&A, "A10_2.txt", "r");

    fopen_s(&B, "B10_2.txt", "w");


    for (int i = 0; i < k - 1; i++)

    {
        if ((abs((a[i] + a[i + 1]) / 2 - d) == 0) || ((abs((a[i] + a[i + 1]) / 2 - d) > 0) && (abs((a[i] + a[i + 1]) / 2 - d) < 1))) {
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
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
