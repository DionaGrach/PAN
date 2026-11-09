#include <iostream>

using namespace std;
class FlightComputer {
private:
	double altitude;
	double velocity;
	double fuel;
	double thrust;
public:
    FlightComputer(double startAltitude, double startVelocity, double startFuel, double startThrust) {
        altitude = startAltitude;
        velocity = startVelocity;
        fuel = startFuel;
        thrust = startThrust;
    }

    void simulateStep(double dt) {
        if (fuel > 0) {
            velocity += (thrust / 1000.0 - 9.8) * dt;
            altitude += velocity * dt;
            fuel -= dt * 2.0;

            if (fuel < 0) {
                fuel = 0;
            }
        }
        else {
            velocity += -9.8 * dt;
            altitude += velocity * dt;
        }
    }

    void printStatus() {
        cout << "Altitude: " << altitude << " m" << " | Velocity: " << velocity << " m/s" << " | Fuel: " << fuel << " kg" << endl;
    }
};

int main() {
    FlightComputer rocket(0.0, 0.0, 100.0, 15000.0);

    double dt = 1.0;
    for (int i = 0; i < 5; ++i) {
        rocket.simulateStep(dt);
        rocket.printStatus();
    }

    return 0;
}
