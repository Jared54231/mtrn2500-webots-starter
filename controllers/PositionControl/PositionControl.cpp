#include <cmath>

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

const double PI {3.1415926535897932384626};

int main(int argc, char **argv) {
    webots::Robot robot;
    webots::Motor* leftMotor{robot.getMotor("left wheel motor")};
    webots::Motor* rightMotor{robot.getMotor("right wheel motor")};

    leftMotor->setPosition(2 * PI);
    rightMotor->setPosition(2 * PI);

    const double timeStep {robot.getBasicTimeStep()};
    while (robot.step(timeStep) != -1) {};

    return 0;
}