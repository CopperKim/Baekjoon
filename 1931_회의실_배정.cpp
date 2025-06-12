// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <algorithm>

using namespace std;

class meeting {
public :
    int start, end;

    meeting(int start, int end) {
        this->start = start;
        this->end = end;
    }

    bool operator<(meeting other) {
        return (this->end < other.end || (this->end == other.end && this->start < other.start));
    }
};

int n;
meeting *schedule;

int main() {
    cin >> n;
    schedule = (meeting*)malloc(sizeof(meeting) * (n+1));
    for(int i=0;i<n;i++) {
        int a, b; cin >> a >> b;
        schedule[i] = meeting(a, b);
    }

    sort(&schedule[0], &schedule[n]);
    // cout << '\n';
    // for(int i=0;i<n;i++) {cout << schedule[i].start << ' ' << schedule[i].end << '\n';}

    int curtime = schedule[0].end, count=1, idx=1;
    while(idx<n) {
        // cout << curtime << ' ';
        if (curtime <= schedule[idx].start) {
            curtime = schedule[idx].end;
            count++;
        }
        idx++;
    }

    cout << count;
}