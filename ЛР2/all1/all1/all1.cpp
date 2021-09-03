// all1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <limits>
#define n 100
using namespace std;
void osn();
void osn2();

void v10_1();
void v10_2();

void v11_1();
void v11_2();

void v12_1();
void v12_2();

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	bool work = true;
	int op;
	while (work)
	{
		cout << "\n1. Вариант 9(1)\n2. Вариант 9(2)\n3.Вариант 10(1)\n4. Вариант 10(2)\n5. Вариант 11(1)\n6. Вариант 11(2)\n7. Вариант 12(1)\n8. Вариант 12(2)\n0. Закончить\n(Введите вариант) ";
		cin >> op;
		switch (op)
		{
		case(1):
			osn();
			break;

		case(2):
			osn2();
			break;

		case(3):
			v10_1();
			break;

		case(4):
			v10_2();
			break;
		case(5):
			v11_1();
			break;
		case(6):
			v11_2();
			break;
		case(7):
			v12_1();
			break;
		case(8):
			v12_2();
			break;

		case(0):
			work = false;
			break;

		default:
			break;
		}
	}
}

void osn()
{
	setlocale(LC_ALL, "");
	int size;
	cout<< "9.1) Компоненты файла fileA – целые числа, значения которых повторяются. Получить файл fileB, образованный из fileA исключением повторных вхождений одного и того же числа.\n\n";
	FILE* fileA;
	FILE* fileB;
	fopen_s(&fileA, "A9.txt", "r"); //Открытие для чте-ния 

	fscanf_s(fileA, "%d", &size);
	int arr[100];
	for (int i = 0; i < size; i++) {
		fscanf_s(fileA, "%d", &arr[i]);
	}
	fclose(fileA);
	fopen_s(&fileB, "B9.txt", "w");



	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				int wasBefore = 0;
				for (int k = 0; k < i; k++)
				{
					if (arr[k] == arr[i]) {
						wasBefore = 1; break;
					}
				}
				if (wasBefore == 0)
				{
					fprintf(fileB, "%d ", arr[i]);
				} break;
			}
		}
	}

	int arr2[100];
	int numb;
	int size2 = 0;
	for (int i = 0; i < size; i++)
	{
		numb = 1;
		for (int j = 0; j < size; j++)
		{
			if ((j != i) && (arr[i] == arr[j]))
			{
				numb = 0;
			}

		}
		if (numb)
		{
			size2++;
			arr2[size2 - 1] = arr[i];
		}
	}
	for (int i = 0; i < size2; i++)
	{
		fprintf(fileB, "%d ", arr2[i]);
	}
	fclose(fileB);
	cout<< "Откройте файлы A9.txt и B9.txt" << endl;

}


void osn2() 
{ 
 setlocale(LC_CTYPE, "Russian"); 
 FILE* F1; 
 FILE* F2; 
 int k = 0; 
 char str[100]; 
 cout << "9.2) Создать текстовый файл F1 не менее, чем из 4 строк, и записать в него информацию. Скопировать из файла F1 в файл F2 строки, количество символов в которых больше, чем заданное число. \n\n"; 
 
 cout << "Введите K = "; 
 cin >> k; 
 cout << "\n"; 
 
 fopen_s(&F1,"A9_2.txt", "w"); 
 for (int i = 0; i < 10; i++) 
 { 
 
   fflush(stdin); 
   printf("Введите %d строку \n", i+1); 
   cin >> (str); 
   fwrite(str, strlen(str), 1, F1); 
   fputs("\n", F1); 
 } 
 fclose(F1); 
 fopen_s(&F1, "A9_2.txt", "r"); 
 fopen_s(&F2, "B9_2.txt", "w"); 
 while (fgets(str, 100, F1) != NULL) 
 { 
  if (strlen(str) - 1 > k) 
  { 
   fputs(str, F2); 
 
  } 
 } 
 
 cout << "\nСмотрите файлы\n "; 
 
 fclose(F1); 
 fclose(F2); 
 
}

void v10_1()
{
	setlocale(LC_ALL, "rus");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Компоненты файла fileA –  целые отличные от нуля числа: х, y1,... yn. Вывести на экран два члена этой последовательности, среднее арифметическое которых ближе всего к х.\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	int d, min = 0, x, a[n], k, z, y;
	
	FILE* A, * B;
	cout << "Введите размер послеледовательности:";
	cin >> k;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	fopen_s(&A, "A10.txt", "w");
	for (int i = 0; i < k; i++)
	{
		x = (rand() % 10);
		fprintf(A, "%d ", x);
		cout << x << " ";
		a[i] = x;
	}
	cout << endl;
	fclose(A);
	cout << "Введите x:";
	cin >> d;
	fopen_s(&A, "A10.txt", "r");
	fopen_s(&B, "B10.txt", "w");
	for (int i = 0; i < k - 1; i++)
	{
		if ((abs((a[i] + a[i + 1]) / 2 - d) == 0) || ((abs((a[i] + a[i + 1]) / 2 - d) > 0) && (abs((a[i] + a[i + 1]) / 2 - d) < 1))) {
			min = i;
			z = a[min];
			y = a[min + 1];
		}
	}
	cout << z << " and " << y;
	fprintf(B, "%d ", z);
	fprintf(B, "%d ", y);
	fclose(A);
	fclose(B);

}

void v10_2()
{
	setlocale(LC_ALL, "rus");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию. Скопировать в файл F2 только строки из F1, которые содержат цифры.\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	int i; char str[50], dts[50]; int j[10] = { 1,0,2,3,4,5,6,7,8,9 };
	FILE* F1, * F2;
	cout << "Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию. Скопировать в файл F2 только строки из F1, которые содержат цифры. " << endl;
	F1 = fopen("A10_2.txt", "wt");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (!F1)
	{
		printf("Error!");
		
	} fclose(F1);
	fopen_s(&F1, "A10_2.txt", "w");

	for (i = 1; i < 6; i++) {

		cout << "Введите cтроку " << i << ":";   gets_s(str);

		fputs(str, F1); fputs("\n", F1);


	}

	fclose(F1);

	int k = 0;

	F1 = fopen("A10_2.txt", "r");
	F2 = fopen("B10_2.txt", "w");

	if (!F2)
	{
		puts("Проблема с файлом F2.txt");
		
	}
	while (!feof(F1))
	{
		fgets(str, sizeof(str), F1);
		for (int i = 0; i < strlen(str); --i) {
			if (isdigit(str[i]))
				fputs(str, F2);
		}
	}
	printf("Данные успешно записаны в файл F2.txt\n");
	fclose(F2);
	fclose(F1);
}

void v11_1()
{
	setlocale(LC_ALL, "rus");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Компоненты файла fileA –  целые числа, значения которых повторяются.  Получить файл fileB, образованный из fileA числами, которые встречаются в A ровно 2 раза.\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	int size;
	FILE* fileA;
	FILE* fileB;
	fileA = fopen("A11.txt", "r");
	fscanf_s(fileA, "%d", &size);
	int* arr = new int[size];
	printf("fileA:   ");
	for (int i = 0; i < size; i++) {
		fscanf_s(fileA, "%d", &arr[i]);
		printf("%d   ", arr[i]);
	}
	fclose(fileA);
	fileB = fopen("B11.txt", "w");
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
}

void v11_2()
{
	setlocale(LC_ALL, "Rus");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию. Скопировать в файл F2 только те строки из F1, которые заканчиваются символом <<а>>.\n ";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	

		FILE* A;
		FILE* B;
		char array[100];
		int size;
		A = fopen("a11_2.txt", "r");
		B = fopen("b11_2.txt", "w");

		for (int i = 0; i < 6; i++) {
			fscanf(A, "%s", &array);
			cout << array << endl;
			size = strlen(array);
			if (array[size - 1] == 'a')
			{
				fprintf(B, " %s", array);
				fprintf(B, "\n");
			}
		}
		fclose(A);
		fclose(B);
		system("pause");
	
}

void v12_1()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Дан файл вещественных чисел, содержащий элементы квадратной матрицы по строкам, причем начальный элемент файла содержит значение количества столбцов матрицы. Создать новый файл той же структуры, содержащий k-ую строку исходной матрицы.\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	setlocale(LC_CTYPE, "Russian");

	int o, sum = 0, num1, numn, a;
	int g[100][100], z[100][100], l[100][100], s, d;
	FILE* A, * B, * C;
	cout << "Введите размеры  матрицы: ";
	cin >> o;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	fopen_s(&A, "A12.txt", "w");
	for (int i = 0; i <= o; i++)
	{
		for (int j = 0; j < o; j++)
		{
			if (i == 0 && j == 0)
			{
				fprintf(A, "%d ", o);
				fprintf(A, "\n");
			}
			s = rand() % 10;
			fprintf(A, "%d ", s);
			g[i][j] = s;
		}
		fprintf(A, "\n");
	}
	fclose(A);

	cout << " Введите номер строки:"; cin >> a;
	fopen_s(&A, "A12.txt", "r");
	fopen_s(&C, "C12.txt", "w");
	fprintf(C, "%d ", o);
	fprintf(C, "\n");
	for (int j = 0; j < o; j++)
	{

		fprintf(C, "%d ", g[a - 1][j]);
	}
	fprintf(C, "\n");

	fclose(C);
	fclose(A);
	
}

void v12_2()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Даны три файла целых чисел одинакового размера с именами NameA, NameB и NameC. Создать новый файл с именем NameD, в который записать минимальные элементы исходных файлов с одним и тем же номером: min(A0, B0, C0), min( A1, B1, C1), min(A2, B2, C2), ... \n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		int size;
		FILE* NameA;
		FILE* NameB;
		FILE* NameC;
		FILE* NameD;
		NameA = fopen("NameA12_2.txt", "r");
		fscanf_s(NameA, "%d", &size);
		NameB = fopen("NameB12_2.txt", "r");
		fscanf_s(NameB, "%d", &size);
		NameC = fopen("NameC12_2.txt", "r");
		fscanf_s(NameC, "%d", &size);
		int* arrA = new int[5];
		int* arrB = new int[5];
		int* arrC = new int[5];
		printf("NameA:  ");
		for (int i = 0; i < size; i++) {
			fscanf_s(NameA, "%d", &arrA[i]);
			printf("%d   ", arrA[i]);

		}printf("\nNameB:  ");
		for (int i = 0; i < size; i++) {
			fscanf_s(NameB, "%d", &arrB[i]);
			printf("%d   ", arrB[i]);

		}printf("\nNameC:  ");
		for (int i = 0; i < size; i++) {
			fscanf_s(NameC, "%d", &arrC[i]);
			printf("%d   ", arrC[i]);

		}
		fclose(NameA);
		fclose(NameB);
		fclose(NameC);
		int* arrD = new int[size];
		NameD = fopen("NameD12_2.txt", "w");
		int min = 0;
		for (int i = 0; i < size; i++) {
			if (arrA[i] < arrB[i] && arrA[i] < arrC[i])
			{
				min = arrA[i];
			}
			if (arrB[i] < arrA[i] && arrB[i] < arrC[i])
			{
				min = arrB[i];
			}
			if (arrC[i] < arrA[i] && arrC[i] < arrB[i])
			{
				min = arrC[i];
			}
			fprintf(NameD, "%d ", min);
		}



		fclose(NameD);
		
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
