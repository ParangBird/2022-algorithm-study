#include <iostream>
#include <string>
using namespace std;

/*

2021.07.26 ������

���� �ּҰ� �������� �Ϸ��� -��ȣ�� ���۵Ǵ� �κп��� ��ȣ�� �����ϴµ�,
��ȣ �ȿ��� -��ȣ�� ������ +��ȣ�� �ǹǷ� -��ȣ ���� ��ȣ�� �ݴ� ����̴�.

�� ����� -��ȣ�� ������ �������� �׻� ��ȣ�� ���缭 ���� ��������, 
-��ȣ�� ���� �ں��ʹ� +��ȣ�� ���͵� ��� ���� ������ ���� ������ �� �ִ�.

*/


int main() {
	string s;
	cin >> s;

	int sum = 0;
	string num = "";
	
	bool plus = 1;
	bool minus = 0;
	for (int i = 0;i < s.length();i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			num += s[i];
		}
		else {
			if (minus) sum -= stoi(num);
			else sum += stoi(num);
			if (s[i] == '-') minus = 1;
			num = "";
		}
	}
	if (minus) sum -= stoi(num);
	else sum += stoi(num);
	cout << sum << endl;
}