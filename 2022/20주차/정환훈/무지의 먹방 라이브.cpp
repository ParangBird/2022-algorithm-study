#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {  
    long long sum = 0;
    long long b4 = 0;
    long long eat = k;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<food_times.size();i++){
        sum += food_times[i];
        pq.push({-1 * food_times[i], i+1});
    }
    // �� �Ծ k+1 �ð��� ���� �� ����
    if(sum <= eat) 
        return -1;
    
    // (���� ���� �� - ������ �� ��) * ���� ����ִ� ���� ����ŭ eat ���� �ö󰣴�
    // ���������� [3,1,2] -> [2,0,1]�� �ǹǷ� ���� (2 - 1) * 2�� ������
    while((-pq.top().first - b4) * pq.size() <= eat){
        eat -= (-pq.top().first - b4) * pq.size();
        b4 = -pq.top().first;
        pq.pop();
    }
    
    vector<pair<int,int>> v;
    while(!pq.empty()){
        pair<int,int> now = pq.top();
        v.push_back({now.second, -1 * now.first});
        pq.pop();
    }
    // ���� �ε��� ������� �ٽ� �迭
    sort(v.begin(), v.end());
    // ��Ƴ��� ���� �迭���� ���� eat����ŭ �����ָ� �װ��� ������ ���� ��
    return v[eat % v.size()].first;
}
