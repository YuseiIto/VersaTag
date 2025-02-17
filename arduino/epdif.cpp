#include "epdif.h"
#include <SPI.h>

EpdIf::EpdIf() {
};

EpdIf::~EpdIf() {
};

void EpdIf::DigitalWrite(int pin, int value) {
    digitalWrite(pin, value);
}

int EpdIf::DigitalRead(int pin) {
    return digitalRead(pin);
}

void EpdIf::DelayMs(unsigned int delaytime) {
    delay(delaytime);
}

void EpdIf::SpiTransfer(unsigned char data) {
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
    digitalWrite(EPD_CS_PIN, LOW);
    SPI.transfer(data);
    digitalWrite(EPD_CS_PIN, HIGH);
    SPI.endTransaction();
}

int EpdIf::IfInit(void) {
    pinMode(EPD_CS_PIN, OUTPUT);
    pinMode(EPD_RST_PIN, OUTPUT);
    pinMode(EPD_DC_PIN, OUTPUT);
    pinMode(EPD_BUSY_PIN, INPUT); 

    pinMode(EPD_PWR_PIN, OUTPUT);
    DigitalWrite(EPD_PWR_PIN, 1);
    return 0;
}
