// 10_1(osn).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//
//#include <fstream>
//#include <iostream>
//
//
//using namespace std;
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    string A = "A.txt", B = "B.txt";
//    char str[512];
//    int  i ,n;
//    ifstream fAin(A), fBin(B);
//    ofstream fAout(A), fBout(B);
//
//    if (fAout.is_open())
//    {
//        cout << "Скопировать из файла FILE1 в файл FILE2 все строки, в которых нет слов, совпадающих с первым словом. Определить количество согласных букв в первой строке  файла FILE2." << endl;
//        cout << "Введите количество строк:";
//        cin >> n;
//        cout << "Введите строки: ";
//
//        for(int i=1;i<=n;i++)
//        {
//            cin.getline(str, 512);
//           
//            fAout << str;
//            fAout << "\n";
//        }
//    }
//    else
//    {
//        cout << " Невозможно открыть файл!" << endl;
//    }
//    fAout.close();
//
//    char st[50],buf[50]; 
//    if (fAin.is_open() && fBout.is_open())
//    {
//        
//        while (!fAin.eof()) {
//           
//            for (int j = 1; j <= n; j++)
//            {
//               
//                
//                fAin >> buf;
//                /*fAin.seekg(0);
//                fAin.getline(st, 50);*/
//                for(int j)
//                    if (buf == 'a'|| buf=) {
//                    }
//                    else {
//                        cout << buf << endl << st;
//                        fBout << st << "\t";
//                        
//                    }
//                    
//            }
//        }
//    }
//    else
//    {
//        cout << " Невозможно открыть файл!" << endl;
//    }
//    fAin.close();
//    fBout.close();
//
//
//}

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; char l; int p; int sgl=0;        // буфер для хранения считываемого из файла текста
    ofstream fout("t.txt"), fout2("b.txt");   // создание объекта fout класса ofstream для записи 
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
    ifstream fin("t.txt");    // создание объекта fin класса ifstream для чтения  
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
            if (!strstr(buff,buff_new)){
                fout2 << buff_new << "" << buff<<"\n";
            }

            buff[0] = 0;
            buff_new[0] = 0;
             // печать строки
        } fin.close();
    }fout2.close();
    ifstream fin2("b.txt");
    if(!fin2.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        char s[] =( "bcdfghjklmnpqrstvwxz");/* { "b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","z" };*/
        char buff2[50];
        fin2.getline(buff2, 50); 
        cout << buff2 << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < strlen(buff2); ++i)
        {
           
            for (int j = 0; j <strlen(s); ++j)
            {
                if (buff2[i] == s[j]) sgl++;
            }
        }
        cout << "Согласных букв в строке: " << sgl << endl;
       
    }
    fin2.close();
}




//
//#include <iostream>
//#include <unordered_set>
//#include <string>
//#include <fstream>
//#include <sstream>
//
//int main()
//{
//    std::ifstream is("input.txt");
//    std::ofstream os("output.txt");
//    if (!is || !os) return 1;
//    std::string str, word;
//    std::unordered_set<std::string> uset;
//
//    while (std::getline(is, str)) {
//        uset.clear();
//        std::stringstream ss(str);
//
//        while (ss >> word) {
//            if (!uset.insert(word).second) {
//                os << str << '\n';
//                break;
//            }
//        }
//    }
//
//    is.close();
//    os.close();
//    return 0;
//}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
