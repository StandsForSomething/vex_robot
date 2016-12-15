#include "main.h"

void controlDrive(int speed, direction dir)
{
    switch(dir)
    {
    case FORWARD:
        setMotor(LFDriveI, speed);
        setMotor(LFDriveO, speed);
        setMotor(LBDriveI, speed);
        setMotor(LBDriveO, speed);
        setMotor(RFDriveI, speed);
        setMotor(RFDriveO, speed);
        setMotor(RBDriveI, speed);
        setMotor(RBDriveO, speed);
        break;

    case BACKWARD:
        setMotor(LFDriveI, -speed);
        setMotor(LFDriveO, -speed);
        setMotor(LBDriveI, -speed);
        setMotor(LBDriveO, -speed);
        setMotor(RFDriveI, -speed);
        setMotor(RFDriveO, -speed);
        setMotor(RBDriveI, -speed);
        setMotor(RBDriveO, -speed);
        break;

    case LEFT_TURN:
        setMotor(LFDriveI, -speed);
        setMotor(LFDriveO, -speed);
        setMotor(LBDriveI, -speed);
        setMotor(LBDriveO, -speed);
        setMotor(RFDriveI, speed);
        setMotor(RFDriveO, speed);
        setMotor(RBDriveI, speed);
        setMotor(RBDriveO, speed);
        break;

    case RIGHT_TURN:
        setMotor(LFDriveI, speed);
        setMotor(LFDriveO, speed);
        setMotor(LBDriveI, speed);
        setMotor(LBDriveO, speed);
        setMotor(RFDriveI, -speed);
        setMotor(RFDriveO, -speed);
        setMotor(RBDriveI, -speed);
        setMotor(RBDriveO, -speed);
        break;

    case LEFT_TURN_WIDE:
        setMotor(LFDriveI, 0);
        setMotor(LFDriveO, 0);
        setMotor(LBDriveI, 0);
        setMotor(LBDriveO, 0);
        setMotor(RFDriveI, speed);
        setMotor(RFDriveO, speed);
        setMotor(RBDriveI, speed);
        setMotor(RBDriveO, speed);
        break;

    case RIGHT_TURN_WIDE:
        setMotor(LFDriveI, speed);
        setMotor(LFDriveO, speed);
        setMotor(LBDriveI, speed);
        setMotor(LBDriveO, speed);
        setMotor(RFDriveI, 0);
        setMotor(RFDriveO, 0);
        setMotor(RBDriveI, 0);
        setMotor(RBDriveO, 0);
        break;

    case STOP:
        setMotor(LFDriveI, 0);
        setMotor(LFDriveO, 0);
        setMotor(LBDriveI, 0);
        setMotor(LBDriveO, 0);
        setMotor(RFDriveI, 0);
        setMotor(RFDriveO, 0);
        setMotor(RBDriveI, 0);
        setMotor(RBDriveO, 0);
        break;

    default:
        return;
        break;
    }
}
void controlDriveEnc(int speed, direction dir, double counts)
{
    encoderReset(encoderRight.shaftEncoder);
    encoderReset(encoderLeft.shaftEncoder);
    controlDrive(speed, dir);
    if(dir == LEFT_TURN_WIDE)
    {
        while(getSensor(encoderRight.parent) < counts)
        {
            printf("%f\n\r", getEncoder(encoderRight));
            delay(20);
        }
    }

    else if(dir == BACKWARD || dir == LEFT_TURN)
    {
        while(getSensor(encoderLeft.parent) > counts)
        {
            printf("%f\n\r", getEncoder(encoderLeft));
            delay(20);
        }
    }

    else
    {
        while(getSensor(encoderLeft.parent) < counts)
        {
            printf("%f\n\r", getEncoder(encoderLeft));
        delay(20);
        }
    }
    controlDrive(0, STOP);
}
