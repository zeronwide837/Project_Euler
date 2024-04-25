#include <iostream>
#include <string>
using namespace std;
int arr[400];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string digit;
	int num,max = 0;
	
	for (int i = 0; i < 400; i++)
	{
		cin >> digit;
		arr[i] = stoi(digit);
	}

	int tmp1 = 0;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			num = arr[tmp1 + j] * arr[tmp1 + j + 1] * arr[tmp1 + j + 2] * arr[tmp1 + j + 3];
			if (max < num) max = num;
		}
		tmp1 += 20;
	}

	int tmp2 = 0;

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			num = arr[tmp2 + j] * arr[tmp2 + j + 20] * arr[tmp2 + j + 40] * arr[tmp2 + j + 60];
			if (max < num) max = num;
		}
		tmp2 += 20;
	}

	int tmp3 = 0;

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			num = arr[tmp3 + j] * arr[tmp3 + j + 21] * arr[tmp3 + j + 42] * arr[tmp3 + j + 63];
			if (max < num) max = num;
		}
		tmp3 += 20;
	}

	int tmp4 = 0;

	for (int i = 3; i < 20; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			num = arr[tmp4 + j] * arr[tmp4 + j + 19] * arr[tmp4+ j + 38] * arr[tmp4 + j + 57];
			if (max < num) max = num;
		}
		tmp4 += 20;
	}

	cout << max << "\n";
}