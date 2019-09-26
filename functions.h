//
// Created by Alen Handukic on 2019-04-02.
//

#ifndef DSFINALPROJECT_FUNCTIONS_H
#define DSFINALPROJECT_FUNCTIONS_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BSTree.hpp"
#include "Node.h"
#include "Movie.h"
#include "Actor.h"
using namespace std;
//This file will hold all functions necessary for the user to navigate through the database. They correspond with menu item numbers.

void readInActors(fstream& infile, BSTree<Actor, string> &tree);
void readInMovies(fstream& infile, BSTree<Movie, string> &tree);
void addActor(int year, string award, int winner, string name, string film, BSTree<Actor, string> &tree);
void addMovie(string name, int year, int nominations, double rating, int duration, string genre1, string genre2, string release, int meta, string synopsis, BSTree<Movie, string> &tree);
void searchModifyActor(string searchfield, string searchterm, BSTree<Actor, string> &tree);
void searchModifyMovie(string searchfield, string searchterm, BSTree<Movie, string> &tree);
void searchDeleteActor(string searchfield, BSTree<Actor, string> &tree);
void searchDeleteMovie(string searchfield, BSTree<Movie, string> &tree);
void sortActors(string sortfield, BSTree<Actor, string> &tree);
void sortMovies(string sortfield, BSTree<Movie, string> &tree);
void compSearchActor(string searchTerm, BSTree<Actor, string> &tree);
void compSearchMovie(string searchTerm, BSTree<Movie, string> &tree);
void partSearchActor(string searchTerm, BSTree<Actor, string> &tree);
void partSearchMovie(string searchTerm, BSTree<Movie, string> &tree);
void printActors(ofstream& outfile, BSTree<Actor, string> &tree);
void printMovies(ofstream& outfile, BSTree<Movie, string> &tree);




#endif //DSFINALPROJECT_FUNCTIONS_H
