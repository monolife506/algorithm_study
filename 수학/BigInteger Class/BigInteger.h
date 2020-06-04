// 9.14 && 10.9: Big Integer Class
// Big Integer Class header file

#pragma once
#include <iostream>
#include <array>
#include <string>

class BigInteger
{
	friend std::ostream& operator<<(std::ostream&, const BigInteger&);
public:
	static const int digits{ 40 }; // Biginteger Class�� �ִ� �ڸ���

	// ������
	BigInteger(long long = 0);
	BigInteger(const std::string&);

	// '+' ������ �����ε�
	BigInteger operator+(const BigInteger&) const;
	BigInteger operator+(int) const;
	BigInteger operator+(const std::string&) const;

	// '-' ������ �����ε�
	BigInteger operator-(const BigInteger&) const;
	BigInteger operator-(int) const;
	BigInteger operator-(const std::string&) const;

	// '*' ������ �����ε�
	BigInteger operator*(const BigInteger&) const;
	BigInteger operator*(int) const;
	BigInteger operator*(const std::string&) const;
	
	// '/' ������ �����ε�
	BigInteger operator/(const BigInteger&) const;
	BigInteger operator/(int) const;
	BigInteger operator/(const std::string&) const;

	// '==' ������ �����ε�
	bool operator==(const BigInteger&) const;
	bool operator==(int) const;
	bool operator==(const std::string&) const;

	// '!=' ������ �����ε�
	bool operator!=(const BigInteger&) const;
	bool operator!=(int) const;
	bool operator!=(const std::string&) const;

	// '>' ������ �����ε�
	bool operator>(const BigInteger&) const;
	bool operator>(int) const;
	bool operator>(const std::string&) const;

	// '<' ������ �����ε�
	bool operator<(const BigInteger&) const;
	bool operator<(int) const;
	bool operator<(const std::string&) const;

	// '>=' ������ �����ε�
	bool operator>=(const BigInteger&) const;
	bool operator>=(int) const;
	bool operator>=(const std::string&) const;

	// '<=' ������ �����ε�
	bool operator<=(const BigInteger&) const;
	bool operator<=(int) const;
	bool operator<=(const std::string&) const;
private:
	std::array<short, digits> integer{}; // Biginteger�� ��
};