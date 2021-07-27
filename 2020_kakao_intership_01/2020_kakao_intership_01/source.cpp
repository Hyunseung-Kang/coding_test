#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand);

int main(void) {
    vector<int> list;
    list.push_back(1);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(8);
    list.push_back(2);
    list.push_back(1);
    list.push_back(4);
    list.push_back(5);
    list.push_back(9);
    list.push_back(5);

    /*list.push_back(7);
    list.push_back(0);
    list.push_back(8);
    list.push_back(2);
    list.push_back(8);
    list.push_back(3);
    list.push_back(1);
    list.push_back(5);
    list.push_back(7);
    list.push_back(6);
    list.push_back(2);*/
    
    string result;
    result = solution(list, "right");

    printf("result: %s\n", result);
    return 0;
}


string solution(vector<int> numbers, string hand) {
    string answer = "";

    int length = size(numbers);


    char* arr = (char*)malloc(sizeof(int) * length);


    return answer;
}