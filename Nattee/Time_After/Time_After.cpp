#include <iostream>
using namespace std;

int main() {
    int h,m,x;
    cin >> h >> m >> x;
    int add_h = 0, add_m = 0;
    add_m += x%60;
    m += add_m;
    if(m >= 60){
        add_h += m/60;
        m %= 60;
    }
    add_h += x/60;
    h += add_h;
    h %= 24;
    if(h/10 == 0){
        cout << '0';
    }
    cout << h << " ";
    if(m/10 == 0){
        cout << '0';
    }
    cout << m;
    return 0;
}