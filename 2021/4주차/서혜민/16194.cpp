#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

/*

2021.08.02 ������

�ִ밪�� ���� ���� �ٸ�����
1) max��� min�� ���
2) �ּ��� ���� ã�ƾ��ϹǷ� �ʱ��� ans[0]�� 0���� �����س���, ans �迭 ��
�� �̿��� ���� ���� ���� �� �ִ� ���� 1000*10000�����̹Ƿ� 1000*10000+1�� ����.

*/

int arr[1001] = { 0, };
int ans[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(ans, 1001, 10000001);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	ans[0] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			ans[j] = min(ans[j], ans[j - i] + arr[i]);
		}
	}
	cout << ans[n] << endl;
}
