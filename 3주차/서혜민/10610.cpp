#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*

2021.07.26 ������

30�� �����, 10�� ����̸鼭 ��� �ڸ��� ���� 3�� ����� ���̴�.
sort�� ���ؼ� ���� ū ���� �տ� ���� ������ ������ ��,
�� �ڸ����� ���� ���ϰ�, 0�� ������ ����,
0�� ���ų�, �� �ڸ��� ���� 3�� ����� �ƴϸ� -1�� ����
�׷��� ������ ���ĵ� ���� ����.

*/

int main() {
	string n;
	cin >> n;
	sort(n.begin(), n.end(), greater<>());
	
	int count = 0;
	int sum = 0;
	for (int i = 0;i < n.size();i++) {
		if (n[i] == '0') count++;
		sum += n[i] - '0';
	}

	if (count && !(sum % 3)) cout << n << endl;
	else cout << -1 << endl;
}