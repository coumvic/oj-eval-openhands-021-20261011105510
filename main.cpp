#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    
    // Sort points by x-coordinate, then by y-coordinate
    sort(points.begin(), points.end());
    
    int count = 0;
    
    // For each pair of points
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // For points[i] to be bottom-left and points[j] to be top-right,
            // we need points[i].x < points[j].x (which is true since i < j after sorting)
            // and points[i].y < points[j].y
            if (points[i].y < points[j].y) {
                // Check if there's any point strictly inside the rectangle
                bool isEmpty = true;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    // Check if point k is inside the rectangle
                    if (points[k].x > points[i].x && points[k].x < points[j].x && 
                        points[k].y > points[i].y && points[k].y < points[j].y) {
                        isEmpty = false;
                        break;
                    }
                }
                if (isEmpty) {
                    count++;
                }
            }
            
            // For points[j] to be bottom-left and points[i] to be top-right,
            // we need points[j].x < points[i].x (impossible since i < j after sorting)
            // and points[j].y < points[i].y
            // This case is not possible because we sorted by x, so points[i].x < points[j].x
            // So we only need to consider the first case
        }
    }
    
    cout << count << endl;
    
    return 0;
}