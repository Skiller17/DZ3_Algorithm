#include "IGraph.h"

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int count);

    explicit ArcGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;

    int VerticesCounter() const override;

    std::vector<int> GetNextVertex(int vertex) const override;

    std::vector<int> GetPreviousVertex(int vertex) const override;

private:
    vector<int> vertices;
    vector<std::pair<int, int>> edges;
};
