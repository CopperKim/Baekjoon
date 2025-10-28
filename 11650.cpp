#include <iostream>
#include <algorithm>

using namespace std;

class point {
public : 
    int x, y;
    bool operator<(point other) {
        if (this->x != other.x) return this->x < other.x;
        return this->y < other.y;
    }
};

int main() {
    int n; cin >> n;
    point *points = (point*)malloc((n+1) * sizeof(point));
    for(int i=0;i<n;i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(&points[0], &points[n]);
    for(int i=0;i<n;i++) cout << points[i].x << ' ' << points[i].y << '\n';
}