#include <iostream>

using namespace std;

int main() {
    double m, traction, resistance;
    cout << "mass, traction and resistance: ";
    cin >> m >> traction >> resistance;

    double ay = (traction - resistance) / m;

    if (ay > 0.5) {
        cout << "Mode: take off" << endl;
    }
    else if (ay >= 0) {
        cout << "Mode: horizontal flight" << endl;
    }
    else {
        cout << "Mode: descent" << endl;
    }

    return 0;
}