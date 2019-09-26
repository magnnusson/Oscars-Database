//
// Created by Alen Handukic on 2019-04-03.
//

#ifndef DSFINALPROJECT_MOVIE_H
#define DSFINALPROJECT_MOVIE_H
#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string name;
    int year;
    int nominations;
    double rating; //member vars for movies
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;
public:
    Movie(): name(" "), year(0), nominations(0), rating(0.0), duration(0), genre1(" "), genre2(" "), release(" "), metacritic(0), synopsis(" "){}

    void setName(string _name){name = _name;}
    void setYear(int _year){year = _year;}
    void setNominations(int _nominations){nominations = _nominations;}
    void setRating(double _rating){rating = _rating;}
    void setDuration(int _duration){duration = _duration;} //setters
    void setGenre1(string gen1){genre1 = gen1;}
    void setGenre2(string gen2){genre2 = gen2;}
    void setRelease(string _release){release = _release;}
    void setMetacritic(int meta){metacritic = meta;}
    void setSynopsis(string syn){synopsis = syn;}

    string getName(){return name;}
    int getYear(){return year;}
    int getNominations(){return nominations;}
    double getRating(){return rating;}
    int getDuration(){return duration;}  //getters
    string getGenre1(){return genre1;}
    string getGenre2(){return genre2;}
    string getRelease(){return release;}
    int getMetacritic(){return metacritic;}
    string getSynopsis(){return synopsis;}
};


#endif //DSFINALPROJECT_MOVIE_H
