#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{   //set container를 사용하여 중복된 폰켓몬을 제거
    set<int> count;
    
    for(int i=0; i<nums.size(); i++)
    {   //폰켓몬의 종류 삽입
        count.insert(nums[i]);
    }//set의 size보다 선택할 수 있는 마리 수가 크거나 같을 때
    if(nums.size()/2>=count.size())
        return count.size();
    else
        return nums.size()/2;
}