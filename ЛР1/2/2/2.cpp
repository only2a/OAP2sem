// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include < iostream >
#include < windows.h >
#include < string >
#include < algorithm >

using namespace std;
string vvod(unsigned u)
{
	string str;
	for (;;)
	{
		cout << "Введите слово " << u + 1 << endl;
		getline(cin, str);
		if (str.size() == 0)
		{
			cout << "Ошибка ввода. Недопустимы пустые строки. Повторите это слово" << endl;
			str.clear();
			continue;
		}
		bool valid = true;
		for (auto c : str)
		{
			if (c == ' ')
			{
				valid = false;
				break;
			}
		}
		if (valid)
		{
			break;
		}
		else
		{
			cout << "Ошибка ввода. Недопустимы пробелы. Повторите это слово" << endl;
			str.clear();
		}
	}
	return str;
}

void sortirovka(string* a, unsigned n, unsigned max_len)
{
	for (long long u = max_len - 1; u >= 0; --u)
	{
		auto p = [u](string s1, string s2)
		{
			unsigned s1_len = s1.size();
			unsigned s2_len = s2.size();
			unsigned short_ = (s1_len < s2_len) ? s1_len : s2_len;

			if (u <= short_ - 1)
			{
				return toupper((unsigned char)s1[u]) < toupper((unsigned char)s2[u]);
			}
			else
			{
				return s1_len < s2_len;
			}
		};
		sort(a, a + n, p);
	}
}

void vivod(string* a, unsigned n)
{
	cout << endl;
	cout << "Строка после сортировки:" << endl;
	for (unsigned u = 0; u < n; ++u)
	{
		
		cout << a[u] << "  ";
	}
	/*out << endl;*/
}


void main()
{
	setlocale(LC_ALL, "Russian");


	cout << "Введите количество слов ";
	unsigned n;
	cin >> n;
	cin.get();

	auto a = new string[n];
	unsigned max_len = 0;

	for (unsigned u = 0; u < n; ++u)
	{
		auto str = vvod(u);

		if (str.size() > max_len)
		{
			max_len = str.size();
		}
		a[u] = str;
	}

	sortirovka(a, n, max_len);

	vivod(a, n);

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
