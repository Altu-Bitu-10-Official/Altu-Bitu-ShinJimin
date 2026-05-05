#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    vector<int> A(n, 0);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int answer = A[n-1];
    for(int i=n-2; i>=0; i--){
        if(answer < A[i]){
            answer = A[i];
        }
        else{
            if(answer % A[i] == 0){
                continue;
            }
            answer = ((answer / A[i])+1) * A[i];
        }
    }

    cout << answer;

    return 0;
}