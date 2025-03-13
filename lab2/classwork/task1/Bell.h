#ifndef BELL_H
#define BELL_H

class Bell {
private:
    bool isDing;  // Флаг для отслеживания состояния

public:
    Bell();
    void sound();
};

#endif // BELL_H