// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

#define sizeS 30 

enum Ecar
{
	bmw, audi, mercedes
} car;

struct Car
{
	string brand;
	string color;
	int num;
	int date;
	string body;
	int dateI : 12;
	string owner;
};

struct Car list_of_car[sizeS], free_car;
int current_size_car = 0;

void var6_1();
void enter_new_car();
void del_car();
void out_car();

union UHRD
{
	char surname[50];
	char education[50];
	char specialty[50];
	char department[50];
	char post[50];
	int earn;
	int date;
} hrd2;

struct HRD2
{
	string surname;
	string education;
	string specialty;
	string department;
	string post;
	int earn;
	int date;
};

struct HRD2 list_of_HRD2[sizeS], free_HRD2;
int current_size_hrd2 = 0;

void var6_2();
void enter_new_hrd2();
void del_hrd2();
void out_hrd2();

enum Estorage
{
	пять, семь, одиннадцать, пятнадцать, двадцать, двадцать_пять, тридцать
} storage;

struct Storage
{
	string name;
	int cost;
	int amount;
	int percent : 7;
};

struct Storage list_of_storage[sizeS], free_storage;
int current_size_storage = 0;

void var7_1();
void enter_new_storage();
void del_storage();
void out_storage();

union Ustorage
{
	char name[50];
	int cost;
	int amount;
	int percent;
}stor2;

struct Storage2
{
	string name;
	int cost;
	int amount;
	int percent;
};

struct Storage list_of_storage2[sizeS], free_storage2;
int current_size_storage2 = 0;

void var7_2();
void enter_new_storage2();
void del_storage2();
void out_storage2();

enum Eflights
{
	Минск, Гродно, Москва
} flg;

struct Flights
{
	int num;
	string destination;
	int time;
	int date : 25;//ddmmyyyy
	int cost;
	int amount;
};

struct Flights list_of_flights[sizeS], free_flights;
int current_size_flights = 0;

void var8_1();
void enter_new_flights();
void del_flights();
void out_flights();

union Uflights2
{
	int num;
	char destination[50];
	int time;
	int date;
	int cost;
	int amount;
} flg2;

struct Flights2
{
	int num;
	string destination;
	int time;
	int date;
	int cost;
	int amount;
};

struct Flights2 list_of_flights2[sizeS], free_flights2;
int current_size_flights2 = 0;

void var8_2();
void enter_new_flights2();
void del_flights2();
void out_flights2();

enum Erailway
{
	пн, вт, ср, чт, пт, сб, вс
} rlw;

struct Railway
{
	int num;
	string destination;
	string days;
	int timein : 13;
	int timeout : 13;
};

struct Railway list_of_railway[sizeS], free_railway;
int current_size_railway = 0;

void var9_1();
void enter_new_railway();
void del_railway();
void out_railway();

union Ustudents
{
	char name[50];
	int classN;
	char classS;
	char subj[100];
	char mark[50];
	int avg;
} stud;

struct Students
{
	string name;
	int classN;
	char classS;
	string subj;
	string marks;
	int avg;
};

struct Students list_of_students[sizeS], free_students;
int current_size_students = 0;

void var9_2();
void enter_new_students();
void del_students();
void out_students();

void main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	bool work = true;
	int n;
	while (work)
	{
		cout << "\n1. Вариант 6(1)\n2. Вариант 6(2)\n1. Вариант 7(1)\n2. Вариант 7(2)\n1. Вариант 8(1)\n2. Вариант 8(2)\n1. Вариант 9(1)\n2. Вариант 9(2)\n0. Закончить\n(Введите вариант) ";
		cin >> n;
		switch (n)
		{
		case(1):
			var6_1();
			break;

		case(2):
			var6_2();
			break;

		case(3):
			var7_1();
			break;

		case(4):
			var7_2();
			break;

		case(5):
			var8_1();
			break;

		case(6):
			var8_2();
			break;

		case(7):
			var9_1();
			break;

		case(8):
			var9_2();
			break;

		case(0):
			work = false;
			break;

		default:
			break;
		}
	}
}

void var6_1()
{
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_car();
			break;

		case(2):
			del_car();
			break;

		case(3):
			out_car();
			break;

		default:
			break;
		}
	}
}

void enter_new_car()
{
	int q, date;
	if (current_size_car < sizeS)
	{
		cout << " Введите данные в формате: Марка автомобиля(bmw - 0, audi - 1, mercedes - 2) | цвет | заводской номер | дата выпуска | тип кузова | дата последнего техосмотра | владелец\n Запись №" << current_size_car + 1 << ": ";
		cin >> q;
		car = (Ecar)q;
		if (car == 0) list_of_car[current_size_car].brand = "bmw";
		else if (car == 1) list_of_car[current_size_car].brand = "audi";
		else list_of_car[current_size_car].brand = "mercedes";
		cin >> list_of_car[current_size_car].color;
		cin >> list_of_car[current_size_car].num;
		cin >> list_of_car[current_size_car].date;
		cin >> list_of_car[current_size_car].body;
		cin >> date;
		list_of_car[current_size_car].dateI = date;
		cin >> list_of_car[current_size_car].owner;
		current_size_car++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_car()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_car[i] = free_car;
		}
		current_size_car = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_car; i++)
		{
			list_of_car[i] = list_of_car[i + 1];
		}
		current_size_car--;
	}
}

void out_car()
{
	int num;
	cout << " Введите заводской номер для поиска записи(для вывода всех записей введите -1): ";
	cin >> num;
	if (num == -1)
	{
		for (int i = 0; i < current_size_car; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Марка автомобиля - ";
			cout << list_of_car[i].brand;
			cout << " | цвет - ";
			cout << list_of_car[i].color;
			cout << " | заводской номер - ";
			cout << list_of_car[i].num;
			cout << " | дата выпуска - ";
			cout << list_of_car[i].date;
			cout << " | тип кузова - ";
			cout << list_of_car[i].body;
			cout << " | дата последнего техосмотра - ";
			cout << list_of_car[i].dateI;
			cout << " | владелец - ";
			cout << list_of_car[i].owner;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_car; i++)
		{
			if (list_of_car[i].num == num)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Марка автомобиля - ";
				cout << list_of_car[i].brand;
				cout << " | цвет - ";
				cout << list_of_car[i].color;
				cout << " | заводской номер - ";
				cout << list_of_car[i].num;
				cout << " | дата выпуска - ";
				cout << list_of_car[i].date;
				cout << " | тип кузова - ";
				cout << list_of_car[i].body;
				cout << " | дата последнего техосмотра - ";
				cout << list_of_car[i].dateI;
				cout << " | владелец - ";
				cout << list_of_car[i].owner;
				cout << endl;
			}
		}
	}
}

void var6_2()
{
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_hrd2();
			break;

		case(2):
			del_hrd2();
			break;

		case(3):
			out_hrd2();
			break;

		default:
			break;
		}
	}
}

void enter_new_hrd2()
{
	int q, date;
	if (current_size_hrd2 < sizeS)
	{
		cout << " Введите данные в формате: Фамилия | образование | специальность | подразделение | должность | оклад | дата поступления на предприятие\n Запись №" << current_size_hrd2 + 1 << ": ";
		cin >> hrd2.surname;
		list_of_HRD2[current_size_hrd2].surname = hrd2.surname;
		cin >> hrd2.education;
		list_of_HRD2[current_size_hrd2].education = hrd2.education;
		cin >> hrd2.specialty;
		list_of_HRD2[current_size_hrd2].specialty = hrd2.specialty;
		cin >> hrd2.department;
		list_of_HRD2[current_size_hrd2].department = hrd2.department;
		cin >> hrd2.post;
		list_of_HRD2[current_size_hrd2].post = hrd2.post;
		cin >> hrd2.earn;
		list_of_HRD2[current_size_hrd2].earn = hrd2.earn;
		cin >> hrd2.date;
		list_of_HRD2[current_size_hrd2].date = hrd2.date;
		current_size_hrd2++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_hrd2()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_HRD2[i] = free_HRD2;
		}
		current_size_hrd2 = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_hrd2; i++)
		{
			list_of_HRD2[i] = list_of_HRD2[i + 1];
		}
		current_size_hrd2--;
	}
}

void out_hrd2()
{
	string num;
	cout << " Введите должность для поиска записи(для вывода всех записей введите -1): ";
	cin >> num;
	if (num == "-1")
	{
		for (int i = 0; i < current_size_hrd2; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Фамилия - ";
			cout << list_of_HRD2[i].surname;
			cout << " | образование - ";
			cout << list_of_HRD2[i].education;
			cout << " | специальность - ";
			cout << list_of_HRD2[i].specialty;
			cout << " | подразделение - ";
			cout << list_of_HRD2[i].department;
			cout << " | должность - ";
			cout << list_of_HRD2[i].post;
			cout << " | оклад - ";
			cout << list_of_HRD2[i].earn;
			cout << " | дата поступления на предприятие - ";
			cout << list_of_HRD2[i].date;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_hrd2; i++)
		{
			if (list_of_HRD2[i].post == num)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Фамилия - ";
				cout << list_of_HRD2[i].surname;
				cout << " | образование - ";
				cout << list_of_HRD2[i].education;
				cout << " | специальность - ";
				cout << list_of_HRD2[i].specialty;
				cout << " | подразделение - ";
				cout << list_of_HRD2[i].department;
				cout << " | должность - ";
				cout << list_of_HRD2[i].post;
				cout << " | оклад - ";
				cout << list_of_HRD2[i].earn;
				cout << " | дата поступления на предприятие - ";
				cout << list_of_HRD2[i].date;
				cout << endl;
			}
		}
	}
}

void var7_1()
{
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_storage();
			break;

		case(2):
			del_storage();
			break;

		case(3):
			out_storage();
			break;

		default:
			break;
		}
	}
}

void enter_new_storage()
{
	int q;
	if (current_size_storage < sizeS)
	{
		cout << " Введите данные в формате: Наименование товара | цена | количество | процент торговой надбавки (5 - 0, 7 - 1, 11 - 2, 20 - 3, 25 - 4, 30 - 5)\n Запись №" << current_size_storage + 1 << ": ";
		cin >> list_of_storage[current_size_storage].name;
		cin >> list_of_storage[current_size_storage].cost;
		cin >> list_of_storage[current_size_storage].amount;
		cin >> q;
		storage = (Estorage)q;
		switch (storage)
		{
		case 0:
			list_of_storage[current_size_storage].percent = 5;
			break;
		case 1:
			list_of_storage[current_size_storage].percent = 7;
			break;
		case 2:
			list_of_storage[current_size_storage].percent = 11;
			break;
		case 3:
			list_of_storage[current_size_storage].percent = 20;
			break;
		case 4:
			list_of_storage[current_size_storage].percent = 25;
			break;
		case 5:
			list_of_storage[current_size_storage].percent = 30;
			break;
		default:
			break;
		}
		current_size_storage++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_storage()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_storage[i] = free_storage;
		}
		current_size_storage = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_storage; i++)
		{
			list_of_storage[i] = list_of_storage[i + 1];
		}
		current_size_storage--;
	}
}

void out_storage()
{
	int num;
	cout << " Введите цену для поиска записи(для вывода всех записей введите -1): ";
	cin >> num;
	if (num == -1)
	{
		for (int i = 0; i < current_size_storage; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Наименование товара - ";
			cout << list_of_storage[i].name;
			cout << " | цена - ";
			cout << list_of_storage[i].cost;
			cout << " | количество - ";
			cout << list_of_storage[i].amount;
			cout << " | процент торговой надбавки - ";
			cout << list_of_storage[i].percent;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_storage; i++)
		{
			if (list_of_storage[i].cost == num)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Наименование товара - ";
				cout << list_of_storage[i].name;
				cout << " | цена - ";
				cout << list_of_storage[i].cost;
				cout << " | количество - ";
				cout << list_of_storage[i].amount;
				cout << " | процент торговой надбавки - ";
				cout << list_of_storage[i].percent;
				cout << endl;
			}
		}
	}
}

void var7_2()
{
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_storage2();
			break;

		case(2):
			del_storage2();
			break;

		case(3):
			out_storage2();
			break;

		default:
			break;
		}
	}
}

void enter_new_storage2()
{
	int q;
	if (current_size_storage2 < sizeS)
	{
		cout << " Введите данные в формате: Наименование товара | цена | количество | процент торговой надбавки \n Запись №" << current_size_storage2 + 1 << ": ";
		cin >> stor2.name;
		list_of_storage2[current_size_storage2].name = stor2.name;
		cin >> stor2.cost;
		list_of_storage2[current_size_storage2].cost = stor2.cost;
		cin >> stor2.amount;
		list_of_storage2[current_size_storage2].amount = stor2.amount;
		cin >> stor2.percent;
		list_of_storage2[current_size_storage2].percent = stor2.percent;
		current_size_storage2++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_storage2()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_storage2[i] = free_storage2;
		}
		current_size_storage2 = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_storage2; i++)
		{
			list_of_storage2[i] = list_of_storage2[i + 1];
		}
		current_size_storage2--;
	}
}

void out_storage2()
{
	string num;
	cout << " Введите наименование товара для поиска записи(для вывода всех записей введите -1): ";
	cin >> num;
	if (num == "-1")
	{
		for (int i = 0; i < current_size_storage2; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Наименование товара - ";
			cout << list_of_storage2[i].name;
			cout << " | цена - ";
			cout << list_of_storage2[i].cost;
			cout << " | количество - ";
			cout << list_of_storage2[i].amount;
			cout << " | процент торговой надбавки - ";
			cout << list_of_storage2[i].percent;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_storage2; i++)
		{
			if (list_of_storage2[i].name == num)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Наименование товара - ";
				cout << list_of_storage2[i].name;
				cout << " | цена - ";
				cout << list_of_storage2[i].cost;
				cout << " | количество - ";
				cout << list_of_storage2[i].amount;
				cout << " | процент торговой надбавки - ";
				cout << list_of_storage2[i].percent;
				cout << endl;
			}
		}
	}
}

void var8_1()
{
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_flights();
			break;

		case(2):
			del_flights();
			break;

		case(3):
			out_flights();
			break;

		default:
			break;
		}
	}
}

void enter_new_flights()
{
	int q;
	if (current_size_flights < sizeS)
	{
		cout << " Введите данные в формате: Номер рейса | пункт назначения(Минск - 0, Гродно - 1, Москва - 2) | время вылета | дата вылета | стоимость билета | количество мест\n Запись №" << current_size_flights + 1 << ": ";
		cin >> list_of_flights[current_size_flights].num;
		cin >> q;
		flg = (Eflights)q;
		if (flg == 0) list_of_flights[current_size_flights].destination = "Гродно";
		else if (flg == 1) list_of_flights[current_size_flights].destination = "Минск";
		else list_of_flights[current_size_flights].destination = "Москва";
		cin >> list_of_flights[current_size_flights].time;
		cin >> q;
		list_of_flights[current_size_flights].date = q;
		cin >> list_of_flights[current_size_flights].cost;
		cin >> list_of_flights[current_size_flights].amount;
		current_size_flights++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_flights()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_flights[i] = free_flights;
		}
		current_size_flights = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_flights; i++)
		{
			list_of_flights[i] = list_of_flights[i + 1];
		}
		current_size_flights--;
	}
}

void out_flights()
{
	int num;
	cout << " Введите дату вылета для поиска записи(для вывода всех записей введите -1): ";
	cin >> num;
	if (num == -1)
	{
		for (int i = 0; i < current_size_flights; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Номер рейса - ";
			cout << list_of_flights[i].num;
			cout << " | пункт назначения - ";
			cout << list_of_flights[i].destination;
			cout << " | время вылета - ";
			cout << list_of_flights[i].time;
			cout << " | пункт назначения - ";
			cout << list_of_flights[i].date;
			cout << " | стоимость билета - ";
			cout << list_of_flights[i].cost;
			cout << " | количество билетов - ";
			cout << list_of_flights[i].amount;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_flights; i++)
		{
			if (list_of_flights[i].date == num)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Номер рейса - ";
				cout << list_of_flights[i].num;
				cout << " | пункт назначения - ";
				cout << list_of_flights[i].destination;
				cout << " | время вылета - ";
				cout << list_of_flights[i].time;
				cout << " | пункт назначения - ";
				cout << list_of_flights[i].date;
				cout << " | стоимость билета - ";
				cout << list_of_flights[i].cost;
				cout << " | количество билетов - ";
				cout << list_of_flights[i].amount;
				cout << endl;
			}
		}
	}
}

void var8_2()
{
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_flights2();
			break;

		case(2):
			del_flights2();
			break;

		case(3):
			out_flights2();
			break;

		default:
			break;
		}
	}
}

void enter_new_flights2()
{
	int q;
	if (current_size_flights2 < sizeS)
	{
		cout << " Введите данные в формате: Номер рейса | пункт назначения | время вылета | дата вылета | стоимость билета | количество мест\n Запись №" << current_size_flights2 + 1 << ": ";
		cin >> flg2.num;
		list_of_flights2[current_size_flights2].num = flg2.num;
		cin >> flg2.destination;
		list_of_flights2[current_size_flights2].destination = flg2.destination;
		cin >> flg2.time;
		list_of_flights2[current_size_flights2].time = flg2.time;
		cin >> flg2.date;
		list_of_flights2[current_size_flights2].date = flg2.date;
		cin >> flg2.cost;
		list_of_flights2[current_size_flights2].cost = flg2.cost;
		cin >> flg2.amount;
		list_of_flights2[current_size_flights2].amount = flg2.amount;
		current_size_flights2++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_flights2()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_flights2[i] = free_flights2;
		}
		current_size_flights2 = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_flights2; i++)
		{
			list_of_flights2[i] = list_of_flights2[i + 1];
		}
		current_size_flights2--;
	}
}

void out_storage()
{
	string num;
	cout << " Введите дату вылета для поиска записи(для вывода всех записей введите -1): ";
	cin >> num;
	if (num == "-1")
	{
		for (int i = 0; i < current_size_flights2; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Номер рейса - ";
			cout << list_of_flights2[i].num;
			cout << " | пункт назначения - ";
			cout << list_of_flights2[i].destination;
			cout << " | время вылета - ";
			cout << list_of_flights2[i].time;
			cout << " | пункт назначения - ";
			cout << list_of_flights2[i].date;
			cout << " | стоимость билета - ";
			cout << list_of_flights2[i].cost;
			cout << " | количество билетов - ";
			cout << list_of_flights2[i].amount;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_flights2; i++)
		{
			if (list_of_flights2[i].destination == num)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Номер рейса - ";
				cout << list_of_flights2[i].num;
				cout << " | пункт назначения - ";
				cout << list_of_flights2[i].destination;
				cout << " | время вылета - ";
				cout << list_of_flights2[i].time;
				cout << " | пункт назначения - ";
				cout << list_of_flights2[i].date;
				cout << " | стоимость билета - ";
				cout << list_of_flights2[i].cost;
				cout << " | количество билетов - ";
				cout << list_of_flights2[i].amount;
				cout << endl;
			}
		}
	}
}

void va9_1()
{
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_railway();
			break;

		case(2):
			del_railway();
			break;

		case(3):
			out_railway();
			break;

		default:
			break;
		}
	}
}

void enter_new_railway()
{
	int q;
	if (current_size_railway < sizeS)
	{
		cout << " Введите данные в формате: Номер поезда | пункт назначения | дни следования(введите кол-во дней, затем индексы: пн - 0, вт - 1, ср - 2, чт - 3, пт - 4, сб - 5, вс - 6) | время прибытия | время отправления\n Запись №" << current_size_railway + 1 << ": ";
		cin >> list_of_railway[current_size_railway].num;
		cin >> list_of_railway[current_size_railway].destination;
		cin >> q;
		for (size_t i = 0; i < q; i++)
		{
			cin >> q;
			rlw = (Erailway)q;
			switch (rlw)
			{
			case пн:
				list_of_railway[current_size_railway].days += " пн";
				break;
			case вт:
				list_of_railway[current_size_railway].days += " вт";
				break;
			case ср:
				list_of_railway[current_size_railway].days += " ср";
				break;
			case чт:
				list_of_railway[current_size_railway].days += " чт";
				break;
			case пт:
				list_of_railway[current_size_railway].days += " пт";
				break;
			case сб:
				list_of_railway[current_size_railway].days += " сб";
				break;
			case вс:
				list_of_railway[current_size_railway].days += " вс";
				break;
			default:
				break;
			}
		}
		cin >> q;
		list_of_railway[current_size_railway].timein = q;
		cin >> q;
		list_of_railway[current_size_railway].timeout = q;
		current_size_railway++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_railway()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_railway[i] = free_railway;
		}
		current_size_railway = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_railway; i++)
		{
			list_of_railway[i] = list_of_railway[i + 1];
		}
		current_size_railway--;
	}
}

void out_railway()
{
	string num;
	cout << " Введите пункт назначение для поиска записи(для вывода всех записей введите -1): ";
	cin >> num;
	if (num == "-1")
	{
		for (int i = 0; i < current_size_railway; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Номер поезда - ";
			cout << list_of_railway[i].num;
			cout << " | пункт назначения - ";
			cout << list_of_railway[i].destination;
			cout << " | дни следования - ";
			cout << list_of_railway[i].days;
			cout << " | время прибытия - ";
			cout << list_of_railway[i].timein;
			cout << " | время отправления - ";
			cout << list_of_railway[i].timeout;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_railway; i++)
		{
			if (list_of_railway[i].destination == num)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Номер поезда - ";
				cout << list_of_railway[i].num;
				cout << " | пункт назначения - ";
				cout << list_of_railway[i].destination;
				cout << " | дни следования - ";
				cout << list_of_railway[i].days;
				cout << " | время прибытия - ";
				cout << list_of_railway[i].timein;
				cout << " | время отправления - ";
				cout << list_of_railway[i].timeout;
				cout << endl;
			}
		}
	}
}

void var9_2()
{
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_students();
			break;

		case(2):
			del_students();
			break;

		case(3):
			out_students();
			break;

		default:
			break;
		}
	}
}

void enter_new_students()
{
	int q;
	if (current_size_students < sizeS)
	{
		cout << " Введите данные в формате: Фамилия | класс цифра | класс буква | кол-во предметов | предметы | оценки | средний балл\n Запись №" << current_size_students + 1 << ": ";
		cin >> stud.name;
		list_of_students[current_size_students].name = stud.name;
		cin >> stud.classN;
		list_of_students[current_size_students].classN = stud.classN;
		cin >> stud.classS;
		list_of_students[current_size_students].classS = stud.classS;
		cin >> q;
		for (size_t i = 0; i < q; i++)
		{
			cin >> stud.subj;
			list_of_students[current_size_students].subj += stud.subj;
			list_of_students[current_size_students].subj += " ";
		}
		for (size_t i = 0; i < q; i++)
		{
			cin >> stud.mark;
			list_of_students[current_size_students].marks += stud.mark;
			list_of_students[current_size_students].marks += " ";
		}
		cin >> stud.avg;
		list_of_students[current_size_students].avg = stud.avg;
		current_size_students++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_students()
{
	int d;
	cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_students[i] = free_students;
		}
		current_size_students = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_students; i++)
		{
			list_of_students[i] = list_of_students[i + 1];
		}
		current_size_students--;
	}
}

void out_students()
{
	string num;
	cout << " Введите фамилию для поиска записи(для вывода всех записей введите -1): ";
	cin >> num;
	if (num == "-1")
	{
		for (int i = 0; i < current_size_students; i++)
		{
			cout << "Запись №";
			cout << i + 1;
			cout << ": Фамилия - ";
			cout << list_of_students[i].name;
			cout << " | класс - ";
			cout << list_of_students[i].classN << list_of_students[i].classS;
			cout << " | предметы - ";
			cout << list_of_students[i].subj;
			cout << " | оценки - ";
			cout << list_of_students[i].marks;
			cout << " | средний балл - ";
			cout << list_of_students[i].avg;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_students; i++)
		{
			if (list_of_students[i].name == num)
			{
				cout << "Запись №";
				cout << i + 1;
				cout << ": Фамилия - ";
				cout << list_of_students[i].name;
				cout << " | класс - ";
				cout << list_of_students[i].classN << list_of_students[i].classS;
				cout << " | предметы - ";
				cout << list_of_students[i].subj;
				cout << " | оценки - ";
				cout << list_of_students[i].marks;
				cout << " | средний балл - ";
				cout << list_of_students[i].avg;
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
