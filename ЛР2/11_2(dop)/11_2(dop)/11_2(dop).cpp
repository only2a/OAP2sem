// 11_2(dop).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
//11 вариант
/*2. Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию.
Скопировать в файл F2 только те строки из F1, которые заканчиваются символом «а». */
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	FILE* my_file_A;
	FILE* my_file_B;
	char array[100];
	int size;
	my_file_A = fopen("a.txt", "r");
	my_file_B = fopen("b.txt", "w");

	for (int i = 0; i < 6; i++) {
		fscanf(my_file_A, "%s", &array);
		cout << array << endl;
		size = strlen(array);
		if (array[size - 1] == 'a')
		{
			fprintf(my_file_B, " %s", array);
			fprintf(my_file_B, "\n");
		}
	}
	fclose(my_file_A);
	fclose(my_file_B);
	system("pause");
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