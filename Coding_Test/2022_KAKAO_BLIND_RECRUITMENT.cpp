#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	vector<int> result;

	// 동적 2차원 배열을 만든다.
	// result 벡터에는 신고당한 횟수가 기록되고
	// answer 벡터에는 신고한 사람의 인덱스를 기록한다.
	int list_num = id_list.size();
	int** flow = new int* [list_num];
	for (int i = 0; i < list_num; i++) {
		flow[i] = new int[list_num];
		answer.push_back(0);
		result.push_back(0);
	}
	for(int i=0; i<list_num; i++)
		for (int j = 0; j < list_num; j++) {
			flow[i][j] = 0;
		}
	
	// id_list에 대해 신고자가 누구이고 신고대상이 누구인지 판단한다.
	for (int i = 0; i < report.size(); i++) {
		int j = 0;
		string reporter;
		string target;

		while (report[i][j] != ' ') {
			reporter.push_back(report[i][j]);
			j++;
		}
		for (int k = j + 1; k < report[i].size(); k++) {
			target.push_back(report[i][k]);
		}

		// 신고자와 신고대상을 2차원 배열로 표시한다.
		for (int k = 0; k < list_num; k++) {
			if (id_list[k] == reporter) {
				for (int m = 0; m < list_num; m++) {
					if (target == id_list[m]) {
						flow[k][m] =1;
					}
				}
			}
		}
	}

	// id_list에 대해 신고당한 횟수를 파악한다.
	for (int i = 0; i < list_num; i++) {
		for (int j = 0; j < list_num; j++) {
			result[i] += flow[j][i];
		}
		result[i] = result[i] / k;
	}

	// 임계값 k 이상의 신고대상에 대해 신고자를 파악한다.
	for (int i = 0; i < list_num; i++) {
		if (result[i] != 0) {
			for (int j = 0; j < list_num; j++) {
				if (flow[j][i] != 0) {
					answer[j] += 1;
				}
			}
		}
	}
	


	return answer;
}

int main(void) {
	vector<string> id_list;
	vector<string> report;
	vector<int> result;

	id_list.push_back("muzi");
	id_list.push_back("frodo");
	id_list.push_back("apeach");
	id_list.push_back("neo");
	report.push_back("muzi frodo");
	report.push_back("apeach frodo");
	report.push_back("frodo neo");
	report.push_back("muzi neo");
	report.push_back("apeach muzi");
	result = solution(id_list, report, 2);

	id_list.clear();
	report.clear();
	id_list.push_back("con");
	id_list.push_back("ryan");
	report.push_back("ryan con");
	report.push_back("ryan con");
	report.push_back("ryan con");
	report.push_back("ryan con");
	result = solution(id_list, report, 3);

	return 0;
}