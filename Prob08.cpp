#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string nums, number;
	long long num = 1, max = 0; //int로 하면 답 안나옴

	for (int i = 0; i < 20; i++)
	{
		cin >> nums;
		number += nums;
	}

	for(int j = 0; j < 988; j++)
	{
		for (int i = 0; i < 13; i++)num *= number[j + i] - '0';
		cout << num << "\n";
		if (max < num) max = num;
		num = 1;
	}

	cout << max << "\n";
}