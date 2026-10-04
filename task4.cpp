#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    double h, ay, t;

    cout << "h = ";
    cin >> h;
    cout << "ay = ";
    cin >> ay;

    if (h > 0 && ay > 0) {
        t = sqrt(2 * h / ay);
        cout << "t = " << t << endl;
    }
    else {
        cout << "Please, enter positive numbers" << endl;
    }

    return 0;
}