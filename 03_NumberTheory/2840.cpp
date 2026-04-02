#include <iostream>
#include <vector>

using namespace std;

int N, K;

void init(vector<char> &wheel){
    for(int i=0; i<N; i++){
        wheel[i] = '?';
    }
}

int main(){
    cin >> N >> K;
    vector<char> wheel(N);
    init(wheel);

    int index;
    for (int i=0; i<K; i++){
        int count;
        char stopped;
        cin >> count >> stopped;
        if (i==0) {
            wheel[0] = stopped;
            index = 0;
            continue;
        }
        index = (count + index) % N;

        if (wheel[index] != '?' && wheel[index] != stopped){
            cout << "!";
            return 0;
        }

        else {
            wheel[index] = stopped;
        }
    }

    for (int i=0; i < N; i++){
        for (int j= i + 1; j< N; j++){
            if(wheel[i]!='?' && wheel[i] == wheel[j]){
                cout << "!";
                return 0;
            }
        }
    }
    for (int i=0; i<N; i++){
        cout << wheel[index--];
        if(index == -1) index = N-1;
    }
    return 0;
}