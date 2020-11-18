#ifndef SCHEDULER_SCHEDULER_H
#define SCHEDULER_SCHEDULER_H
#include <queue>
#include "task.h"

class Scheduler{
public:
    Scheduler(std::vector<ITask*>);
    void runScheduler();

private:
    std::queue<ITask*> _taskQueue;
};



#endif //SCHEDULER_SCHEDULER_H
