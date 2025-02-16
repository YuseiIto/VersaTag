#ifndef EPDIF_H
#define EPDIF_H

#include <Arduino.h>

// Load port assignments from pin_config.h
#include "pin_config.h"


// Ensure that the necessary pins are defined
#ifndef EPD_RST_PIN
#error "EPD_RST_PIN is not defined"
#endif

#ifndef EPD_DC_PIN
#error "EPD_DC_PIN is not defined"
#endif

#ifndef EPD_CS_PIN
#error "EPD_CS_PIN is not defined"
#endif

#ifndef EPD_BUSY_PIN
#error "EPD_BUSY_PIN is not defined"
#endif

#ifndef EPD_PWR_PIN
#error "EPD_PWR_PIN is not defined"
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
