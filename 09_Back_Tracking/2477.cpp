#include <iostream>

using namespace std;
const int N = 6;

int k;
int d[N], l[N];
int bArea, sArea;
int bl[2], sl[2];

int findBigArea(){
    int cnt[5] = {0};
    
    for(int i=0; i<N; i++){
        cnt[d[i]]++;
    }

    int bc=0, sc=0;

    for(int i=0; i<N; i++){
        if(cnt[d[i]] == 1){
            bl[bc++] = l[i];
            sl[sc++] = l[(i+3)%N];
        }
    }
    bArea = bl[0] * bl[1];
    sArea = sl[0] * sl[1];

    return bArea - sArea;
}

int main(){
    cin >> k;
    for (int i=0; i<N; i++){
        cin >> d[i] >> l[i];
    }
    int count;
    count = k * findBigArea();
    cout << count << '\n';

    return 0;
}