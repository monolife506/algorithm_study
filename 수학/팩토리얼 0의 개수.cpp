// 1676�� : ���丮�� 0�� ����

#include <iostream>
using namespace std;

int main()
{
	size_t N, tmp;
	cin >> N;

	size_t count_5{ 0 };
	for (size_t i = 5; i <= N; i += 5)
	{
		tmp = i;
		while (tmp % 5 == 0)
		{
			count_5++;
			tmp /= 5;
		}
	}
	cout << count_5;
}