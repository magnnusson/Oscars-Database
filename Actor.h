//
// Created by Alen Handukic on 2019-04-03.
//

#ifndef DSFINALPROJECT_ACTOR_H
#define DSFINALPROJECT_ACTOR_H
#include <iostream>
#include <string>
using namespace std;

class Actor {
private:
    int year;
    string award; //member vars for actors/actresses
    int winner;
    string name;
    string film;
public:
    Actor(): year(0), award(" "), winner(0), name(" "), film(" "){} //constructor

    void setYear(int _year){year = _year;}
    void setAward(string _award){award = _award;}
    void setWinner(int _winner){winner = _winner;} //setters
    void setName(string _name){name = _name;}
    void setFilm(string _film){film = _film;}

    int getYear(){return year;}
    string getAward(){return award;}
    int getWinner(){return winner;} //getters
    string getName(){return name;}
    string getFilm(){return film;}

};


#endif //DSFINALPROJECT_ACTOR_H
