// Lab8.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h";
#include <iostream>;
#include <cmath>;

using namespace std;

double Carv(double x0,double x1,double e);
double Function(double x);

int main()
{
	setlocale(LC_ALL,"rus");
	double a = -7, b = 3, h = 0.1, x, xstr, y, e;
	cout << "¬ведите точность" << endl;
	cin >> e;
	for ( x = a; x < b; x+=h)
	{
		if (Function(x)*Function(x + h) < 0)
		{
			xstr=Carv(x,x+h,e);
			y = Function(xstr);
			cout << xstr << " " << y << endl;
		}
	}

	system("pause");
    return 0;
}

double Carv(double x0,double x1,double e)
{
    double x,temp;
	while (fabs(x1 - x0) > e)
	{
		temp = x1;
		x1 = x1 - (x1 - x0)*Function(x1) / (Function(x1) - Function(x0));
		x0 = temp;
	}
	if (x1 != x1)
	{
		x = x0;
	}
	else
	{
		x = x1;
	}
	return x;
}

double Function(double x)
{
    double y;
	y = pow(sin(x), 2) - 3 * cos(x);
	return y;
}