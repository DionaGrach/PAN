#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DroneFlight {
private:
    vector<double> x;
    vector<double> y;
    double totalDistance;

public:
    DroneFlight() {
        totalDistance = 0.0;
    }

    void addPoint(double newX, double newY) {
        if (x.size() > 0) {
            double dx = newX - x[x.size() - 1];
            double dy = newY - y[y.size() - 1];
            totalDistance += sqrt(dx * dx + dy * dy);
        }

        x.push_back(newX);
        y.push_back(newY);
    }

    double getTotalDistance() {
        return totalDistance;
    }

    void printPath() {
        cout << "Points of itinerary:" << endl;
        for (size_t i = 0; i < x.size(); ++i) {
            cout << "(" << x[i] << ", " << y[i] << ")" << endl;
        }
    }
};

int main() {
    DroneFlight d;
    d.addPoint(0, 0);
    d.addPoint(3, 4);
    d.addPoint(6, 8);

    d.printPath();
    cout << "Covered: " << d.getTotalDistance() << " m" << endl;

    return 0;
}