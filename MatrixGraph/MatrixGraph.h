#include "IGraph.h"
#include "cassert"

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int count);

    explicit MatrixGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;

    int VerticesCounter() const override;

    vector<int> GetNextVertex(int vertex) const override;

    vector<int> GetPreviousVertex(int vertex) const override;

private:
    vector<vector<int>> matrix;
};
