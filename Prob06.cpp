#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long sum1 = 0, sum2 = 0;

	for (int i = 1; i <= 100; i++)
	{
		sum1 += i;
		sum2 += i * i;
	}

	sum1 = sum1 * sum1;

	cout << sum1 - sum2 << "\n";
}