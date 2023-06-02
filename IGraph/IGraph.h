#pragma once

#include <cassert>
#include<vector>
#include<queue>

using std::vector;
using std::queue;

struct IGraph {
    virtual ~IGraph() {}

    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCounter() const = 0;

    virtual std::vector<int> GetNextVertex(int vertex) const = 0;

    virtual std::vector<int> GetPreviousVertex(int vertex) const = 0;
};
