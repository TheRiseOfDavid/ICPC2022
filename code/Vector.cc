# 向量模板
```c=
class Vector {
    private:
        double _x;
        double _y;
    
    public:
        Vector(double x, double y) : _x(x), _y(y) {}
        double cross(const Vector& other_vector) const {
            return _x * other_vector._y - _y * other_vector._x;
        }
        double dot(const Vector& other_vector) const {
            return _x * other_vector._x + _y * other_vector._y;
        }
        double getX() { return _x; }
        double getY() { return _y; }
    
        Vector operator*(double k) const {
            return *(new Vector(k * _x, k * _y));
        }
};
```