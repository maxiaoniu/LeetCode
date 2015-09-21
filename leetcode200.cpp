//Number of Island
//use bfs
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// To execute C++, please define "int main()" 
int numIslands(vector<vector<char>>& grid) {
  if(grid.size()==0)
    return 0;
  int res = 0;
  int n = grid.size();
  int m = grid[0].size();
  
  //vector<bool> visited(m*n,false);
  queue<pair<int,int>> q;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(grid[i][j] == '1') {
        q.push(make_pair(i, j));
        grid[i][j] = '2';
        
        while(!q.empty()) {
          pair<int, int> pos = q.front();
          q.pop();
          int new_i = pos.first;
          int new_j = pos.second+1;
          
          if(new_j < m && grid[new_i][new_j] == '1'  ) {
            q.push(make_pair(new_i, new_j));
            grid[new_i][new_j] = '2';
          }
          new_i = pos.first+1;
          new_j = pos.second;
          
          if(new_i < n && grid[new_i][new_j] =='1') {
            q.push(make_pair(new_i, new_j));
            grid[new_i][new_j] = '2';
          }
          
          new_i = pos.first-1;
          new_j = pos.second;
          
          if(new_i >= 0  && grid[new_i][new_j] =='1') {
            q.push(make_pair(new_i, new_j));
            grid[new_i][new_j] = '2';
          } 
          
          new_i = pos.first;
          new_j = pos.second-1;
          
          if(new_j >= 0  && grid[new_i][new_j] =='1') {
            q.push(make_pair(new_i, new_j));
            grid[new_i][new_j] = '2';
          } 
          
        
        }
        ++res;
      }
      
      
    }
  }
  return res;
}
int main() {
  vector<vector<char>> grid={{'1','1','1'},{'0','1','0'},{'1','1','1'}};
  
  cout << numIslands(grid);
  return 0;
}
