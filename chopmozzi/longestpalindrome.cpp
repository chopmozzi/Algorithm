#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;
    int oddmax =0; //홀수일 때 최대값
    int evenmax =0;//짝수일 때 최대값
    int count =0; //한 쪽의 길이(중심을 기준으로)
    bool odd = false; //홀수일 때 최대인지
    bool even = false;//짝수일 때 최대인지
    //홀수 카운트
    for(int i=1; i<s.length()-1; i++)
    {
        count=0;
        int j = 1;
        while((i-j)>=0&&(i+j)<(s.length()))
        {
            if(s[i-j]!=s[i+j])
                break;
            else
                count++;
            j++;
        }
        if(oddmax<count)
        {
            oddmax=count;
            odd=true;
        }
    }
    //짝수 카운트
    for(int i=0; i<s.length()-1; i++)
    {
        count=0;
        int j = 1;
        
        while((i-j+1)>=0&&(i+j)<(s.length()))
        {
           if(s[i-j+1]!=s[i+j])
               break;
            else
                count++;
            j++;
        }
        if(evenmax<count)
        {
            evenmax=count;
            even=true;
        }
    }
    //홀수와 짝수 어떤 방식을 사용하여 최대값을 구했는지
    if(odd||even)
    {
        if(oddmax>=evenmax)
            answer=(oddmax*2+1);
        else
            answer=(evenmax*2);
    }
    else //default는 1
        answer =1;
    return answer;
}