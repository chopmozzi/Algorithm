#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> tree;
    
    for(int i = 0; i < skill.length(); i++)
        tree[skill[i]] = i + 1;
    
    for(auto skills : skill_trees){
        int count = 1;
        bool check = true;
        for(int j = 0; j < skills.length(); j++){
            if(tree[skills[j]] > count){
                check = false;
                break;
            } else if(tree[skills[j]] == count){
                count++;
            }
        }
        if(check)
            answer++;
    }
    
    return answer;
}