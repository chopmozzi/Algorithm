#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size()); //id 개수만큼 0으로 초기화 -> 후에 카운팅을 위해
    map<int, string> id_idx; //id list를 index 순으로 값을 가지기 위하여
    map<string, int> report_count; //신고받은 횟수
    map<string, vector<string>>report_list; //누가 누구를 신고했는지
    set<string> report_check; //신고 기록을 체크하기 위함
    for(int i=0; i<id_list.size(); i++)
    {   //id list의 순서대로 id와 index의 값을 맞춰줌
        id_idx.insert({i,id_list[i]});
    }
    for(int i=0; i<report.size(); i++)
    {   //이전의 신고 경력을 비교하여 똑같은 신고 경력이 있는지
        if(report_check.find(report[i])==report_check.end())
        {   //신고 경력 insert
            report_check.insert(report[i]);
            char* send = NULL; //문자열 분리
            char* recv = NULL;
            send=strtok((char*)report[i].c_str()," ");
            recv=strtok(NULL, " ");
            string sen(send);
            string rec(recv);
            report_list[sen].push_back(rec); //sender가 receiver한테 신고한 기록
            report_count[rec]++; //신고횟수 카운트
        }
    }
    for (int i = 0; i < id_list.size(); i++)
    {   //id list 순회
        if (report_count[id_list[i]] >= k)
        {   //해당 id의 count가 k보다 크거나 같으면
            for (int j = 0; j < id_list.size(); j++)
            {   //밑의 반복문은 시간 초과의 케이스
                /*for (int l = 0; l < report_list[id_idx[j]].size(); l++)
                {
                    if (report_list[id_idx[j]][l] == id_list[i])
                    {
                        answer[j]++;
                        break;
                    }
                }*/
                //if(report_list[id_idx[j]].find(id_list[i])!=report_list[id_idx[j]].end())
                    //answer[j]++;
                //find를 통해 해당 신고 횟수를 넘은 id를 신고한 id를 찾고 해당 index의 값에 해당하는 answer의 위치를 카운팅 함
                if(find(report_list[id_idx[j]].begin(),report_list[id_idx[j]].end(),id_list[i])!=report_list[id_idx[j]].end())
                    answer[j]++;
            }
        }
    }
    return answer;
}