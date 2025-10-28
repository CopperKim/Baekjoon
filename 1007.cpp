// https://www.acmicpc.net/problem/1007

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Point {
public : 
    long long x, y;
    Point(long long k, long long l) {x = k; y = l;}
};

long long n;
double min_distance = 0;
vector<long long> selected;
Point total(0, 0);
Point* PointArr;

double distance(Point a) {
    return sqrt(a.x*a.x+a.y*a.y);
}

Point addPoint(Point a, Point b) {
    return Point(a.x+b.x, a.y+b.y);
}

void brute_force() {
    if (selected.size() == n/2+1) {
        Point start(0, 0);
        for(long long idx : selected) {
            start = addPoint(start, PointArr[idx]);
        }
        Point res = Point(total.x-2*start.x, total.y-2*start.y);
        min_distance = min(min_distance, distance(res));
        return;
    }
    for(long long i=selected.back()+1;i<=n/2+selected.size()-1;i++) {
        selected.push_back(i);
        brute_force();
        selected.pop_back();
    }
}

int main() {
    long long T; cin >> T;
    while(T-->0) {
        cin >> n;
        PointArr = (Point*)calloc(n+2, sizeof(Point));
        PointArr[0] = Point(0, 0);
        for(long long i=1;i<=n;i++) cin >> PointArr[i].x >> PointArr[i].y;
        selected = {0};
        min_distance = 100000000;
        total = Point(0, 0);
        for(long long i=1;i<=n;i++) total = addPoint(total, PointArr[i]); 

        brute_force();

        cout.precision(6);
        printf("%.15lf\n", min_distance);

        free(PointArr);
    }
}