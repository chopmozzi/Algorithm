#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string result = "";
    
    for (int i=0;i<seoul.size();i++){
        if(seoul[i]=="Kim")
            
        result = "김서방은 " +to_string(i)+ "에 있다" ;
    }

    return result;
}