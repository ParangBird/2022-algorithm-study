#include <iostream>
using namespace std;

/*

2021.08.02 ������

1
10
100 101
1000 1001 1010
10000 10001 10010 10100 10101
...
���� ���� ���� �ڿ� 0�� ������ ���� ���� 0�̳� 1.
1�� ������ ���� ���� 0.

*/

long long int arr[91][2] = { 0, };
int main() {
	int n;
	cin >> n;
	arr[1][1] = 1;
	for (int i = 2;i <= n;i++) {
		arr[i][0] = arr[i - 1][1] + arr[i - 1][0];
		arr[i][1] = arr[i-1][0];
	}
	cout << arr[n][0]+arr[n][1] << endl;
}