#include <iostream>
#include <string>
#define MAX_SIZE 10001

using namespace std;

int main(){
    int A[MAX_SIZE]={0}, B[MAX_SIZE]={0}, sum[MAX_SIZE]={0};
    string a, b, temp;
    int remain, carry;

    cin >> a >> b;
    if (b.length() >= a.length()){
        temp = a;
        a = b;
        b = temp;
    }

    for(int i=0; i<a.length();i++){
        A[i+1] = a[i] - '0';
    }

    for(int i=0; i<b.length();i++){
        B[i+a.length()-b.length() + 1] = b[i] - '0';
    }

    for(int i=a.length(); i>=1; i--){
        remain = (A[i] + B[i] + sum[i]) % 10;
        carry = (A[i] + B[i] + sum[i]) / 10;
        if (carry == 1){
            sum[i-1] += 1;
        }
        sum[i] = remain;
    }
    
    if(sum[0] != 0){
        for(int i=0;i<=a.length(); i++){
            cout << sum[i];
        }
    }
    else {
        for(int i=1;i<=a.length(); i++){
            cout << sum[i];
        }
    }
   

    return 0;
}