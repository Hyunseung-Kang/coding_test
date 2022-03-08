#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	vector<char> result;
	int count = 0;
	for (int i = 1; i <= s.length() / 2; i++) {
		int start_pt = 0;
		while (start_pt+i <= s.length()) {
			vector<char> part1;
			vector<char> part2;
			for (int j = 0; j < i; j++) {
				part1.push_back(s[start_pt+j]);
			}
			for (int j = 0; j < i; j++) {

			}
		}
	}
	cout << s.length() << endl;

	return answer;
}



int main(void) {
	cout << solution("aabbaccc") << endl;
	cout << solution("ababcdcdababcdcd") << endl;
	cout << solution("abcabcdede") << endl;
	cout << solution("abcabcabcabcdededededede") << endl;
	cout << solution("xababcdcdababcdcd") << endl;
	//	7	9	8	14	17

	return 0;
}