//word ladder,BFS
class Solution {
public:
    vector<string> stateExtend(string word, unordered_set<string>& wordList, unordered_set<string>& visited) {
      vector<string> res;
      for(size_t i =0; i< word.size(); ++i) {
        for(char c = 'a'; c <= 'z'; ++c) {
          if(c == word[i])
            continue;
          char temp = word[i];
          word[i] = c;
          
          if(wordList.count(word) && !visited.count(word)) {
            res.push_back(word);
            
          }
          word[i] = temp;
        }
      }
      return res;
    }
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
      wordList.insert(endWord);
      queue<string> current, next;
      unordered_set<string> visited;
      visited.insert(beginWord);
      int level = 1;
      current.push(beginWord);
      while(!current.empty()) {
        while(!current.empty()) {
          string word = current.front();
          current.pop();   
          vector<string> states = stateExtend(word, wordList, visited);
          for(string& str:states) {
            if(str == endWord)
                return level+1;
            next.push(str);
            visited.insert(word);
          }         
        }
        ++level;
        swap(next, current);
      }
      return 0;        
    }

};
