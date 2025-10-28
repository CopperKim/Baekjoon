#include <iostream>

using namespace std;

int n, lastIdx; 
int *heap;

bool cmp(int a, int b) { // a가 b보다 우선순위 높음
    return (abs(heap[a]) < abs(heap[b]) || (abs(heap[a])==abs(heap[b]) && heap[a]<heap[b])) ;
}

int getHighPriorityChild(int idx) {
    if (2*idx+1 >= lastIdx) return 0;
    if (2*idx+2 == lastIdx) return 2*idx+1;
    return cmp(2*idx+1, 2*idx+2)?2*idx+1:2*idx+2;
}

void heapInsert(int data) {
    int curIdx = lastIdx++;
    heap[curIdx]=data;
    while(curIdx > 0 && cmp(curIdx, (curIdx-1)/2)) {
        swap(heap[curIdx], heap[(curIdx-1)/2]);
        curIdx = (curIdx-1)/2;
    }
}

void heapDelete() {
    if (lastIdx == 0) {cout << 0 << '\n'; return;}
    
    cout << heap[0] << '\n';
    heap[0]=heap[--lastIdx];

    int parentIdx = 0, childIdx;
    
    while(childIdx = getHighPriorityChild(parentIdx)) {
        if (cmp(parentIdx, childIdx)) break;
        swap(heap[parentIdx], heap[childIdx]);
        parentIdx = childIdx;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    heap = (int*)calloc(n, sizeof(int));

    for(int i=0;i<n;i++) {
        int input; cin >> input; 
        if (input == 0) heapDelete();
        else heapInsert(input);
    }
}