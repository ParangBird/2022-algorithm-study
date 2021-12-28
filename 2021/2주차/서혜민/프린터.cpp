#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.07.19 ������

1. priorities���� ���� ��� ��ġ�ߴ��� �˷��ִ� �ε�����, �߿䵵�� ¦���� �� ���Ϳ� �־��ش�.
2. �ε��� 0�� ��ġ�� ������ �������� ������ ������ ��� �߿䵵�� ���ٸ� �� ������ �μⰡ �� �� �����Ƿ�,
   �� ������ ���Ϳ��� �����ش�.
3. ���� �߿䵵�� ���� ������ �ִٸ�, �� ������ ���Ϳ��� ����� ���Ӱ� Ǫ�ø� ����, ���� �ڿ� �ִ� �ε�����
   ��ġ�ϰ� �ȴ�.

*/

int solution(vector<int> priorities, int location) {
    vector<pair<int, int>> v;
    for (int i = 0;i < priorities.size();i++) {
        v.push_back(make_pair(i, priorities[i]));
    }

    bool canCopy = true;
    int count = 0;
    while (!v.empty()) {
        int index = v[0].first;
        int max = v[0].second;
        canCopy = true;
        for (int i = 1;i < v.size();i++) {
            if (max < v[i].second) {
                canCopy = false;
                break;
            }
        }
        if (canCopy && index == location) {
            v.erase(v.begin());
            return ++count;
        }
        else if (canCopy) {
            count++;
        }
        else v.push_back(make_pair(index, max));
        v.erase(v.begin());
    }
}

int main() {
    cout << solution({ 1,1,9,1,1,1 }, 0);
}