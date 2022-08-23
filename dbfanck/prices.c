#include <stdio.h>
#include <stdlib.h>

// prices_len은 배열 prices의 길이입니다.
int* solution(int prices[], size_t prices_len) {

    int* answer = (int*)malloc(sizeof(int)*prices_len);
    int i,j;
    
    for (i=0;i<prices_len;i++)
    {
        answer[i]=0;
        for (j=i+1;j<prices_len;j++)
        {
            if(prices[i]<=prices[j]) //가격 유지
            {
                answer[i]+=1;
            }
            else //가격 떨어짐
            {
                answer[i]+=1;
                break;
            }
        }
    }
    
    return answer;
}