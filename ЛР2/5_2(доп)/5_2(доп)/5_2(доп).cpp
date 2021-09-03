// 5_2(доп).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <cstdio>
//#include <iostream>
//using namespace std;
//int extraTask1_2() //вар 5
//{
//    cout << "Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию. Скопировать в файл F2 только те строки из F1, которые начинаются с буквы «А»" << endl;
//    char x, arr[512];
//    string str;
//    int n = 0;
//    FILE* A, * B;
//    fopen_s(&A, "A.txt", "w");
//
//    while (true)
//    {
//        cin.getline(arr, 512);
//        if (arr[0] == ';') break;
//        fprintf(A, "%s\n", arr);
//    }
//    fclose(A);
//
//    fopen_s(&A, "A.txt", "r");
//    fopen_s(&B, "B.txt", "w");
//    while (true)
//    {
//
//        fgets(arr, sizeof(arr), A);
//        if (feof(A) != 0) break;
//        if (arr[0] == 'A' || arr[0] == 'a') fprintf(B, "%s\n", arr);
//    }
//    fclose(A);
//    fclose(B);
//    return 0;
//}
//int main() {
//    setlocale(LC_CTYPE, "Russian");
//    extraTask1_2();
//
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int i; char str[50], dts[50]; int t, j[10] = { 1,0,2,3,4,5,6,7,8,9 };
    FILE* F1, * F2;
    cout << "Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию. Скопировать в файл F2 только те строки из F1, которые начинаются с буквы «А». " << endl;
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
        
            if (str[strlen(str)-1]== 'a')
                fputs(str, F2);
        
    }
    printf("Данные успешно записаны в файл F2.txt\n");
    fclose(F2);
    fclose(F1);
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
