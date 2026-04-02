#include <iostream>

using namespace std;

int GCD(int a, int b){
    if (b==0){
        return a;
    }
    if (a>b){
        return GCD(b, a%b);
    }
    else{
        return GCD(a, b%a);
    }
}

int main(){
    int N, S;
    cin >> N >> S;

    int *A = new int[N];

    for (int i=0;i<N;i++){
        cin >> A[i];
        A[i] = abs(S-A[i]); // 절댓값
    }

    int result=A[0];
    for (int i=1; i<N; i++){
        result = GCD(result, A[i]);
    }
    cout << result << '\n';

    return 0;
}