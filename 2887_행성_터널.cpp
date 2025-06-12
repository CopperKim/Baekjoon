#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321;

using namespace std;

class Point {
public :
    int idx, x, y, z;
    Point (int __idx, int __x, int __y, int __z) {
        idx = __idx;
        x = __x;
        y = __y;
        z = __z;
    }
};

vector<Point> Vx, Vy, Vz;

class Edge {
public :
    int first, second;
    int distance;

    Edge(int a, int b, int dis) {
        first = a;
        second = b;
        distance = dis;
    }

    bool operator<(Edge other) {
        return this->distance < other.distance;
    }
};

bool cmpx(Point p1, Point p2) {
    return p1.x < p2.x;
}

bool cmpy(Point p1, Point p2) {
    return p1.y < p2.y;
}

bool cmpz(Point p1, Point p2) {
    return p1.z < p2.z;
}

vector<Edge> Ex, Ey, Ez;

int *disjoint;

int find(int idx) {
    if (disjoint[idx] == idx) return idx;
    else return disjoint[idx] = find(disjoint[idx]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    disjoint[a] = b;
}

int main() {
    int n; cin >> n;
    disjoint = (int*)calloc(n+1, sizeof(int));
    for(int i=0;i<n;i++) disjoint[i] = i;

    for(int i=0;i<n;i++) {
        int a, b, c; cin >> a >> b >> c;
        Vx.push_back(Point(i, a, b, c));
        Vy.push_back(Point(i, a, b, c));
        Vz.push_back(Point(i, a, b, c));
    }

    sort(Vx.begin(), Vx.end(), cmpx);
    sort(Vy.begin(), Vy.end(), cmpy);
    sort(Vz.begin(), Vz.end(), cmpz);

    for(int i=0;i<n-1;i++) {
        Ex.push_back(Edge(Vx[i].idx, Vx[i+1].idx, abs(Vx[i].x-Vx[i+1].x)));
        Ey.push_back(Edge(Vy[i].idx, Vy[i+1].idx, abs(Vy[i].y-Vy[i+1].y)));
        Ez.push_back(Edge(Vz[i].idx, Vz[i+1].idx, abs(Vz[i].z-Vz[i+1].z)));
    }

    sort(Ex.begin(), Ex.end());
    sort(Ey.begin(), Ey.end());
    sort(Ez.begin(), Ez.end());

    int cost=0;
    int cnt = n-1;
    int x=0, y=0, z=0;

    for(int i=0;i<3*n;i++) {
        int m = MAX;
        if (x < n) m = min(m, Ex[x].distance);
        if (y < n) m = min(m, Ey[y].distance);
        if (z < n) m = min(m, Ez[z].distance);

        if (m == Ex[x].distance) {
            if (find(Ex[x].first) != find(Ex[x].second)) {
                merge(Ex[x].first, Ex[x].second);
                cost += Ex[x].distance;
                cnt--;
            }
            x++;
        } else if (m == Ey[y].distance) {
            if (find(Ey[y].first) != find(Ey[y].second)) {
                merge(Ey[y].first, Ey[y].second);
                cost += Ey[y].distance;
                cnt--;
            }
            y++;
        } else if (m == Ez[z].distance) {
            if (find(Ez[z].first) != find(Ez[z].second)) {
                merge(Ez[z].first, Ez[z].second);
                cost += Ez[z].distance;
                cnt--;
            }
            z++;
        }

        if (cnt == 0) {
            cout << cost;
            return 0;
        }
    } 

    cout << cost;
}