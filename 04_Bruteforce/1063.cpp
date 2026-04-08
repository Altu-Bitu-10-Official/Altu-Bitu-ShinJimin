#include <iostream>
#include <string>

using namespace std;

void Position(string&position, int&x, int&y){
    x = position[1] - '0';
    y = position[0] - 'A' + 1;
}

void Outposition(string&position, int x, int y){
    position[1] = '0' + x;
    position[0] = 'A' + y-1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string king, stone, move;
    int count, kingX, kingY, stoneX, stoneY;
    cin >> king >> stone >> count;

    Position(king, kingX, kingY);
    Position(stone, stoneX, stoneY);

    for(int i=0;i<count;i++){
        cin >> move;

        int dX = 0, dY = 0;

        if (move == "R")  dY++;
        else if (move == "L")  dY--;
        else if (move == "B")  dX--;
        else if (move == "T")  dX++;
        else if (move == "RT") { dX++; dY++; }
        else if (move == "LT") { dX++; dY--; }
        else if (move == "RB") { dX--; dY++; }
        else if (move == "LB") { dX--; dY--; }

        int prevKX = kingX, prevKY = kingY;
        int prevSX = stoneX, prevSY = stoneY;

        kingX += dX;
        kingY += dY;

        if(kingX < 1 || kingX > 8 || kingY < 1 || kingY > 8){
            kingX = prevKX;
            kingY = prevKY;
            continue;
        }
        if(kingX == stoneX && kingY == stoneY){
            stoneX += dX;
            stoneY += dY;
            if(stoneX < 1 || stoneX > 8 || stoneY < 1 || stoneY > 8){
                kingX = prevKX;
                kingY = prevKY;
                stoneX = prevSX;
                stoneY = prevSY;
            }
        }
    }
    Outposition(king, kingX, kingY);
    Outposition(stone, stoneX, stoneY);
    cout << king << " " << stone << '\n';
}
