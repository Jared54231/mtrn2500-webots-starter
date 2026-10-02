#include <cmath>

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

const double PI {3.1415926535897932384626};
const double MAX_MOTOR_SPEED{6.28};
const double WHEEL_RADIUS{0.02};
const double AXLE_LENGTH{0.052};

void rightTurn(webots::Motor* leftMotor, webots::Motor* rightMotor, double turnAngle, double wheelRadius, double axleLength);
void leftTurn(webots::Motor* leftMotor, webots::Motor* rightMotor, double turnAngle, double wheelRadius, double axleLength);

int main(int argc, char **argv) {
    webots::Robot robot;
    webots::Motor* leftMotor{robot.getMotor("left wheel motor")};
    webots::Motor* rightMotor{robot.getMotor("right wheel motor")};

    // leftMotor->setPosition(5);
    // rightMotor->setPosition(5);


    leftMotor->setVelocity(0.1 * MAX_MOTOR_SPEED);
    rightMotor->setVelocity(0.1 * MAX_MOTOR_SPEED);

    rightTurn(leftMotor, rightMotor, 90, WHEEL_RADIUS, AXLE_LENGTH);

    const double timeStep {robot.getBasicTimeStep()};
    while (robot.step(timeStep) != -1) {};

    return 0;
}


void rightTurn(webots::Motor* leftMotor, webots::Motor* rightMotor, double turnAngle, double wheelRadius, double axleLength) {
    double angle = turnAngle * PI/180;
    leftMotor->setPosition(-axleLength * angle / (2 * wheelRadius));
    rightMotor->setPosition(axleLength * angle / (2 * wheelRadius));
}

void leftTurn(webots::Motor* leftMotor, webots::Motor* rightMotor, double turnAngle, double wheelRadius, double axleLength) {
    double angle = turnAngle * PI/180;
    leftMotor->setPosition(axleLength * angle / (2 * wheelRadius));
    rightMotor->setPosition(-axleLength * angle / (2 * wheelRadius));
}