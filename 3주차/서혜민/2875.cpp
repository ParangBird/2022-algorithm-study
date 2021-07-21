#include <iostream>
using namespace std;

/*

2021.07.26 ������

n(���л�), m(���л�), k(����)
count(��)

��2��1->1���̹Ƿ� �ִ� ���� �� �ִ� ���� ������ m�̴�.
for���� ���ؼ� ���� ������ 1���� �÷����鼭,
���� ���鶧���� ��, �� �л����� ���ش�. �̶�,
0) ���л��� ���ų�, ���л��� ������ ���� ����� �����Ƿ� �� ������ 0.
1) ���� �л����� ���� ���Ͽ� ������ �л��� ���� �������� �� ���� �� ������ ����
2) �۾����� �� ���� �������� �ƴ� ������ �� ������ ������ �ȴ�.
3) 1,2�� ��찡 �ƴϸ鼭 ���� ���� �� ���� �����̸� �� ������ ������� �� ������ ����.

*/

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int count = 0;
	int girl = n, man = m;
	bool makeTeam = false;
	for (int i = 0;i < m;i++) {
		makeTeam = false;
		if (girl >= 2 && man >= 1) {
			girl -= 2;
			man -= 1;
			count++;
			makeTeam = true;
		}
		if ((girl + man) <= k) {
			if ((girl + man) == k) cout << count << endl;
			else cout << count - 1 << endl;
			return 0;
		}
		if (!makeTeam) {
			cout << count << endl;
			return 0;
		}
	}
	cout << count << endl;
}