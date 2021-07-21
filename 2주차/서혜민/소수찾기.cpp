#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

/*

2021.07.19 ������

����, �����佺�׳׽��� ü�� ���� ������ ���� �� �ִ� ���� ū ������ �Ҽ��� ���Ѵ�.
0�� 1�� �Ҽ��� �ƴϹǷ� 1�� �ʱ�ȭ�� ��, for���� ���ؼ� 2���� 9999999�� �����ٱ���
�� ������ �������� ���� �� ������ �������� ���� �Ҽ��� �ƴϰ� �ȴ�.

��������, �Է¹��� numbers���ڿ��� ������������ ������ �Ѵ�. 
������ �ؼ� ���� ����, numbers���ڿ��� ���� �� �ִ� ���� ū ���̴�.

��������, �� numbers���ڿ��� �����ϴ� ������ ������ �˱� ����
���� 10�� countOrg�迭�� �ε����� numbers���ڿ� ���� ���ڷμ� 
for���� ���� ������ �迭�� ������ ���ش�.

���� ���� ���� �Ҽ��� 2���� ���� ū ������ for���� ���ؼ�
�� ���� �Ҽ��̸鼭, ���ڿ��� �����ϴ� ���� ���� �� �ִ� ������ ������� countOrg�迭�� ���ؼ� Ȯ���� �ϸ� �ȴ�.

*/
bool num[10000000];
int solution(string numbers) {
    //�����佺�׳׽��� ü, 0�̸� �Ҽ�.
    num[0] = 1; num[1] = 1; //0�ϰ� 1�� �Ҽ�x.
    for (int i = 2;i <= sqrt(9999999);i++) {
        if (num[i] == 1) continue; 
        for (int j = i * i;j <= 9999999;j += i) {
            num[j] = 1;
        }
    }
  
    sort(numbers.begin(), numbers.end(), greater<>());
    int maxNum;//���� �� �ִ� ���� ū ��.
    int countOrg[10] = { 0, };//0~9 ���� ����
    for (int i = 0;i < numbers.length();i++) {
        countOrg[numbers[i]-'0']++;
    }
    if (numbers[0] == '0') return 0;
    else {
        maxNum = stoi(numbers);
    }

    int answer = 0;
    int count[10];
    bool succ = true;
    int countNum = 0;
    for (int i = 2;i <= maxNum;i++) {
        succ = true;
        countNum = 0;
        copy(countOrg, countOrg + 10, count);
        string number = to_string(i);
        if (num[i]) continue;//num[i]�� 1�̸� �� ���� �Ҽ��� x.
        else {      
            for (int j = 0;j < number.length();j++) {
                cout << endl;
                if (count[number[j]-'0'] == 0) {
                    succ = false;
                    break;
                }
                else {
                    count[number[j]-'0']--;
                    countNum++;
                }
            }
            if (succ==true && countNum==number.length()) {
                answer++;
            }
        }   
    }
    return answer;
}

int main() {
    cout << solution("011");
}