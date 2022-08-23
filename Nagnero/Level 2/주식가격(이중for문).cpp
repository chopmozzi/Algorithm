#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    for(int i = 0; i < prices.size(); i++){
        for(int j = i + 1; j < prices.size(); j++){
            if(prices[i] <= prices[j]){
                answer[i]++;
            } else {
                if(find(answer.begin(),answer.end(),i) != answer.end() - 1)
                    answer[i]++;
                break;
            }
        }
    }
    
    return answer;
} // 효율성 검사 실패

//stack 방식 이해 X