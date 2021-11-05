//
// Created by anon on 11/5/21.
//

#ifndef JIPP_2_STUDENT_H
#define JIPP_2_STUDENT_H
#include <iostream>
#include <string>



using namespace std;

class Student {
private:
    string imie;
    string nazwisko;
    unsigned int numer_albumu;
    unsigned int liczba_pytan;
    unsigned int poprawne_odp;

public:
    Student(string imie, string nazwisko, unsigned int numer_albumu, unsigned int liczba_pytan, unsigned int poprawne_odp);
    double calculateCorrect();
    string get_imie();
    string get_nazwisko();
    unsigned int get_numer_albumu();
    unsigned int get_liczba_pytan();
    unsigned int get_poprawne_odp();
    void set_imie(string imie);
    void set_nazwisko(string nazwisko);
    void set_numer_albumu(unsigned int numer_albumu);
    void set_liczba_pytan(unsigned int liczba_pytan);
    void set_poprawne_odp(unsigned int poprawne_odp);

};


#endif //JIPP_2_STUDENT_H

/*
 * Napisz program, ktory stworzy klasę Student o polach: imię, nazwisko, numer albumu, liczba pytan, poprawne odpowiedzi
 Napisz funckję, która wczyta te dane oraz funkcję, która obliczy procent poprawnych odpowiedzi.
 */