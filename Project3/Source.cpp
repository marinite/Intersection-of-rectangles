#include <iostream>
#include <string>
using namespace std;

void func(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double l1, l2, r1, r2, d1, d2, u1, u2; //проекция на оси
	double a1 = 0, b1 = 0, a2 = 0, b2 = 0; //координаты пересечения прямоугольников
	bool Ox = false, Oy = false;

	////ось х
	//задаём значения l,r
	if (x1 <= x3)
	{
		l1 = x1;
		l2 = x3;
	}
	else if (x3 < x1)
	{
		l1 = x3;
		l2 = x1;
	}
	if (x2 <= x4)
	{
		r1 = x2;
		r2 = x4;
	}
	else if (x4 < x2)
	{
		r1 = x4;
		r2 = x2;
	}

	//ось у
	//задаём значения d,u
	if (y1 <= y3)
	{
		d1 = y1;
		d2 = y3;
	}
	else if (y3 < y1)
	{
		d1 = y3;
		d2 = y1;
	}
	if (y2 <= y4)
	{
		u1 = y2;
		u2 = y4;
	}
	else if (y4 < y2)
	{
		u1 = y4;
		u2 = y2;
	}

	if ((r1 < l2) || (u1 < d2))
	{
		cout << "Triangles do not intersect" << endl;
	}
	else if (r1 == l2) //(полоска или точка)
	{
		a1 = a2 = l2;
		if (u1 == d2)
		{
			cout << "Triangles intersect at a point" << endl;
			b1 = b2 = d2;
			cout << "a1,b1: " << a1 << "," << b1 << endl;
		}
		else
		{
			cout << "Triangles intersect in a straight line" <<endl;
			b1 = d2;
			b2 = u1;
			cout << "a1,b1: " << a1 << "," << b1 << endl;
			cout << "a2,b2: " << a2 << "," << b2 << endl;
		}
	}
	else if (u1 == d2) //(полоска или точка)
	{
		b1 = b2 = d2;
		if (r1 == l2)
		{
			cout << "Triangles intersect at a point" <<endl;
			a1 = a2 = l2;
			cout << "a1,b1: " << a1 << "," << b1 << endl;
		}
		else
		{
			cout << "Triangles intersect in a straight line" <<endl;
			a1 = l2;
			a2 = r1;
			cout << "a1,b1: " << a1 << "," << b1 << endl;
			cout << "a2,b2: " << a2 << "," << b2 << endl;
		}
	}
	else
	{
		cout << "Triangles intersect" << endl;
		a1 = l2;
		a2 = r1;
		b1 = d2;
		b2 = u1;
		cout << "a1,b1: " << a1 << "," << b1 << endl;
		cout << "a2,b2: " << a2 << "," << b2 << endl;
	}
}

int main()
{
	string in1, in2, in3, in4, in5, in6, in7, in8;
	double x1, x2, y1, y2, x3, x4, y3, y4; //входные данные

	cout << "Input:" << endl;
	//cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	cin >> in1 >> in2 >> in3 >> in4 >> in5 >> in6 >> in7 >> in8;
	try
	{
		x1 = stof(in1.c_str());
		y1 = stof(in2.c_str());
		x2 = stof(in3.c_str());
		y2 = stof(in4.c_str());
		x3 = stof(in5.c_str());
		y3 = stof(in6.c_str());
		x4 = stof(in7.c_str());
		y4 = stof(in8.c_str());
		if (x1 < x2 && x3 < x4 && y1 < y2 && y3 < y4)
			func(x1, y1, x2, y2, x3, y3, x4, y4);
		else
			cout << "Error" << endl;
	}
	catch (...)
	{
		cout << "Error" << endl;
	}

	return 0;
}