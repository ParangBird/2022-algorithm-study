#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*

2021.07.19  ������

���� ���� �ο�Ƚ���� ��� citations�� ������ �Ѵ�.
����, ���� �ο�Ƚ���� �ε����μ� �ش� �� �ο� Ƚ���� �� ������ ���� countSum�迭��
������ �� citations ���Ϳ��� ���� ���� ������ ���� ���� ������ 0���� ��� ���� �������� ������ ���� �����Ѵ�.
�ᱹ �̸� ���Ͽ�, countSum�迭���� �ش� �ο� Ƚ�� ������ ���� ������ ������ �ȴ�.

������ Ư���� �ο� Ƚ���� �ǹ��ϴ� h�� 0�� �� �� �����Ƿ�, countSum�迭���� �ε��� 1���� ������ Ž���� �ϸ鼭
h�� �̻� �ο�� ���� ������ [ ��ü �� - countSum[h-1]�� �� ] �̰�
h�� ���� �ο�� ���� ������ [ countSum[h-1]�� ��] �̹Ƿ�
���� �� ������ h���� �̻�/�����̸鼭 ���� �ε����� ū ���� ������ �ȴ�.

*/

int countSum[10001];//0~10000ȸ�� �� �ο� Ƚ���� �� ���� 
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int sum = 0;
    int num = 0;
    for (int i = 0;i < citations.size();i++) {
        countSum[citations[i]] = ++sum;
    }
    int maxIndex = 0;
    for (int i = 1;i <= 10000;i++) {
        if (countSum[i] == 0) countSum[i] = countSum[i - 1];
        int sumUp = citations.size() - countSum[i - 1];//�̻�
        int sumDown = countSum[i - 1];//����
        if (i > maxIndex && sumUp >= i && sumDown <= i) maxIndex = i;
    }
    return maxIndex;
}

int main() {
    cout << solution({ 3,0,6,1,5, });
}