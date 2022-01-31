#include <LiquidCrystal_I2C.h>

#include "PlaceLCD.h"


PlaceLCD::PlaceLCD(const unsigned& addr, const unsigned& rows, const unsigned& cols) :
        lcd(addr, cols, rows), rows(rows), cols(cols), row(0), col(0), backlight(true) {
    lcd.init();
    lcd.backlight();
    }

void PlaceLCD::print(String str, unsigned row, unsigned col) {

    row = unsCeil(row, rows);
    col = unsCeil(col, cols);
    str = strChop(str, cols - str.length());

    setCursor(row, col);
    lcd.print(str);
}
    
    
void PlaceLCD::printLn(String str, const unsigned& ln, const Just& just) {
    
    str = strChop(str);

    int startCol;
    switch (just) {
        case PlaceLCD::Just::Center:
            startCol = (cols - str.length()) / 2;
            break;
        case PlaceLCD::Just::Right:
            startCol = cols - str.length();
            break;
        default:
            startCol = 0;
    }

    lcd.setCursor(startCol, ln);
    lcd.print(str);
}
void PlaceLCD::setBacklight(const bool& set) {
    if (backlight != set) lcd.backlight();
    backlight = set;
}
void PlaceLCD::setCursor(unsigned row, unsigned col) {
    row = unsCeil(row, rows);
    col = unsCeil(col, cols);
    lcd.setCursor(col, row);
}


unsigned PlaceLCD::unsCeil(const unsigned& uns, const unsigned& max) {
    if (uns > max) return max;
    return uns;
}
String PlaceLCD::strChop(const String& str, const unsigned& len) {
    if (str.length() > cols) return str.substring(0, cols);
    return str;
}
