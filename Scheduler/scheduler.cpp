#include "scheduler.h"

Scheduler::Scheduler(std::vector<ITask*> tasksList) {
    for (unsigned int i = 0; i < tasksList.size(); ++i) {
        _taskQueue.push(tasksList[i]);
    }
}
void Scheduler::runScheduler() {
    ITask *currentTask;

    while (!_taskQueue.empty()) {
        currentTask = _taskQueue.front();
        currentTask->run();
        _taskQueue.pop();

        if (currentTask -> getNumOfCycles()) {
            _taskQueue.push(currentTask);
        }
    }
}