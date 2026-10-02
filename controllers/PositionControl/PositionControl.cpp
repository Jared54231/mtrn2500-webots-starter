#include <cmath>

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

const double PI {3.1415926535897932384626};
const double MAX_MOTOR_SPEED{6.28};

int main(int argc, char **argv) {
    webots::Robot robot;
    webots::Motor* leftMotor{robot.getMotor("left wheel motor")};
    webots::Motor* rightMotor{robot.getMotor("right wheel motor")};

    leftMotor->setPosition(5);
    rightMotor->setPosition(5);

    leftMotor->setVelocity(0.1 * MAX_MOTOR_SPEED);
    rightMotor->setVelocity(0.1 * MAX_MOTOR_SPEED);

    const double timeStep {robot.getBasicTimeStep()};
    while (robot.step(timeStep) != -1) {};

    return 0;
}