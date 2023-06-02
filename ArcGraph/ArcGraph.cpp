#include "ArcGraph.h"

ArcGraph::ArcGraph(int count) {
    vertices.resize(count);
}

ArcGraph::ArcGraph(const IGraph &graph) {
    vertices.resize(graph.VerticesCounter());
    for (int i = 0; i < graph.VerticesCounter(); i++) {
        vector<int> vect = graph.GetNextVertex(i);
        for (int j = 0; j < vect.size(); j++) {
            edges.emplace_back(std::pair<int, int>(i, j));
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices.size());
    assert(to >= 0 && to < vertices.size());
    edges.emplace_back(std::pair<int, int>(from, to));
}

int ArcGraph::VerticesCounter() const {
    return vertices.size();
}

std::vector<int> ArcGraph::GetNextVertex(int vertex) const {
    assert(vertex >= 0 && vertex < vertices.size());
    vector<int> vect;
    for (auto &i: edges) {
        if (i.first == vertex)
            vect.push_back(i.second);
    }
    return vect;
}

std::vector<int> ArcGraph::GetPreviousVertex(int vertex) const {
    assert(vertex >= 0 && vertex < vertices.size());
    vector<int> vect;
    for (auto &i: edges) {
        if (i.second == vertex)
            vect.push_back(i.first);
    }
    return vect;
}
