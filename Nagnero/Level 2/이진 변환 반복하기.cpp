#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_Binary(int n){
    string r;
    while(n != 0){
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    return r;
}

vector<int> solution(string s) {
    vector<int> answer;
    int num_zero = 0;
    int count = 0;
    
    while(s != "1") {
        sort(s.begin(), s.end());
        num_zero += s.find("1");
        s = to_Binary(s.length() - s.find("1"));
        count++;
    }
    
    answer.push_back(count);
    answer.push_back(num_zero);
    
    return answer;
}