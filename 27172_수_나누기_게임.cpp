#include <iostream>
#include <vector>

using namespace std;

int score[1000001];
bool cards[1000001];

int main() {
    int n; cin >> n;
    vector<int> V;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        cards[input] = true;
        V.push_back(input);
    }

    for(int i=0;i<n;i++) {
        for(int j=2*V[i];j<=1000000;j+=V[i]) {
            if (cards[j]) {
                score[V[i]] ++;
                score[j] --;
            }
        }
    }

    for(int i=0;i<n;i++) cout << score[V[i]] << ' ';
}