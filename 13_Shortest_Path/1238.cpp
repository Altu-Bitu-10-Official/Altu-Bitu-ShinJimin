#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
const int INF = 1e9;

vector<int> dijkstra(int start, int v, vector<vector<edge>> &graph) {
    vector<int> dist(v + 1, INF);

    priority_queue<edge, vector<edge>, greater<edge>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) {
            continue;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;

            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }

    return dist;
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<edge>> graph(n + 1, vector<edge>(0));
    vector<vector<edge>> reverse_graph(n + 1, vector<edge>(0));

    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;

        graph[a].push_back({b, t});
        reverse_graph[b].push_back({a, t});
    }

    vector<int> go_home = dijkstra(x, n, graph);
    vector<int> go_party = dijkstra(x, n, reverse_graph);

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        answer = max(answer, go_party[i] + go_home[i]);
    }

    cout << answer << '\n';

    return 0;
}