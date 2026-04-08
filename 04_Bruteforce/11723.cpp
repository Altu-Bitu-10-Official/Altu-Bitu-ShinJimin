#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    string s;
    int x;
    int b=0;
    
    while(n>0){
        cin >> s;
        if(s == "add"){
            cin >> x;
            b |= (1 << x);
        }
        else if(s == "remove"){
            cin >> x;
            b &= ~(1 << x);
        }
        else if(s == "check"){
            cin >> x;
            if(b & (1 << x)){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if(s == "toggle"){
            cin >> x;
            b ^= (1 << x);
            }
        else if(s == "all"){
            b = (1 << 21) - 2;
        }
        else if(s == "empty"){
            b = 0;
        }
        n--;
    }
}