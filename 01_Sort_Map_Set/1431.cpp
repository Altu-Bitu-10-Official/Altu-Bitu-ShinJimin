#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    
    if(a.size() != b.size())
    {
        return a.size() < b.size();
    }
    else
    {
        int a_sum = 0;
        for (char c : a)
        {
            if(isdigit(c))
            {
                a_sum += (c-'0');
            }
        }
        
        int b_sum = 0;
        for (char c : b)
        {
            if(isdigit(c))
            {
                b_sum += (c-'0');
            }
        }
        
        if (a_sum != b_sum) 
        {
            return a_sum < b_sum;
        }
        else
        {
            return a<b;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    
    vector<string> v;
    
    for(int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i=0; i<v.size(); ++i)
    {
        cout << v[i] << '\n';
    }

    return 0;
}