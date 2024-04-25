#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long num = 600851475143;
	long long factor = 2;

	while (num != 1)
	{
		if (num % factor == 0) num /= factor;
		else factor++;
	}

	cout << factor << "\n";
}
