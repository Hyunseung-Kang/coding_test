#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int nums[], size_t nums_len);
// nums_len은 배열 nums의 길이입니다.

int main(void) {
    int list[] = { 1, 2, 3, 4 };
    //int list[] = { 1, 2, 7, 6, 4 };

    size_t length = sizeof(list)/sizeof(int);
    int result = solution(list, length);


    printf("result: %d\n", result);
    return 0;
}
int solution(int nums[], size_t nums_len) {
    int answer = -1;


    // 조합을 통해 nums_len개 중 3개를 뽑는 경우를 생각하자.
    int sum = 0;
    int check = 0;
    int count = 0;
    for (int i = 0; i < nums_len - 2; i++) 
        for (int j = i+1; j < nums_len - 1; j++) 
            for (int k = j + 1; k < nums_len; k++) {
                sum = nums[i] + nums[j] + nums[k];
                int half_data = sum / 2;
                check = 0;
                for (int s = 2; s <= half_data; s++) {
                    if (sum % s == 0)
                        break;
                    else {
                        check++;
                    }
                }
                if (check == (half_data - 1))
                    count++;
            }
    answer = count;

    return answer;
}