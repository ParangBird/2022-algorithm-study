#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

2021.08.09 ������

�Է¹��� �簢���� ���� �Ʒ� ��ǥ�� ������ ���� ��ǥ�� ���ؼ�
�簢�� ���� ��ǥ���� ��� 1�� �� ��,
���������� ���ؼ� ��ǥ�� �簢���� ���� �ʰ�, ���� �湮���� ���� ��ǥ�� ��ǥ���� dfs�� ���� Ž���� ���־���.
�ѹ� dfs�� �ؼ� �� dfs�� ���� ������ count�� �÷����� ���� count������ ���Ϳ� �־��ֹǷ�,
������ ���� ������ ������ ������ �ȴ�.

*/

int arr[101][101] = { 0, };
bool visited[101][101] = { 0, };
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };
int N, M, K, count;

void dfs(int x, int y) {
	::count++;
	visited[x][y] = true;
	for (int i = 0;i < 4;i++) {
		int newX = x + moveX[i];
		int newY = y + moveY[i];
		if (newX >= 0 && newX < N && newY >= 0 &&newY < M && !visited[newX][newY] && !arr[newX][newY]) dfs(newX, newY);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	while (K--) {
		int  lx, ly, rx, ry;
		cin >> ly >> lx >> ry >> rx;
		for (int i = lx;i < rx;i++) {
			for (int j = ly;j < ry;j++) {
				arr[i][j] = 1;
			}
		}
	}

	vector<int> v;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			::count = 0;
			if (!arr[i][j] && !visited[i][j]) {
				dfs(i, j);
				v.push_back(::count);
			}
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size();i++)cout << v[i] << ' ';
	cout << endl;
}
