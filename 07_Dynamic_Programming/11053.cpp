#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> A(n,0);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    vector<int> dp(n,1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[i]>A[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }
    int max = 0;
    for(int i=0; i<n; i++){
        if(max < dp[i]){
            max = dp[i];
        }
    }
    cout << max << '\n';
    return 0;
}