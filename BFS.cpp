#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Define the graph as an adjacency list
typedef pair<int, int> pii; // pair representing (node, weight)
typedef vector<vector<pii>> Graph;

vector<int> dijkstra(const Graph& graph, int start) {
    int n = graph.size();
    vector<int> distances(n, INF);
    distances[start] = 0;

    // Use a priority queue to keep track of the nodes with the smallest distance
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap

    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // If the current distance is greater than the known distance, skip
        if (current_distance > distances[current_node]) {
            continue;
        }

        // Iterate through neighbors
        for (const auto& neighbor : graph[current_node]) {
            int neighbor_node = neighbor.first;
            int weight = neighbor.second;
            int distance = current_distance + weight;

            // If a shorter path is found, update the distance and push to the priority queue
            if (distance < distances[neighbor_node]) {
                distances[neighbor_node] = distance;
                pq.push({distance, neighbor_node});
            }
        }
    }

    return distances;
}

int main() {
    // Example usage:
    int n = 4; // number of nodes
    Graph graph(n);

    // Adding edges to the graph
    graph[0].push_back({1, 1});
    graph[0].push_back({2, 4});
    graph[1].push_back({0, 1});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({0, 4});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 1});
    graph[3].push_back({1, 5});
    graph[3].push_back({2, 1});

    int start_node = 0;
    vector<int> result = dijkstra(graph, start_node);

    // Output the shortest distances
    cout << "Shortest distances from " << start_node << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "To node " << i << ": " << result[i] << "\n";
    }

    return 0;
}
