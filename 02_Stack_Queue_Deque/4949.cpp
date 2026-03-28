#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string str;
    while(true){
        stack<char> s;
        getline(cin, str);

        if(str == ".") return 0;

        bool result=true;
        for (int i=0; i<str.length();i++){
            if(str[i] == '(' || str[i] == '['){
                s.push(str[i]);
            }
            else if(str[i] == ')'){
                if(s.empty() || s.top() != '('){
                    result=false;
                    break;
                }
                s.pop();
            }
            else if(str[i] == ']'){
                if(s.empty() || s.top() != '['){
                    result=false;
                    break;
                }
                s.pop();
            }
        }
        if (result && s.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}