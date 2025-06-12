#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k; cin >> n >> k;
    long long *bags = (long long*)calloc(k+1, sizeof(long long));
    pair<long long, long long> *gems = (pair<long long, long long>*)calloc(n+1, sizeof(pair<long long, long long>)); // 무게, 가격
    for(long long i=0;i<n;i++) {
        long long input1, input2; cin >> input1 >> input2;
        gems[i] = {input1, input2};
    }
    for(long long i=0;i<k;i++) {
        cin >> bags[i];
    }
    sort(gems, gems+n);
    sort(bags, bags+k);

    int idx=0;
    long long sum=0;
    priority_queue<long long> pq; 
    for(int i=0;i<k;i++) {
        while(idx < n && gems[idx].first <= bags[i]) pq.push(gems[idx++].second);
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}