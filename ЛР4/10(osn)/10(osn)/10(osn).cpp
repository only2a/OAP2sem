// Справочник автомобилей. Марка автомобиля, цвет, заводской номер, дата выпуска, тип кузова (седан, универсал и т. п.), дата последнего техосмотра, владелец. Выбор транспортных средств по владельцу.
//


#include <fstream>
#include <iostream>
#include<Windows.h>
using namespace std;
#define size 1


struct univ {
		char name[20];
		char color[20];
		int num;
		int date;
		char type[20];
		int date2;
		char owner[20];
	};
univ arr[size];
int i = 0;
int oper;

void input();
void remove();
void output();
void search();
void infile();
void outfile();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	do {
		cout << "Что вы хотите сделать?\n";
		cout << "1 - Ввод данных в структуру\n";
		cout << "2 - Удаление данных из структуры\n";
		cout << "3 - Вывод данных на экран\n";
		cout << "4 - Поиск по владельцу\n";
		cout << "5 - Запись в файл\n";
		cout << "6 - Чтение из файла\n";
		cout << "7 - Для завершения работы\n";
		cin >> oper;
		switch (oper)
		{
		case 1:  input(); break;
		case 2:  remove(); break;
		case 3:  output(); break;
		case 4:  search(); break;
		case 5:  infile(); break;
		case 6:  outfile(); break;
		case 7: break;
		}
	} while (oper != 7);
	system("pause");
}

void input()
{
	while(i < size)
	{
		
		cout << "Введите марку автомобиля: ";
		cin >> arr[i].name;
		cout << "Введите цвет автомобиля: ";
		cin >> arr[i].color;
		cout << "Введите заводской номер: ";
		cin >> arr[i].num;
		cout << "Введите дату выпуска авт.(ДДММГГГГ): ";
		cin >> arr[i].date;
		cout << "Введите тип кузова авт.: ";
		cin >> arr[i].type;
		cout << "Введите дату последнего техосмотра авт.(ДДММГГГГ): ";
		cin >> arr[i].date2;
		cout << "Введите фамилию владельца: ";
		cin >> arr[i].owner;
		
		i++;
		cout << "-------------------------------------------" << endl;
	}
	
}
void output()
{
	if (i > 0)
	{
		int n;
		cout << "Введите номер элемента, который хотите вывести: "; cin >> n;
		n--;
		cout << "Mаркa автомобиля: ";
		for (i = 0; i < 4; i++)
		{
			cout << arr[n].name[i];
		}
		cout << endl;
		cout << "Цвет: " << arr[n].color << endl;
		cout << "Заводской номер: " << arr[n].num << endl;
		cout << "Дата выпуска: " << arr[n].date << endl;
		cout << "Тип кузова: " << arr[n].type << endl;
		cout << "Дата последнего техосмотра: " << arr[n].date2 << endl;
		cout << "Фамилия владельца: " << arr[n].owner << endl;
	
	}
	cout << "-------------------------------------------" << endl;
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
	cout << "-------------------------------------------" << endl;
}
void search()
{
	string t, owner;
	if (i > 0)
	{
		cout << "Введите фамилию владельца: "; cin >> t;
		for (int k = 0; k < i; k++)
		{   
			   owner = arr[k].owner;
			if (owner == t)
			{
				cout << "Mаркa автомобиля: ";
				for (int z = 0; z < 4; z++)
				{
					cout << arr[k].name[z];
				}
				cout << endl;
				cout << "Цвет: " << arr[k].color << endl;
				cout << "Заводской номер: " << arr[k].num << endl;
				cout << "Дата выпуска: " << arr[k].date << endl;
				cout << "Тип кузова: " << arr[k].type << endl;
				cout << "Дата последнего техосмотра: " << arr[k].date2 << endl;
				
				
			}
		}
	}
	cout << "-------------------------------------------" << endl;
}
void infile() {
	ofstream fout("t.txt");
	for (int k = 0; k < i; k++) {
		fout<<"\n"<< arr[k].name;
		fout << "\n" << arr[k].color;
		fout << "\n" << arr[k].date;
		fout << "\n" << arr[k].type;
		fout << "\n" << arr[k].date2;
		fout << "\n" << arr[k].owner ;
		fout << "\n"<< "-------------------------------------------" << endl;
	}
	fout.close();
}
void outfile(){
	char buff[50];
	ifstream fin("t.txt");
	do {
		fin.getline(buff, 50);
		cout << buff << endl;
		buff[0] = 0;
	} while (!fin.eof());

}
//#include <iostream>
//using namespace std;
//
//struct Worker
//{
//	char lastName[30];
//	char position[30];
//	int year;
//};
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	const int size = 3;
//	const int currentYear = 2017;
//	int i, b, counter = 0;
//	Worker a[size];
//	for (i = 0; i < size; i++)
//	{
//		cout << "Введите фамилию " << i + 1 << "-ого работника " << endl;
//		cin >> a[i].lastName;
//		cout << endl << "Должность: ";
//		cin >> a[i].position;
//		cout << endl << "Год поступления на работу: ";
//		cin >> a[i].year;
//	}
//	return 0;
//}