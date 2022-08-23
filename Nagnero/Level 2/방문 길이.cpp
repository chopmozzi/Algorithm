#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    int curlocx = 5;
    int curlocy = 5;
    int move[11][11][11][11];
    
    for(auto i : dirs) {
        if(i == 'U') {
            if(curlocy < 10) {
                if(move[curlocx][curlocy][curlocx][curlocy + 1] != 1){
                    move[curlocx][curlocy][curlocx][curlocy + 1] = 1;
                    move[curlocx][curlocy + 1][curlocx][curlocy] = 1;
                    answer++;
                }
                curlocy++;
            }
        } else if(i == 'D') {
            if(curlocy > 0) {
                if(move[curlocx][curlocy][curlocx][curlocy - 1] != 1){
                    move[curlocx][curlocy][curlocx][curlocy - 1] = 1;
                    move[curlocx][curlocy - 1][curlocx][curlocy] = 1;
                    answer++;
                }
                curlocy--;
            }
        } else if(i == 'R') {
            if(curlocx < 10) {
                if(move[curlocx][curlocy][curlocx + 1][curlocy] != 1){
                    move[curlocx][curlocy][curlocx + 1][curlocy] = 1;
                    move[curlocx + 1][curlocy][curlocx][curlocy] = 1;
                    answer++;
                }
                curlocx++;
            }
        } else if(i == 'L') {
            if(curlocx > 0) {
                if(move[curlocx][curlocy][curlocx - 1][curlocy] != 1){
                    move[curlocx][curlocy][curlocx - 1][curlocy] = 1;
                    move[curlocx - 1][curlocy][curlocx][curlocy] = 1;
                    answer++;
                }
                curlocx--;
            }
        }
    }
    
    return answer;
}