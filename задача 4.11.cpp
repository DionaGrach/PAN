#include <iostream>
#include <iomanip>


using namespace std;
class Engine {
private:
	double thrust;
	double fuelFlow; 
	double fuel;
public:
    Engine(double t, double flow, double f) {
        thrust = t;
        fuelFlow = flow;
        fuel = f;
    }

    double getThrust() {
        return thrust;
    }

    bool hasFuel() {
        return fuel > 0;
    }

    void burn(double dt) {
        if (hasFuel()) {
            fuel -= fuelFlow * dt;
            if (fuel < 0) {
                fuel = 0;
            }
        }
    }

    double getFuel() {
        return fuel;
    }
};

class Navigation {
private:
    double altitude;
    double velocity;
    double acceleration;
    double mass;

public:
    Navigation(double alt, double vel, double m) {
        altitude = alt;
        velocity = vel;
        mass = m;
        acceleration = 0;
    }

    void update(double thrust, double dt) {
        acceleration = (thrust / mass) - 9.81;
        velocity += acceleration * dt;
        altitude += velocity * dt;
    }

    void printStatus(double time) {
        cout << fixed << setprecision(2);
        cout << "t=" << time << "s | h=" << altitude << "m | v=" << velocity << "m/s | a=" << acceleration << "m/s²" << endl;
    }

    double getAltitude() {
        return altitude;
    }
};

class AutonomousFlightSystem {
private:
    Engine engine;
    Navigation nav;
    double time;

public:
    AutonomousFlightSystem(Engine e, Navigation n) : engine(e), nav(n) {
        time = 0;
    }

    void simulate(double dt, double totalTime) {
        while (time < totalTime && engine.hasFuel()) {
            engine.burn(dt);
            nav.update(engine.getThrust(), dt);
            nav.printStatus(time);
            time += dt;
        }
    }

    void printSummary() {
        cout << "   The flight is over    " << endl;
        cout << "Left fuel: " << engine.getFuel() << " kg" << endl;
    }
};

int main() {
    Engine myEngine(20000, 5, 10);
    Navigation myNav(0, 0, 1000);
    AutonomousFlightSystem flight(myEngine, myNav);

    flight.simulate(1.0, 2.0);
    flight.printSummary();

    return 0;
}

