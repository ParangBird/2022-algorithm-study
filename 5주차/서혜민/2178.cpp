#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
2021.08.09 ������
dfs->�ð��ʰ�
bfs�� ���� Ž���ϸ鼭 ù �������� 1�� ������ ��, ��θ� ã�� ������
1���� �ϳ��� ������ ���� route�� ����.

*/

string arr[101];
int route[101][101];
bool visited[101][101];
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };

int main() {
	
	int N, M;
	cin >> N >> M;
	arr[0] = "";
	for (int i = 1;i <= N;i++) {
		string s;
		cin >> s;
		arr[i] = "0" + s;
	}
	
	queue<pair<int, int>> queue;
	queue.push({ 1, 1 });
	visited[1][1] = 1;
	route[1][1] = 1;
	int count = 1;

	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		if (x == N && y == M) break;
		queue.pop();
		for (int i = 0;i < 4;i++) {
			int newX = x + moveX[i];
			int newY = y + moveY[i];
			if (newX >= 1 && newY >= 1 && newX <= N && newY <= M && !visited[newX][newY]
				&& arr[newX][newY] == '1') {
				queue.push({ newX,newY });
				visited[newX][newY] = 1;
				route[newX][newY] = route[x][y] + 1;
			}
		}
	}
	cout << route[N][M] << endl;
}