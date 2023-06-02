#include "SetGraph.h"

SetGraph::SetGraph(int count) {
    adjList.resize(count);
}

SetGraph::SetGraph(const IGraph &graph) {
    adjList.resize(graph.VerticesCounter());
    for (int i = 0; i < graph.VerticesCounter(); i++) {
        for(auto &j: graph.GetNextVertex(i))
            adjList[i].insert(j);
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjList.size());
    assert(to >= 0 && to < adjList.size());
    adjList[from].insert(to);
}

int SetGraph::VerticesCounter() const {
    return adjList.size();
}

std::vector<int> SetGraph::GetNextVertex(int vertex) const {
    assert(vertex >= 0 && vertex < adjList.size());
    vector<int> vect;
    for(auto &i: adjList[vertex]){
        vect.emplace_back(i);
    }
    return vect;
}

std::vector<int> SetGraph::GetPreviousVertex(int vertex) const {
    assert(vertex >= 0 && vertex < adjList.size());
    vector<int> previousVertices;
    for (int j = 0; j < adjList.size(); j++) {
        for (auto& i: adjList[j]) {
            if(i==vertex)
                previousVertices.push_back(j);
        }
    }
    return previousVertices;
}
