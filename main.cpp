#include <iostream>

#include "ListGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"

void BFS(const IGraph &graph, int vertex, void (*visit)(int)) {
    vector<bool> visited(graph.VerticesCounter(), false);
    queue<int> bfs;
    bfs.push(vertex);
    visited[vertex] = true;
    while (!bfs.empty()) {
        int current = bfs.front();
        bfs.pop();
        visit(current);
        vector<int> adjList = graph.GetNextVertex(current);
        for (int i = 0; i < adjList.size(); ++i) {
            if (!visited[adjList[i]]) {
                bfs.push(adjList[i]);
                visited[adjList[i]] = true;
            }
        }

    }
}

int main() {
    IGraph *graph = new ListGraph(6);
    graph->AddEdge(1, 3);
    graph->AddEdge(2, 1);
    graph->AddEdge(2, 3);
    graph->AddEdge(2, 4);
    graph->AddEdge(3, 4);
    graph->AddEdge(4, 5);
    graph->AddEdge(5, 3);
    graph->AddEdge(5, 4);
    BFS(*graph, 2, [](int v) { std::cout << v << ' '; });
    delete graph;
    return 0;
}
