#include <iostream>
#include <string>
using namespace std;

/*

�� 2021.07.26 ������

a�� ���� aCount, b�� ���� bCount�̶� �ϸ�,
���� �� �ִ� ���� ������ �ִ� aCount * bCount���̸�,
���� ���� k�� 0�� ����, n���̸�ŭ�� B���̷��� ���ڿ��� �� �ڸ� A�� �ٲ��ָ�
k�� ���� �� �ִ� �ִ� ���� ������ a�� b�� ���� ���ڿ� ������ ������ �� �̹Ƿ�,
(n/2) * (n/2)���� ũ�ٸ� -1�� �����Ѵ�.

aCount�� 1�����Ͽ� ���� �� �ִ� �ִ� ���� ������ aCount * bCount�� k���� �۴ٸ� �ǳʶٰ�,
�׷��� �ʴٸ� n-1������ B�� �̷��� ���ڿ��� ������ �� aCount-1����ŭ �տ������� A�� ä���ش�.
�̶� ����� ���� ������ aCount-1 * bCount �̴�.
�� ���� k�� ���Ͽ� k�� ���ٸ� ���� ���� ���� �� ������ �� �ڿ� A�� ��ġ��Ű��
k���� �۴ٸ� ���� ������ �÷���� �ϹǷ�, insert�� ���ؼ� �� ������ �ϴ� ���� ������ŭ �ڿ������� ������ �ű� ���� A�� �����Ѵ�.

*/

int main() {
	//n���� k��
	int n, k;
	cin >> n >> k;
	if (k > (n/(double)2 * n/2)) {
		cout << -1 << endl;
		return 0;
	}
	if (k == 0) {
		string s(n, 'B');
		s[n - 1] = 'A';
		cout << s << endl;
		return 0;
	}

	int aCount, bCount;
	for (aCount = 1;aCount < n;aCount++) {
		bCount = n - aCount;
		if (aCount * bCount < k) continue;
		string s(n-1, 'B');
		for (int i = 0;i < aCount - 1;i++) {
			s[i] = 'A';
		}
		if (k == (aCount * bCount)) {
			s.insert(n-1,"A");
			cout << s << endl;
			return 0;
		}
		else if (k > ((aCount-1) * bCount)) {
			s.insert((n - 1) - (k - (aCount - 1) * bCount), "A");
			cout << s << endl;
			return 0;
		}
	}
}