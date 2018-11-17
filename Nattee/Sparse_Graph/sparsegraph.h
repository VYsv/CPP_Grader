#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        // Your code here
        graph;
    }

    SparseGraph(int n_in) {
        // Your code here
        graph;
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        graph = G.graph;
    }

    void AddEdge(int a, int b) {
        // Your code here
        graph[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if(graph.count(a) > 0){
            graph[a].erase(b);
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        if(graph.count(a) > 0){
            if(graph.at(a).count(b) > 0) return true;
        }
        return false;
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph tmp;
        for(auto x:graph){
            for(auto y:x.second){
                tmp.graph[y].insert(x.first);
            }
        }
        return tmp;
    }

protected:
    // Your code here
    map<int, set<int> > graph;
};
#endif // __SPARSE_GRAPH_H__

