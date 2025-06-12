#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

long long target, a, b;
vector<long long> A, B;

int main() {
    cin >> target;

    cin >> a;
    for(long long i=0;i<a;i++) {
        long long input; cin >> input;
        A.push_back(input);
    }
    cin >> b;
    for(long long i=0;i<b;i++) {
        long long input; cin >> input;
        B.push_back(input);
    }

    vector<long long> Asum, Bsum;
    for(long long i=0;i<a;i++) {
        long long sum = A[i];
        Asum.push_back(sum);
        for(long long j=i+1;j<a;j++) {
            sum += A[j];
            Asum.push_back(sum);
        }
    }
    for(long long i=0;i<b;i++) {
        long long sum = B[i];
        Bsum.push_back(sum);
        for(long long j=i+1;j<b;j++) {
            sum += B[j];
            Bsum.push_back(sum);
        }
    }

    long long ans=0; 

    sort(Bsum.begin(), Bsum.end());
    // for(long long t : Asum) cout << t << ' ';
    // cout << '\n';
    // for(long long t : Bsum) cout << t << ' ';
    // cout << '\n';
    for(long long AS : Asum) {
        long long real_target = target - AS;
        int hi = upper_bound(Bsum.begin(), Bsum.end(), real_target)-Bsum.begin();
        int lo = lower_bound(Bsum.begin(), Bsum.end(), real_target)-Bsum.begin();
        ans += hi-lo;
    }

    cout << ans;
}