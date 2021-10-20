//
//  main.cpp
//  ellenek2_HW6_2
//
//  Created by Ellen Kirsh on 10/19/21.
//

#include <iostream>
#include <fstream>
using namespace std;

bool *IntervalScheduling(int *s, int *f, int n){
    int temp;
    bool q[3];
    bool r[3];
    for(int i = 0 ; i < (n-1) ; i++){
        for(int j = i+1; j < n; j++)
            if ( *(s + j) < *(s+i)){
            temp = *(s+i);
            *(s + i) = *(s+j);
            *(s + j) = temp;
            }
    }
    for(int i = 0 ; i < (n-1) ; i++){
        for(int j = i+1; j < n; j++)
            if ( *(f + j) < *(f+i)){
            temp = *(f+i);
            *(f + i) = *(f+j);
            *(f + j) = temp;
            }
    }
    int i = 0;
    q[i] = s[i];
    r[i] = f[i];
    for(int j = 1; j < n; j++){
        if (s[j] >= f[i]){
            q[j] = s[j];
            r[j] = f[j];
            i = j;
        }
    }
    for(int i = 0 ; i < (n-1) ; i++){
        cout << "(" << q[i] << ", " << r[i] << ")" << endl;
    }
    return 0;
}

int main() {
    ifstream file1;
    file1.open("input-scheduling.txt");
    int n;
    file1 >> n;
    int *s, *f;
    int **r;
    r = new int *[n];
    for(int i=0; i<n; i++){
        r[i] = new int[n];
    }
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            file1 >> r[i][j];
            s[i] = r[0][j];
            f[j] = r[1][j];
        }
    }
    file1.close();
    IntervalScheduling(s, f, n);
    return 0;
}
