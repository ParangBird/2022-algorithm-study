#include <iostream>
#include <algorithm>
#include <vector>]
#include <cstdlib>
#include <limits.h>
using namespace std;

/*

2021.09.04 ������

front, back�̶�� �� ���� �����͸� �ּ� �ش� �� �ε����� ���� ���밪�� min���� �۴ٸ�
min�� �־��ְ� �׷��� �ʰ� ���� ����̸� 0�� ����� ���� ����� ���� �� �� ������ ���� ���� ���ؾ��ϹǷ� back�� ��ĭ �մ���, 
0���� �۴ٸ� �� ū ���� ���ؾ��ϹǷ� front�� ��ĭ �մ���.

*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0;i < N;i++) cin >> v[i];

	sort(v.begin(), v.end());

	int front = 0, back = N - 1;
	int minsum = INT_MAX;
	int x, y;
	while (front < back) {
		int sum = v[front] + v[back];
		if (abs(sum) < minsum) {
			minsum = abs(sum);
			x = front;
			y = back;
		}
		else {
			if (sum > 0) back--;
			else front++;
		}
	}
	cout << v[x] << ' ' << v[y] << endl;
}