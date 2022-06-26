# 找三角形外心
```c=
#include <cmath>
#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
    Point() {}
    Point(double X, double Y) {
        x = X;
        y = Y;
    }
};

double distance_p2p(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Point p[100];
int n;

class Circle {
    public:
        double r;
        Point c;
        Circle(Point p1, Point p2) : r(distance_p2p(p1, p2) / 2), c((p1.x + p2.x) / 2, (p1.y + p2.y) / 2){}
        Circle(Point p1, Point p2, Point p3) {
            double A1 = p1.x - p2.x, B1 = p1.y - p2.y, C1 = (p1.x * p1.x - p2.x * p2.x + p1.y * p1.y - p2.y * p2.y) / 2;
            double A2 = p3.x - p2.x, B2 = p3.y - p2.y, C2 = (p3.x * p3.x - p2.x * p2.x + p3.y * p3.y - p2.y * p2.y) / 2;
        c.x = (C1 * B2 - C2 * B1) / (A1 * B2 - A2 * B1);
        c.y = (A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);
        r = distance_p2p(c, p1);
    }
    ˜Circle() {}
};
double find_smallest_r() {
    Circle c(p[0], p[1]);
    for (int i = 2; i < n; i++) {
        if (distance_p2p(c.c, p[i]) > c.r) {
            c = Circle(p[0], p[i]);
            for (int j = 1; j < i; j++) {
                if (distance_p2p(c.c, p[j]) > c.r) {
                c = Circle(p[j], p[i]);
                    for (int k = 0; k < j; k++) {
                        if (distance_p2p(c.c, p[k]) > c.r) {
                            c = Circle(p[j], p[i], p[k]);
                        }
                    }
                }
            }
        }
    }
    return c.r;
}
```