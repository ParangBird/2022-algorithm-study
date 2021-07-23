#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

/*

2021.07.19 ������

������ ��������� ĥ���� ������ ���� ���� ī���� �����̴�.
���θ� 2�����ؼ� ī���� ������ �����ٱ���
���̸� ���η� ������ �� �ȹٷ� �������� ���� ���η��Ͽ�
����� ������ ���� (����-2)*(����-2)�̹Ƿ� �� ���� �־��� ����� ������ ���� ���ٸ�

�ش� ���ο� ���θ� ���Ϳ� Ǫ�����ش�.

*/

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    vector<int> answer;
    int garo, sero;
    for (sero = 2;sero <= sqrt(sum);sero++) {
        if ((sum % sero)==0) {
            garo = sum / sero;
            int yellowCount = (sero - 2) * (garo - 2);
            if (yellow == yellowCount) {
                answer.push_back(garo);
                answer.push_back(sero);
                return answer;
            }
        }
    }
}

int main() {
    solution(24,24);
}