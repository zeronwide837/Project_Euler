#include <iostream>
using namespace std;
int arr[40000000] = { 0 };
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int idx = 2;
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= 4000000; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	
	int sum = 0;
	for (int i = 0; i <= 40000000; i++) {
		if (arr[i] > 4000000) break;
		if (arr[i] % 2 == 0) sum += arr[i];
	}
		

	cout << sum << "\n";
}
