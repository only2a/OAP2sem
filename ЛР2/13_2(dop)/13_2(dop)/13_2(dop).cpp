// 13_2(dop).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "");
//	int n;
//	FILE* A;
//	FILE* B;
//	A = fopen("f.txt", "r"); 
//
//	fscanf_s(A, "%d", &n);
//	int a[100];
//	for (int i = 0; i < n; i++) {
//		fscanf_s(A, "%d", &a[i]);
//		printf("%d   ", a[i]);
//	}
//	fclose(A);
//	B = fopen("g.txt", "w");
//	cout << endl;
//
//	for (int i = 0; i < n; i++)
//	{
//
//		for (int k = i + 1; k < n; k++)
//		{
//			if (a[i] == a[k])
//			{
//
//				int w = 0;
//				for (int k = 0; k < i; k++) {
//					if (a[k] == a[i]) {
//						w = 1; break;
//					}
//				}
//				if (w == 0) {
//					fprintf(B, "%d ", a[i]);
//					cout << a[i] << " ";
//				}
//				break;
//			}
//		}
//	}
//	fclose(B);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int n;
	FILE* A;
	FILE* B;
	A = fopen("f.txt", "r");  

	fscanf_s(A, "%d", &n);
	int a[100];
	for (int i = 0; i < n; i++) {
		fscanf_s(A, "%d", &a[i]);
		printf("%d   ", a[i]);
	}
	fclose(A);
	B = fopen("g.txt", "w");
	cout << endl;

	for (int i = 0; i < n; i++)
	{

		for (int k = i + 1; k < n; k++)
		{
			if (a[i] == a[k])
			{

				int w = 0;
				for (int k = 0; k < i; k++) {
					if (a[k] == a[i]) {
						w = 1; break;
					}
				}
				if (w == 0) {
					fprintf(B, "%d ", a[i]);
					cout << a[i] << " ";
				}
				break;
			}
		}
	}
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
