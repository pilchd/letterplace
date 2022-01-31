#pragma once

#include <LiquidCrystal_I2C.h>


class PlaceLCD {

    public:
    PlaceLCD(const unsigned& addr=0x27, const unsigned& rows=4, const unsigned& cols=20);

    enum class Just {
        Left,
        Center,
        Right
    };
    void print(const String& str) {
        print(str, row, col);
    }
    void print(String str, unsigned row, unsigned col);
    void printLn(String str, const unsigned& ln, const Just& just=Just::Left);
    void setCursor() {
        setCursor(0, 0);
    }
    void setCursor(unsigned row, unsigned col);
    void setBacklight(const bool& set=true);


    private:
    unsigned unsCeil(const unsigned& uns, const unsigned& max);
    String strChop(const String& str) {
        return strChop(str, cols);
    }
    String strChop(const String& str, const unsigned& len);
    
    LiquidCrystal_I2C lcd;

    bool backlight;
    unsigned row;
    unsigned col;
    const unsigned rows;
    const unsigned cols;
};
