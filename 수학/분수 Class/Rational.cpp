// 9.6 : Rational Class
// Rational Class���� �Լ� ����
// +. ������ �����ε�(+, -, *, /, ++, --, >>, <<) �̿�

#include <iostream>
#include <iomanip>
#include "Rational.h"
using namespace std;

// ����� ���Ǹ� ���� ���밪�� ���� �� ������ �ּҰ������ ���ϴ� �Լ�
int absolute_GCD(int a, int b) 
{
	if (a == 0)
	{
		return 1;
	}

	a = (a > 0) ? a : -a;
	b = (b > 0) ? b : -b;

	while (b != 0) 
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

ostream& operator<<(std::ostream& output, const Rational& R)
{
	if (R.denominator == 1 || R.numerator == 0)
	{
		output << R.numerator;
	}
	else
	{
		output << R.numerator << '/' << R.denominator;
	}
	
	return output;
}

istream& operator>>(std::istream& input, Rational& R)
{
	int num; int deno;
	input >> num;
	input.ignore();
	input >> deno;

	R.setRational(num, deno);
	return input;
}

// Rational ��ü�� numerator�� denominator���� ���ϴ� �Լ�
void Rational::setRational(int numer, int deno)
{
	if (deno == 0)
	{
		cout << "�и�� 0�� �Ǿ�� �ȵ˴ϴ�. �и� 1�� �ʱ�ȭ�մϴ�." << '\n';
		deno = 1;
	}

	int gcd = absolute_GCD(numer, deno);
	numer /= gcd; deno /= gcd;

	numerator = numer;
	denominator = deno;
}

Rational::Rational(int numer, int deno)
{
	setRational(numer, deno);
}

Rational Rational::operator+(const Rational& R)
{
	Rational result
	{
		this->numerator * R.denominator + this->denominator * R.numerator,
		this->denominator * R.denominator
	};
	return result;
}

Rational Rational::operator-(const Rational& R)
{
	Rational result
	{
		this->numerator * R.denominator - this->denominator * R.numerator,
		this->denominator * R.denominator
	};
	return result;
}

Rational Rational::operator*(const Rational& R)
{
	Rational result
	{
		this->numerator * R.numerator,
		this->denominator * R.denominator
	};
	return result;
}

Rational Rational::operator/(const Rational& R)
{
	Rational result
	{
		this->numerator * R.denominator,
		this->denominator * R.numerator
	};
	return result;
}

// Postfix
Rational Rational::operator++()
{
	setRational(numerator + denominator, denominator);
	return *this;
}


// Prefix
Rational& Rational::operator++(int)
{
	Rational temp{ *this };
	setRational(numerator + denominator, denominator);
	return temp;
}

// Postfix
Rational Rational::operator--()
{
	setRational(numerator - denominator, denominator);
	return *this;
}

// Prefix
Rational& Rational::operator--(int)
{
	Rational temp{ *this };
	setRational(numerator - denominator, denominator);
	return temp;
}

// ���� / �и��� ���� �Ǽ������� return�ϴ� �Լ�
double Rational::getdouble() const
{
	return static_cast<double>(numerator) / denominator;
}