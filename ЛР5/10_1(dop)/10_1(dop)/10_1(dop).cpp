#include<iostream>		
#include<Windows.h>
#include <string>
using namespace std;
#define size 4

enum Ds {
	Monarchy = 1, Democracy, Bureaucracy, Dictatorship, Communism, Colonialism
}ff;

struct book {
	char country[50];
	char capital[50];
	int count ;
	int S;
	int form = ff;

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
		cout << "Введите государствo: ";
		cin >>arr[i].country;
		cout << "Введите столицу госудраства: ";
		cin >> arr[i].capital;
		cout << "Введите численность населения: ";
		cin >> arr[i].count;
		cout << "Введите площать территорий,занимаемой гос.-ом(км^2): ";
		cin >> arr[i].S;
		cout << "Введите форму рпавления(1 - Монахрия, 2 - Демократия, 3 - Бюракратия, 4 - Диктатура,5 - Коммунизм, 6 - Колониализм): ";
		cin >> arr[i].form;
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
		int n; int d, m, d2, m2;
		cout << "Введите номер элемента, который хотите вывести: "; cin >> n;
		n--;
		
		cout << "Государствo: " ;
		cout<< arr[n].country;
		cout << endl;
		cout << "Столица госудраства: " ;
		cout<< arr[n].capital;
		cout << endl;
		cout << "Численность населения: " ;
		cout<< arr[n].count;
		cout << endl;
		cout << "Площать территорий,занимаемой гос.-ом(км^2): " ;
		cout<< arr[n].S;
		cout << endl;
		cout << "Форма правления: ";
		switch (arr[n].form) {
		case Monarchy: cout << "Монархия" << endl; 
			break;
		case Democracy: cout << "Демократия" << endl;
			break;
		case Bureaucracy: cout << "Бюракратия" << endl;
			break;
		case Dictatorship: cout << "Диктатура" << endl;
			break;
		case Communism: cout << "Коммунизм" << endl;
			break;
		case Colonialism: cout << "Колониализм" << endl;
			break;
		}
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
	 int t,tt;
	if (i > 0)
	{
		cout << "Введите площадь: "; cin >> t;
		for (int k = 0; k < i; k++)
		{
			tt = arr[k].S;
			if (tt > t)
			{
				cout << "Государствo: " ;
				cout << arr[k].country;
				cout << endl;
				cout << "Столица госудраства: " ;
				cout << arr[k].capital;
				cout << endl;
				cout << "Численность населения: " ;
				cout << arr[k].count;
				cout << endl;
				cout << "Площать территорий,занимаемой гос.-ом(км^2): " ;
				cout << arr[k].S;
				cout << endl;
				cout << "Форма правления: ";
				switch (arr[k].form) {
				case Monarchy: cout << "Монархия" << endl;
					break;
				case Democracy: cout << "Демократия" << endl;
					break;
				case Bureaucracy: cout << "Бюракратия" << endl;
					break;
				case Dictatorship: cout << "Диктатура" << endl;
					break;
				case Communism: cout << "Коммунизм" << endl;
					break;
				case Colonialism: cout << "Колониализм" << endl;
					break;
				}
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