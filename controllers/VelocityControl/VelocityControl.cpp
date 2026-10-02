#include <cmath>

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

const double MAX_MOTOR_SPEED{6.28};

int main(int argc, char **argv) {
    webots::Robot robot;

    webots::Motor* leftMotor {robot.getMotor("left wheel motor")};
    webots::Motor* rightMotor {robot.getMotor("right wheel motor")};

    leftMotor->setPosition(INFINITY);
    rightMotor->setPosition(INFINITY);

    leftMotor->setVelocity(1 * MAX_MOTOR_SPEED);
    rightMotor->setVelocity(-1 * MAX_MOTOR_SPEED);

    const double timeStep {robot.getBasicTimeStep()};
    double time = 0;
    while (robot.step(timeStep) != -1 && time < 3000) {
        time += timeStep;
    }
    
    leftMotor->setVelocity(0 * MAX_MOTOR_SPEED);
    rightMotor->setVelocity(0 * MAX_MOTOR_SPEED);
}
