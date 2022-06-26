# 直線模板
```c=
class Line {
    private:
        Point _p1, _p2;
    public:
        Line(Point p1, Point p2) : _p1(p1), _p2(p2){};
        Point Point1() const {
            return _p1;
        }
        Point Point2() const {
            return _p2;
        }
        bool isIntersect(const Line& other_line) const {
            int max_other_x = max(other_line.Point1().getX(), other_line.Point2().getX());
            int max_other_y = max(other_line.Point1().getY(), other_line.Point2().getY());
            int min_other_x = min(other_line.Point1().getX(), other_line.Point2().getX());
            int min_other_y = min(other_line.Point1().getY(), other_line.Point2().getY());
            int max_self_x = max(_p1.getX(), _p2.getX());
            int max_self_y = max(_p1.getY(), _p2.getY());
            int min_self_x = min(_p1.getX(), _p2.getX());
            int min_self_y = min(_p1.getY(), _p2.getY());
            
            if ((max_self_x >= min_other_x) && (max_other_x >= min_self_x) && (max_self_y >= min_other_y) && (max_other_y >= min_self_y)) {
                if ((_p1 - other_line.Point1()).cross(_p1 - _p2) * (_p1 - other_line.Point2()).cross(_p1 - _p2) <= 0) {
                    if ((other_line.Point1() - _p1).cross(other_line.Point1() - other_line.Point2()) * (other_line.Point1() - _p2).cross(other_line.Point1() - other_line.Point2()) <= 0) {
                        return true;
                    }
                }
            }
            return false;
        }
};
```