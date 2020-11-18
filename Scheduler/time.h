#ifndef SCHEDULER_TIME_H
#define SCHEDULER_TIME_H
#include <unistd.h>
#include <ctime>

class Time{
public:
    Time():_currentTime(clock()){}
    void now();
    bool operator<= (const Time &time)const;
    bool operator< (const Time &time)const;
    bool operator>= (const Time &time)const;
    bool operator> (const Time &time)const;
    Time operator+ (const Time &time);

    unsigned long operator+ (unsigned long milliseconds);
    unsigned long operator- (const Time &time);

private:
    unsigned long _currentTime;
};


#endif //SCHEDULER_TIME_H
