#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*

2021.07.19 ������

�ð� ������� ������ �� �� ���� ������
���� ������ ���� ���� ���� ������ ���Ҹ� ��������
�� ���Һ��� �̻��� �����̸� 1�ʾ� ������Ű��,
�׷��� �ʰ� ������ ���´ٸ� 1�ʸ� ������Ų ��, �ݺ����� ���� ���ҷ� �Ѿ�Եȴ�.

*/

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int second;
	for (int i = 0;i < prices.size();i++) {
		second = 0;
		for (int j = i + 1;j < prices.size();j++) {
			if (prices[i] <= prices[j]) second++;
			else {
				second++;
				break;
			}
		}
		answer.push_back(second);
	}
	return answer;
}
