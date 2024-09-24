#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x;
    float y, radius, area;
    
    cin >> x;
    y = 0.01 * (float)x * (float)x * (float)x - 0.02 * (float)x * (float)x + 0.1 * (float)x - 0.2;
    radius = sqrt(x * x + y * y);
    area = 3.14 * radius * radius;

    // system("chcp 65001");
    cout << "113522041 蔡秉睿" << endl;
    cout << "(x, y) = (" << x << ", " << y << ")" << endl;
    cout << "Area = " << area << endl;

    return 0;
}