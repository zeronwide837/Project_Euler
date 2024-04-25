#include <iostream>
#include <string>
using namespace std;

int arr[1000000];

bool palinD(string str)
{
	int tmp = 0;
	for (int i = 0; i < str.length() / 2 ; i++)
		if (str[i] == str[str.length() - 1 - i]) tmp++; //-1 ÇØ¾ßµÊ
	if (tmp == str.length() / 2) return true;
	else return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string num;
	int idx=0, max=0;

	for (int i = 999; i > 99; i--)
		for (int j = 999; j > 99; j--)
		{
			num = to_string(i*j);
			if (palinD(num) == true)
			{
				arr[idx] = stoi(num);
				idx++;
			}
		}

	for (int i = 0; i < 1000000; i++) if (arr[i] > max) max = arr[i];
	cout << max << "\n";
}