#include <iostream>
#include "Ranking.h"


using std::cin;
using std::cout;
using std::endl;
/*
Program niedokonczony
aby zmienic wielkosc sortowanej tablicy
wystarczy zmienic warosc makra SIZE.
*/
int main() {
    Ranking Ran;
    Ran.read_file();
    Ran.quicksort(0,SIZE-1);
    //cout<<Ran;  //lepiej nie odkomentowywac jak sa duze wartosci makra SIZE
    Ran.~Ranking();
    return 0;
}
