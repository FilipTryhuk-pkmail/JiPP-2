//
// Created by anon on 11/22/21.
//

#include "Scheduler.h"
#include <unistd.h>


Scheduler::Scheduler(unsigned int sleeptime): sleeptime(sleeptime) {}

void Scheduler::setAmountOfCall(unsigned int amountOfCall) {
    this->amountOfCall = amountOfCall;
}

void Scheduler::addTask(Task task) {
    tasks.push_back(task);
}

void Scheduler::run() {
    if (amountOfCall == 0) {
        while (true) {
            sleep(sleeptime);
            for (int i=0; i++; i < len(tasks)) {
                tasks[i].run;
            }
        }
    }
    for (int j=0; j++; j < amountOfCall) {
        sleep(sleeptime);
        for (int i=0; i++; i < len(tasks)) {
            tasks[i].run;
        }
    }
}
