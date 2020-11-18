#include "task.h"
#include <iostream>

unsigned long Task1::getNextRunPeriod() {
    if (_numOfCycles) {
        return _EndLastExe + _interval;
    }

    return 0;
}

void Task1::run() {
    _taskCurrentTime.now();

    if (getNextRunPeriod() >  _taskCurrentTime - _EndLastExe) {
        usleep(_taskCurrentTime - _EndLastExe);
    }
    std::cout << "running task 1:"<<std::endl;
    std::cout << "cycle: "<< _numOfCycles <<std::endl;
    --_numOfCycles;
    _EndLastExe.now();

    if (!_numOfCycles) {
        std::cout<< "task 1 - DONE!" << std::endl;
    }
}

unsigned long Task2::getNextRunPeriod() {
    if (_numOfCycles) {
        return _EndLastExe + _interval;
    }

    return 0;
}

void Task2::run() {
    _taskCurrentTime.now();

    if (getNextRunPeriod() >  _taskCurrentTime - _EndLastExe) {
        sleep(_taskCurrentTime - _EndLastExe);
    }
    std::cout << "running task 2:"<<std::endl;
    std::cout << "cycle: "<< _numOfCycles <<std::endl;
    --_numOfCycles;
    _EndLastExe.now();

    if (!_numOfCycles){
        std::cout<< "task 2 - DONE!" << std::endl;
    }
}

unsigned long Task3::getNextRunPeriod() {
    if (_numOfCycles) {
        return _EndLastExe + _interval;
    }

    return 0;
}

void Task3::run() {
    _taskCurrentTime.now();

    if (getNextRunPeriod() >  _taskCurrentTime - _EndLastExe) {
        sleep(_taskCurrentTime - _EndLastExe);
    }
    std::cout << "running task 3:"<<std::endl;
    std::cout << "cycle: "<< _numOfCycles <<std::endl;
    --_numOfCycles;
    _EndLastExe.now();

    if (!_numOfCycles) {
        std::cout<< "task 3 - DONE!" << std::endl;
    }
}
unsigned long Task4::getNextRunPeriod() {
    if (_numOfCycles) {
        return _EndLastExe + _interval;
    }

    return 0;
}

void Task4::run() {
    _taskCurrentTime.now();

    if (getNextRunPeriod() >  _taskCurrentTime - _EndLastExe) {
        sleep(_taskCurrentTime - _EndLastExe);
    }
    std::cout << "running task 4:"<<std::endl;
    std::cout << "cycle: "<< _numOfCycles <<std::endl;
    --_numOfCycles;
    _EndLastExe.now();
    if (!_numOfCycles) {
        std::cout<< "task 4 - DONE!" << std::endl;
    }
}


