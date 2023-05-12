#include <bits/stdc++.h>
#include "cores.h"

using namespace std;

int main(int argc, char const *argv[]){
    float x,h, g, f, y;
    x = 1;
    h = g = f = y = 0;

    bmagenta;
    cout << "-------------------------------------------------------------" << endl;
    cout << "     x     |   h(x)   |   f(x)   |   g(x)   |   f(x)+g(x)   " << endl;
    cout << "-------------------------------------------------------------" << endl;
    reset;
    while(x <= 10){
        blue;
        h = pow(x,2)-16;
        if(h >= 0){
            f = h;
        } else f = 1;
        
        if(f == 0){
            g = pow(x,2)+16;
        }else g = 0;
        y = f + g;
        printf("    %3.0f    |   %3.0f    |   %3.0f    |   %3.0f    |     %3.0f    \n", x, h, f, g, y);
        cout << "-------------------------------------------------------------" << endl;
        x++;        
    }
    reset;
    return 0;
}
