#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){ // 비교함수 커스텀
    return a + b > b + a; // 문자열 ab와 ba를 내림차순으로 return
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp; // 임시 벡터
    
    for(auto i : numbers)
        temp.push_back(to_string(i));
    
    sort(temp.begin(), temp.end(), compare);
    
    if(temp[0] == "0")
        answer = "0";
    else
        for(auto j : temp)
            answer += j;
    
    return answer;
}