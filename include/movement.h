#ifndef MOVEMENT_H_
#define MOVEMENT_H_
typedef enum direction
{
    FORWARD,
    BACKWARD,
    LEFT_TURN,
    RIGHT_TURN,
    LEFT_TURN_WIDE,
    RIGHT_TURN_WIDE,
    STOP
    }direction;

//function prototypes
void controlDrive(int speed, direction dir);
void controlDriveEnc(int speed, direction dir, double counts, bool antiDrift);
void controlLift(int speed);
void controlLiftPot(int speed, double potValue, bool waitForTaskEnd);
void controlClaw(int speed);
void controlClawTime(int speed, int timeMS);
#endif //MOVEMENT_H_
