#include <iostream>

using namespace std;
const int MAX_N = 7;

int n, m;
int sequence[MAX_N];
int a[MAX_N];

void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backtrack(int cnt){
    if (cnt == m){
        printSequence();
        return;
    }

    for (int i=0; i<n; i++){
        if (i > 0 && a[i] == a[i-1]) continue;
        sequence[cnt] = a[i];
        backtrack(cnt+1);
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    backtrack(0);

    return 0;
}