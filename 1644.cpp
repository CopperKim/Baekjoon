#include <iostream>
#include <vector>

using namespace std;

vector<int> primes, sums;

bool isPrime(int num) { 
    for(int i=0;primes[i]*primes[i]<=num;i++) {
        if (num % primes[i] == 0) return false;
    }
    return true;
}

int main() {
    int N; cin >> N;

    sums.push_back(0);
    primes.push_back(2);
    sums.push_back(2);

    while(primes.back() <= N) {
        int i = primes.back()+1;
        while(!isPrime(i)) i++;
        primes.push_back(i);
        sums.push_back(sums.back()+i);
    }

    // for(int a : primes) cout << a << ' ';
    // cout << '\n';
    // for(int b : sums) cout << b << ' ';
    // cout << '\n';

    int left=0, right=1, cnt=0;
    while(right <= sums.size() && left < right) {
        if (sums[right]-sums[left] == N) {
            cnt++;
            right++;
        } else if (sums[right]-sums[left] > N) {
            left++;
        } else {
            right ++;
        }
    }
    cout << cnt;
}