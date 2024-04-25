#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long tri, idx = 1;
	int cnt = 0;
	/*
	while (cnt < 500)
	{
		tri += idx;
		cout << tri << "\n";
		cout << "\n";

		for (int i = 1; i <= tri; i++)
			if (tri % i == 0) cnt += 1;
		cout << cnt << "\n";
		cout << "\n";
		if (cnt >= 500) break;
		else
		{
			cnt = 0;
			idx += 1;
		}
	}
	*/

	while (1)
	{
		tri = idx * (idx + 1) / 2;
		for (int i = 1; i <= tri; i++)
			if (tri % i == 0) cnt += 1;
		if (cnt >= 500) break;
		else
		{
			cnt = 0;
			idx++;
		}
	}
	cout << tri << "\n";
	return 0;
}
