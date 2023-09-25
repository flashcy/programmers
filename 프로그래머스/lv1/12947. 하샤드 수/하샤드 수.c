#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int temp = x;
    int sum = 0;
    while(temp) {
        sum += temp%10;
        temp /= 10;
    }
    if(x % sum != 0) answer = false;
    return answer;
}