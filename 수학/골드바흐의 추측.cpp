// 9020�� : �������� ����

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// �Է�
	size_t T; cin >> T;
	vector<unsigned> nums(T);
	for (size_t i = 0; i < T; i++)
		cin >> nums[i];

	// 5000���� �Ҽ� ���ϱ�
	bool D[10001]; vector<unsigned> decimals;
	for (size_t i = 0; i < 10001; i++)
		(i == 0 || i == 1) ? D[i] = false : D[i] = true;
	for (size_t i = 2; i < 10001; i++)
	{
		if (D[i] == false)
			continue;
		else
		{
			decimals.push_back(i);
			for (size_t j = 2; i * j <= 10000; j++)
				D[i * j] = false;
		}
	}

	// ���
	bool isFoundPartion{ false };
	for (const auto& N : nums)
	{
		for (size_t gap = 0; gap < decimals.size(); gap++)
		{
			for (size_t i = 0; i + gap < decimals.size(); i++)
			{
				if (decimals[i] + decimals[i + gap] == N)
				{
					cout << decimals[i] << ' ' << decimals[i + gap] << '\n';
					isFoundPartion = true;
					break;
				}
			}
			if (isFoundPartion == true)
			{
				isFoundPartion = false;
				break;
			}
		}
	}
}