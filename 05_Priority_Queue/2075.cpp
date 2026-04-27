#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int arr[2250010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            pq.push(input);
        }
        while (pq.size() > n)
        {
            pq.pop();
        }
    }
    cout << pq.top() << '\n';
    
    return 0;
}