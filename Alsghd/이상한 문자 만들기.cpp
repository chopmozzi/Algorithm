#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string s) {
	string answer = "";
	answer = s;
	int temp = 0;
	for (int i = 0; i < answer.length(); i++) {
		if (answer[i] != ' ') {
			if (temp % 2 == 0) answer[i] = toupper(answer[i]);
			else if (temp % 2 == 1) answer[i] = tolower(answer[i]);
			temp++;
		}
		else {
			temp = 0;
			answer[i] = ' ';
		}
	}
	return answer;
}

int main(void) {
	string str1;
	getline(cin, str1);
	string str2 = solution(str1);
	cout << str2;

	return 0;
}
