#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(const char* s) {
    bool answer = true;
    int num = 0;
    int i;
		for (i=0;s[i]!='\0';i++)
    {
        if (s[i]=='(')
        {
            num++;
        }
        else //s[i]==')'
        {
            num--;
            if (num<0)
                answer=false;
        }
    }
    
    if (num!=0)
        answer=false;
    
    return answer;
}