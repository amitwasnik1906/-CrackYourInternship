#include<bits/stdc++.h>
using namespace std;

class Solution {
    int check(vector<vector<int>>& temp, int i, int j){
        int n = temp.size();
        int m = temp[0].size();
        int cnt = 0;
        for(int x = -1; x<2; x++){
            for(int y = -1; y<2; y++){
                if((x==0 && y==0) || i+x<0 || j+y<0 || i+x>=n || j+y>=m) continue;
                cnt += temp[i+x][j+y];
            }
        }
        return cnt;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>temp = board;

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int cnt = check(temp, i,j);
                if(temp[i][j] == 1 ){
                    if(cnt < 2 || cnt > 3){
                        board[i][j] = 0;
                    }
                    else if(cnt == 2 || cnt == 3){
                        board[i][j] = 1;
                    }
                }
                else{
                    if(cnt == 3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};

// T.C. : O(N)
// S.C. : O(1)