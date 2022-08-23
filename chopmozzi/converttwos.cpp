#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string twos="";
    int zerocount = 0;
    int changecount = 0;
    while (s != "1")
    {
        string twos="";
        int zero = 0;
        int one = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                zero++;
                zerocount++;
            }
        }
        one = s.length() - zero;
       //s="";
        while (one != 0)
        {
            if (one % 2 == 1)
            {
                twos = '1' + twos;
            }
            else
                twos = '0' + twos;
           // s+=to_string(one%2);
            one = one / 2;
        }
        long num = stol(twos);
        s = to_string(num);
        changecount++;
    }
    answer.push_back(changecount);
    answer.push_back(zerocount);
    return answer;
}