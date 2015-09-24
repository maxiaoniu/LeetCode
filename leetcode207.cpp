//There are a total of n courses you have to take, labeled from 0 to n - 1.
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? 

class Solution {
public:
using Node = pair<int, vector<int>>;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

  vector<Node> graph(numCourses);
  for(auto p:prerequisites) {
    int src = p.first;
    int des = p.second;
    graph[src].second.push_back(p.second);
    graph[des].first++;  
  }
  
  //check 
  vector<int> que;
  for(int i = 0; i < numCourses; ++i) {
    if(graph[i].first == 0)
      que.push_back(i);
  }

  int num = 0;
  while(!que.empty() && num < numCourses) {
    int i = que.back();
    que.pop_back();
    
    vector<int> outNodes = graph[i].second;
    
    for(auto k : outNodes) {
      if(--graph[k].first == 0)
        que.push_back(k); 
    }
    ++num;
  }
  for(Node n:graph) {
      if(n.first > 0)
        return false;
  }
  return true;
}
};
