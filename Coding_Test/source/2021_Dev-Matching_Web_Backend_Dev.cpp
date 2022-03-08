#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> solution(vector<int>lottos, vector<int> win_nums) {
	vector<int> answer;



	return answer;
}

int main(void) {
	vector<int> lottos;
	vector<int> win_nums;
	vector<int> answer;

	lottos = { 44, 1, 0, 0, 31, 25 };
	win_nums = { 31, 10, 45, 1, 6, 19 };
	answer = solution(lottos, win_nums);
	for (int i = 0; i < answer.size(); i++) {
		cout << "lottos[" << i << "]: " << answer[i] << endl;
	}

	lottos = { 0, 0, 0, 0, 0, 0};
	win_nums = { 38, 19, 20, 40, 15, 25};
	answer = solution(lottos, win_nums);
	for (int i = 0; i < answer.size(); i++) {
		cout << "lottos[" << i << "]: " << answer[i] << endl;
	}

	lottos = { 45, 4, 35, 20, 3, 9};
	win_nums = { 20, 9, 3, 45, 4, 35};
	answer = solution(lottos, win_nums);
	for (int i = 0; i < answer.size(); i++) {
		cout << "lottos[" << i << "]: " << answer[i] << endl;
	}


	return 0;
}