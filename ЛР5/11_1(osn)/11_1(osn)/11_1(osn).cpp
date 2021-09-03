// 11_1(osn).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>		
#include<Windows.h>
#include <string>
using namespace std;
#define size 4




struct book {
	char sname[50];
	char tov[50];
	int count;
	int sum;
	struct Date {
		unsigned int day : 5;
		unsigned int mon : 5;
		unsigned int year : 12;
	}DT;
	int srok;

};
book arr[size];
int i = 0;
int oper;

void input();
void remove();
void output();
void search();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Что вы хотите сделать?\n";
	cout << "1 - Ввод данных в структуру\n";
	cout << "2 - Удаление данных из структуры\n";
	cout << "3 - Вывод данных на экран\n";
	cout << "4 - Поиск по пункту назначения\n";
	cout << "5 - Для завершения работы\n";
	cin >> oper;
	do {
		switch (oper)
		{
		case 1:  input(); break;
		case 2:  remove(); break;
		case 3:  output(); break;
		case 4:  search(); break;
		}
	} while (oper != 5);
	system("pause");
}

void input()
{
	int d;
	int m;
	int y;
	if (i < size)
	{
		cout << "Введите фамилию: ";
		cin >> arr[i].sname;
		cout << "Введите наим.тов.: ";
		cin >> arr[i].tov;
		cout << "Введите оценочную стоимость: ";
		cin >> arr[i].count;
		cout << "Введите сумму,выданную под залог: ";
		cin >> arr[i].sum;
		cout << "Дата сдачи(день,месяц,год): ";
		cin >> d >> m >> y;
		arr[i].DT.day = d;
		arr[i].DT.mon = m;
		arr[i].DT.year = y;
		cout << "Введите срок хранения: ";
		cin >> arr[i].srok;
		i++;
		cout << "-------------------------------------------" << endl;
	}
	else
		cout << "Введено максимальное кол-во строк!\n";
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void output()
{
	if (i > 0)
	{
		int n; 	int d;
		int m;
		int y;
		cout << "Введите номер элемента, который хотите вывести: "; cin >> n;
		n--;

		cout << "Фамилия: ";
		cout << arr[n].sname;
		cout << endl;
		cout << "Наименование товара: ";
		cout << arr[n].tov;
		cout << endl;
		cout << "Оценочная стоимость: ";
		cout << arr[n].count;
		cout << endl;
		cout << "Сумма,выданная под залог: ";
		cout << arr[n].sum;
		cout << endl;
		cout << "Дата сдачи: ";
		cout << arr[n].DT.day << "." << arr[n].DT.mon << "." << arr[n].DT.year;
		cout << endl;
		cout << "Срок хранения: ";
		cout << arr[n].srok;
		cout << endl;
		i++;
		cout << "-------------------------------------------" << endl;


	}
	else
		cout << "Недостаточно информации для вывода!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void remove()
{
	if (i > 0)
	{
		int d;
		cout << "Номер записи, которую нужно удалить: "; cin >> d;
		for (int de1 = (d - 1); de1 < i; de1++)
			arr[de1] = arr[de1 + 1];
		i--;
		cout << "Запись удалена" << endl;
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void search()
{
	int t, tt;
	if (i > 0)
	{
		cout << "Введите площадь: "; cin >> t;
		for (int k = 0; k < i; k++)
		{
			tt = arr[k].srok;
			if (tt == t)
			{
				cout << "Фамилия: ";
				cout << arr[k].sname;
				cout << endl;
				cout << "Наименование товара: ";
				cout << arr[k].tov;
				cout << endl;
				cout << "Оценочная стоимость: ";
				cout << arr[k].count;
				cout << endl;
				cout << "Сумма,выданная под залог: ";
				cout << arr[k].sum;
				cout << endl;
				cout << "Дата сдачи: ";
				cout << arr[k].DT.day << "." << arr[k].DT.mon << "." << arr[k].DT.year;
				cout << endl;
				cout << "Срок хранения: ";
				cout << arr[k].srok;
				cout << endl;
				}
				i++;
				cout << "-------------------------------------------" << endl;


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
