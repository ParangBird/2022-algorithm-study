#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.08.02 ������

1���� n����� �ִ� ī������ �ݺ����� ����
1�� ¥�� ī���Ѻ��� n����� ����� �� ��� ����� ans�迭�� ������ �ϴµ�,
���� ans[j]�� ���� ans[j-i]+costs[i]�� ���Ͽ� �� ū ���� �����Ѵ�.

ex) n=4  1,5,6,7
1 2 3 4
1 5 6 10
1 5 6 10
1 5 6 10

*/
int costs[10001] = { 0, };
int ans[10001] = { 0, };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> costs[i];
	}

	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			ans[j] = max(ans[j], ans[j - i] + costs[i]);
		}
	}

	cout << ans[n] << endl;
}