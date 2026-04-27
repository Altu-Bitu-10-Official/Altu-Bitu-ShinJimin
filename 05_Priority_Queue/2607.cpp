#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    string base = words[0];
    int answer = 0;

    for (int i = 1; i < n; i++)
    {
        vector<int> count(26, 0);

        for (char c : base)
            count[c - 'A']++;

        for (char c : words[i])
            count[c - 'A']--;

        int plus = 0;
        int minus = 0;

        for (int x : count)
        {
            if (x > 0) plus += x;
            else minus -= x;
        }

        if (plus <= 1 && minus <= 1)
        {
            answer++;
        }
    }

    cout << answer;
}