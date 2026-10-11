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

// Function to check if a rectangle with bottom-left corner p1 and top-right corner p2 is empty
bool isEmptyRectangle(const Point& p1, const Point& p2, const vector<Point>& points) {
    // Check if there's any point strictly inside the rectangle
    for (const Point& p : points) {
        if (p.x > p1.x && p.x < p2.x && p.y > p1.y && p.y < p2.y) {
            return false;
        }
    }
    return true;
}

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
                if (isEmptyRectangle(points[i], points[j], points)) {
                    count++;
                }
            }
            
            // Check if points[j] can be bottom-left and points[i] can be top-right
            if (points[j].x < points[i].x && points[j].y < points[i].y) {
                if (isEmptyRectangle(points[j], points[i], points)) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}