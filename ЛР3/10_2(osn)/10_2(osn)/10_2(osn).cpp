// 10_2(osn).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <fstream>
//#include <iostream>
//using namespace std;
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    string A = "A.txt", B = "B.txt";
//    char str[512];
//    int k = 0, i = 1, count = 0;
//    ifstream fAin(A), fBin(B);
//    ofstream fAout(A), fBout(B);
//    if (fAout.is_open())
//    {
//        cout << "Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл. Прочитать из файла данные, вывести слова строки и записать их в другой файл" << endl;
//        cout << "Введите строки: ";
//        while (true)
//        {
//            cin.getline(str, 512);
//            if (str[0] == ';') break;
//            fAout << str;
//            fAout << "\n";
//        }
//    }
//    else
//    {
//        cout << " Невозможно открыть файл!" << endl;
//    }
//    fAout.close();
//    char strk[50];
//    if (fAin.is_open() && fBout.is_open())
//    {
//        while (!fAin.eof()) {
//            fAin.getline(strk, 50);
//
//            for (int i = 0; i < strlen(strk); i++) {
//                if ((strk[i] == 'p') || (strk[i] == 'P')) {
//
//                    fBout << strk << "\t";
//                    break;
//                }
//            }
//        }
//    }
//    else
//    {
//        cout << " Невозможно открыть файл!" << endl;
//    }
//    fAin.close();
//    fBout.close();
//}


#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; char g[] = "aeiouy"; int p; int max = 0, min = 1000, gl = 0, gl2 = 0;        // буфер для хранения считываемого из файла текста
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
        char s[50];
        while (!fin.eof()){
            fin >> s;
                for (int x = 0; x < strlen(s); x++)
                {
                    if (s[x] == 'p' || s[x] == 'P') cout << s << endl;
                }
                s[0] = 0;
         }
         



        }
        fin.close();
    }


//
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <conio.h>
//#include <cstdio>
//#include <string.h>
//#include <fstream>
//using namespace std;
//
//void invers(string str) {
//    ofstream file("out.txt");
//    file << str << "\n";
//    string str2 = "";
//    for (int i = str.length() - 1; i >= 0; i--) {
//        str2 += str[i];
//    }
//    file << str2;
//    file.close();
//}
//
//char s[256] = "The twenty first century is a century of technologies, computers and technology. It is well-known that the computer has become one of the main ways of getting information.";
//char ss[256];
//
//int main() {
//    int m = strcmp(s, ss);
//    cout << "Enter a sentence:\n"; scanf("%255[^\n]", ss);
//    if (m < 0) cout << "\nNew S >> S"; else if (m == 0) cout << "\nNew S = S";
//    else cout << "\nS >> New S";
//
//    char l;
//    char* pch = strtok(s, " ,.-");
//    cout << "\nEnter a letter: "; cin >> l;
//
//    while (pch != NULL) {
//        if (strchr(pch, l)) cout << pch << "\n";
//        pch = strtok(NULL, " ,.-");
//    }
//
//    invers(ss);
//    return 0;
//}
