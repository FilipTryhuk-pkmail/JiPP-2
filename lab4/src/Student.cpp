//
// Created by anon on 11/5/21.
//

#include "Student.h"
#include <utility>

Student::Student(string imie, string nazwisko, unsigned int numer_albumu, unsigned int liczba_pytan, unsigned int poprawne_odp) {
    this->imie = std::move(imie);
    this->nazwisko = std::move(nazwisko);
    this->numer_albumu = numer_albumu;
    this->liczba_pytan = liczba_pytan;
    this->poprawne_odp = poprawne_odp;
}

double Student::calculateCorrect() {
    double correct;
    correct = (float(poprawne_odp)/float(liczba_pytan)) * 100;
    return correct;
}

string Student::get_imie() {
    return imie;
}
string Student::get_nazwisko() {
    return nazwisko;
}

unsigned int Student::get_numer_albumu() {
    return numer_albumu;
}

unsigned int Student::get_liczba_pytan() {
    return liczba_pytan;
}

unsigned int Student::get_poprawne_odp() {
    return poprawne_odp;
}

void Student::set_imie(string imie) {
    this->imie = std::move(imie);
}
void Student::set_nazwisko(string nazwisko) {
    this->nazwisko = std::move(nazwisko);
}

void Student::set_numer_albumu(unsigned int numer_albumu) {
    this->numer_albumu = numer_albumu;
}

void Student::set_liczba_pytan(unsigned int liczba_pytan) {
    this->liczba_pytan = liczba_pytan;
}

void Student::set_poprawne_odp(unsigned int poprawne_odp) {
    this->poprawne_odp = poprawne_odp;
}
