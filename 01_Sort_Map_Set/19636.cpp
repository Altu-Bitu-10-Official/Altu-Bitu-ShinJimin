#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int w0, i0, i, a;
    /*
    다이어트 전 체중, 
    다이어트 전 기초대사량(에너지 섭취량), 
    다이어트 중 일일 에너지 섭취량, 
    다이어트 중 일일 활동 대사량
    */
    int d, t;
    /* 
    다이어트 기간, 
    임계값
    */
    
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    int w1 = w0, f1 = i0; // 기초대사량 변화를 고려하지 않은 체중
    int w2 = w0, f2 = i0; // 기초대사량 변화를 고려한 체중
    
    for (int j=0; j<d; j++)
    {
        w1 += i - (f1 + a);
        w2 += i - (f2 + a);

        if (abs(i-(f2 + a)) > t) {
            f2 += floor((i - (f2 + a))/2.0);
        }
    }

    if(w1 <= 0)
    {
        cout << "Danger Diet" << '\n';
    } else {
        cout << w1 << " " << f1 << '\n';
    }
    
    if(w2 <= 0 || f2 <= 0) 
    {
        cout << "Danger Diet" << '\n';
    } else {
        cout << w2 << " " << f2 << " ";
        if (i0 > f2) {
            cout << "YOYO";
        }
        else {
            cout << "NO";
        }
    }
    
    return 0;
    
}