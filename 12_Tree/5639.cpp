#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;
int idx=0;

void postorder(int min, int max) {
    if (idx >= preorder.size()) {
        return;
    }
    
    int root = preorder[idx];
    if (root < min || root > max) {
        return;
    }
    
    idx++;
    
    postorder(min, root-1);
    postorder(root + 1, max);
    
    cout << root << '\n';
}

int main()
{
    int n;
    while(cin >> n) {
        preorder.push_back(n);
    }
    postorder(1, 1000000);

    return 0;
}