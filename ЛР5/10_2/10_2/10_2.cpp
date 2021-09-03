#include<iostream>		
#include<Windows.h>
#include <string>
using namespace std;
#define size 4


struct book {
	char name[50];
	int bithday;
	char adress[50];
	char gender [10];


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
	if (i < size)
	{
		cout << "Введите Ф.И.О: ";
		cin >> arr[i].name;
		cout << "Введите дату рождения(ДДММГГГГ): ";
		cin >> arr[i].bithday;
		cout << "Введите адрес: ";
		cin >> arr[i].adress;
		cout << "Введите пол(м,ж): ";
		cin >> arr[i].gender;
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
		int n; int d, m, g,a;
		cout << "Введите номер элемента, который хотите вывести: "; cin >> n;
		n--;
		a = arr[n].bithday;
		d = a / 1000000;
		m = (a - d * 1000000) / 10000;
		g = (a - d * 1000000 - m * 10000) / 1;
		cout << "Ф.И.О: ";
		cout << arr[n].name;
		cout << endl;
		cout << "Дата рождения: ";
		cout << d << "." << m << "." << g;
		cout << endl;
		cout << "Адрес: ";
		cout << arr[n].adress;
		cout << endl;
		cout << "Пол: ";
		cout << arr[n].gender;
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
	int t, tt,a,d,m,g;
	if (i > 0)
	{
		cout << "Введите дату рождения(ДДММГГГГ): "; cin >> t;
		for (int k = 0; k < i; k++)
		{
			a = arr[k].bithday;
			
			if (a == t)
			{
				
				d = a / 1000000;
				m = (a - d * 1000000) / 10000;
				g = (a - d * 1000000 - m * 10000) / 1;
				cout << "Ф.И.О: ";
				cout << arr[k].name;
				cout << endl;
				cout << "Дата рождения: ";
				cout << d << "." << m << "." << g;
				cout << endl;
				cout << "Адрес: ";
				cout << arr[k].adress;
				cout << endl;
				cout << "Пол: ";
				cout << arr[k].gender;
				cout << endl;
				i++;
				cout << "-------------------------------------------" << endl;


			}
		}
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}