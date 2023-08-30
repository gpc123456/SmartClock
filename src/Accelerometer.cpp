#include "Accelerometer.h"
/*
请注意：加速度传感器低功耗模式时每25ms更新一次数据(可修改),如使用多次采样相关的算法,
为保证结果准确性,相邻两次采样间隔建议>25ms.
*/
short InitAccelerometer()
{
    return (Init_STK8BA58());
}

AccelerationData ReadAccelerometer()
{
    AccelerationData SensorData;
    SensorData.x_axis = STK8BA58_ReadAcceleration_X();
    SensorData.y_axis = STK8BA58_ReadAcceleration_Y();
    SensorData.z_axis = STK8BA58_ReadAcceleration_Z();
    return SensorData;
}

bool Shaking()
{
    float SVM;
    AccelerationData SensorData;
    SensorData = ReadAccelerometer();
    SVM = sqrt(pow(SensorData.x_axis, 2) + pow(SensorData.y_axis, 2) + pow(SensorData.z_axis, 2));
    if (SVM >= 17.5)
    {
        return IS_SHAKING;
    }
    else
    {
        return NO_SHAKING;
    }
}

short Direction()
{
    AccelerationData SensorData;
    SensorData = ReadAccelerometer();

    if (SensorData.y_axis >= 8 && (abs(SensorData.x_axis) <= 3 && abs(SensorData.z_axis) <= 3))
    {
        return FRONT_DOWN;
    }
    else if (SensorData.y_axis <= -8 && (abs(SensorData.x_axis) <= 3 && abs(SensorData.z_axis) <= 3))
    {
        return FRONT_UP;
    }
    else
    {
        return DIRECTION_NORMAL;
    }
}

AccelerometerStatus ReadAccelerometerStatus()
{
    AccelerometerStatus AcStatus;
    AcStatus.Shaking = Shaking();
    AcStatus.Direction = Direction();
    return AcStatus;
}

float ReadAccelerometer_X()
{
    return (STK8BA58_ReadAcceleration_X());
}

float ReadAccelerometer_Y()
{
    return (STK8BA58_ReadAcceleration_Y());
}

float ReadAccelerometer_Z()
{
    return (STK8BA58_ReadAcceleration_Z());
}
