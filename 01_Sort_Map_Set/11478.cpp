#include <iostream>
#include <set>

using namespace std;
 
int main() {
    string s;
    set<string> str_set;
    string part_str;
    
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            part_str += s[j];
            str_set.insert(part_str);
        }
        part_str = "";
    }
    cout << str_set.size();
}