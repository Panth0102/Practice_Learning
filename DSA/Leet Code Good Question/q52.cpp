// Q52 N Queens 2

#include<iostream>
#include<vector>


using namespace std;

class Solution {
    public:
        bool isSafe(vector<string>&board,int r, int c){
            int n = board.size();
            for(int i=0; i<n; i++){
                if(board[r][i]=='Q') return false;
            }
            for(int i =0; i<n; i++){
                if(board[i][c]=='Q') return false;
            }
            for(int i=r, j=c; i>=0 && j>=0; i--, j--){
                if(board[i][j] == 'Q') return false;
            }
            for(int i=r, j=c; i>=0 && j<n; i--, j++){
                if(board[i][j] == 'Q') return false;
            }
            return true;
        }
        int nQueens(vector<string>&board,int row){
            int n = board.size();
            int cnt =0;
            if(row == n){
                return 1;
            }
            for(int i =0; i< n; i++){
                if(isSafe(board,row,i)){
                    board[row][i] = 'Q';
                    cnt += nQueens(board,row+1);
                    board[row][i] = '.';
                }
            }
            return cnt;
        }
        int totalNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            return nQueens(board,0);
        }
    };