#include <cstdlib>
#include <iostream>

using namespace std;

/*int main(int argc, char** argv) {
    int m1[3][4]{
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3}
    };
    
    int m2[3][4]{
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3}
    };
    
    int m3[3][4];
   
    int *p = &m1[0][0], *q = &m2[0][0], *r = &m3[0][0];
    
    cout << "Soma das matrizes " << endl;
    
    for( ; q < &m2[0][0] + 12; p++, q++, r++){
 *r = *p + *q;
         cout << *r << " ";
    }
    
    
    return 0;
}*/

int main(int argc, char** argv) {
    int m1[3][4]{
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3}
    };

    int m2[4][5]{
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4}
    };

    int m3[3][5];

    int *p1, *q1, *r, *p2, *q2;
    
    r = &m3[0][0];
    
    cout << "Multiplicação de matrizes" << endl;

    for (p1 = &m1[0][0]; p1 < &m1[0][0] + 12; p1 += 4) {
        for (q1 = &m2[0][0]; q1 <&m2[0][0] + 5; q1++) {
            *r = 0;
            for (p2 = p1, q2 = q1; p2 < p1 + 4; p2++, q2 += 5){
                *r += *p2 * (*q2);
            }
            cout << *r << " ";
            r++;
            }
    }
    
    
   


    return 0;
}