//// 11_1(dop).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
////
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <iostream>
//#define n 100
//#define s 100
//using namespace std;
////11 вариант
///*1. Компоненты файла fileA –  целые числа, значения которых повторяются.
//Получить файл fileB, образованный из fileA числами, которые встречаются в A ровно 2 раза.*/
//int main()
//{
//	setlocale(LC_ALL, "RUSSIAN");
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
//	int cal = 0, d = 0;
//	for (int i = 0; i < k; i++) {
//		for (int a = i + 1; a < k; a++) {
//			if (z[i] == z[a]) {
//				cal++;
//
//			}
//		}
//
//		if (cal == 1) fprintf(B, "%d ", z[i]);
//
//		cal = 0;
//
//
//	}
//
//	fclose(B);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
//11 вариант
/*1. Компоненты файла fileA –  целые числа, значения которых повторяются.
Получить файл fileB, образованный из fileA числами, которые встречаются в A ровно 2 раза.*/
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int size;
	FILE* fileA;
	FILE* fileB;
	fileA = fopen("A.txt", "r");
	fscanf_s(fileA, "%d", &size);
	int* arr = new int[size];
	printf("fileA:   ");
	for (int i = 0; i < size; i++) {
		fscanf_s(fileA, "%d", &arr[i]);
		printf("%d   ", arr[i]);
	}
	fclose(fileA);
	fileB = fopen("B.txt", "w");
	int cal = 0;
	for (int i = 0; i < size; i++) {

		for (int a = i + 1; a < size; a++) {
			if (arr[i] == arr[a]) {
				cal++;
			}
		}
	}
	int* arr2 = new int[cal];
	printf("\n fileB:   ");
	for (int i = 0; i < cal; i++)
	{
		for (int a = i + 1; a < cal; a++)
		{
			if (arr[i] == arr[a])
			{
				arr2[i] = arr[i];
				fprintf(fileB, "%d ", arr[i]);
				printf("%d   ", arr[i]);
			}
		}
	}


	fclose(fileB);
	return 0;
}