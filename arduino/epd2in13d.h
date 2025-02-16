#ifndef __EPD_2IN13D_H_
#define __EPD_2IN13D_H_

#include "epdif.h"

// Display resolution
#define EPD_WIDTH   104
#define EPD_HEIGHT  212

class Epd : EpdIf {
public:
    unsigned long width;
    unsigned long height;

    Epd();
    ~Epd();
    int Init(void);
    void SendCommand(unsigned char command);
    void SendData(unsigned char data);
    void ReadBusy(void);
    void SetFullReg(void);
    void SetPartReg(void);
    void TurnOnDisplay(void);
    
    void Reset(void);
    void Clear(void);
    void Display(const unsigned char* frame_buffer);
    void Displayimage(const unsigned char *Image);
    void DisplayPart(const unsigned char* frame_buffer);
    
    void Sleep(void);
private:
    unsigned int reset_pin;
    unsigned int dc_pin;
    unsigned int cs_pin;
    unsigned int busy_pin;
};

#endif
