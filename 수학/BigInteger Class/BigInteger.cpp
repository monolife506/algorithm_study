// 9.14 && 10.9: Big Integer Class
// Big Integer Class ���� �Լ��� ����

#include <iostream>
#include <array>
#include <string>
#include <cctype> // for isdigit()
#include "BigInteger.h"
using namespace std;

// ������
BigInteger::BigInteger(long long value)
{
	for (int i{digits - 1}; value != 0 && i >= 0; i--)
	{
		integer[i] = value % 10;
		value /= 10;
	}
}
BigInteger::BigInteger(const string& value)
{
	int length = value.size() ;
	for (int i{ digits - length }, j{ 0 }; i < digits; i++, j++)
	{
		if (isdigit(value[j]))
		{
			integer[i] = value[j] - '0';
		}
		else
		{
			throw invalid_argument("string�� �ڿ����� ǥ������ �ʽ��ϴ�.");
		}
	}
}

// '+' ������ �����ε� 
BigInteger BigInteger::operator+(const BigInteger& value) const
{
	BigInteger temp;
	int carry{ 0 };

	for (int i{ digits - 1 }; i >= 0; i--)
	{
		temp.integer[i] = this->integer[i] + value.integer[i] + carry;

		if (temp.integer[i] > 9)
		{
			carry = 1;
			temp.integer[i] %= 10;
		}
		else
		{
			carry = 0;
		}
	}

	return temp;
}
BigInteger BigInteger::operator+(int value) const
{
	return *this + BigInteger(value); // BigInteger + BigInteger�� ������ Ȱ��
}
BigInteger BigInteger::operator+(const string& value) const
{
	return *this + BigInteger(value); // BigInteger + BigInteger�� ������ Ȱ��
}

// '-' ������ �����ε�
BigInteger BigInteger::operator-(const BigInteger& value) const
{
	BigInteger temp;
	int carry{ 0 };

	for (int i{ digits - 1 }; i >= 0; i--)
	{
		temp.integer[i] = this->integer[i] - value.integer[i] + carry;

		if (temp.integer[i] < 0)
		{
			carry = -1;
			temp.integer[i] = temp.integer[i] + 10;
		}
		else
		{
			carry = 0;
		}
	}

	return temp;
}
BigInteger BigInteger::operator-(int value) const
{
	return *this - BigInteger(value); // BigInteger - BigInteger�� ������ Ȱ��
}
BigInteger BigInteger::operator-(const string& value) const
{
	return *this - BigInteger(value); // BigInteger - BigInteger�� ������ Ȱ��
}

// '*' ������ �����ε�
BigInteger BigInteger::operator*(const BigInteger& value) const
{
	static BigInteger temp;
	temp = 0;

	// BigInteger�� '+', '<' ������ �����ε� Ȱ��
	for (BigInteger i; i < value; i = i + 1)
	{
		temp = temp + *this;
	}

	return temp;
}
BigInteger BigInteger::operator*(int value) const
{
	return *this * BigInteger(value); // BigInteger * BigInteger�� ������ Ȱ��
}
BigInteger BigInteger::operator*(const string& value) const
{
	return *this * BigInteger(value); // BigInteger * BigInteger�� ������ Ȱ��
}

// '/' ������ �����ε�
BigInteger BigInteger::operator/(const BigInteger& value) const
{
	static BigInteger temp;
	temp = *this;
	BigInteger i;

	// BigInteger�� '-', '>' ������ �����ε� Ȱ��
	for (; temp >= value; i = i + 1)
	{
		temp = temp - value;
	}

	return i;
}
BigInteger BigInteger::operator/(int value) const
{
	return *this / BigInteger(value); // BigInteger / BigInteger�� ������ Ȱ��
}
BigInteger BigInteger::operator/(const string& value) const
{
	return *this / BigInteger(value); // BigInteger / BigInteger�� ������ Ȱ��
}

// '==' ������ �����ε�
bool BigInteger::operator==(const BigInteger& value) const
{
	return (this->integer == value.integer);
}
bool BigInteger::operator==(int value) const
{
	return (*this == BigInteger(value));
}
bool BigInteger::operator==(const string& value) const
{
	return (*this == BigInteger(value));
}

// '!=' ������ �����ε�
bool BigInteger::operator!=(const BigInteger& value) const
{
	return !(*this == value);
}
bool BigInteger::operator!=(int value) const
{
	return (*this != BigInteger(value));
}
bool BigInteger::operator!=(const string& value) const
{
	return (*this != BigInteger(value));
}

// '>' ������ �����ε�
bool BigInteger::operator>(const BigInteger& value) const
{
	return this->integer > value.integer;
}
bool BigInteger::operator>(int value) const
{
	return (*this > BigInteger(value));
}
bool BigInteger::operator>(const string& value) const
{
	return (*this > BigInteger(value));
}

// '<' ������ �����ε�
bool BigInteger::operator<(const BigInteger& value) const
{
	return this->integer < value.integer;
}
bool BigInteger::operator<(int value) const
{
	return (*this < BigInteger(value));
}
bool BigInteger::operator<(const string& value) const
{
	return (*this < BigInteger(value));
}

// '>=' ������ �����ε�
bool BigInteger::operator>=(const BigInteger& value) const
{
	return !(*this < value);
}
bool BigInteger::operator>=(int value) const
{
	return !(*this < BigInteger(value));
}
bool BigInteger::operator>=(const string& value) const
{
	return !(*this < BigInteger(value));
}

// '<=' ������ �����ε�
bool BigInteger::operator<=(const BigInteger& value) const
{
	return !(*this > value);
}
bool BigInteger::operator<=(int value) const
{
	return !(*this > BigInteger(value));
}
bool BigInteger::operator<=(const string& value) const
{
	return !(*this > BigInteger(value));
}

// '<<' ������ �����ε�
ostream& operator<<(ostream& output, const BigInteger& value)
{
	int i;
	for (i = 0; (i < BigInteger::digits) && (value.integer[i] == 0); ++i) {}

	if (i == BigInteger::digits)
	{
		output << 0;
	}
	else
	{
		for (; i < BigInteger::digits; i++)
		{
			output << value.integer[i];
		}
	}

	return output;
}