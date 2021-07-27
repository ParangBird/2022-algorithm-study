#include <iostream>
using namespace std;

/*

2021.08.02 ������

n�� 1�� ���� 1,
n�� 2�� ���� 3,
n�� 3�� ���� 5,
n�� 4�� ���� 11,
n�� 5�� ���� 21,
...

f(n) = 2*f(n-2)+f(1)�̶�� ��ȭ���� �ϼ��ȴ�.

*/

long long int arr[1001] = { 0, };
int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3;i <= n;i++) {
		arr[i] = arr[i - 1] % 10007 + (arr[i - 2] * 2) % 10007;
	}
	cout << arr[n] % 10007 << endl;
}