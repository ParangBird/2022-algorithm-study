#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, k;
vector<int> v;
set<int> s;
void input(){
	cin >> n >> k;
	v = vector<int>(k);
	for(int i=0;i<k;i++){
		cin >> v[i];
	}
}
int pop(int id){
	// 1. �ٽô� �ȳ����� ��� 
	for(auto e : s){		
		if(find(v.begin()+id, v.end(), e) == v.end()){
			return e;
		}		
	}
	// 2. ù ������ ���� �� �������� �����ϴ� ���
	vector<int> t;
	vector<bool> first(101, false);	
	for(int i=id;i<k;i++){
		if(s.find(v[i]) != s.end() && !first[v[i]]){
			first[v[i]] = true;			
			t.push_back(v[i]);
		}
	}
	return t.back();
}
void solve(){
	int ans = 0;	
	int use = 0;
	for(int i=0;i<k;i++){
		int cur = v[i];
		// �̹� ����� 
		if(s.find(cur) != s.end()){
			continue;
		}
		// �ڸ� ���� 
		else if(use < n){
			s.insert(cur);
			use++;
		}	 
		else{
			ans++;						
			int p = pop(i);
			s.erase(p);
			s.insert(cur);
		}
	}
	cout << ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();		
	return 0;
}
