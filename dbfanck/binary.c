#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* s) {

    int* answer = (int*)malloc(sizeof(int) * 2);
    int num=0, zero=0, one=0, s_len=strlen(s);
    int i;

		if (s_len==1) //문자열 s가 "1"인 경우
    {
        answer[0]=num;
        answer[1]=zero;
        return answer;
    }    

    num++;
    for (i=0;i<s_len;i++)
    {
        if(s[i]=='0')
            zero++;
        else //s[i]=='1'인 경우
            one++;
    }
    
    while(one!=1) //문자열 s가 "1"이 될 때까지 반복
    {
        num++;
        s_len=one; //one은 0 제거 후의 길이
        one=0;

        while (s_len!=0) //문자열 s의 길이를 2진법으로 표현
        {
            if (s_len%2==0)
                zero++;
            else
                one++;

            s_len=s_len/2;
        }
    }
    
    answer[0]=num;
    answer[1]=zero;
    
    return answer;
}