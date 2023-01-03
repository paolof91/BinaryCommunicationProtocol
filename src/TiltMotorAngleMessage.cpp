#include "TiltMotorAngleMessage.h"

TiltMotorAngleMessage::TiltMotorAngleMessage(bool msgData)
{
    data = msgData;
}

void TiltMotorAngleMessage::serialize(uint8_t* data)
{
    memcpy(data, (void*)this, sizeof(TiltMotorAngleMessage));
}

void TiltMotorAngleMessage::deserialize(uint8_t* data)
{
    memcpy((void*)this, data, sizeof(TiltMotorAngleMessage));
}

