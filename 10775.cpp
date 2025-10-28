#include <iostream>

using namespace std;

int *disjoint;

int find(int idx) {
    if (idx == disjoint[idx]) return idx;
    else return disjoint[idx] = find(disjoint[idx]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    if (a<b) swap(a, b);
    disjoint[a] = b;
}

int main() {
    int G, P; cin >> G >> P;
    disjoint = (int*)calloc(G+1, sizeof(int));
    for(int i=1;i<=G;i++) disjoint[i] = i;

    int cnt=0;

    while(P--) {
        int input; cin >> input; 

        if (find(input) == 0) {
            break;
        } else {
            merge(find(input), find(input)-1);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}