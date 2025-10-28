// https://www.acmicpc.net/problem/1017

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool visited[51];
vector<int> as, bs, primes;
vector<int> a_cnt[51], b_cnt;

bool isPrime(int k) {
    for(int i=0;primes[i]*primes[i]<=k;i++) {
        if(k%primes[i]==0) return false;
    }
    return true;
}

bool dfs(int a_from) {
    if (a_from == 1 || visited[a_from]) return false;
    visited[a_from] = true;
    for(int i=0;i<a_cnt[a_from].size();i++) {
        int to = a_cnt[a_from][i];
        if (b_cnt[to] == -1 || !visited[b_cnt[to]] && dfs(b_cnt[to])) {
            b_cnt[to] = a_from;
            return true;
        }
    }
    return false;
}

int main() {
    as.push_back(0);
    bs.push_back(0);
    cin >> n;
    bool is_first_even;

    for(int i=0;i<n;i++) {
        int input; cin >> input;
        if (i == 0) is_first_even = !(input%2);
        if(is_first_even) { // 첫 수가 짝수인 경우, as 가 짝수 벡터, bs가 홀수 벡터
            if (input % 2 == 0) as.push_back(input);
            else bs.push_back(input);
        } else { // 첫 수가 홀수인 경우 as가 홀수 벡터, bs가 짝수 벡터
            if (input % 2 == 0) bs.push_back(input);
            else as.push_back(input);
        }
    }

    primes.push_back(2);
    for(int i=3;i<=100;i++) if(isPrime(i)) primes.push_back(i);

    if (as.size() != bs.size()) {
        cout << -1;
        return 0;
    }

    int m = as.size();

    for(int i=1;i<m;i++) {
        for(int j=1;j<m;j++) {
            if (isPrime(as[i]+bs[j])) a_cnt[i].push_back(j);
        }
    }

    // for(int i=1;i<m;i++) {
    //     vector<int> vec = a_cnt[i];
    //     for(int value : vec) cout << value << ' ';
    //     cout << '\n';
    // }

    // as, bs : 1부터 
    // a_cnt : 1부터, a_cnt[i] : 0부터
    // b_cnt : 1부터

    vector<int> results;

    for(int i=0;i<a_cnt[1].size();i++) {
        b_cnt = vector<int>(m+1, -1);
        b_cnt[a_cnt[1][i]]=1;
        int paired=1;
        for(int j=1;j<m;j++) {
            memset(visited, false, m+1);
            if (dfs(j)) paired++;
        }
        if (paired == m-1) {
            results.push_back(bs[a_cnt[1][i]]); 
        }
    }

    sort(results.begin(), results.end());

    if (results.size() != 0) {for(auto output : results) cout << output << ' ';}
    else cout << -1;
}