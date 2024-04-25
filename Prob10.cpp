#include <iostream>
using namespace std;

constexpr int MAX = 2000001;
bool prime[MAX];

// ���� �������� Ư�� �Ҹ������� �ٲٴ� �ζ��� �Լ�
inline void change_bool(int strt, int acc, bool flag) {
    for (int i = strt; i < MAX; i += acc) {
        prime[i] = flag;
    }
}

void eratosthenes() {
    std::fill_n(prime, MAX, false);//�迭�� �ʱ�ȭ�Ѵ�.
    prime[2] = true;//2�� �Ҽ���.
    prime[3] = true;//3�� �Ҽ���. �̷��� 5 �̻��� Ȧ���� �Ǻ��ϸ� �ȴ�.
    // 5 (mod 6) �� 1 (mod 6)�� ������ �����Ѵ�. �̵��� 2�ǹ���� �ƴϰ� 3�� ����� �ƴ� ���������̴�.
    // ��, 1�� �Ҽ��� �ƴϱ⿡ 1 (mod 6)�� 7���� �����Ѵ�.
    change_bool(5, 6, true);
    change_bool(7, 6, true);

    for (int i = 5, j = 25; j < MAX;) {
        int nxt = (i - 3) % 6; // ������ i�� 5 (mod 6) �̸� 2, 1 (mod 6) �̸� 4�� �ȴ�.
        if (prime[i] == true) {
            int addi = i * 6; //i�� 6��� �Ͽ� x (mod 6)�� ���� �˻��ϰ� �Ѵ�.

            // i * i �̻��� ���� ����������. ������ �� �̸��� ������ �̹� �Ҽ� ���ΰ� �Ǻ��Ǿ���.
            change_bool(j, addi, false);

            //���� �������� ������ �κ��� ���� ����������.
            change_bool(nxt * i + j, addi, false); // nxt * i + j == i * ( i + nxt)
        }
        // ���� ���� ������ ���� �غ�. ������ i�� 5 (mod 6) �̸� 2��, 1 (mod 6)�̸� 4�� ���Ѵ�.
        i += nxt;
        j = i * i;
    }
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    eratosthenes();

	long long sum = 0;

    for (int i = 0; i < MAX; i++) if (prime[i] == true) sum += i;
    cout << sum << "\n";
	/*for (int i = 1; i < 2000001; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= i; j++) if (i % j == 0) cnt += 1;
		if (cnt == 2) sum += i;
	}

	cout << sum << "\n";*/
}