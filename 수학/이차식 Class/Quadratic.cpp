// 9.5 : Quadratic Equations Class
// Quadratic class�� �Լ� ����
// +. operator overloading�� �̿��Ͽ� add�� substract�� ��ü

#include <iostream>
#include <cmath>
#include <string>
#include <sstream> // for ostringstream
#include <stdexcept> // for handling invalid_argument exception 
#include "Quadratic.h"

using namespace std;

Quadratic::Quadratic(int a, int b, int c) : B(b), C(c)
{
	if (a != 0)
	{
		A = a;
	}
	else
	{
		cout << "a�� ���� 0�� �ƴϿ��� �մϴ�." << '\n';
		cout << "a = 1�� �ʱ�ȭ�մϴ�." << "\n\n";
		A = 1;
	}
}

Quadratic Quadratic::operator+(const Quadratic& Q)
{
	Quadratic result{this->A, this->B, this->C};
	result.A += Q.A; result.B += Q.B; result.C += Q.C;
	return result;
}

Quadratic Quadratic::operator-(const Quadratic& Q)
{
	Quadratic result{ this->A, this->B, this->C };
	result.A -= Q.A; result.B -= Q.B; result.C -= Q.C;
	return result;
}

string Quadratic::toString() const
{
	ostringstream output;

	if (A == 1)
	{
		output << "x^2";
	}
	else
	{
		output << A << "x^2";
	}

	if (B == 1)
	{
		output << "+x";
	}
	else if (B < 0)
	{
		output << B << "x";
	}
	else if (B != 0)
	{
		output << "+" << B << "x";
	}

	if (C < 0)
	{
		output << C;
	}
	else if (C != 0)
	{
		output << "+" << C;
	}

	output << " = 0";
	return output.str();
}

int Quadratic::solve(char sign)
{
	double discriminant = B * B - 4 * A * C;
	if (discriminant < 0)
	{
		throw invalid_argument("�����Ŀ� �Ǳ��� �������� �ʽ��ϴ�.");
	}
	else
	{
		double numer;
		if (sign == '+')
		{
			numer = - B + sqrt(discriminant);
		}
		else if (sign == '-')
		{
			numer = - B - sqrt(discriminant);
		}
		else
		{
			throw invalid_argument("�ùٸ� ��ȣ�� �Էµ��� �ʾҽ��ϴ�.");
		}

		double deno = 2 * A;
		return numer / deno;
	}
}
