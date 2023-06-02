#include "IGraph.h"

#include<unordered_map>
#include<unordered_set>
#include"cassert"

using std::unordered_map;
using std::unordered_set;

class SetGraph : public IGraph {
public:
    explicit SetGraph(int count);

    explicit SetGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;

    int VerticesCounter() const override;

    std::vector<int> GetNextVertex(int vertex) const override;

    std::vector<int> GetPreviousVertex(int vertex) const override;

private:
    vector<unordered_set<int>> adjList;
};
