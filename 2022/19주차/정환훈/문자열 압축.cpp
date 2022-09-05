#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string compress(string s, int n){
    string res;
    for(int i=0;i<s.size();i+=n){
        string now = s.substr(i, n);
        int k = i;
        string compressed = now;
        int iter = 0;
        while(k<s.size() && s.substr(k, n) == now){
            k += n;
            iter++;
        }
        if(iter > 1){
            compressed += to_string(iter);
            i += (iter -1) * n;
        }
        res += compressed;
    }
    return res;
}


int solution(string s) {
    int answer = 0;
    vector<pair<int,string>> v;
    for(int i=1;i<=s.size();i++){ // 1������ n������ ������ �ڸ���
        string str = compress(s, i);
        v.push_back({str.size(), str});
    }
    // ���� ª�� ���ڿ� ������ ����
    sort(v.begin(), v.end());
    answer = v[0].first;
    return answer;
}
