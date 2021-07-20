#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*

2021.07.19 ������

bigger�� ���� ��� 3�� 30�� ���� �� �� �η� 330�� 303�� ���� �� �ִ� ��, �� �� �� �߿��� 
�� ū ���� ������ ���� ���� �� �ֵ��� ������ �ǵ��� sort�Լ��� ����° ���ڷ� ����.
�׷��� �̸� ���� numbers ���ʹ� �տ������� ���� ū ���� ���� �� �ֵ��� ������ �ȴ�.

�ᱹ, numbers���� �տ������� �ϳ��� ������ �ؼ� string���� ��ȯ�� �ϸ鼭
���ڸ� �ǹ��ϴ� ���ڿ��� ������ �ȴ�.

�̶� 0�� ������ ���� ��, �ش� ���ڿ��� �ܼ� 0���� ��ȯ�� ���ش�.

*/
bool bigger(int a, int b) {
    int num1 = stoi(to_string(a) + to_string(b));
    int num2 = stoi(to_string(b) + to_string(a));
    return num1 > num2;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), bigger);
    string answer = "";
    for (auto i : numbers) {
        answer += to_string(i);
    }
    if (answer[0] == '0') answer = '0';
    return answer;
}

int main() {
    string answer = solution({ 0,0,0 });
    cout << endl << answer << endl;
}