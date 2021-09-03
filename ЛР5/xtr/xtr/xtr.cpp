// xtr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#14 - Разработать функцию, которая формирует стек Stack, включив в него повторяющиеся элементы стеков Stack1 и Stack 2


#include <iostream>
#include <windows.h>
#include<fstream>
#include<string>
using namespace std;

struct Stack1 {			//Стуктура элемента стека
	int data;
	Stack1* Head;		//Указатель на вершину стека
	Stack1* Next;		//Указатель на следующий элемент
};

struct Stack2 {			//Стуктура элемента стека
	int data;
	Stack2* Head;		//Указатель на вершину стека
	Stack2* Next;		//Указатель на следующий элемент
};

struct Stack {			//Стуктура элемента стека
	int data;
	Stack* Head;		//Указатель на вершину стека
	Stack* Next;		//Указатель на следующий элемент
};


void Add1(Stack1* s1);				//Добавить элемент в стек 1
void Add2(Stack2* s2);				//Добавить элемент в стек 2
void Show1(Stack1* s1);					//Вывести стек
void Show2(Stack2* s2);					//Вывести стек
void Show(Stack1* s1, Stack2* s2, Stack* s);



void Add1(Stack1* s1) {	//Добавление элементов в стек 1
	Stack1* Man = new Stack1;							//Выделение памяти для элемента стека
	cout << "Введите число: "; cin >> Man->data;
	Man->Next = s1->Head;							//Указатель на следующий элемент 
	s1->Head = Man;								//сдигаем вершину стека
	return;
}

void Add2(Stack2* s2) {	//Добавление элементов в стек 2
	Stack2* Man = new Stack2;
	cout << "Введите число: "; cin >> Man->data;
	Man->Next = s2->Head;
	s2->Head = Man;
	return;
}

void Show1(Stack1* s1) {	//Вывод стека 1 на экран
	Stack1* show = s1->Head;	//Указатель на вершину стека
	int a;
	if (show == NULL)
		cout << " Стек пуст! \n";
	else {
		cout << "Весь стек: \n";
		while (show != NULL)
		{
			a = show->data;
			cout << a << "  ";
			show = show->Next;		//Перейти к следующему элементу
		}
		cout << endl;
	}
}

void Show2(Stack2* s2) {	//Вывод стека 2 на экран
	Stack2* show = s2->Head;	//Указатель на вершину стека
	int a;
	if (show == NULL)
		cout << " Стек пуст! \n";
	else {
		cout << "Весь стек: \n";
		while (show != NULL)
		{
			a = show->data;
			cout << a << "  ";
			show = show->Next;		//Перейти к следующему элементу
		}
		cout << endl;
	}
}

void Show(Stack1* s1, Stack2* s2, Stack* s) {	//Вычисление элементов стека Stack

	Stack1* a = s1->Head;	//Указатель на вершину стека
	Stack2* b = s2->Head;
	Stack* c = s->Head;

	if (s1 == 0 || (s2 == 0))
		cout << " Один из стеков пуст! \n";
	else {
		while (s1 != NULL) {
			while (s2 != NULL) {
				if (s1->data == s2->data) {
					int a = s1->data;
					s->data = a;
					s = s->Next;
				}
				s2 = s2->Next;
			}
			s1 = s1->Next;
		}
		while (s != NULL)
		{
			cout << s->data << "  ";
			s = s->Next;		//Перейти к следующему элементу
		}
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	Stack1* s1 = new Stack1;	//выделение памяти для элемента стека
	s1->Head = NULL;			//указатель на вершину стека - NULL

	Stack2* s2 = new Stack2;
	s2->Head = NULL;

	Stack* s = new Stack;
	s->Head = NULL;

	for (;;) {
		cout << "\n\nРабота со стеком. Выберите команду:" << endl;
		cout << "1 - Добавление в Stack1" << endl;
		cout << "2 - Добавление в Stack2" << endl;
		cout << "3 - Вывод Stack1" << endl;
		cout << "4 - Вывод Stack2" << endl;
		cout << "5 - Вывод Stack" << endl;
		cout << "6 - Выход" << endl;
		cin >> choice;
		system("cls");

		switch (choice) {
		case 1: Add1(s1); break;						//Добавить элемент в стек
		case 2: Add2(s2); break;						//Добавить элемент в стек
		case 3: Show1(s1); break;
		case 4: Show2(s2); break;
		case 5: Show(s1, s2, s); break;									//Вывести стек
		case 6: return;											//Конец
		}
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
