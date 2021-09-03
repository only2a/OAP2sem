// 11_2(dop).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; char g[] = "aeiouy"; int p; int max = 0, min = 1000,gl=0,gl2=0;        // буфер для хранения считываемого из файла текста
    ofstream fout("t.txt");   // создание объекта fout класса ofstream для записи 
    while (true)
    {
        cin.getline(buff, 512);


        if (buff[0] == ';') break;
        fout << buff;
        fout << "\n";
    }

    // запись строки в файл
    fout.close();
    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        char s[100], str[100], s2[100], str2[100];
        for (int y = 0; y < 2; y++) {
            if (y == 0) {
                fin.getline(s,100);
                for (char* p = strtok(s, " "); p; p = strtok(NULL, " "))
                {
                    if (strlen(p) < min)
                    {
                        min = strlen(p);
                        strcpy(str, p);
                    }
                }
                for (int i = 0; i < strlen(str); ++i)
                {
                    for (int j = 0; j < strlen(g); ++j)
                    {
                        if (str[i] == g[j]) gl++;
                    }
                }
            }
            if (y == 1) {
                fin.getline(s2, 100);
                for (char* p = strtok(s2, " "); p; p = strtok(NULL, " "))
                {
                    if (strlen(p) > max)
                    {
                        max = strlen(p);
                        strcpy(str2, p);
                    }
                }
                for (int i = 0; i < strlen(str2); ++i)
                {
                    for (int j = 0; j < strlen(g); ++j)
                    {
                        if (str2[i] == g[j]) gl2++;
                    }
                }
            }



        }cout << "\nСамое короткое слово: " << str << "(" << gl << ")";
        cout << "\nСамое длинное слово: " << str2<<"("<<gl2<<")";
        fin.close();
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
