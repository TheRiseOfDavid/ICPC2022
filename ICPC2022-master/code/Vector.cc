#include <iostream>

using namespace std;

struct Point {float x, y;}; // 點的資料結構
typedef Point Vector;       // 向量的資料結構，和點一樣

// 向量的長度
float length(Vector v)
{
    return sqrt(v1.x * v1.x + v2.y * v2.y);
//  return sqrt(dot(v, v));
}
void base_height(Point p, Point p1, Point p2)
{
    Vector v1 = p1 - p;
    Vector v2 = p2 - p;

    float base = fabs(dot(v1, v2)) / length(v1);
    float height = fabs(cross(v1, v2)) / length(v1);
}
// 向量oa與向量ob進行內積，判斷∠aob之大小。
//內積大於 0 時，兩向量夾角小於 90˚ ；等於 0 時，夾角等於 90˚ ；小於零時，夾角大於 90˚ 且小於 180˚ 
float dot(Point o, Point a, Point b)
{
    return (a.x-o.x) * (b.x-o.x) + (a.y-o.y) * (b.y-o.y);
}
// 向量oa與向量ob進行外積，判斷oa到ob的旋轉方向。
//外積大於 0 時，兩向量前後順序為逆時針順序（在 180˚ 之內）；等於 0 時，兩向量平行，也就是指夾角等於 0˚ 或 180˚ ；小於 0 時，兩向量前後順序為順時針順序（在 180˚ 之內）。
float cross(Point o, Point a, Point b)
{
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}
void sin_cos_θ(Point p, Point p1, Point p2)
{
    Point p, p1, p2;

    Vector v1 = p1 - p;
    Vector v2 = p2 - p;

    float l1 = length(v1);
    float l2 = length(v2);

    float cosθ = dot(v1, v2)   / l1 / l2;
    float sinθ = cross(v1, v2) / l1 / l2;

    float θ = acos(cosθ);   // [0, π]
    float θ = asin(sinθ);   // [-π/2, π/2]
}
