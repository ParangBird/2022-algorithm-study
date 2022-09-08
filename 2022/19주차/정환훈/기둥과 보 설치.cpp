#include <string>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> buildings;

bool check(){
    
    for(auto b : buildings){
        int x = b[0]; int y = b[1]; int type = b[2];
        if(type == 0){ // ���
            // ����� �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
            if(y == 0) continue;
            vector<vector<int>> pre = { {x, y, 1}, {x-1, y, 1}, {x, y-1, 0}};
            if(buildings.find(pre[0]) != buildings.end() ||
               buildings.find(pre[1]) != buildings.end() || 
               buildings.find(pre[2]) != buildings.end()) continue;            
            return false;
        }
        else{ // ��
            // ���� ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.
            vector<vector<int>> pre = { {x, y-1, 0}, {x+1, y-1, 0}, {x+1, y, 1}, {x-1, y, 1}};
            if(buildings.find(pre[0]) != buildings.end() ||
               buildings.find(pre[1]) != buildings.end() || 
               (buildings.find(pre[2]) != buildings.end() && buildings.find(pre[3]) != buildings.end())) 
                continue;
            return false;
        }
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(vector<int> b : build_frame){
        int cmd = b[3];
        vector<int> t = {b[0], b[1], b[2]};
        if(cmd == 0){ // ����
            buildings.erase(t);
            if(!check()){
                buildings.insert(t);
            }
        }
        else{ // ��ġ
            buildings.insert(t);
            if(!check()){
                buildings.erase(t);
            }
        }
    }
    
    for(auto &v : buildings){
        answer.push_back(v);
    }
    
    return answer;
}
