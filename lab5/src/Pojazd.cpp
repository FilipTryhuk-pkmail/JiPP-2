//
// Created by anon on 11/8/21.
//

#include "Pojazd.h"

#include <utility>
#include <iostream>

using namespace std;

Pojazd::Pojazd(int plate, string name, int pass_count, string model, string *pass, double currentSoftwareVer) : pass_count(pass_count) {
    this->plate = plate;
    this->name = move(name);
    this->model = move(model);
    this->currentSoftwareVer = currentSoftwareVer;
    for (int i=0; i<pass_count; i++) {
        this->pass[i] = pass[i];
    }
}

void Pojazd::printout() {
    cout << plate << " " << name << " " << model << " " << pass_count << endl;
    for (int i=0; i<pass_count; i++) {
        cout << pass[i] << " ";
    }
    cout << endl;
}

void Pojazd::printPassenger(int slot) {
    cout << "Na " << slot << " miejscu jest: " << pass[slot] << endl;
}

Pojazd::Pojazd(Pojazd &pojazd) : pass_count(pojazd.pass_count){
    plate = pojazd.plate;
    name = pojazd.name;
    model = pojazd.model;
    currentSoftwareVer = pojazd.currentSoftwareVer;
    for (int i=0; i<pojazd.pass_count; i++) {
        this->pass[i] = pojazd.pass[i];
    }

}

string Pojazd::getName() const {
    return name;
}

int Pojazd::getPlate() const {
    return plate;
}

string Pojazd::getModel() const {
    return model;
}

void Pojazd::setPlate(int plate) {
    this->plate = plate;
}

void Pojazd::setName(string name) {
    this->name = std::move(name);
}

double Pojazd::getCurrentSoftwareVer() const {
    return currentSoftwareVer;
}

void Pojazd::updateSoftware() {
    currentSoftwareVer = newestSoftwareVer;
}

void Pojazd::releaseSoftwareUpdate(double update) {
    newestSoftwareVer = update;
}
