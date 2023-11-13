#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

// Define the graph as an adjacency list
typedef vector<vector<int>> Graph;

void bfs(const Graph& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);

    // Queue for BFS
    queue<int> bfsQueue;

    // Start BFS from the given node
    bfsQueue.push(start);
    visited[start] = true;

    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();

        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                bfsQueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Example usage:
    int n = 6; // number of nodes
    Graph graph(n);

    // Adding edges to the graph (undirected)
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 4};
    graph[3] = {1, 5};
    graph[4] = {2};
    graph[5] = {3};

    int start_node = 0;
    
    cout << "BFS starting from node " << start_node << ":\n";
    bfs(graph, start_node);

    return 0;
}
