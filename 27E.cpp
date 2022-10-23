/* Program to find the intersection of a plane ax+by+cz+d=0 and sphere x^2+y^2+z^2+ex+fy+gz+h=0.*/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{

    float a, b, c, d, e, f, g, h, x, y, z, t, r, s, k, m, n, v;

    cout << "The value of a = " << endl;
    cin >> a;

    cout << "The value of b = " << endl;
    cin >> b;

    cout << "The value of c = " << endl;
    cin >> c;

    cout << "The value of d = " << endl;
    cin >> d;

    cout << "The value of e = " << endl;
    cin >> e;

    cout << "The value of f = " << endl;
    cin >> f;

    cout << "The value of g = " << endl;
    cin >> g;

    cout << "The value of h =" << endl;
    cin >> h;

    x = -(e / 2);
    y = -(f / 2);
    z = -(g / 2);

    t = ((x * x) + (y * y) + (z * z) - h);
    r = sqrt(t); // radius of sphere

    s = (a * x) + (b * y) + (c * z);
    k = sqrt((a * a) + (b * b) + (c * c));

    m = (s / k); // distance from plane

    n = sqrt((r * r) - (m * m)); // radius of circle

    v = (3.14) * (n * n);
    cout << "The area of circle of intersection = " << v << endl;
    cout << "The distance from plane = " << m << endl;
    cout << "The radius of sphere = " << r << endl;

    return 0;
}