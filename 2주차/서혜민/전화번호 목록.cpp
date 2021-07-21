#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*

2021.07.19 ������

sort�� ���ؼ� ������ �� �� ���� ���� �� ���ڵ���
�տ������� ���� ���Ͽ� �� ū ���� �ڿ� ��ġ�ϰ� �Ǵ� ������ ��ġ�� �ȴ�.
�ᱹ �̸� ���ؼ� � ���� ���� ��ġ�� ���� �ٸ� ��ġ�� �ִ� ���麸��
�տ������� ���̰� �� ���� ����� ���ڸ� ������ �ȴ�.

�׷��� �� ���ڰ� �� ������ ���� �ִ� ���ڿ��� �߰ߵ� ���۵� ��ġ�� 0�̶��
�� ���ڴ� ���ξ �ǹǷ� false�� �����Ѵ�.

*/

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0;i < phone_book.size();i++) {
        cout << phone_book[i] << endl;
    }
    for (int i=0;i<phone_book.size()-1;i++)
    {
        if (phone_book[i + 1].find(phone_book[i]) == 0) return false;
    }
    return true;
}

int main() {
    cout << solution({ {"123"},{"12"},{"125"},{"567"},{"88"}});
}

