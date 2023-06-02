#include "IGraph.h"

#include <vector>
#include <cassert>

using std::vector;

class ListGraph : public IGraph {
public:
    explicit ListGraph(int count);

    explicit ListGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;

    int VerticesCounter() const override;

    std::vector<int> GetNextVertex(int vertex) const override;

    std::vector<int> GetPreviousVertex(int vertex) const override;

private:
    vector<vector<int>> adjList;
};
