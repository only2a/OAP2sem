#include<iostream>		
#include<Windows.h>
#include <string>
using namespace std;
#define size 4

enum Ds {
	MO = 1, Tu, We, Th, Fr, Sa, Su
}ride;

union ride2 {
	int numb;
	char punkt[50] ;
	int day = ride;
	int timeIn;
	int timeOUT;
	
}ridee;
struct book {
	int numb;
	string punkt;
	int day = ride;
	int timeIn:12;
	int timeOUT:12;
	
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
		cout << "Номер поезда: ";
		cin >> ridee.numb;
		arr[i].numb = ridee.numb;
		cout << "Введите пункт назначения : ";
		cin >> ridee.punkt ;
		arr[i].punkt=ridee.punkt ;
		cout << "Введите дни следования((1 - Понедельник, 2 - Вторник, 3 - Среда, 4 - Четверг, 5 - Пятница, 6 - Суббота, 7 - Воскресенье)): ";
		cin >> ridee.day;
		arr[i].day = ridee.day;
		cout << "Введите время прибытия(ЧЧММ): ";
		cin >> ridee.timeIn;
		arr[i].timeIn = ridee.timeIn;
		cout << "Введите время отправления(ЧЧММ): ";
		cin >> ridee.timeOUT;
		arr[i].timeOUT = ridee.timeOUT;
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
		int n; int d,m,d2,m2;
		cout << "Введите номер элемента, который хотите вывести: "; cin >> n;
		n--;
		d = arr[n].timeIn / 100;
		m = (arr[n].timeIn - d * 100) / 1;
		d2 = arr[n].timeOUT / 100;
		m2 = (arr[n].timeOUT - d2 * 100) / 1;
		cout << "Номер поезда: " << arr[n].numb;
		cout << endl;
		cout << "Пункт назначения : " << arr[n].punkt;
		cout << endl;
		cout << "Дни следования: ";
		switch (arr[n].day) {
		case MO: cout << "Понедельник" << endl;
			break;
		case Tu: cout << "Вторник" << endl;
			break;
		case We: cout << "Среда" << endl;
			break;
		case Th: cout << "Четверг" << endl;
			break;
		case Fr: cout << "Пятница" << endl;
			break;
		case Sa: cout << "Суббота" << endl;
			break;
		case Su: cout << "Воскресенье" << endl;
			break;
		}
		cout << "Время отправления: " << d2 << "ч " << m2 <<"мин"<< endl;
		cout << "Время прибытия: " << d << "ч " << m << "мин" << endl;
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
	 string t, punkt; int hours, minutes, hours2, minutes2;
	if (i > 0)
	{
		cout << "Введите пункт назначения: "; cin >> t;
		for (int k = 0; k < i; k++)
		{
			punkt = arr[k].punkt;
			if (punkt == t)
			{
				hours = arr[k].timeIn / 100;
				minutes = (arr[k].timeIn - (hours * 100)) / 1;
				hours2 = arr[k].timeOUT / 100;
				minutes2 = (arr[k].timeOUT - (hours2 * 100)) / 1;
				cout << "Номер поезда: " << arr[k].numb;
				cout << endl;
				cout << "Дни следования: ";
				switch (arr[k].day) {
				case MO: cout << "Понедельник" << endl;
					break;
				case Tu: cout << "Вторник" << endl;
					break;
				case We: cout << "Среда" << endl;
					break;
				case Th: cout << "Четверг" << endl;
					break;
				case Fr: cout << "Пятница" << endl;
					break;
				case Sa: cout << "Суббота" << endl;
					break;
				case Su: cout << "Воскресенье" << endl;
					break;
				}
				cout << "Время отправления: " << hours2<<"." <<minutes2 << endl;
				cout << "Время прибытия: " << hours << "." << minutes << endl;
				cout << "-------------------------------------------" << endl;
			}
		}
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}