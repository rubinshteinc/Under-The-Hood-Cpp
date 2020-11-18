#include "time.h"


void Time::now() {
    _currentTime = clock();
}
bool Time::operator<= (const Time &time)const {
    return (_currentTime <= time._currentTime);
}
bool Time::operator< (const Time &time)const{
    return (_currentTime < time._currentTime);
}
bool Time::operator>= (const Time &time)const {
    return (_currentTime >= time._currentTime);
}
bool Time::operator> (const Time &time)const {
    return (_currentTime > time._currentTime);

}
Time Time::operator+ (const Time &time) {
        Time temp;
        temp._currentTime = _currentTime + time._currentTime;
        return temp;
}

unsigned long Time::operator- (const Time &time) {

    return _currentTime - time._currentTime;

}

unsigned long Time::operator+ (unsigned long milliseconds) {

    return _currentTime + milliseconds;
}