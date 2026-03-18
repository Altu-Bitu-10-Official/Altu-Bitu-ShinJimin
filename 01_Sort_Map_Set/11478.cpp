#include <iostream>
#include <string>
#include <set>

using namespace std;
 
int main() {
    string s;
    set<string> str_set;
    
    cin >> s;
    
    for (int i=0; i<s.size(); i++)
    {
        for (int j=0; j<s.size(); j++){
            str_set.insert(s.substr(i, j));
        }
    }

    cout << str_set.size();
}