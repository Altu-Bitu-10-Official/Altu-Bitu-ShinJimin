#include <iostream>
#define MAX 1000000

using namespace std;

bool is_prime[MAX + 1];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 2; i <= MAX; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i) {
            is_prime[j] = false;
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        bool found = false;

        for (int i = 3; i < n; i += 2) {
            if (is_prime[i] && is_prime[n - i]) {
                cout << n << " = " << i << " + " << n - i << '\n';
                found = true;
                break;
            }
        }
        if(!found){
            cout << "Goldbach's conjecture is wrong.";
        }
    }

    return 0;
}