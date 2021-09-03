// 9_2(osn).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

#define sizeS 30 
union UPuples
{
	char name[100];
	char numcl[50];
	char lessons[50];
	char marks[50];
	int sr_ball;
} pu;
struct Puples
{
	string name;
	string numcl;
	string lessons;
	string marks;
	int sr_ball;
};
struct Puples list_of_puple[sizeS], free_puple;
int current_size_pu = 0;
void out_pu();
void enter_new_pu();
void del_pu();
void main()
{
	setlocale(LC_CTYPE, "Rus");
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_pu();
			break;

		case(2):
			del_pu();
			break;

		case(3):
			out_pu();
			break;

		default:
			break;
		}
	}
}

void enter_new_pu()
{
	if (current_size_pu < sizeS)
	{
		cout << "\n Запись №" << current_size_pu + 1 << ": ";
		cout << "\n Введите Ф.И.О.: ";
		cin >> pu.name;
		list_of_puple[current_size_pu].name = pu.name;
		cout << "\n Введите класс(цифра+буква): ";
		cin >> pu.numcl;
		list_of_puple[current_size_pu].numcl = pu.numcl;
		cout << "\n Введите предметы(Математика, Информатика, КЯР и т.д.): ";
		cin >> pu.lessons;
		list_of_puple[current_size_pu].lessons = pu.lessons;
		cout << "\n Введите оценки по этим предметам: ";
		cin >> pu.marks;
		list_of_puple[current_size_pu].marks = pu.marks;
		cout << "\n Введите средний балл: ";
		cin >> pu.sr_ball;
		list_of_puple[current_size_pu].sr_ball = pu.sr_ball;
		current_size_pu++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_pu()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_puple[i] = free_puple;
		}
		current_size_pu = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_pu; i++)
		{
			list_of_puple[i] = list_of_puple[i + 1];
		}
		current_size_pu--;
	}
}

void out_pu()
{
	string name;
	cout << " Введите Ф.И.О. для поиска записи(для вывода всех записей введите -1): ";
	cin >> name;
	if (name == "-1")
	{
		for (int i = 0; i < current_size_pu; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Ф.И.О. - ";
			cout << list_of_puple[i].name;
			cout << " | Класс(ц+б) - ";
			cout << list_of_puple[i].numcl;
			cout << " | предметы - ";
			cout << list_of_puple[i].lessons;
			cout << " | оценки - ";
			cout << list_of_puple[i].marks;
			cout << " | средний балл - ";
			cout << list_of_puple[i].sr_ball;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_pu; i++)
		{
			if (list_of_puple[i].name == name)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Ф.И.О. - ";
				cout << list_of_puple[i].name;
				cout << " | Класс(ц+б) - ";
				cout << list_of_puple[i].numcl;
				cout << " | предметы - ";
				cout << list_of_puple[i].lessons;
				cout << " | оценки - ";
				cout << list_of_puple[i].marks;
				cout << " | средний балл - ";
				cout << list_of_puple[i].sr_ball;
				cout << endl;
			}
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

