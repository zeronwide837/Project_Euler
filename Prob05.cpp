#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 1000001;
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

int arr[20];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int idx = 0;
    eratosthenes();
    for (int i = 1; i <= 20; i++)
        if (prime[i] == true)
        {
            arr[idx] = i;
            idx++;
        }

    //for (int i = 0; i < 20; i++) cout << arr[i] << " ";
    //cout << "\n";
    for (int i = 0; i < 20; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = 1;
            continue;
        }
        int tmp = arr[i];
        while (arr[i] <= 20) arr[i] *= tmp;
        if (arr[i] > 20) arr[i] /= tmp;
    }

    //for (int i = 0; i < 20; i++) cout << arr[i] << " ";
    //cout << "\n";

    int multi = 1;
    for (int i = 0; i < 20; i++) multi *= arr[i];
    cout << multi << "\n";
}
