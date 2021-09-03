// Вар9+допы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string A = "A.txt";
char str[200];
int amountOfStr = 0;

struct list
{
    int number;
    list* next;
};

struct list2
{
    char number;
    list2* next;
};

struct list3 {
    float number;
    list3* next;
};

list * v10;
list2* v11;
list3* v9, * v12;

int menu();
void insert1(list*&, int);
void del1(list*&, int);
void find1(list*, int);
void printList1(list*);
void toFile(list*);
void fromFile(list*&);

void insert1(list2*&, char);
void del1(list2*&, char);
void find1(list2*, char);
void printList1(list2*);
void toFile(list2*);
void fromFile(list2*&);


void insert1(list3*&, float);
float del1(list3*&, float);
void find1(list3*, float);
void printList1(list3*);
void toFile(list3*);
void fromFile(list3*&);

void call(int n, list3*);
void mainTask1(list*&);
void mainTask1(list2*&);
void mainTask1(list3*&, int n);
void extraTaskVar9(list3*);
void extraTaskVar10(list*);
void extraTaskVar12(list3*);
void extraTaskVar11(list2*);

int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 1;
    while (a != 0)
    {
        cout << "1. Вариант 9" << endl;
        cout << "2. Вариант 10" << endl;
        cout << "3. Вариант 11" << endl;
        cout << "4. Вариант 12" << endl;
        cout << "0. Выход" << endl;
        cout << "(Введите выбор) ";
        cin >> a;
        switch (a)
        {
        case 1:
            mainTask1(v9,9);
            break;
        case 2:
            mainTask1(v10);
            break;
        case 3:
            mainTask1(v11);
            break;
        case 4:
            mainTask1(v12, 12);
            break;
        case 0:
            break;

        default:
            cout << "Неправильный выбор" << endl;
            break;
        }
    }
    return 0;
}

void mainTask1(list*& first)
{
    first = NULL;
    int a = 1, n;
    while (a != 0)
    {
        switch (menu())
        {
        case 1:
            cout << "Введите число: ";
            cin >> n;
            insert1(first, n);
            break;

        case 2:
            cout << "Введите число: ";
            cin >> n;
            del1(first, n);
            break;

        case 3:
            cout << "Введите число: ";
            cin >> n;
            find1(first, n);
            break;

        case 4:
            printList1(first);
            break;

        case 5:
            toFile(first);
            break;

        case 6:
            fromFile(first);
            break;

        case 7:
            extraTaskVar10(first);
            break;

        case 0:
            a = 0;
            break;

        default:
            break;
        }
    }
}

void mainTask1(list2*& first)
{
    first = NULL;
    int a = 1;
    char n;
    while (a != 0)
    {
        switch (menu())
        {
        case 1:
            cout << "Введите число: ";
            cin >> n;
            insert1(first, n);
            break;

        case 2:
            cout << "Введите число: ";
            cin >> n;
            del1(first, n);
            break;

        case 3:
            cout << "Введите число: ";
            cin >> n;
            find1(first, n);
            break;

        case 4:
            printList1(first);
            break;

        case 5:
            toFile(first);
            break;

        case 6:
            fromFile(first);
            break;

        case 7:
            extraTaskVar11(first);
            break;

        case 0:
            a = 0;
            break;

        default:
            break;
        }
    }
}

void mainTask1(list3*& first,int f)
{
    first = NULL;
    int a = 1;
    char n;
    while (a != 0)
    {
        switch (menu())
        {
        case 1:
            cout << "Введите число: ";
            cin >> n;
            insert1(first, n);
            break;

        case 2:
            cout << "Введите число: ";
            cin >> n;
            del1(first, n);
            break;

        case 3:
            cout << "Введите число: ";
            cin >> n;
            find1(first, n);
            break;

        case 4:
            printList1(first);
            break;

        case 5:
            toFile(first);
            break;

        case 6:
            fromFile(first);
            break;

        case 7:
            call(f,first);
            break;

        case 0:
            a = 0;
            break;

        default:
            break;
        }
    }
}


int menu()
{
    int n;
    cout << endl;
    cout << " 1. Ввод числа" << endl;
    cout << " 2. Удаление числа" << endl;
    cout << " 3. Поиск числа" << endl;
    cout << " 4. Вывод списка в консольное окно" << endl;
    cout << " 5. Запись списка в файл" << endl;
    cout << " 6. Считывание списка из файла" << endl;
    cout << " 7. Задание" << endl;
    cout << " 0. Выход" << endl;
    cout << "(Введите выбор) ";
    cin >> n;
    cout << endl;
    return n;
}



void insert1(list*& p, int value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else cout << "Операция добавления не выполнена" << endl;
}

void del1(list*& p, int value)  // Удаление числа 
{
    list* previous, * current;

    previous = p;
    current = p->next;
    if (p->number == value)
    {
        free(p);
        p = current;
    }
    else
    {
        while (current != NULL)
        {
            if (current->number == value)
            {
                previous->next = current->next;
                free(current);
                break;
            }
            previous = current;
            current = current->next;
        }
    }
 
}

void find1(list* p, int value)
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Переменные: " << value << endl;
        while (p != NULL)
        {
            if (p->number == value) cout << p->number << endl;
            p = p->next;
        }
    }
}

void printList1(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void toFile(list* p)
{
    amountOfStr = 0;
    ofstream fAout(A);
    if (fAout.is_open())
    {
        if (p == NULL)
        {
            fAout << "Список пуст" << endl;
        }
        else
        {
            while (p != NULL)
            {
                fAout << p->number << endl;
                p = p->next;
                amountOfStr++;
            }
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void fromFile(list*& p)
{
    list* previous, * current;
    previous = p;
    current = p->next;
    while (current != NULL)
    {
        free(previous);
        previous = current;
        current = previous->next;
    }
    p = NULL;

    ifstream fAin(A);
    int* arr = new int[amountOfStr];
    if (fAin.is_open())
    {
        for (size_t i = 0; i < amountOfStr; i++)
        {
            fAin.getline(str, sizeof(str));
            arr[i] = atoi(str);
        }
        for (int i = amountOfStr - 1; i >= 0; i--)
        {
            insert1(p, arr[i]);
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
}





void insert1(list2*& p, char value) //Добавление числа value в список 
{
    list2* newP = new list2;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else cout << "Операция добавления не выполнена" << endl;
}

void del1(list2*& p, char value)  // Удаление числа 
{
    list2* previous, * current;

    previous = p;
    current = p->next;
    if (p->number == value)
    {
        free(p);
        p = current;
    }
    else
    {
        while (current != NULL)
        {
            if (current->number == value)
            {
                previous->next = current->next;
                free(current);
                break;
            }
            previous = current;
            current = current->next;
        }
    }
  
}

void find1(list2* p, char value)
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Переменные: " << value << endl;
        while (p != NULL)
        {
            if (p->number == value) cout << p->number << endl;
            p = p->next;
        }
    }
}

void printList1(list2* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void toFile(list2* p)
{
    amountOfStr = 0;
    ofstream fAout(A);
    if (fAout.is_open())
    {
        if (p == NULL)
        {
            fAout << "Список пуст" << endl;
        }
        else
        {
            while (p != NULL)
            {
                fAout << p->number << endl;
                p = p->next;
                amountOfStr++;
            }
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void fromFile(list2*& p)
{
    list2* previous, * current;
    previous = p;
    current = p->next;
    while (current != NULL)
    {
        free(previous);
        previous = current;
        current = previous->next;
    }
    p = NULL;

    ifstream fAin(A);
    int* arr = new int[amountOfStr];
    if (fAin.is_open())
    {
        for (size_t i = 0; i < amountOfStr; i++)
        {
            fAin.getline(str, sizeof(str));
            arr[i] = atoi(str);
        }
        for (int i = amountOfStr - 1; i >= 0; i--)
        {
            insert1(p, arr[i]);
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
}






void insert1(list3*& p, float value) //Добавление числа value в список 
{
    list3* newP = new list3;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else cout << "Операция добавления не выполнена" << endl;
}

float del1(list3*& p, float value)  // Удаление числа 
{
    list3* previous, * current;

    previous = p;
    current = p->next;
    if (p->number == value)
    {
        free(p);
        p = current;
    }
    else
    {
        while (current != NULL)
        {
            if (current->number == value)
            {
                previous->next = current->next;
                free(current);
                break;
            }
            previous = current;
            current = current->next;
        }
    }
    return 0;
}

void find1(list3* p, float value)
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Переменные: " << value << endl;
        while (p != NULL)
        {
            if (p->number == value) cout << p->number << endl;
            p = p->next;
        }
    }
}

void printList1(list3* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void toFile(list3* p)
{
    amountOfStr = 0;
    ofstream fAout(A);
    if (fAout.is_open())
    {
        if (p == NULL)
        {
            fAout << "Список пуст" << endl;
        }
        else
        {
            while (p != NULL)
            {
                fAout << p->number << endl;
                p = p->next;
                amountOfStr++;
            }
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void fromFile(list3*& p)
{
    list3* previous, * current;
    previous = p;
    current = p->next;
    while (current != NULL)
    {
        free(previous);
        previous = current;
        current = previous->next;
    }
    p = NULL;

    ifstream fAin(A);
    int* arr = new int[amountOfStr];
    if (fAin.is_open())
    {
        for (size_t i = 0; i < amountOfStr; i++)
        {
            fAin.getline(str, sizeof(str));
            arr[i] = atoi(str);
        }
        for (int i = amountOfStr - 1; i >= 0; i--)
        {
            insert1(p, arr[i]);
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
}






void call(int n, list3* p)
{
    switch (n)
    {
   
    case(9):
        extraTaskVar9(p);
        break;
    case(12):
        extraTaskVar12(p);
        break;
    default:
        break;
    }
}

void extraTaskVar9(list3* p)
{
    cout << "Найти среднее значение отрицательных элементов" << endl;
    float sum = 0, num = 0;
    if (p == NULL) cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 0)
            {
                sum += p->number;
                num++;
            }
            p = p->next;
        }
        if (sum == 0) cout << "Таких элементов нет";
        else cout << "Среднее значение = " << sum / num << endl;
    }
}

void extraTaskVar10(list* p)
{
    cout << "Найти произведение элементов,которые меньше 10" << endl;
    int sum = 1;
    if (p == NULL) cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number<10)
            {
                sum *= p->number;
               
            }
            p = p->next;
        }
        if (sum == 0) cout << "Таких элементов нет";
        else cout << "Произведение = " << sum << endl;
    }
}

void extraTaskVar12(list3* p)
{
    cout << "Найти среднее значение положительных элементов" << endl;
    float sum = 0, num = 0;
    if (p == NULL) cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number > 0)
            {
                sum += p->number;
                num++;
            }
            p = p->next;
        }
        if (sum == 0) cout << "Таких элементов нет";
        else cout << "Среднее значение = " << sum / num << endl;
    }
}

void extraTaskVar11(list2* p)
{
    
    cout << "Найти символ, равный введенному с клавиатуры, вывести этот символ и предыдущий." << endl;
    char s, real, s1, s2;
    cout << "Введите символ" << endl;
    cin >> s;
    if (p == NULL) cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            real = p->number;
            p = p->next;
            if (p != NULL) {

                if (p->number == s) {
                    s1 = s; s2 = real;
                };
            }
            
        }
       if (s1 == 0 ) cout << "Таких элементов нет";
        cout << "Найденный|предыдущий элементы " << s1 << "|" << s2 << endl;
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
