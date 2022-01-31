#pragma once


constexpr unsigned TICK = 5;
unsigned long lastMillis = 0;

void doTick(const unsigned& tick=TICK) {
    unsigned elapsed = millis() - lastMillis;
    if (elapsed < tick) {
        delay(tick - elapsed);
    }
    lastMillis = millis();
}
