//
// Created by anon on 11/22/21.
//

#ifndef JIPP_2_SCHEDULER_H
#define JIPP_2_SCHEDULER_H

#include <iostream>
#include "Task.h"
using namespace std;

class Scheduler {
private:
    vector <Task *> tasks;
    unsigned sleeptime;
    unsigned amountOfCall = 0;

public:
    Scheduler(unsigned sleeptime);

    //Ustawianie ilości wykonań (ile razy ma się uśpić w pętli), jeżeli 0, to ma działać w nieskończoność
    void setAmountOfCall(unsigned amountOfCall);

    //Dodawanie elementu do listy zadań do wykonania
    void addTask(Task task);

    //Uruchomienie działania (usypianie, wykonywanie wszystkich zadań i tak w kółko)
    void run();
};


#endif //JIPP_2_SCHEDULER_H
