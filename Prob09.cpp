#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b,num;
	num = 501;
	a = 1;
	while (num < 667)
	{
		b = num - a;
		if (1000 * (a + b) - a * b == 500000)
		{
			cout << a << " " << b << "\n";
			cout << a * b * (1000 - a - b) << "\n";
			return 0;
		}
		a++;
		if (a == num)
		{
			num++;
			a = 1;
		}
	}
}
