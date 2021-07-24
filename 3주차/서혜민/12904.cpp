#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*

2021.07.24 ������

t�� ��� ��ȯ�� �ؼ� s�� ���� �� �ִ��� Ȯ���ϴ� ����̴�.

t�� �� ������ ���ڰ� A�� ����, t�� A�� ���� �ٷ� �������� �߶��ְ�
�� ������ ���ڰ� B�� ���� B�� ���� �ٷ� �������� �߶��� ��,
reverse�� ���� ���ڿ��� �������ش�.

�̷��� ��ȯ�� �����ϸ鼭 s�� ���� �Ǹ� 1�� ���������,
t�� ���̰� 0�� �ɶ����� s�� ���� ���� �ʴ´ٸ� 0�� ����Ѵ�.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t;
	cin >> s >> t;
	while (1) {
		if (t[t.length() - 1] == 'A') {
			t = t.substr(0, t.length()-1);
		}
		else {
			t = t.substr(0, t.length()-1);
			reverse(t.begin(), t.end());
		}
		if (t == s) {
			cout << 1 << endl;
			return 0;
		}
		if (t.length() == 0) {
			cout << 0 << endl;
			return 0;
		}
	}
}