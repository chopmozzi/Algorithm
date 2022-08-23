#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";
    
    for(int i = 0; i < s.length();){
        if(s.substr(i, 1) >= "0" && s.substr(i,1) <= "9"){
            temp += s.substr(i, 1);
            i++;
        } else if(s.substr(i, 4) == "zero") {
            temp += "0";
            i += 4;
        } else if(s.substr(i, 3) == "one") {
            temp += "1";
            i += 3;
        } else if(s.substr(i, 3) == "two") {
            temp += "2";
            i += 3;
        } else if(s.substr(i, 5) == "three") {
            temp += "3";
            i += 5;
        } else if(s.substr(i, 4) == "four") {
            temp += "4";
            i += 4;
        } else if(s.substr(i, 4) == "five") {
            temp += "5";
            i += 4;
        } else if(s.substr(i, 3) == "six") {
            temp += "6";
            i += 3;
        } else if(s.substr(i, 5) == "seven") {
            temp += "7";
            i += 5;
        } else if(s.substr(i, 5) == "eight") {
            temp += "8";
            i += 5;
        } else if(s.substr(i, 4) == "nine") {
            temp += "9";
            i += 4;
        }
    }
    
    answer = stoi(temp);
    
    return answer;
}