﻿// 13_1(dop).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; char g[] = "aeiouy"; int z; int c = 0, k = 0, max = 0,gl=0,u=1,n;        // буфер для хранения считываемого из файла текста
    ofstream fout("t.txt"), fout2("b.txt");   // создание объекта fout класса ofstream для записи 
    while (true)
    {
        cin.getline(buff, 512);


        if (buff[0] == ';') break;
        fout << buff;
        fout << "\n";
    }
    cout << "Количество введённых строк:"; cin >> z;
    // запись строки в файл
    fout.close();
    ifstream fin("t.txt"), fin2("b.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < z; i++) {
            k = 0;
            char buff[50];
            fin.getline(buff, 50);
            cout << buff << endl;
            cout << "----------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < strlen(buff); i++) {
                if (buff[i] != ' ' && (buff[i + 1] == ' ' || buff[i + 1] == '\0'))
                    k++;
            }
            if (k == 2) {
                fout2 << buff << "\n"; c++;
            }


            buff[0] = 0;

            // печать строки
        } fin.close();
    }fout2.close();




    if (!fin2.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        char s[100], str[100];
        for (int y = 0; y < c; y++) {
            
                fin2.getline(s, 100);
                for (char* p = strtok(s, " "); p; p = strtok(NULL, " "))
                {
                    
                        strcpy(str, p);
                        for (int i = 0; i < strlen(str); ++i)
                        {
                            for (int j = 0; j < strlen(g); ++j)
                            {
                                if (str[i] == g[j]) gl++;
                            }
                        }
                        if (gl > max) {
                            max = gl;
                            n = u;
                        }
                        u++;
                    
                }
                s[0] = 0;
            
        }
        cout << "Номер слова с большим количеством гласных:" << n;
        
        fin2.close();
    }
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
