#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*

2021.07.21 ������

�� ������ ���� a��, ���� ������ ���� b���� �ִٸ�
�����̰� �� �� �ִ� ��ü ������ �� ���� ��� ���Դ� �ͺ���
�� ������ �ʸ� �԰ų�, ���� ������ �ʸ� �԰ų� �� �� ������ ���� ��� �Դ� �� ���� �����Ѵ�.
�� ��츦 ��� ����ϸ� (a+1)*(b+1)�� �ȴ�.
������ �����̴� �ּ� �� ���� ���� �Ծ���ϹǷ� ��� ���� �ʴ� ����� �ϳ��� ����
������ (a+1)(b+1)-1�� �ȴ�.

���� ������ ������ ���� ���� �̹� �����ϴ� ���̸� �ش� �ε����� ã�Ƽ� ������ �ϳ� �����ְ�,
�������� �ʴٸ� ���Ϳ� ���Ӱ� ������ ���ش�.
���� ���� ������ ������ ������ 1(���� �ʴ� ���)�� ���� ���� ���� ��,
���������� ��� ���� �ʴ� ����� �ϳ��� �� ���� ������ �ȴ�.

*/

vector<pair<string, int>> matches;
int kindExist(string kind) {
	for (int i = 0;i < matches.size();i++) {
		if (kind == matches[i].first) return i;
	}
	return -1;
}

int solution(vector<vector<string>> clothes) {
	int index = 0;
	for (int i = 0;i < clothes.size();i++) {
		if ((index = kindExist(clothes[i][1])) != -1) {
			matches[index].second++;
		}
		else matches.push_back(make_pair(clothes[i][1], 1));
	}
	int answer = 1;
	for (int i = 0;i < matches.size();i++) {
		answer *= (matches[i].second + 1);
	}
	return answer - 1;
}

int main() {
	vector<vector<string>> v = { {"yellow","headgear"},{"blue","eyewear"},{"green","headgear"} };
	solution(v);
}