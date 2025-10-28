// https://www.acmicpc.net/problem/2166

#include <iostream>

using namespace std;

class Point {
public :
    long double x, y; 
};

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    Point *points = (Point*)calloc(n+1, sizeof(Point));
    long double area=0;
    for(int i=0;i<n;i++) {
        cin >> points[i].x >> points[i].y;
    }
    points[n].x = points[0].x;
    points[n].y = points[0].y;
    
    for(int i=0;i<n;i++) {
        // cout << (double)(points[i].x*points[i+1].y - points[i].y*points[i+1].x)/2 << '\n'; 
        area += (points[i].x*points[i+1].y - points[i].y*points[i+1].x)/2;
    }
    if (area<0) area = -area;
    
    cout << fixed;
	cout.precision(1);
	cout << area << endl;
}