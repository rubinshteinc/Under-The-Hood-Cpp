
#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H

#include "time.h"

struct ITask {
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0;
    virtual unsigned long getNumOfCycles()const = 0;
};


class Task1: public ITask {
public:
    Task1(unsigned long cycles, unsigned long interval):_taskCurrentTime(), _EndLastExe(), _numOfCycles(cycles), _interval(interval){}
    unsigned long getNextRunPeriod();
    void run();
    unsigned long getNumOfCycles()const { return _numOfCycles;}


private:
    Time _taskCurrentTime;
    Time _EndLastExe;
    unsigned long _numOfCycles;
    unsigned long _interval; //milliseconds
};

class Task2: public ITask {
public:
    Task2(unsigned long cycles, unsigned long interval):_taskCurrentTime(), _EndLastExe(), _numOfCycles(cycles), _interval(interval){}
    unsigned long getNextRunPeriod();
    void run();
    unsigned long getNumOfCycles()const { return _numOfCycles;}


private:
    Time _taskCurrentTime;
    Time _EndLastExe;
    unsigned long _numOfCycles;
    unsigned long _interval; //milliseconds
};

class Task3: public ITask {
public:
    Task3(unsigned long cycles, unsigned long interval):_taskCurrentTime(), _EndLastExe(), _numOfCycles(cycles), _interval(interval){}
    unsigned long getNextRunPeriod();
    void run();
    unsigned long getNumOfCycles()const { return _numOfCycles;}


private:
    Time _taskCurrentTime;
    Time _EndLastExe;
    unsigned long _numOfCycles;
    unsigned long _interval; //milliseconds
};

class Task4: public ITask {
public:
    Task4(unsigned long cycles, unsigned long interval):_taskCurrentTime(), _EndLastExe(), _numOfCycles(cycles), _interval(interval){}
    unsigned long getNextRunPeriod();
    void run();
    unsigned long getNumOfCycles()const { return _numOfCycles;}


private:
    Time _taskCurrentTime;
    Time _EndLastExe;
    unsigned long _numOfCycles;
    unsigned long _interval; //milliseconds
};

#endif //SCHEDULER_TASK_H
