#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int count) {
    matrix.resize(count);
    for(auto& i: matrix)
        i.resize(count);
}

MatrixGraph::MatrixGraph(const IGraph &graph) {
    matrix.resize(graph.VerticesCounter());
    for(auto& i: matrix)
        i.resize(graph.VerticesCounter());
    for (int i = 0; i < graph.VerticesCounter(); ++i) {
        vector<int> vect = graph.GetNextVertex(i);
        for(int j = 0; j < vect.size(); ++j){
            matrix[i][vect[j]] = 1;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < matrix.size());
    assert(to >= 0 && to < matrix.size());
    matrix[from][to] = 1;
}

int MatrixGraph::VerticesCounter() const {
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertex(int vertex) const {
    assert(vertex >= 0 && vertex < matrix.size());
    vector<int> vect;
    for(int i=0; i < VerticesCounter(); ++i){
        if(matrix[vertex][i] == 1)
            vect.push_back(i);
    }
    return vect;
}

std::vector<int> MatrixGraph::GetPreviousVertex(int vertex) const {
    assert(vertex >= 0 && vertex < matrix.size());
    vector<int> previousVertices;
    for (int j = 0; j < matrix.size(); j++) {
        if(matrix[vertex][j] == 1)
            previousVertices.push_back(j);
    }
    return previousVertices;
}
