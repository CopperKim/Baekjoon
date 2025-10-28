#include <iostream>

using namespace std;

int n; 
int *inOrder, *postOrder;

void preOrder(int inLeft, int inRight, int postLeft, int postRight) {
    // cout << inLeft << ' ' << inRight << ' ' << postLeft << ' ' << postRight << '\n';
    if (inLeft > inRight || postLeft > postRight) {
        return;
    }

    int root = postOrder[postRight];
    cout << root << ' ';
    
    int inOrderRootIndex = inLeft;
    while(inOrder[inOrderRootIndex] != root) {
        inOrderRootIndex++;
        if (inOrderRootIndex > inRight) {
            cout << "qt"; 
            return;
        }
        
    } 

    int postOrderRootIndex = postRight - inRight + inOrderRootIndex;

    preOrder(inLeft, inOrderRootIndex-1, postLeft, postOrderRootIndex -1);
    preOrder(inOrderRootIndex+1, inRight, postOrderRootIndex, postRight-1);
    return;
}

int main() {
    cin >> n;
    inOrder = new int[n+1]; // 중위 순회
    for(int i=1;i<=n;i++) cin >> inOrder[i];
    postOrder = new int[n+1]; // 후위 순회
    for(int i=1;i<=n;i++) cin >> postOrder[i];

    preOrder(1, n, 1, n);
}