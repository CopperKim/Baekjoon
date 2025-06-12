// https://www.acmicpc.net/problem/9251

#include <iostream>

using namespace std;

int main() {
    char input1[1003], input2[1003];
    cin >> input1;
    cin >> input2;

    int** LCS=(int**)malloc(1003*sizeof(int*));
    for(int i=0;i<1003;i++) LCS[i]=(int*)calloc(1003, sizeof(int));
    
    for(int i=0;input1[i]!='\0';i++) {
        for(int j=0;input2[j]!='\0';j++) {
            if (input1[i] == input2[j]) LCS[i+1][j+1] = LCS[i][j] + 1;
            else LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
        }
    }
    
    // for(int i=0;input1[i]!='\0';i++) cout << LCS[i] << ' ';

    int maxValue = 0;
    for(int i=0;input1[i]!='\0';i++) {
        for(int j=0;input2[j]!='\0';j++) {
            maxValue = max(maxValue, LCS[i+1][j+1]);\
        }
    }
    cout << maxValue;
}