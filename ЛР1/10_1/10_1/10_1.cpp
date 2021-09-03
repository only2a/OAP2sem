

#include <iostream>
#include <math.h>
using namespace std;

void ttt(double(*funn) (double(*fun0) (double),/*double,*/ double, double), double(*fun1) (double x),/* double e,*/ double a, double b)
{
	funn(fun1, /*e,*/ a, b);
   }
	double f(double x) {



		return pow(x,3) +sin(x);
   }
	double f2(double x) {
		return (0.4 + pow(x, 3));
	}
	double dichotomyMethod(double(*g) (double) /*double e*/, double a, double b) {
		double x,e=0.0001;
		do
		{
		    x = (a + b) / 2.0;
			if (g(x) * g(a) <= 0)
				b = x;
			else
				a = x;
		} while (fabs(a - b) > 2.0 * e);
		cout << (a + b) / 2.0 << endl;
		return (a + b) / 2.0;
	}

	int main()
	{
		setlocale(LC_CTYPE, "Russian");
		double a, b;
	
		cout << "Введите левую границу интервала (a) "; cin >> a;
		cout << "Введите правую границу интервала (b) "; cin >> b;
		cout << "Корень решения 1го уравнения методом дихотомии:";
		ttt(dichotomyMethod, f, a, b);
			cout << "Корень решения 2го уравнения методом дихотомии:";
			ttt(dichotomyMethod, f2, a, b );
			return(0);
	}


	int s(int d,int m,int y)