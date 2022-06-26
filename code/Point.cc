# 點的模板

```c=
class Point {
    private:
        int _x, _y;
    public:
        Point(int x, int y) : _x(x), _y(y){};
        int getX() const { return _x; }
        int getY() const { return _y; }
    
        bool operator==(const Point& other_point) const {
            return _x == other_point.getX() && _y < other_point.getY();
        }
        Point& operator+(const Point& other_point) const {
            return *(new Point(_x + other_point.getX(), _y + other_point.getY()));
        }
        Point& operator-(const Point& other_point) const {
            return *(new Point(_x - other_point.getX(), _y - other_point.getY()));
        }
        int cross(const Point& other_point) {
            return _x * other_point.getY() - _y * other_point.getX();
        }
};
```