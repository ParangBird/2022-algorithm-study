#include <iostream>
using namespace std;

/*

2021.08.02 ������

n=1�� ��, 1��
n=2�� ��, 2��
n=3�� ��, 3��
n=4�� ��, 5��
...
�̷��� n�� �� ���� �� �ִ� ����� ����� ���� n-1�� n-2�� �� ����� �հ� ����.

*/

int arr[1001] = { 0, };
int main() {
	int n;
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3;i <= n;i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n] << endl;
}