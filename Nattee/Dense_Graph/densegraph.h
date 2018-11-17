#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
class DenseGraph{   
protected:
    int n;
    int **graph;
public:
    DenseGraph() {
        // Your code here
        n = 3;
        graph = new int*[3];
        for(int i = 0; i < 3; i++){
            graph[i] = new int[3]();
        }
    }

    DenseGraph(int n_in) {
        // Your code here
        n = n_in;
        graph = new int*[n];

        for(int i = 0; i < n; i++){
            graph[i] = new int[n]();
        }
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        n = G.n;
        graph = new int*[n];
        for(int i = 0; i < n; i++){
            graph[i] = new int[n]();
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                graph[i][j] = G.graph[i][j];
            }
        }
    }

    void AddEdge(int a, int b) {
        // Your code here
        if(graph[a][b] == 0) graph[a][b] = 1;
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        if(graph[a][b] == 1) graph[a][b] = 0;
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        if(graph[a][b] == 1) return true;
        return false;
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph tmp(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][j] == 1) tmp.AddEdge(j,i);
            }
        }
        return tmp;
    }

    int print(int a, int b){
        return graph[a][b];
    }
};
#endif // __DENSE_GRAPH_H__