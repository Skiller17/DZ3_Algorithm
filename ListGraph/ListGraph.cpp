#include "ListGraph.h"

ListGraph::ListGraph(int count) {
    adjList.resize(count);
}

ListGraph::ListGraph(const IGraph &graph) {
    adjList.resize(graph.VerticesCounter());
    for (int i = 0; i < graph.VerticesCounter(); i++) {
        adjList[i] = graph.GetNextVertex(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjList.size());
    assert(to >= 0 && to < adjList.size());
    adjList[from].push_back(to);
}

int ListGraph::VerticesCounter() const {
    return adjList.size();
}

std::vector<int> ListGraph::GetNextVertex(int vertex) const {
    assert(vertex >= 0 && vertex < adjList.size());
    return adjList[vertex];
}

std::vector<int> ListGraph::GetPreviousVertex(int vertex) const {
    assert(vertex >= 0 && vertex < adjList.size());
    vector<int> previousVertices;
    for (int j = 0; j < adjList.size(); j++) {
        for (int i = 0; i < adjList[j].size(); i++) {
            if (adjList[j][i] == vertex)
                previousVertices.push_back(j);
        }
    }
    return previousVertices;
}
