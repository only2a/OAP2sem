// 13_1(dop).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include<ctime>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");

	FILE* F1;
	FILE* F2;
	errno_t er, err2;
	const int size = 20;

	int a[size];
	er=fopen_s(&F1, "A.txt", "w");  
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 10;
		fprintf(F1, "%d ", a[i]);
	}
	fclose(F1);
	er = fopen_s(&F1, "A.txt", "r");
	for (int i = 0; i < size; i++)
	{
		fscanf(F1, "%d ", &a[i]);
		std::cout << a[i] << " ";
	}

	err2 = fopen_s(&F2, "B.txt", "w");

	cout << endl;
	int kol = 0;
	for (int i = 0; i < size; i++)
	{
		kol = 1;
		for (int j = i + 1; j < size; j++)
		{
			if (a[i] == a[j])
			{
				kol++;
				int w = 0;
				for (int k = 0; k < i; k++) {
					if (a[k] == a[i]) {
						w = 1; break;
					}
				}
				if (w == 0 && kol >2) {
					fprintf(F2, "%d ", a[i]);
					cout << a[i] << " ";
					break;
				}

			}
		}
	}
	fclose(F2);
	return 0;
}
//#include <stdio.h>
//#include <iostream>
//#define n 100
//#define s 100
//using namespace std;
////11 вариант
///*1. Компоненты файла A –  целые числа, значения которых повторяются.
//Получить файл B, образованный из A числами, которые встречаются в A ровно 2 раза.*/
//int main()
//{
//	setlokole(LC_ALL, "RUSSIAN");
//	int  x, z[n], m[n], k;
//	FILE* A;
//	FILE* B;
//	cout << "Введите размер послеледовательности:";
//	cin >> k;
//	fopen_s(&A, "A.txt", "w");
//	for (int i = 0; i < k; i++)
//	{
//		x = (rand() % 10);
//		fprintf(A, "%d ", x);
//		z[i] = x;
//	}
//	fclose(A);
//	B = fopen("B.txt", "w");
//	int kol = 0, d = 0;
//	for (int i = 0; i < k; i++) {
//		for (int a = i + 1; a < k; a++) {
//			if (z[i] == z[a]) {
//				kol++;
//
//			}
//		}
//
//		if (kol == 1) fprintf(B, "%d ", z[i]);
//
//		kol = 0;
//
//
//	}
//
//	fclose(B);
//	return 0;
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
