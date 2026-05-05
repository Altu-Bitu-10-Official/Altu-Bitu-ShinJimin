#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, k = 0;
    cin >> n >> k;

    string A;
    cin >> A;

    int cnt = 0;

    for(int i=0; i<n; i++){
        if(A[i] == 'P'){
            for(int j=max(0, i-k); j<=min(n-1, i+k); j++){
                if(A[j] == 'H'){
                    cnt++;
                    A[j] = '-';
                    break;
                }
            }
        }
    }
    cout << cnt;
}