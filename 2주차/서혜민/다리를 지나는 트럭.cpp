#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*

2021.07.19 ������

answer : �ҿ� �ð�
weightSum : �ٸ� �� Ʈ���� ���� ��
pass : �ٸ��� ������ Ʈ���� ��

onBridge�ٸ��� �ǳʴ� Ʈ���� ���ԿͰ� �ٸ��� �ǳʴ� �� �ҿ�ǰ� �ִ� �ð��� ������ �����̴�. 
���Ϳ� ���Ե� Ʈ���� ������ �հ� ���� �ٸ��� �ǳʷ��� Ʈ���� ����,  �׸���
���� ������ ����, �� �ٸ��� �ǳʴ� Ʈ���� ���� �Է� ���� ������ ����, Ʈ���� ���� ���Ͽ�
�ش� Ʈ���� �ٸ��� �ǳ� �� �ִٸ� onBridge���Ϳ� Ʈ���� ���Կ� ó������ �ҿ�Ǵ� �ð� 1�ʸ� ������ ���ָ鼭,weightSum�� ������ ���ش�.
�̶� 1�ʸ��� Ʈ���� �ٸ��� ���� �� 1�� ����, ���� Ʈ���� �ٸ��� ���� ���� �� �������Ƿ�, ��� �ٸ� ���� Ʈ���� �ٸ��� �ǳʴ� �� �ҿ�Ǵ� �ð��� 1�ʾ� �����ش�.
�׸��� �ٸ����� ���� �� �տ� ��ġ�� Ʈ���� �ҿ�ð��� �ٸ��� ���̿� �������� �ٸ��� ������ �ǳʰ� �ǹǷ�, �̸� ���Ϳ��� ���ָ鼭 weightSum�� ���Ӱ� �����Ѵ�.

�� ������ ��� Ʈ���� �ٸ��� �ǳ� ������ �ݺ����ش�.

*/
int solution(int bridge_length, int weight, vector<int> v) {
    int answer = 0;
    int weightSum = 0;
    int pass = 0;
    vector<pair<int,int>> onBridge;

    int index = 0;
    while (pass<v.size()) {
        answer++;//��.
        if (onBridge.size() + 1 <= bridge_length && weightSum + v[index] <= weight) {
            onBridge.push_back({ v[index],1 });
            weightSum += v[index++];
        }
        if (onBridge[0].second >= bridge_length) {
            weightSum -= onBridge[0].first;
            onBridge.erase(onBridge.begin());
            pass++;
        }
        for (int i = 0;i < onBridge.size();i++) {
            onBridge[i].second++;
        }
        cout << index << " " << answer << endl;
    }
    return answer+1;
}

int main() {
    cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 });
}