﻿// 12_1(dop).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; char l; int p; int sgl = 0, k = 0;        // буфер для хранения считываемого из файла текста
    ofstream fout("t.txt"), fout2("b.txt");   // создание объекта fout класса ofstream для записи 
    cout << "Введите строки:" << endl;
    while (true)
    {
        cin.getline(buff, 512);


        if (buff[0] == ';') break;
        fout << buff;
        fout << "\n";
    }
    cout << "Количество введённых строк:"; cin >> p;
    // запись строки в файл
    fout.close();
    ifstream fin("t.txt"), fin2("b.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < p; i++) {
            char buff[50]; char buff_new[50];
            fin >> buff_new;
            cout << buff_new << endl;
            fin.getline(buff, 50);
            cout << buff << endl;
            cout << "----------------------------------------------------------------------------------" << endl;
            if (strstr(buff, buff_new)) {
                fout2 << buff_new << "" << buff << "\n";
                k++;
            }

            buff[0] = 0;
            buff_new[0] = 0;
            // печать строки
        } fin.close();
    }fout2.close();




    if (!fin2.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        for (int y = 0; y <= k; y++) {
            char buff2[50];
            if (y == k-1) {
                
                    char s[] = ("bcdfghjklmnpqrstvwxz");/* { "b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","z" };*/
                    
                    fin2.getline(buff2, 50);
                    cout << buff2 << endl;

                    for (int i = 0; i < strlen(buff2); ++i)
                    {

                        for (int j = 0; j < strlen(s); ++j)
                        {
                            if (buff2[i] == s[j]) sgl++;
                        }
                    }
                    cout << "Согласных букв в строке: " << sgl << endl;
                    cout << "----------------------------------------------------------------------------------" << endl;
                
            }
            else {
                fin2.getline(buff2, 50); cout << buff2 << endl;
                buff[0] = 0;
            }
            
        }
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
