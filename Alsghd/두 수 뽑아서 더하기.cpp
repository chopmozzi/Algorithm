#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int>numbers) {
	vector<int> answer;
	vector<int> temp;

	for (int i = 0; i < numbers.size(); i++) {
		for (int j = 0; j < numbers.size() - i - 1; j++) {
			answer.push_back(numbers[i] + numbers[i + j + 1]);
		}
	}
	sort(answer.begin(), answer.end(), less<int>());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return answer;
}