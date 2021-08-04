#include <iostream>
#include <string>
#include <set>
using namespace std;

/*

2021.08.09 ������

�湮�ߴ� ���� �ٽ� �湮�� �� �ִ� dfs
5���� Ž���� ��� ������ ��, ���̰� 6�� ���ڰ� �ϼ��� �Ǹ� set�� ����.

*/

int arr[5][5] = { 0, };
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };
set<string> s;

void dfs(int x, int y, string ans, int count) {
	if (count == 6) {
		if (ans.length() == 6) {
			auto it = s.find(ans);
			if (it == s.end()) {
				s.insert(ans);
			}
			return;
		}
		return;
	}

	for (int i = 0;i < 4;i++) {
		int newX = x + moveX[i];
		int newY = y + moveY[i];
		if (newX >= 0 && newX < 5 && newY >= 0 && newY < 5) {
			dfs(newX, newY, ans + to_string(arr[newX][newY]), count + 1);
		}
	}
}

int main() {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			dfs(i, j, to_string(arr[i][j]), 1);
		}
	}
	cout << s.size() << endl;
}