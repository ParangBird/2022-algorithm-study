#include <iostream>
using namespace std;

bool board[101][101];

/*
�Է¹��� �� ��ǥ ���ο� ���Ե� ���簢�� ������ 1�� ����
1�� ������ ���� ���ϸ� �ȴ�.
*/
int main() {
	
	int x1, y1, x2, y2;
	for (int i = 0;i < 4;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int y = y1;y < y2;y++) {
			for (int x = x1;x < x2;x++) {
				board[x][y] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 0;i < 101;i++) {
		for (int j = 0;j < 101;j++) {
			if (board[i][j]) sum++;
		}
	}

	cout << sum << endl;
}