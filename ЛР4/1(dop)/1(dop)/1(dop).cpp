

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#define str_len 40                               
#define sizeS 30  
#define trains_len 8
string A = "A.txt";
char str[512];

struct Stu
{
	char name[str_len];
	int date_of_in;
	char sp[str_len];
	char numgr[str_len];
	char f[str_len];
	char sr[str_len];
};

struct Students
{
	char name[str_len];
	int amount_exams;
	int* marks = new int[amount_exams];
};

struct Trains
{
	char name[str_len];
	int num;
	int time;
};

struct Sanatorium
{
	char name[str_len];
	char location[str_len];
	char profile[str_len];
	int amount;
};
struct Stu list_of_stu[sizeS], free_students;
int current_size = 0;

struct Students list_of_students[sizeS], free_student;
int current_size_st = 0;

struct Trains list_of_trains[trains_len], free_train, help_train;
int current_size_tr = 0;

struct Sanatorium list_of_sanatorium[sizeS], free_sanatorim, help_sanatorim;
int current_size_sn = 0;

void osn();
void enter_new();
void del(int d);
void out();
void write_file();
void read_file();

void dop1();
void enter_new_st();
void del_st(int d);
void out_st();
void write_file_st();
void performance();
void read_file_st();;

void dop2();
void enter_new_tr();
void del_tr(int d);
void out_tr();
void write_file_tr();
void sorting();
void read_file_tr();

void dop3();
void enter_new_sn();
void del_sn(int d);
void out_sn();
void write_file_sn();
void sorting_sn();
void read_file_sn();

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	bool work = true;
	int n;
	while (work)
	{
		cout << "\n1. Вариант 9\n2. Доп 1\n3. Доп 2\n4. Доп 3\n0. Закончить\n(Введите вариант) ";
		cin >> n;
		switch (n)
		{
		case(1):
			osn();
			break;

		case(2):
			dop1();
			break;

		case(3):
			dop2();
			break;

		case(4):
			dop3();
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
	int choice = 1, d;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new();
			break;

		case(2):
			cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
			cin >> d;
			del(d);
			break;

		case(3):
			out();
			break;

		case(4):
			write_file();
			break;

		case(5):
			read_file();
			break;

		default:
			break;
		}
	}
}

void enter_new()
{
	if (current_size < sizeS)
	{
		cout << " Введите данные в формате: Фамилия | дата поступления | специальность | группа | факультет | средний балл:\n Запись №" << current_size + 1 << ": ";
		cin >> list_of_stu[current_size].name >> list_of_stu[current_size].date_of_in >> list_of_stu[current_size].sp >> list_of_stu[current_size].numgr >> list_of_stu[current_size].f>> list_of_stu[current_size].sr;
		current_size++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del(int d)
{
	if (d == -1)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_stu[i] = free_students;
		}
		current_size = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size; i++)
		{
			list_of_stu[i] = list_of_stu[i + 1];
		}
		current_size--;
	}
}

void out()
{
	string name, num;
	cout << " Введите фамилию для поиска записи(для вывода всех записей введите 1): ";
	cin >> name;
	if (name == "1")
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << " Запись №" << i + 1 << ": Фамилия - " << list_of_stu[i].name << " | дата поступления - " << list_of_stu[i].date_of_in << " | специальность - " << list_of_stu[i].sp << " | группа- " << list_of_stu[i].numgr << " | факультет - " << list_of_stu[i].f << " | средний балл - " << list_of_stu[i].sr << endl;

		}
	}
	else
	{
		for (int i = 0; i < current_size; i++)
		{
			if (list_of_stu[i].name==name)
			{
				cout << " Запись №" << i + 1 << ": Фамилия - " << list_of_stu[i].name << " | дата поступления - " << list_of_stu[i].date_of_in << " | специальность - " << list_of_stu[i].sp << " | группа- " << list_of_stu[i].numgr << " | факультет - " << list_of_stu[i].f << " | средний балл - " << list_of_stu[i].sr << endl;
			}
		}
	}
}

void write_file()
{
	ofstream fAout(A);
	if (fAout.is_open())
	{
		for (int i = 0; i < current_size; i++)
		{
			fAout << list_of_stu[i].name << "\n";
			fAout << list_of_stu[i].date_of_in << "\n";
			fAout << list_of_stu[i].sp << "\n";
			fAout << list_of_stu[i].numgr << "\n";
			fAout << list_of_stu[i].f << "\n";
			fAout << list_of_stu[i].sr << "\n";
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}

void read_file()
{
	del(-1);
	char str2[200], str3[200], str4[200],str5[200],str6[200];
	ifstream fAin(A);
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(list_of_stu[current_size].name, sizeof(list_of_stu[current_size].name));
			fAin.getline(str2, sizeof(str2));
			list_of_stu[current_size].date_of_in = atoi(str2);
			fAin.getline(list_of_stu[current_size].sp, sizeof(list_of_stu[current_size].sp));
			fAin.getline(list_of_stu[current_size].numgr, sizeof(list_of_stu[current_size].numgr));
			fAin.getline(list_of_stu[current_size].f, sizeof(list_of_stu[current_size].f));
			fAin.getline(list_of_stu[current_size].sr, sizeof(list_of_stu[current_size].sr));
			if (fAin.eof() != 0) break;
			current_size++;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
}

void dop1()
{
	int choice = 1, d;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n6. Успеваемость\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_st();
			break;

		case(2):
			cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
			cin >> d;
			del_st(d);
			break;

		case(3):
			out_st();
			break;

		case(4):
			write_file_st();
			break;

		case(5):
			read_file_st();
			break;

		case(6):
			performance();
			break;

		default:
			break;
		}
	}
}

void enter_new_st()
{
	if (current_size_st < sizeS)
	{
		cout << " Введите данные в формате: Фамилия | число экзаменов | отметки(через пробел)\n Запись №" << current_size_st + 1 << ": ";
		cin >> list_of_students[current_size_st].name >> list_of_students[current_size_st].amount_exams;
		for (int i = 0; i < list_of_students[current_size_st].amount_exams; i++)
		{
			cin >> list_of_students[current_size_st].marks[i];
		}
		current_size_st++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_st(int d)
{
	if (d == -1)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_students[i] = free_student;
		}
		current_size_st = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_st; i++)
		{
			list_of_students[i] = list_of_students[i + 1];
		}
		current_size_st--;
	}
}

void out_st()
{
	string name, num;
	cout << " Введите фамилию для поиска записи(для вывода всех записей введите 1): ";
	cin >> name;
	if (name == "1")
	{
		for (int i = 0; i < current_size_st; i++)
		{
			cout << " Запись №" << i + 1 << " | Фамилия - " << list_of_students[i].name << " | кол-во экзаменов - " << list_of_students[i].amount_exams;
			for (int j = 0; j < list_of_students[i].amount_exams; j++)
			{
				cout << " | отметка за " << j + 1 << "-й экзамен - " << list_of_students[i].marks[j];
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_st; i++)
		{
			if (list_of_students[i].name == name)
			{
				cout << " Запись №" << i + 1 << " | Фамилия - " << list_of_students[i].name << " | кол-во экзаменов - " << list_of_students[i].amount_exams;
				for (int j = 0; j < list_of_students[i].amount_exams; j++)
				{
					cout << " | отметка за " << j + 1 << "-й экзамен - " << list_of_students[i].marks[j];
				}
				cout << endl;
			}
		}
	}
}

void write_file_st()
{
	ofstream fAout(A);
	if (fAout.is_open())
	{
		for (int i = 0; i < current_size_st; i++)
		{
			fAout << list_of_students[i].name << "\n";
			fAout << list_of_students[i].amount_exams << "\n";
			for (int j = 0; j < list_of_students[i].amount_exams; j++)
			{
				fAout << list_of_students[i].marks[j] << "\n";
			}
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}

void read_file_st()
{
	del_st(-1);
	char str2[200], str3[200];
	ifstream fAin(A);
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(list_of_students[current_size_st].name, sizeof(list_of_students[current_size_st].name));
			fAin.getline(str2, sizeof(str2));
			if (fAin.eof() != 0) break;
			list_of_students[current_size_st].amount_exams = atoi(str2);
			for (int i = 0; i < list_of_students[current_size_st].amount_exams; i++)
			{
				fAin.getline(str2, sizeof(str2));
				list_of_students[current_size_st].marks[i] = atoi(str2);
			}
			current_size_st++;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
}

void performance()
{
	float num = 0;
	for (int i = 0; i < current_size_st; i++)
	{
		for (int j = 0; j < list_of_students[i].amount_exams; j++)
		{
			if (list_of_students[i].marks[j] < 4) break;
			if (j == list_of_students[i].amount_exams - 1) num++;
		}
	}
	cout << "Процент студентов, сдавших экзамены на 4 и 5 = " << num / current_size_st * 100 << "%" << endl;
}

void dop2()
{
	int choice = 1, d;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n6. Сортировка\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_tr();
			break;

		case(2):
			cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
			cin >> d;
			del_tr(d);
			break;

		case(3):
			out_tr();
			break;

		case(4):
			write_file_tr();
			break;

		case(5):
			read_file_tr();
			break;

		case(6):
			sorting();
			break;

		default:
			break;
		}
	}
}

void enter_new_tr()
{
	if (current_size_tr < trains_len)
	{
		cout << " Введите данные в формате: названия пункта назначения | номер поезда | время отправления\n Запись №" << current_size_tr + 1 << ": ";
		cin >> list_of_trains[current_size_tr].name >> list_of_trains[current_size_tr].num >> list_of_trains[current_size_tr].time;
		current_size_tr++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_tr(int d)
{
	if (d == -1)
	{
		for (int i = 0; i < trains_len; i++)
		{
			list_of_trains[i] = free_train;
		}
		current_size_tr = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_tr; i++)
		{
			list_of_trains[i] = list_of_trains[i + 1];
		}
		current_size_tr--;
	}
}

void out_tr()
{
	int t, q = 0;
	cout << "Введите время: ";
	cin >> t;
	for (int i = 0; i < current_size_tr; i++)
	{
		if (list_of_trains[i].time >= t)
		{
			cout << " Запись №" << i + 1 << " | названия пункта назначения - " << list_of_trains[i].name << " | номер поезда - " << list_of_trains[i].num << " | время отправления - " << list_of_trains[i].time << endl;
			q++;
		}
	}
	if (q == 0) cout << "Таких поездов нет" << endl;
}

void write_file_tr()
{
	ofstream fAout(A);
	if (fAout.is_open())
	{
		for (int i = 0; i < current_size_tr; i++)
		{
			fAout << list_of_trains[i].name << endl;;
			fAout << list_of_trains[i].num << endl;;
			fAout << list_of_trains[i].time << endl;;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}

void read_file_tr()
{
	del_tr(-1);
	char str2[200], str3[200];
	ifstream fAin(A);
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(list_of_trains[current_size_tr].name, sizeof(list_of_trains[current_size_tr].name));
			fAin.getline(str2, sizeof(str2));
			fAin.getline(str3, sizeof(str3));
			if (fAin.eof() != 0) break;
			list_of_trains[current_size_tr].num = atoi(str2);
			list_of_trains[current_size_tr].time = atoi(str3);
			current_size_tr++;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
}

void sorting()
{
	int q, i;
	for (i = 0; i < current_size_tr - 1; i++)
	{
		q = (strlen(list_of_trains[i].name) > strlen(list_of_trains[i + 1].name)) ? strlen(list_of_trains[i + 1].name) : strlen(list_of_trains[i].name);
		for (int j = 0; j < q; j++)
		{
			if (list_of_trains[i].name[j] < list_of_trains[i + 1].name[j]) break;
			if (list_of_trains[i].name[j] > list_of_trains[i + 1].name[j])
			{
				help_train = list_of_trains[i + 1];
				list_of_trains[i + 1] = list_of_trains[i];
				list_of_trains[i] = help_train;
				i = -1;
				break;
			}
		}
	}
}

void dop3()
{
	int choice = 1, d;

	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n6. Сортировка\n0. Завершить работу\n(Введите выбор) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			enter_new_sn();
			break;

		case(2):
			cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
			cin >> d;
			del_sn(d);
			break;

		case(3):
			out_sn();
			break;

		case(4):
			write_file_sn();
			break;

		case(5):
			read_file_sn();
			break;

		case(6):
			sorting_sn();
			break;

		default:
			break;
		}
	}

}

void enter_new_sn()
{
	if (current_size_sn < sizeS)
	{
		cout << " Введите данные в формате: Название санатория | Место расположения | Лечебный профиль | Количество путевок\n Запись №" << current_size_sn + 1 << ": ";
		cin >> list_of_sanatorium[current_size_sn].name >> list_of_sanatorium[current_size_sn].location >> list_of_sanatorium[current_size_sn].profile >> list_of_sanatorium[current_size_sn].amount;
		current_size_sn++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_sn(int d)
{
	if (d == -1)
	{
		for (int i = 0; i < sizeS; i++)
		{
			list_of_sanatorium[i] = free_sanatorim;
		}
		current_size_sn = 0;
	}
	else
	{
		for (int i = d - 1; i < current_size_sn; i++)
		{
			list_of_sanatorium[i] = list_of_sanatorium[i + 1];
		}
		current_size_sn--;
	}
}

void out_sn()
{
	string name, num;
	cout << " Введите название санатория для поиска записи(для вывода всех записей введите 1): ";
	cin >> name;
	if (name == "1")
	{
		for (int i = 0; i < current_size_sn; i++)
		{
			cout << " Запись №" << i + 1 << " | название санатория - " << list_of_sanatorium[i].name << " | место расположения - " << list_of_sanatorium[i].location << " | лечебный профиль - " << list_of_sanatorium[i].profile << " | кол-во путёвок - " << list_of_sanatorium[i].amount << endl;
		}
	}
	else
	{
		for (int i = 0; i < current_size_sn; i++)
		{
			if (list_of_sanatorium[i].name == name)
			{
				cout << " Запись №" << i + 1 << " | название санатория - " << list_of_sanatorium[i].name << " | место расположения - " << list_of_sanatorium[i].location << " | лечебный профиль - " << list_of_sanatorium[i].profile << " | кол-во путёвок - " << list_of_sanatorium[i].amount << endl;
			}
		}
	}
}

void write_file_sn()
{
	ofstream fAout(A);
	if (fAout.is_open())
	{
		for (int i = 0; i < current_size_sn; i++)
		{
			fAout << list_of_sanatorium[i].name << endl;
			fAout << list_of_sanatorium[i].location << endl;
			fAout << list_of_sanatorium[i].profile << endl;
			fAout << list_of_sanatorium[i].amount << endl;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}

void read_file_sn()
{
	del_sn(-1);
	char str4[200];
	ifstream fAin(A);
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(list_of_sanatorium[current_size_sn].name, sizeof(list_of_sanatorium[current_size_sn].name));
			fAin.getline(list_of_sanatorium[current_size_sn].location, sizeof(list_of_sanatorium[current_size_sn].location));
			fAin.getline(list_of_sanatorium[current_size_sn].profile, sizeof(list_of_sanatorium[current_size_sn].profile));
			fAin.getline(str4, sizeof(str4));
			if (fAin.eof() != 0) break;
			list_of_sanatorium[current_size_sn].amount = atoi(str4);
			current_size_sn++;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
}

void sorting_sn()
{
	int q, n;
	for (int i = 0; i < current_size_sn - 1; i++)
	{
		q = (strlen(list_of_sanatorium[i].name) > strlen(list_of_sanatorium[i + 1].name)) ? strlen(list_of_sanatorium[i + 1].name) : strlen(list_of_sanatorium[i].name);
		for (int j = 0; j < q; j++)
		{
			if (list_of_sanatorium[i].name[j] < list_of_sanatorium[i + 1].name[j]) break;
			if (list_of_sanatorium[i].name[j] > list_of_sanatorium[i + 1].name[j])
			{
				help_sanatorim = list_of_sanatorium[i + 1];
				list_of_sanatorium[i + 1] = list_of_sanatorium[i];
				list_of_sanatorium[i] = help_sanatorim;
				i = -1;
				break;
			}
		}
	}

	n = 0;
	for (int k = 0; k < current_size_sn; k++)
	{
		if (list_of_sanatorium[k].name != list_of_sanatorium[k + 1].name)
		{
			for (int i = n; i < k; i++)
			{
				q = (strlen(list_of_sanatorium[i].profile) > strlen(list_of_sanatorium[i + 1].profile)) ? strlen(list_of_sanatorium[i + 1].profile) : strlen(list_of_sanatorium[i].profile);
				for (int j = 0; j < q; j++)
				{
					if (list_of_sanatorium[i].profile[j] < list_of_sanatorium[i + 1].profile[j]) break;
					if (list_of_sanatorium[i].profile[j] > list_of_sanatorium[i + 1].profile[j])
					{
						help_sanatorim = list_of_sanatorium[i + 1];
						list_of_sanatorium[i + 1] = list_of_sanatorium[i];
						list_of_sanatorium[i] = help_sanatorim;
						i = -1;
						break;
					}
				}
			}
			n = k;
		}
	}
}
