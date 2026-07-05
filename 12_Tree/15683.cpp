#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int subtreeSize[100001];
bool visited[100001];

int dfs(int now) {
    visited[now] = true;

    subtreeSize[now] = 1;

    for (int next : tree[now]) {
        if (visited[next]) {
            continue;
        }
        subtreeSize[now] += dfs(next);
    }

    return subtreeSize[now];
}

int main() {
    int n, root, q;
    cin >> n >> root >> q;

    int u, v;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(root);

    for (int i = 0; i < q; i++) {
        cin >> u;
        cout << subtreeSize[u] << '\n';
    }

    return 0;
}