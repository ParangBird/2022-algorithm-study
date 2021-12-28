#include <iostream>
#define DIV 10007
using namespace std;

/*

2021.07.29 ������

arr[���� ����][���ڸ� ��]

���ڸ� ���� 1�̶�� ���� �ڸ��� 0�Ǵ� 1�� �����ϹǷ�
�ش� ���̺��� 1 ���� ������ ���ڸ� ���� 1 ������ ��츦 ��� ���� ���� �ȴ�.

*/

int arr[1001][10] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0;i <= 9;i++) arr[1][i] = 1;

	for (int i = 2;i <= N;i++) {
		for (int j = 0;j <= 9;j++) {
			int sum = 0;
			for (int k = 0;k <= j;k++) {
				sum = (sum + arr[i-1][k]) % DIV;
			}
			arr[i][j] = sum;
		}
	}
	int sum = 0;
	for (int i = 0;i <= 9;i++) sum = (sum + arr[N][i]) % DIV;
	cout << sum << endl;
}