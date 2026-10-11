#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
    
    // For each pair of points, check if they can form a valid rectangle
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if points[i] can be bottom-left and points[j] can be top-right
            if (points[i].x < points[j].x && points[i].y < points[j].y) {
                // Check if there's any point strictly inside the rectangle
                bool isEmpty = true;
                for (int k = i + 1; k < j; k++) {
                    // Since points are sorted by x, we only need to check points between i and j
                    // And we only need to check y-coordinate
                    if (points[k].y > points[i].y && points[k].y < points[j].y) {
                        isEmpty = false;
                        break;
                    }
                }
                if (isEmpty) {
                    count++;
                }
            }
            
            // Check if points[j] can be bottom-left and points[i] can be top-right
            if (points[j].x < points[i].x && points[j].y < points[i].y) {
                // Check if there's any point strictly inside the rectangle
                bool isEmpty = true;
                for (int k = min(i, j) + 1; k < max(i, j); k++) {
                    // Since points are sorted by x, we only need to check points between i and j
                    // And we only need to check y-coordinate
                    if (points[k].y > points[j].y && points[k].y < points[i].y) {
                        isEmpty = false;
                        break;
                    }
                }
                if (isEmpty) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}