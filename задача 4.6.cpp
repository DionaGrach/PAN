#include <iostream>

using namespace std;

class RocketStage {
private:
    double thrust;
    double burnTime;
    double mass;

public:
    RocketStage(double t, double time, double m) {
        thrust = t;
        burnTime = time;
        mass = m;
    }

    double getDeltaV() {
        return (thrust * burnTime) / mass;
    }

    void printInfo() {
        cout << "Stage Info -> Thrust: " << thrust << " N, Burn Time: " << burnTime << " s, Mass: " << mass << " kg, DeltaV: " << getDeltaV() << " m/s" << endl;
    }
};

int main() {
    RocketStage s1(5000, 10, 1000);
    RocketStage s2(7000, 8, 900);
    RocketStage s3(9000, 6, 800);

    double totalV = s1.getDeltaV() + s2.getDeltaV() + s3.getDeltaV();

    cout << "total rocket speed: " << totalV << " m/s" << endl;

    return 0;
}