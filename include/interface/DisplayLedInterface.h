#pragma once

class DisplayLedInterface
{
public:
    virtual bool init() = 0;
    virtual bool displayUpdate();
    DisplayLedInterface(/* args */);
    ~DisplayLedInterface();
};
