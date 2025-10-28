#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int arr[2001]; 
    for(int i=0;i<n;i++) cin >> arr[i];

    float pal[4002]={}; // 0->0 | 0.5->1 | 1->2 | 1.5->3 ...
    for(int i=0;i<2*n-1;i++) {
        float mid = (double)i/2, range = (i%2==0)?0:0.5;
        while(mid-range>=0 && mid+range<n && (arr[(int)(mid+range)] == arr[(int)(mid-range)])) range += 1;
        pal[i] = range-1;
    }
    // for(int i=0;i<n;i++) cout << pal[i] << ' ';

    int m; cin >> m;
    for(int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        if ((double)(b-a)/2 <= pal[a+b]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}