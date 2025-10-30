// 1605

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int L; 
string S; 
vector<int> sa; 
vector<int> lcp; 

void sort() {
    int classes = 0, k = 1, base=26; 
    vector<int> rank(L, 0); // S[i] ~ S[i+k-1] 로 결정되는 rank 를 저장하는 배열, 길이 L, i - substring : rank 
    for(int i=0;i<L;i++) rank[i] = S[i] - 'a', sa[i] = i; // initial rank; 
    
    while(k < L && classes < L) {
        // rank[i], rank[i+k] 를 이용해 정렬 후 새 rank 생성 
        vector<int> rank2(L, 0), sa2(L, 0), A(L), B(L); 
        vector<int> cnt(base+1, 0); 

        for(int i=0;i<L;i++) {
            sa[i] = i; 
            A[i] = rank[i] + 1; 
            B[i] = (i + k < L ? rank[i+k] + 1 : 0 ); 
        }

        for(int i=0;i<L;i++) cnt[B[i]]++; 
        for(int i=1;i<=base;i++) cnt[i] += cnt[i-1]; 
        for(int i=L-1;i>=0;i--) sa2[--cnt[B[sa[i]]]] = sa[i]; 

        fill(cnt.begin(), cnt.end(), 0); 

        for(int i=0;i<L;i++) cnt[A[i]]++; 
        for(int i=1;i<=base;i++) cnt[i] += cnt[i-1]; 
        for(int i=L-1;i>=0;i--) sa[--cnt[A[sa2[i]]]] = sa2[i]; 

        classes = 1; 
        rank2[sa[0]] = 0;
        for(int i=0;i<L-1;i++) {
            int a = sa[i], b = sa[i+1]; 
            if (rank[a] != rank[b] || (a+k < L ? rank[a+k]+1 : 0) != (b+k < L ? rank[b+k]+1 : 0)) classes ++;  
            rank2[b] = classes - 1; 
        }

        base = classes; 
        rank = rank2; 

        k *= 2; 
    }
}

void fillLCP() { 
    vector<int> rsa(L); 

    for(int i=0;i<L;i++) rsa[sa[i]] = i; 

    int h=0; 

    for(int i=0;i<L;i++) {
        int r = rsa[i]; 
        if (r == L-1) {
            h = 0; 
            continue;
        }
        int j = sa[r+1]; 
        while(i + h < L && j + h < L && S[i + h] == S[j + h]) h++; 
        lcp[r] = h; 
        if (h) h--; 
    }
}

int main() {
    // cin >> L; 
    cin >> S; 
    L = S.length(); 
    sa = vector<int>(L); 
    lcp = vector<int>(L-1, 0); 

    sort(); 

    for(int a : sa) {
        cout << a+1 << ' '; 
        // cout << S+a << '\n'; 
    }

    cout << '\n'; 

    fillLCP(); 

    cout << 'x' << ' '; 
    for(int a : lcp) cout << a << ' '; 
}