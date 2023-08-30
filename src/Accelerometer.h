#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "STK8BA58.h"

#define INIT_ACCELEROMETER_OK 0
#define IS_SHAKING 1
#define NO_SHAKING 0
#define FRONT_UP 0
#define FRONT_DOWN 1
#define DIRECTION_NORMAL 2

struct AccelerationData
{
    float x_axis;
    float y_axis;
    float z_axis;
};

struct AccelerometerStatus
{
    bool Shaking;
    bool Direction;
};

//--------FUNCTION--------//
short InitAccelerometer();
bool Shaking();
short Direction();
AccelerometerStatus ReadAccelerometerStatus();
AccelerationData ReadAccelerometer();
float ReadAccelerometer_X();
float ReadAccelerometer_Y();
float ReadAccelerometer_Z();

#endif