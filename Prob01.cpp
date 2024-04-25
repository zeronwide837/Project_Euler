#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sum = 0;

	for (int i = 1; i < 1000; i++)
		if (i % 3 == 0 || i % 5 == 0) sum += i;

	cout << sum << "\n";
	return 0;
}
