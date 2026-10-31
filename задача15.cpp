#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Point {
    double x, y, z;
};

int main() {
    double vx = 30.0;
    double vy = 20.0;
    double vz = 40.0;

    double dt = 0.5;
    double t_max = 3.0;

    vector<Point> traj;
    traj.reserve(static_cast<size_t>(t_max / dt) + 1);

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    cout << fixed << setprecision(2);
    cout << setw(10) << "t (s)" << setw(15) << "x (m)" << setw(15) << "y (m)" << setw(15) << "z (m)" <<endl;
    cout << string(55, '-') << endl;

    for (double t = 0.0; t <= t_max + 1e-9; t += dt) {

        traj.push_back({ x, y, z });

        cout << setw(10) << t << setw(15) << x << setw(15) << y << setw(15) << z << endl;

        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
    }

    cout << "Check at the end: x = " << x << " expected = " << vx * t_max << endl;

    return 0;
}