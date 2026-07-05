#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000000;

void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    int cost = graph[i][k] + graph[k][j];

                    if (cost < graph[i][j]) {
                        graph[i][j] = cost;
                    }
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    // 자기 자신
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    // a < b
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a][b] = 1;
    }

    floydWarshall(n, graph);

    int answer = 0;

    // 키 순서 알 수 있는지 확인
    for (int i = 1; i <= n; i++) {
        int count = 0;

        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }

            // i < j 이거나 j < i 이면 비교 가능
            if (graph[i][j] != INF || graph[j][i] != INF) {
                count++;
            }
        }

        // 자신을 제외한 모든 학생과 비교 가능
        if (count == n - 1) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}