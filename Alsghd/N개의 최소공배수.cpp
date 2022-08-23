#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b; 
        b = c;
    }                                          
    return a;
}

int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int gcd = Gcd(answer, arr[i]);
        int lcm = answer * arr[i] / gcd;
        answer = lcm;
    }

    return answer;


}