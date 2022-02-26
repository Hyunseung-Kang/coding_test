#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	vector<int> result;

	// ���� 2���� �迭�� �����.
	// result ���Ϳ��� �Ű���� Ƚ���� ��ϵǰ�
	// answer ���Ϳ��� �Ű��� ����� �ε����� ����Ѵ�.
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
	
	// id_list�� ���� �Ű��ڰ� �����̰� �Ű����� �������� �Ǵ��Ѵ�.
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

		// �Ű��ڿ� �Ű����� 2���� �迭�� ǥ���Ѵ�.
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

	// id_list�� ���� �Ű���� Ƚ���� �ľ��Ѵ�.
	for (int i = 0; i < list_num; i++) {
		for (int j = 0; j < list_num; j++) {
			result[i] += flow[j][i];
		}
		result[i] = result[i] / k;
	}

	// �Ӱ谪 k �̻��� �Ű��� ���� �Ű��ڸ� �ľ��Ѵ�.
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