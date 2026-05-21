#include <iostream>
#include <queue>

using namespace std;

int n;
int startPerson, endPerson;
int graph[101][101] = { 0 };
bool visited[101] = { false };
int depth[101] = { 0 };

void bfs(int start)
{
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (graph[now][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
                depth[i] = depth[now] + 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> startPerson >> endPerson;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    bfs(startPerson);

    if (visited[endPerson] == false) cout << -1;
    else cout << depth[endPerson];

    return 0;
}