/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) {
            return nullptr;
        }
        queue<UndirectedGraphNode*> current;
        unordered_map<UndirectedGraphNode* ,UndirectedGraphNode*> visited;
        current.push(node);
        visited[node] = new UndirectedGraphNode(node->label);

        while(!current.empty()) {
            UndirectedGraphNode* n = current.front();
            current.pop();
            for(auto nbr : n->neighbors) {
                if(visited.count(nbr)) {
                    visited[n]->neighbors.push_back(visited[nbr]);
                }
                else {
                    UndirectedGraphNode *new_node = new UndirectedGraphNode(nbr->label);
                    visited[nbr] = new_node;
                    visited[n] -> neighbors.push_back(new_node);
                    current.push(nbr);
                }
            }
        }
        return visited[node];
        
    }
};
