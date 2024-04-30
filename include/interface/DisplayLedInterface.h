#pragma once

class DisplayLedInterface
{
public:
    virtual bool init() = 0;
    virtual bool displayUpdate() = 0;

    virtual bool setCenterColor(uint8_t rc, uint8_t gc, uint8_t bc) = 0;
    virtual bool setInnnerColor(uint8_t rc, uint8_t gc, uint8_t bc) = 0;
    virtual bool setOuterColor(uint8_t rc, uint8_t gc, uint8_t bc) = 0;
};
