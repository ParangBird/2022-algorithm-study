#include <iostream>
#include <bitset>
using namespace std;

/*

2022.2.17
bitset���� 2���� ��ȯ ��, 1�� ������ ����.

*/

int main() {
	int X;
	cin >> X;

	int ans = 0;
	for (char num : bitset<7>(X).to_string()) if (num == '1') ans++;

	cout << ans;
}