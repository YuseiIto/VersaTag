#ifndef EPDIF_H
#define EPDIF_H

#include <Arduino.h>

// Load port assignments from pin_config.h
#include "pin_config.h"


// Ensure that the necessary pins are defined
#ifndef RST_PIN
#error "RST_PIN is not defined"
#endif

#ifndef DC_PIN
#error "DC_PIN is not defined"
#endif

#ifndef CS_PIN
#error "CS_PIN is not defined"
#endif

#ifndef BUSY_PIN
#error "BUSY_PIN is not defined"
#endif

#ifndef PWR_PIN
#error "PWR_PIN is not defined"
#endif

class EpdIf {
public:
    EpdIf(void);
    ~EpdIf(void);

    static int  IfInit(void);
    static void DigitalWrite(int pin, int value); 
    static int  DigitalRead(int pin);
    static void DelayMs(unsigned int delaytime);
    static void SpiTransfer(unsigned char data);
};

#endif
