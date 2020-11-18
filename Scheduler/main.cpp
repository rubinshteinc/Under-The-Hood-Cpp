#include "task.h"
#include <vector>
#include "scheduler.h"
int main() {

    Task1 task1(5, 0);
    Task2 task2(4, 0);
    Task3 task3(2, 0);
    Task4 task4(6, 0);

    std::vector<ITask*> tasks;

    tasks.push_back(&task1);
    tasks.push_back(&task2);
    tasks.push_back(&task3);
    tasks.push_back(&task4);

    Scheduler scheduler(tasks);
    scheduler.runScheduler();

    return 0;
}