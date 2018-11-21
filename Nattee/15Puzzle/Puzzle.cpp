#include <iostream>

using namespace std;

int max(int puzzle[4][4]);

int main() {
    int puzzle[4][4];
    for(int i = 0; i < 4; i++){
        cin >> puzzle[i][0] >> puzzle[i][1] >> puzzle[i][2] >> puzzle[i][3];
    }
    max(puzzle);
}

int max(int puzzle[4][4]){
    
}