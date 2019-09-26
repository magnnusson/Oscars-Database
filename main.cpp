/*Driver program demonstrating creating a tree, adding, finding and deleting nodes
Dr. Augustine 10/30/2017
Status: works with completed and correct BSTree.cpp
*/

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include <iostream>
#include <fstream>
#include <vector>
#include "BSTree.h"
#include "functions.h"
#include "Actor.h"
#include "Movie.h"
using namespace std;

int main()
{
    int option = 0;
    BSTree<Actor, string> ActorTree;
    BSTree<Movie, string> MovieTree;
    fstream actors("actor-actress.csv");
    fstream movies("pictures.csv");
    ofstream actorOutfile;
    ofstream movieOutfile;

    int year;
    string award;
    string winnerentry;
    int winner;
    string name;
    string film;

    string filmname;
    int filmyear;
    int nominations;
    double rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;

    string actorname;
    string moviename;
    string searchfield;
    string sortfield;
    string compsearch;
    string partsearch;
    string outfileName;

    cout << "Welcome to the Academy Awards Database." << endl;
    while(option != 20)
    {
        cout << "Choose an option: " << endl << endl;
        cout << "1. Read in Actors and Actresses" << endl;
        cout << "2. Read in Movies" << endl;
        cout << "3. Add record to Actor Database" << endl;
        cout << "4. Add record to Movie Database" << endl;
        cout << "5. Search and Modify an Actor" << endl;
        cout << "6. Search and Modify a Movie" << endl;
        cout << "7. Search and Delete an Actor" << endl;
        cout << "8. Search and Delete a Movie" << endl;
        cout << "9. Sort Actor Database" << endl;
        cout << "10. Sort Movie Database" << endl;
        cout << "11. 'Exact' Search of an Actor" << endl;
        cout << "12. 'Exact' Search of a Movie" << endl;
        cout << "13. 'Contains' Search of an Actor" << endl;
        cout << "14. 'Contains' Search of a Movie" << endl;
        cout << "15. Print out Actor Database to separate file" << endl;
        cout << "16. Print out Movie Database to separate file" << endl;
        cout << "17. Exit" << endl;

        cin >> option;

        switch(option)
        {
            case 1:
                readInActors(actors, ActorTree);
                cout << "Actors and Actresses successfully read in!" << endl;
                cout << endl;
                break;

            case 2:
                readInMovies(movies, MovieTree);
                cout << "Movies successfully read in!" << endl;
                cout << endl;
                break;

            case 3:
                cout << "What year did this take place?" << endl;
                cin >> year;
                cin.ignore();
                cout << "What award?" << endl;
                getline(cin, award);
                cout << "Did the actor or actress win? (y/n)" << endl;
                cin >> winnerentry;
                cin.ignore();
                if(winnerentry == "y" || winnerentry == "Y")
                    winner = 1;
                else if(winnerentry == "n" || winnerentry == "N")
                    winner = 0;
                else
                    {
                        cout << "Choose y for yes or n for no" << endl;
                        cin >> winnerentry;
                        cin.ignore();
                    }
                cout << "What is the actor or actress' name?" << endl;
                getline(cin, name);
                cout << "What is the film they performed in?" << endl;
                getline(cin, film);

                cout << "Now adding to actor database..." << endl;
                addActor(year, award, winner, name, film, ActorTree);
                cout << "Success!" << endl;
                cout << endl;
                break;

            case 4:
                cout << "What is the name of the film?" << endl;
                cin.ignore();
                getline(cin, filmname);
                cout << "When was it made?" << endl;
                cin >> filmyear;
                cin.ignore();
                cout << "How many nominations did it recieve?" << endl;
                cin >> nominations;
                cout << "What was its rating? (0.0-5.0)" << endl;
                cin >> rating;
                cout << "How long was the movie in minutes?" << endl;
                cin >> duration;
                cin.ignore();
                cout << "What is one genre for the movie?" << endl;
                getline(cin, genre1);
                cout << "What is another genre for the movie?" << endl;
                getline(cin, genre2);
                cout << "What month was it released?" << endl;
                getline(cin, release);
                cout << "What is its metacritic score?" << endl;
                cin >> metacritic;
                cin.ignore();
                cout << "Write a short synopsis for the movie." << endl;
                getline(cin, synopsis);

                cout << "Now adding to movie database..." << endl;
                addMovie(filmname, filmyear, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis, MovieTree);
                cout << "Success!" << endl;
                cout << endl;
                break;

            case 5:
                cout << "What actor or actress would you like to modify?" << endl;
                cin.ignore();
                getline(cin, actorname);
                cout << "What would you like to modify about " << actorname << "? (year, award, winner, name, film)" << endl;
                getline(cin, searchfield);
                if(ActorTree.findNode(actorname))
                {
                    searchModifyActor(actorname, searchfield, ActorTree);
                }
                else
                    cout << actorname << " not found!" << endl;
                cout << endl;
                break;

            case 6:
                cout << "What movie would you like to modify?" << endl;
                cin.ignore();
                getline(cin, moviename);
                cout << "What would you like to modify about " << moviename << "? (name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis)" << endl;
                getline(cin, searchfield);
                if(MovieTree.findNode(moviename))
                {
                    searchModifyMovie(moviename, searchfield, MovieTree);
                } else
                    cout << moviename << " not found!" << endl;
                cout << endl;
                break;

            case 7:
                cout << "Which actor would you like to delete?" << endl;
                cin.ignore();
                getline(cin, actorname);
                cout << "Deleting..." << endl;
                if(ActorTree.findNode(actorname))
                searchDeleteActor(actorname, ActorTree);
                else
                    cout << "Actor not found!" << endl;
                cout << endl;
                break;

            case 8:
                cout << "Which movie would you like to delete?" << endl;
                cin.ignore();
                getline(cin, moviename);
                cout << "Deleting..." << endl;
                if(MovieTree.findNode(moviename))
                searchDeleteMovie(moviename, MovieTree);
                else
                    cout << "Movie not found!" << endl;
                cout << endl;
                break;

            case 9:
                cout << "Which field would you like to sort by? (year, name, award, winner, film)" << endl;
                cin.ignore();
                getline(cin, sortfield);
                sortActors(sortfield, ActorTree);
                cout << "Done!" << endl;
                cout << endl;
                break;

            case 10:
                cout << "Which field would you like to sort by? (year, nominations, rating, duration, genre 1, genre 2, release, metacritic)" << endl;
                cin.ignore();
                getline(cin, sortfield);
                sortMovies(sortfield, MovieTree);
                cout << "Done!" << endl;
                cout << endl;
                break;

            case 11:
                cout << "What field would you like to do an 'exact' search for? (year, name, award, winner, film)" << endl;
                cin.ignore();
                getline(cin, searchfield);
                compSearchActor(searchfield, ActorTree);
                cout << endl;
                break;

            case 12:
                cout << "What field would you like to do an 'exact' search for? (year, nominations, rating, duration, genre 1, genre 2, release, metacritic)" << endl;
                cin.ignore();
                getline(cin, searchfield);
                compSearchMovie(searchfield, MovieTree);
                cout << endl;
                break;

            case 13:
                cout << "What field would you like to do a 'contains' search for? (name, award, film)" << endl;
                cin.ignore();
                getline(cin, partsearch);
                partSearchActor(partsearch, ActorTree);
                cout << endl;
                break;

            case 14:
                cout << "What field would you like to do a 'contains' search for? (genre 1, genre 2, release, synopsis)" << endl;
                cin.ignore();
                getline(cin, partsearch);
                partSearchMovie(partsearch, MovieTree);
                cout << endl;
                break;

            case 15:
                cout << "Enter name of output file: " << endl;
                cin.ignore();
                getline(cin, outfileName);
                actorOutfile.open(outfileName);
                cout << "Printing actor database to " << outfileName << "..." << endl;
                printActors(actorOutfile, ActorTree);
                actorOutfile.close();
                cout << "Done!" << endl;
                break;

            case 16:
                cout << "Enter name of output file: " << endl;
                cin.ignore();
                getline(cin, outfileName);
                movieOutfile.open(outfileName);
                cout << "Printing movie database to " << outfileName << "..." << endl;
                printMovies(movieOutfile, MovieTree);
                movieOutfile.close();
                cout << "Done!" << endl;
                break;

            case 17:
                cout << "Goodbye!" << endl;
                return 0;
                break;

            default:
                cout << "Please enter a valid option: " << endl;
                cin >> option;
                break;
        }
    }




return 0;
}