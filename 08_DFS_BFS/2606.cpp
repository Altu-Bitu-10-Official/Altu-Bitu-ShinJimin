#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int c, n;
    int a, b;
    int cnt = -1;

    bool visit[10000] = {false};
    vector<int> v[101];

    cin >> c >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;

    q.push(1);
    visit[1] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        cnt++;

        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i];

            if (visit[y] == false)
            {
                q.push(y);
                visit[y] = true;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}