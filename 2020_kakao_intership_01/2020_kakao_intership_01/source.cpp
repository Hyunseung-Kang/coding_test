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
    
    char temp_hand = 'o';
    if (hand == "right")
        temp_hand = 'R';
    else if (hand == "left")
        temp_hand = 'L';
    int length = size(numbers);
    int left[2] = { 0, 3 };    int right[2] = { 2, 3 };
    int data[2] = { 0,0 };
    char out;
    int left_dist = 0;
    int right_dist = 0;
    
    char* arr = (char*)malloc(sizeof(char) * (length));
    
    if(arr != NULL)
    for (int i = 0; i < length; i++) {
        left_dist = 0;
        right_dist = 0;
        switch (numbers[i]) {
        case 0:
            data[0] = 1;    data[1] = 3;
            left_dist = abs(data[0] - left[0]) + abs(data[1] - left[1]);
            right_dist = abs(data[0] - right[0]) + abs(data[1] - right[1]);
            if (left_dist < right_dist) {
                out = 'L';
                left[0] = data[0];
                left[1] = data[1];
            }
            else if (left_dist == right_dist) {
                out = temp_hand;
                if (temp_hand == 'L') {
                    left[0] = data[0];
                    left[1] = data[1];
                }
                else {
                    right[0] = data[0];
                    right[1] = data[1];
                }
            }
            else {
                out = 'R';
                right[0] = data[0];
                right[1] = data[1];
            }
            break;

        case 1:
            left[0] = 0;    left[1] = 0;
            out = 'L';
            break;
        case 2:
            data[0] = 1;    data[1] = 0;
            left_dist = abs(data[0] - left[0]) + abs(data[1] - left[1]);
            right_dist = abs(data[0] - right[0]) + abs(data[1] - right[1]);
            if (left_dist < right_dist) {
                out = 'L';
                left[0] = data[0];
                left[1] = data[1];
            }
            else if (left_dist == right_dist) {
                out = temp_hand;
                if (temp_hand == 'L') {
                    left[0] = data[0];
                    left[1] = data[1];
                }
                else {
                    right[0] = data[0];
                    right[1] = data[1];
                }
            }
            else {
                out = 'R';
                right[0] = data[0];
                right[1] = data[1];
            }
            break;

        case 3:
            right[0] = 2;   right[1] = 0;
            out = 'R';
            break;
        case 4:
            left[0] = 0;    left[1] = 1;
            out = 'L';
            break;
        case 5:
            data[0] = 1;    data[1] = 1;
            left_dist = abs(data[0] - left[0]) + abs(data[1] - left[1]);
            right_dist = abs(data[0] - right[0]) + abs(data[1] - right[1]);
            if (left_dist < right_dist) {
                out = 'L';
                left[0] = data[0];
                left[1] = data[1];
            }
            else if (left_dist == right_dist) {
                out = temp_hand;
                if (temp_hand == 'L') {
                    left[0] = data[0];
                    left[1] = data[1];
                }
                else {
                    right[0] = data[0];
                    right[1] = data[1];
                }
            }
            else {
                out = 'R';
                right[0] = data[0];
                right[1] = data[1];
            }
            break;
        case 6:
            right[0] = 2;   right[1] = 1;
            out = 'R';
            break;
        case 7:
            left[0] = 0;   left[1] = 2;
            out = 'L';
            break;
        case 8:
            data[0] = 1;    data[1] = 2;
            left_dist = abs(data[0] - left[0]) + abs(data[1] - left[1]);
            right_dist = abs(data[0] - right[0]) + abs(data[1] - right[1]);
            if (left_dist < right_dist) {
                out = 'L';
                left[0] = data[0];
                left[1] = data[1];
            }
            else if (left_dist == right_dist) {
                out = temp_hand;
                if (temp_hand == 'L') {
                    left[0] = data[0];
                    left[1] = data[1];
                }
                else {
                    right[0] = data[0];
                    right[1] = data[1];
                }
            }
            else {
                out = 'R';
                right[0] = data[0];
                right[1] = data[1];
            }
            break;
        case 9:
            right[0] = 2;   right[1] = 2;
            out = 'R';
            break;
        }
        arr[i] = out;
        answer.append(1, out);
        //answer = answer + out;
    }
    //answer = answer + '\0';
    printf("%s: ", answer);
    return answer;
}