#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    double *scores = (double*)calloc(n, sizeof(double));
    double maxscore=0;

    for(int i=0;i<n;i++) {
        cin >> scores[i];
        maxscore = max(maxscore, scores[i]);
    }
    double mean=0;
    for(int i=0;i<n;i++) {
        mean += scores[i]*100/maxscore;
    }
    mean /= n;
    cout << mean;
}