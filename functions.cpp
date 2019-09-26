//
// Created by Alen Handukic on 2019-04-02.
//

#include "functions.h"

void readInActors(fstream& infile, BSTree<Actor, string> &tree)
{
    Actor actor;
    Actor tempActor;
    string inyear;
    int year;
    string award;
    string inwinner;
    int winner;
    string name;
    string film;
    string line;


    getline(infile, line, '\n'); //ignore the first line of the csv file, which is the header ("year", "name", etc.)

    while(getline(infile, inyear, ',')) //use comma character as delimiter in the getline function
    {
        year = stoi(inyear); //converting year string variables into integers using stoi
        tempActor.setYear(year); //setting tempActor year
        getline(infile, award, ',');
        tempActor.setAward(award); //setting tempActor award
        getline(infile, inwinner, ',');
        winner = stoi(inwinner); //converting winner string variables into integers using stoi
        tempActor.setWinner(winner); //setting tempActor winner
        getline(infile, name, ',');
        tempActor.setName(name);  //setting tempActor name
        getline(infile, film, '\n'); //each line ends with newline
        tempActor.setFilm(film); //setting tempActor film

        actor = tempActor; //copying tempActor to actor
        tree.addNode(actor.getName(), actor); //adding each actor object to the tree as a node, which uses actor names as keys
    }

}

void readInMovies(fstream& infile, BSTree<Movie, string> &tree)
{
    Movie movie;
    Movie tempMovie;
    string name;
    string inyear;
    int year;
    string innominations;
    int nominations;
    string inrating;
    double rating;
    string induration;
    int duration;
    string genre1;
    string genre2;
    string release;
    string inmetacritic;
    int metacritic;
    string synopsis;

    string line;

    getline(infile, line, '\n'); //ignore the first line of the .csv file, which are the column labels


    while(getline(infile, name, ',')) //using comma as delimiter in the getline
    {

        tempMovie.setName(name); //setting tempMovie name
        getline(infile, inyear, ',');
        year = stoi(inyear); //converting year string to integer
        tempMovie.setYear(year); //setting tempMovie year
        getline(infile, innominations,',');
        if(innominations != "-")
        {
            nominations = stoi(innominations);
            tempMovie.setNominations(nominations); //checking if the movie has any nominations by using csv file symbols that indicate if not (-)
        }
        else
            {
            tempMovie.setNominations(0); //if not, we set tempMovie nominations to zero
            }
        getline(infile, inrating, ',');
        rating = stod(inrating); //converting rating string to double
        tempMovie.setRating(rating); //setting tempMovie rating
        getline(infile, induration, ',');
        duration = stoi(induration); //converting duration string to integer
        tempMovie.setDuration(duration); //setting tempMovie duration
        getline(infile, genre1, ',');
        tempMovie.setGenre1(genre1); //setting tempMovie genre1
        getline(infile, genre2, ',');
        tempMovie.setGenre2(genre2); //setting tempMovie genre2 (error checking unnecessary since strings can be blank and the class member variable is a string type)
        getline(infile, release, ',');
        tempMovie.setRelease(release); //setting tempMovie release
        getline(infile, inmetacritic, ',');
        if(inmetacritic != "")
        {
            metacritic = stoi(inmetacritic);
            tempMovie.setMetacritic(metacritic); //checking if the movie has a metacritic score by using csv file symbols that indicate if not (score left blank)
        }
        else
            {
                tempMovie.setMetacritic(0); //if not, then just set the metacritic score to 0
            }
        getline(infile, synopsis, '\n');
        tempMovie.setSynopsis(synopsis); //setting tempMovie synopsis

        movie = tempMovie; //copying tempMovie to movie
        tree.addNode(movie.getName(), movie); //adding the movie object into the tree as a node, with the name of the film as the key


    }
}

void addActor(int year, string award, int winner, string name, string film, BSTree<Actor, string> &tree)
{
    Actor tempActor;

    tempActor.setYear(year);
    tempActor.setAward(award);
    tempActor.setWinner(winner); //creating temporary Actor object with user input for each variable
    tempActor.setName(name);
    tempActor.setFilm(film);

    tree.addNode(tempActor.getName(), tempActor); //adding temporary actor object to the Actor search tree
    tree.printInorder(); //printing out names so user can see that their actor has been added
}
void addMovie(string name, int year, int nominations, double rating, int duration, string genre1, string genre2, string release, int meta, string synopsis,
        BSTree<Movie, string> &tree)
{
    Movie tempMovie;

    tempMovie.setName(name);
    tempMovie.setYear(year);
    tempMovie.setNominations(nominations); //creating temporary Movie object with user input for each variable
    tempMovie.setRating(rating);
    tempMovie.setDuration(duration);
    tempMovie.setGenre1(genre1);
    tempMovie.setGenre2(genre2);
    tempMovie.setRelease(release);
    tempMovie.setMetacritic(meta);
    tempMovie.setSynopsis(synopsis);

    tree.addNode(tempMovie.getName(), tempMovie); //adding temporary movie object to the Movie search tree
    tree.printInorder(); //printing out films so user can see that their movie has been added
}

void searchModifyActor(string searchfield, string searchterm, BSTree<Actor, string> &tree)
{
    int newyear;
    string newaward;
    string newname;
    string newfilm;
    string yesOrNo;

    Actor newactor; //create a temporary actor object that will overwrite the old actor object in the tree

    newactor.setYear(tree.findNode(searchfield)->Data().getYear());
    newactor.setName(tree.findNode(searchfield)->Data().getName());
    newactor.setFilm(tree.findNode(searchfield)->Data().getFilm());
    newactor.setWinner(tree.findNode(searchfield)->Data().getWinner()); //set it to the old actor object in the tree
    newactor.setAward(tree.findNode(searchfield)->Data().getAward());


    if(tree.findNode(searchfield))
    {
        cout << searchfield << " found!" << endl;
        cout << "Now modifying " << searchterm << "..." << endl;

        if(searchterm == "year" || searchterm == "Year") //set temp actor object's year to user modification
        {
            cout << "Please enter the new year for " << searchfield << ":" << endl;
            cin >> newyear;
            newactor.setYear(newyear);
            tree.findNode(searchfield)->setData(newactor); //overwrite the old node with the temp actor
        }
        else if(searchterm == "award" || searchterm == "Award") //set temp actor object's award to user modification
        {
            cout << "Please enter the name of the award for " << searchfield << ":" << endl;
            getline(cin, newaward);
            newactor.setAward(newaward);
            tree.findNode(searchfield)->setData(newactor); //overwrite the old node with the temp actor
        }
        else if(searchterm == "winner" || searchterm == "Winner") //set temp actor object's winner to user modification
        {
            cout << "Please enter if " << searchfield << " was a winner or not (y/n)" << endl;
            cin >> yesOrNo;
            if(yesOrNo == "y" || yesOrNo == "Y") //set winner to 1 if yes
            {
                newactor.setWinner(1);
            }
            else if(yesOrNo == "n" || yesOrNo == "N") //set winner to 0 if no
            {
                newactor.setWinner(0);
            }
            tree.findNode(searchfield)->setData(newactor); //overwrite the old node with the temp actor
        }
        else if(searchterm == "name" || searchterm == "Name") //set temp actor object's name to user modification
        {
            cout << "Please enter a new name for this actor/actress: " << endl;
            getline(cin, newname);
            newactor.setName(newname);
            tree.findNode(searchfield)->setData(newactor); //overwrite the old node with the temp actor
        }
        else if(searchterm == "film" || searchterm == "Film") //set temp actor object's film to user modification
        {
            cout << "Please enter a new film name for " << searchfield << ":" << endl;
            getline(cin, newfilm);
            newactor.setFilm(newfilm);
            tree.findNode(searchfield)->setData(newactor); //overwrite the old node with the temp actor
        }

        cout << searchfield << " has been modified. Here is their new information: " << endl;
        cout << "Name: " << tree.findNode(searchfield)->Data().getName() << endl;
        cout << "Year: " << tree.findNode(searchfield)->Data().getYear() << endl;
        cout << "Award: " << tree.findNode(searchfield)->Data().getAward() << endl; //display that actor for the user with the latest information after modification
        if(tree.findNode(searchfield)->Data().getWinner() == 0)
        {
            cout << "Winner: No" << endl;
        }
        else
            cout << "Winner: Yes" << endl;

        cout << "Film: " << tree.findNode(searchfield)->Data().getFilm() << endl;
        cout << endl;
    }
}
void searchModifyMovie(string searchfield, string searchterm, BSTree<Movie, string> &tree)
{
    int newyear;
    string newname;
    int newnominations;
    double newrating;
    int newduration;
    string newrelease;
    string newgenre1;
    string newgenre2;
    int newmetacritic;
    string newsynopsis;

    Movie newmovie; //creating a temporary movie object to overwrite the old one in the tree

    newmovie.setName(tree.findNode(searchfield)->Data().getName());
    newmovie.setYear(tree.findNode(searchfield)->Data().getYear());
    newmovie.setNominations(tree.findNode(searchfield)->Data().getNominations());
    newmovie.setMetacritic(tree.findNode(searchfield)->Data().getMetacritic());
    newmovie.setRelease(tree.findNode(searchfield)->Data().getRelease());  //set the temp movie object to old one in tree
    newmovie.setDuration(tree.findNode(searchfield)->Data().getDuration());
    newmovie.setSynopsis(tree.findNode(searchfield)->Data().getSynopsis());
    newmovie.setRating(tree.findNode(searchfield)->Data().getRating());
    newmovie.setGenre1(tree.findNode(searchfield)->Data().getGenre1());
    newmovie.setGenre2(tree.findNode(searchfield)->Data().getGenre2());



    if(searchterm == "year" || searchterm == "Year") //set temp movie object's year to user modification
    {
        cout << "Please enter the new year for " << searchfield << ":" << endl;
        cin >> newyear;
        newmovie.setYear(newyear);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "name" || searchterm == "Name") //set temp movie object's name to user modification
    {
        cout << "Please enter the new name for " << searchfield << ":" << endl;
        getline(cin, newname);
        newmovie.setName(newname);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "nominations" || searchterm == "Nominations") //set temp movie object's nominations to user modification
    {
        cout << "Please enter the new number of nominations for " << searchfield << ":" << endl;
        cin >> newnominations;
        newmovie.setNominations(newnominations);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "rating" || searchterm == "Rating") //set temp movie object's rating to user modification
    {
        cout << "Please enter the new rating for " << searchfield << ":" << endl;
        cin >> newrating;
        newmovie.setRating(newrating);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "duration" || searchterm == "Duration") //set temp movie object's duration to user modification
    {
        cout << "Please enter the new duration, in minutes, of " << searchfield << ":" << endl;
        cin >> newduration;
        newmovie.setDuration(newduration);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "release" || searchterm == "Release") //set temp movie object's release to user modification
    {
        cout << "Please enter the new month of release for " << searchfield << ":" << endl;
        getline(cin, newrelease);
        newmovie.setRelease(newrelease);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "genre1" || searchterm == "Genre1") //set temp movie object's genre1 to user modification
    {
        cout << "Please enter a new first genre for " << searchfield << ":" << endl;
        getline(cin, newgenre1);
        newmovie.setGenre1(newgenre1);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "genre2" || searchterm == "Genre2") //set temp movie object's genre2 to user modification
    {
        cout << "Please enter a new second genre for " << searchfield << ":" << endl;
        getline(cin, newgenre2);
        newmovie.setGenre2(newgenre2);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "metacritic" || searchterm == "Metacritic") //set temp movie object's metacritic to user modification
    {
        cout << "Please enter a new metacritic score for " << searchfield << ":" << endl;
        cin >> newmetacritic;
        newmovie.setMetacritic(newmetacritic);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else if(searchterm == "synopsis" || searchterm == "Synopsis") //set temp movie object's synopsis to user modification
    {
        cout << "Please enter a new synopsis for " << searchfield << ":" << endl;
        getline(cin, newsynopsis);
        newmovie.setSynopsis(newsynopsis);
        tree.findNode(searchfield)->setData(newmovie); //overwrite the old node with temp actor
    }
    else
        {
        cout << "Enter a valid field for modification that is listed." << endl;
        return;
        }

    cout << searchfield << " has been modified. Here is its new information: " << endl;
    cout << "Name: " << tree.findNode(searchfield)->Data().getName() << endl;
    cout << "Year: " << tree.findNode(searchfield)->Data().getYear() << endl;
    cout << "Nominations: " << tree.findNode(searchfield)->Data().getNominations() << endl;
    cout << "Rating: " << tree.findNode(searchfield)->Data().getRating() << endl;
    cout << "Duration: " << tree.findNode(searchfield)->Data().getDuration() << endl; //displaying the same movie node with the latest information after modification
    cout << "Genre 1: " << tree.findNode(searchfield)->Data().getGenre1() << endl;
    cout << "Genre 2: " << tree.findNode(searchfield)->Data().getGenre2() << endl;
    cout << "Release: " << tree.findNode(searchfield)->Data().getRelease() << endl;
    cout << "Metacritic: " << tree.findNode(searchfield)->Data().getMetacritic() << endl;
    cout << "Synopsis: " << tree.findNode(searchfield)->Data().getSynopsis() << endl;
    cout << endl;

}
void searchDeleteActor(string searchfield, BSTree<Actor, string> &tree)
{

    tree.deleteNode(searchfield);
    cout << "Actor successfully deleted." << endl; //simply call the deleteNode function using actor name as key


}
void searchDeleteMovie(string searchfield, BSTree<Movie, string> &tree)
{

    tree.deleteNode(searchfield);
    cout << "Movie successfully deleted." << endl; //simply call the deleteNode function using movie name as key


}
void sortActors(string sortfield, BSTree<Actor, string> &tree)
{

    vector<Actor> actorvec; //creating a vector to store tree information and to use to sort the information
    actorvec = tree.TreeToVec(actorvec); //use the sortTree function to transfer data from the tree into a vector

    cout << "Now sorting actors by " << sortfield << "..." << endl;

    for(int i = 0; i < actorvec.size(); i++)
    {
        if(sortfield == "year" || sortfield == "Year") //bubble sort comparing year
        {
            for(int j = 0; j < actorvec.size(); j++)
            {
                for(int k = 0; k < actorvec.size()-j-1; k++)
                {
                    if(actorvec[k].getYear() > actorvec[k+1].getYear())
                    {
                        Actor temp = actorvec[k+1];
                        actorvec[k+1] = actorvec[k];
                        actorvec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "award" || sortfield == "Award") //bubble sort comparing award
        {
            for(int j = 0; j < actorvec.size(); j++)
            {
                for(int k = 0; k < actorvec.size()-j-1; k++)
                {
                    if(actorvec[k].getAward() > actorvec[k+1].getAward())
                    {
                        Actor temp = actorvec[k+1];
                        actorvec[k+1] = actorvec[k];
                        actorvec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "name" || sortfield == "Name") //bubble sort comparing name
        {
            for(int j = 0; j < actorvec.size(); j++)
            {
                for(int k = 0; k < actorvec.size()-j-1; k++)
                {
                    if(actorvec[k].getName() > actorvec[k+1].getName())
                    {
                        Actor temp = actorvec[k+1];
                        actorvec[k+1] = actorvec[k];
                        actorvec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "winner" || sortfield == "Winner") //bubble sort comparing winner
        {
            for(int j = 0; j < actorvec.size(); j++)
            {
                for(int k = 0; k < actorvec.size()-j-1; k++)
                {
                    if(actorvec[k].getWinner() > actorvec[k+1].getWinner())
                    {
                        Actor temp = actorvec[k+1];
                        actorvec[k+1] = actorvec[k];
                        actorvec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "film" || sortfield == "Film") //bubble sort comparing film
        {
            for(int j = 0; j < actorvec.size(); j++)
            {
                for(int k = 0; k < actorvec.size()-j-1; k++)
                {
                    if(actorvec[k].getFilm() > actorvec[k+1].getFilm())
                    {
                        Actor temp = actorvec[k+1];
                        actorvec[k+1] = actorvec[k];
                        actorvec[k] = temp;
                    }

                }
            }
        }
        else
            {
            cout << "Enter a valid sortable field that is listed." << endl; //else, report an error
            return;
            }

        cout << "Year: " << actorvec[i].getYear() << endl; //displaying the actor tree information
        cout << "Award: " << actorvec[i].getAward() << endl;
        cout << "Name: " << actorvec[i].getName() << endl;
        if(actorvec[i].getWinner() == 0)
        {
            cout << "Winner: No" << endl;
        } else
            {
            cout << "Winner: Yes" << endl;
            }
        cout << "Film: " << actorvec[i].getFilm() << endl;
        cout << endl;
    }

}

void sortMovies(string sortfield, BSTree<Movie, string> &tree)
{
    vector<Movie> movievec; //creating a vector to store tree information and to use to sort the information
    movievec = tree.TreeToVec(movievec); //use the sortTree function to transfer data from the tree into a vector

    cout << "Now sorting movies by " << sortfield << "..." << endl;

    for(int i = 0; i < movievec.size(); i++)
    {
        if(sortfield == "year" || sortfield == "Year") //using bubble sorts
        {
            for(int j = 0; j < movievec.size(); j++)
            {
                for(int k = 0; k < movievec.size()-j-1; k++)        //simple bubble sort comparing year
                {
                    if(movievec[k].getYear() > movievec[k+1].getYear())
                    {
                        Movie temp = movievec[k+1];
                        movievec[k+1] = movievec[k];
                        movievec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "nominations" || sortfield == "Nominations")
        {
            for(int j = 0; j < movievec.size(); j++)
            {
                for(int k = 0; k < movievec.size()-j-1; k++) //bubble sort for nominations
                {
                    if(movievec[k].getNominations() > movievec[k+1].getNominations())
                    {
                        Movie temp = movievec[k+1];
                        movievec[k+1] = movievec[k];
                        movievec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "rating" || sortfield == "Rating")
        {
            for(int j = 0; j < movievec.size(); j++)
            {
                for(int k = 0; k < movievec.size()-j-1; k++)
                {
                    if(movievec[k].getRating() > movievec[k+1].getRating()) //bubble sort for rating
                    {
                        Movie temp = movievec[k+1];
                        movievec[k+1] = movievec[k];
                        movievec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "duration" || sortfield == "Duration")
        {
            for(int j = 0; j < movievec.size(); j++)
            {
                for(int k = 0; k < movievec.size()-j-1; k++)
                {
                    if(movievec[k].getDuration() > movievec[k+1].getDuration()) //bubble sort for duration
                    {
                        Movie temp = movievec[k+1];
                        movievec[k+1] = movievec[k];
                        movievec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "genre 1" || sortfield == "Genre 1")
        {
            for(int j = 0; j < movievec.size(); j++)
            {
                for(int k = 0; k < movievec.size()-j-1; k++)
                {
                    if(movievec[k].getGenre1() > movievec[k+1].getGenre1()) //bubble sort for genre 1
                    {
                        Movie temp = movievec[k+1];
                        movievec[k+1] = movievec[k];
                        movievec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "genre 2" || sortfield == "Genre 2")
        {
            for(int j = 0; j < movievec.size(); j++)
            {
                for(int k = 0; k < movievec.size()-j-1; k++)
                {
                    if(movievec[k].getGenre2() > movievec[k+1].getGenre2()) //bubble sort for genre 2
                    {
                        Movie temp = movievec[k+1];
                        movievec[k+1] = movievec[k];
                        movievec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "release" || sortfield == "Release")
        {
            for(int j = 0; j < movievec.size(); j++)
            {
                for(int k = 0; k < movievec.size()-j-1; k++)
                {
                    if(movievec[k].getRelease() > movievec[k+1].getRelease()) //bubble sort for release
                    {
                        Movie temp = movievec[k+1];
                        movievec[k+1] = movievec[k];
                        movievec[k] = temp;
                    }

                }
            }
        }
        else if(sortfield == "metacritic" || sortfield == "Metacritic")
        {
            for(int j = 0; j < movievec.size(); j++)
            {
                for(int k = 0; k < movievec.size()-j-1; k++)
                {
                    if(movievec[k].getMetacritic() > movievec[k+1].getMetacritic()) //bubble sort for metacritic
                    {
                        Movie temp = movievec[k+1];
                        movievec[k+1] = movievec[k];
                        movievec[k] = temp;
                    }

                }
            }
        } else
            {
                cout << "Enter a valid listed sortable field." << endl; //else, break out of function with error message. user cannot sort by synopsis
                return;
            }



        cout << "Name: " <<  movievec[i].getName() << endl;
        cout << "Year: " << movievec[i].getYear() << endl;
        cout << "Nominations: " << movievec[i].getNominations() << endl;
        cout << "Rating: " << movievec[i].getRating() << endl;
        cout << "Duration : " << movievec[i].getDuration() << endl; //displaying the sorted movie tree information
        cout << "Genre 1: " << movievec[i].getGenre1() << endl;
        cout << "Genre 2: "<< movievec[i].getGenre2() << endl;
        cout << "Release: " << movievec[i].getRelease() << endl;
        cout << "Metacritic Score: " << movievec[i].getMetacritic() << endl;
        cout << "Synopsis: " << movievec[i].getSynopsis() << endl;
        cout << endl;
    }

}

void compSearchActor(string searchTerm, BSTree<Actor, string> &tree)
{

    vector<Actor> searchVec; //use another vector to execute the exact search
    searchVec = tree.TreeToVec(searchVec); //transfer info from tree to vector

    int searchYear;
    string searchName;
    string searchAward;
    string searchWinner; //user input variables
    string searchFilm;


            if(searchTerm == "year" || searchTerm == "Year") //checking for user input of search field for each category
            {
            cout << "Enter an exact year for your search: " << endl;
            cin >> searchYear;
            for(int i = 0; i < searchVec.size(); i++) //iterating through the vector
            {
                if(searchVec[i].getYear() == searchYear) //seeing if any element(s) in the vector match the user input exactly
                {
                    cout << "Year: " << searchVec[i].getYear() << endl; //if so, output the result(s) to the user
                    cout << "Award: " << searchVec[i].getAward() << endl;
                    if(searchVec[i].getWinner() == 0)
                    {
                        cout << "Winner: No" << endl;
                    }
                    else
                    {
                        cout << "Winner: Yes" << endl;
                    }
                    cout << "Name: " << searchVec[i].getName() << endl;
                    cout << "Film: " << searchVec[i].getFilm() << endl;
                    cout << endl;
                }
             }
            }
            else if(searchTerm == "name" || searchTerm == "Name") //same as above for the name category
            {
                cout << "Enter an exact name for your search: " << endl;
                getline(cin, searchName);
                for(int i = 0; i < searchVec.size(); i++)
                {
                    if(searchVec[i].getName() == searchName)
                    {
                        cout << "Year: " << searchVec[i].getYear() << endl;
                        cout << "Award: " << searchVec[i].getAward() << endl;
                        if(searchVec[i].getWinner() == 0)
                        {
                            cout << "Winner: No" << endl;
                        }
                        else
                        {
                            cout << "Winner: Yes" << endl;
                        }
                        cout << "Name: " << searchVec[i].getName() << endl;
                        cout << "Film: " << searchVec[i].getFilm() << endl;
                        cout << endl;
                    }
                }
            }
            else if(searchTerm == "award" || searchTerm == "Award") //same as above for the award category
             {
                 cout << "Enter an exact award for your search: " << endl;
                 getline(cin, searchAward);
                 for(int i = 0; i < searchVec.size(); i++)
                 {
                     if(searchVec[i].getAward() == searchAward)
                     {
                         cout << "Year: " << searchVec[i].getYear() << endl;
                         cout << "Award: " << searchVec[i].getAward() << endl;
                         if(searchVec[i].getWinner() == 0)
                         {
                             cout << "Winner: No" << endl;
                         }
                         else
                         {
                             cout << "Winner: Yes" << endl;
                         }
                         cout << "Name: " << searchVec[i].getName() << endl;
                         cout << "Film: " << searchVec[i].getFilm() << endl;
                         cout << endl;
                     }
                 }
             }
            else if(searchTerm == "winner" || searchTerm == "Winner") //same as above for the winner category
            {
                cout << "Enter if actor was a winner for your search (exactly 'yes' or 'no'): " << endl;
                getline(cin, searchWinner);
                for(int i = 0; i < searchVec.size(); i++)
                {
                    if(searchWinner == "yes" || searchWinner == "Yes") //winner is either 1 or 0, so user must input yes or no which is then checked accordingly
                    {
                        if(searchVec[i].getWinner() == 1)
                        {
                            cout << "Year: " << searchVec[i].getYear() << endl;
                            cout << "Award: " << searchVec[i].getAward() << endl;
                            if(searchVec[i].getWinner() == 0)
                            {
                                cout << "Winner: No" << endl;
                            }
                            else
                            {
                                cout << "Winner: Yes" << endl;
                            }
                            cout << "Name: " << searchVec[i].getName() << endl;
                            cout << "Film: " << searchVec[i].getFilm() << endl;
                            cout << endl;
                        }
                    }
                    else if(searchWinner == "no" || searchWinner == "No")
                    {
                        if(searchVec[i].getWinner() == 0)
                        {
                            cout << "Year: " << searchVec[i].getYear() << endl;
                            cout << "Award: " << searchVec[i].getAward() << endl;
                            if(searchVec[i].getWinner() == 0)
                            {
                                cout << "Winner: No" << endl;
                            }
                            else
                            {
                                cout << "Winner: Yes" << endl;
                            }
                            cout << "Name: " << searchVec[i].getName() << endl;
                            cout << "Film: " << searchVec[i].getFilm() << endl;
                            cout << endl;
                        }
                    }
                    else
                        {
                        cout << "Please enter 'yes' or 'no'." << endl;
                        return;
                        }

                }
            }
            else if(searchTerm == "film" || searchTerm == "Film") //same as above for the film category
                {
                    cout << "Enter an exact film name for your search: " << endl;
                    getline(cin, searchFilm);
                    for(int i = 0; i < searchVec.size(); i++)
                    {
                        if(searchVec[i].getFilm() == searchFilm)
                        {
                            cout << "Year: " << searchVec[i].getYear() << endl;
                            cout << "Award: " << searchVec[i].getAward() << endl;
                            if(searchVec[i].getWinner() == 0)
                            {
                                cout << "Winner: No" << endl;
                            }
                            else
                            {
                                cout << "Winner: Yes" << endl;
                            }
                            cout << "Name: " << searchVec[i].getName() << endl;
                            cout << "Film: " << searchVec[i].getFilm() << endl;
                            cout << endl;
                        }
                    }
                }
            else {
                cout << "Please enter a listed valid field to do an 'exact' search by." << endl; //else, error message reporting bad input
                return;
            }



}
void compSearchMovie(string searchTerm, BSTree<Movie, string> &tree)
{
    vector<Movie> searchVec; //use another vector to execute the exact search
    searchVec = tree.TreeToVec(searchVec); //transfer info from tree to vector


    int searchYear;
    int searchNom;
    double searchRating;
    int searchDuration; //user input variables
    string searchGenre1;
    string searchGenre2;
    string searchRelease;
    int searchMeta;




        if(searchTerm == "year" || searchTerm == "Year") //checking for user input of search field for each category (except synopsis)
        {
            cout << "Enter an exact year for your search: " << endl;
            cin >> searchYear;
            for(int i = 0; i < searchVec.size(); i++) //iterating through the vector
            {
                if(searchVec[i].getYear() == searchYear) //seeing if any element(s) in the vector match the user input exactly
                {
                    cout << "Name: " <<  searchVec[i].getName() << endl; //if so, output relevant info to the user
                    cout << "Year: " << searchVec[i].getYear() << endl;
                    cout << "Nominations: " << searchVec[i].getNominations() << endl;
                    cout << "Rating: " << searchVec[i].getRating() << endl;
                    cout << "Duration : " << searchVec[i].getDuration() << endl;
                    cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                    cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                    cout << "Release: " << searchVec[i].getRelease() << endl;
                    cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                    cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                    cout << endl;
                }
            }
        }
        else if(searchTerm == "nominations" || searchTerm == "Nominations") //same as above for nominations
        {
            cout << "Enter an exact number of nominations (0-14) for your search: " << endl;
            cin >> searchNom;
            for(int i = 0; i < searchVec.size(); i++)
            {
                if(searchVec[i].getNominations() == searchNom)
                {
                    cout << "Name: " <<  searchVec[i].getName() << endl;
                    cout << "Year: " << searchVec[i].getYear() << endl;
                    cout << "Nominations: " << searchVec[i].getNominations() << endl;
                    cout << "Rating: " << searchVec[i].getRating() << endl;
                    cout << "Duration : " << searchVec[i].getDuration() << endl;
                    cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                    cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                    cout << "Release: " << searchVec[i].getRelease() << endl;
                    cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                    cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                    cout << endl;
                }
            }
        }
        else if(searchTerm == "rating" || searchTerm == "Rating") //same as above for rating
        {
            cout << "Enter an exact rating (6.0-9.2) for your search: " << endl;
            cin >> searchRating;
            for(int i = 0; i < searchVec.size(); i++)
            {
                if(searchVec[i].getRating() == searchRating)
                {
                    cout << "Name: " <<  searchVec[i].getName() << endl;
                    cout << "Year: " << searchVec[i].getYear() << endl;
                    cout << "Nominations: " << searchVec[i].getNominations() << endl;
                    cout << "Rating: " << searchVec[i].getRating() << endl;
                    cout << "Duration : " << searchVec[i].getDuration() << endl;
                    cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                    cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                    cout << "Release: " << searchVec[i].getRelease() << endl;
                    cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                    cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                    cout << endl;
                }
            }
        }
        else if(searchTerm == "duration" || searchTerm == "Duration") //same as above for duration
        {
            cout << "Enter an exact duration in minutes (90-238) for your search: " << endl;
            cin >> searchDuration;
            for(int i = 0; i < searchVec.size(); i++)
            {
                if(searchVec[i].getDuration() == searchDuration)
                {
                    cout << "Name: " <<  searchVec[i].getName() << endl;
                    cout << "Year: " << searchVec[i].getYear() << endl;
                    cout << "Nominations: " << searchVec[i].getNominations() << endl;
                    cout << "Rating: " << searchVec[i].getRating() << endl;
                    cout << "Duration : " << searchVec[i].getDuration() << endl;
                    cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                    cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                    cout << "Release: " << searchVec[i].getRelease() << endl;
                    cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                    cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                    cout << endl;
                }
            }
        }
        else if(searchTerm == "genre 1" || searchTerm == "Genre 1") //same as above for genre1
        {
            cout << "Enter an exact genre 1 name for your search: " << endl;
            getline(cin, searchGenre1);
            for(int i = 0; i < searchVec.size(); i++)
            {
                if(searchVec[i].getGenre1() == searchGenre1)
                {
                    cout << "Name: " <<  searchVec[i].getName() << endl;
                    cout << "Year: " << searchVec[i].getYear() << endl;
                    cout << "Nominations: " << searchVec[i].getNominations() << endl;
                    cout << "Rating: " << searchVec[i].getRating() << endl;
                    cout << "Duration : " << searchVec[i].getDuration() << endl;
                    cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                    cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                    cout << "Release: " << searchVec[i].getRelease() << endl;
                    cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                    cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                    cout << endl;
                }
            }
        }
        else if(searchTerm == "genre 2" || searchTerm == "Genre 2") //same as above for genre2
        {
            cout << "Enter an exact genre 2 name for your search: " << endl;
            getline(cin, searchGenre2);
            for(int i = 0; i < searchVec.size(); i++)
            {
                if(searchVec[i].getGenre2() == searchGenre2)
                {
                    cout << "Name: " <<  searchVec[i].getName() << endl;
                    cout << "Year: " << searchVec[i].getYear() << endl;
                    cout << "Nominations: " << searchVec[i].getNominations() << endl;
                    cout << "Rating: " << searchVec[i].getRating() << endl;
                    cout << "Duration : " << searchVec[i].getDuration() << endl;
                    cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                    cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                    cout << "Release: " << searchVec[i].getRelease() << endl;
                    cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                    cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                    cout << endl;
                }
            }
        }
        else if(searchTerm == "release" || searchTerm == "Release") //same as above for release
        {
            cout << "Enter an exact release month for your search: " << endl;
            getline(cin, searchRelease);
            for(int i = 0; i < searchVec.size(); i++)
            {
                if(searchVec[i].getRelease() == searchRelease)
                {
                    cout << "Name: " <<  searchVec[i].getName() << endl;
                    cout << "Year: " << searchVec[i].getYear() << endl;
                    cout << "Nominations: " << searchVec[i].getNominations() << endl;
                    cout << "Rating: " << searchVec[i].getRating() << endl;
                    cout << "Duration : " << searchVec[i].getDuration() << endl;
                    cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                    cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                    cout << "Release: " << searchVec[i].getRelease() << endl;
                    cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                    cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                    cout << endl;
                }
            }
        }
        else if(searchTerm == "metacritic" || searchTerm == "Metacritic") //same as above for metacritic
        {
            cout << "Enter an exact metacritic score (0-100) for your search. Note that earlier titles have no score and are listed as 0: " << endl;
            cin >> searchMeta;
            for(int i = 0; i < searchVec.size(); i++)
            {
                if(searchVec[i].getMetacritic() == searchMeta)
                {
                    cout << "Name: " <<  searchVec[i].getName() << endl;
                    cout << "Year: " << searchVec[i].getYear() << endl;
                    cout << "Nominations: " << searchVec[i].getNominations() << endl;
                    cout << "Rating: " << searchVec[i].getRating() << endl;
                    cout << "Duration : " << searchVec[i].getDuration() << endl;
                    cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                    cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                    cout << "Release: " << searchVec[i].getRelease() << endl;
                    cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                    cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                    cout << endl;
                }
            }
        }
        else
            {
            cout << "Please enter a listed field to do an 'exact' search by." << endl; //else, error message reporting bad input
            return;
            }



}
void partSearchActor(string searchTerm, BSTree<Actor, string> &tree)
{
    vector<Actor> searchVec; //use another vector to execute the exact search
    searchVec = tree.TreeToVec(searchVec); //transfer info from tree to vector



    string searchName;
    string searchAward;  //user input variables, only searchable fields are ones that contain strings. integer partial searches wouldn't make much sense.
    string searchFilm;


    if(searchTerm == "name" || searchTerm == "Name") //checking for user input of search field for specified categories
    {
        cout << "Enter an partial part of a name for your search: (searches are case sensitive) " << endl;
        getline(cin, searchName);

        for(int i = 0; i < searchVec.size(); i++) //iterating through the vector
        {
            if(searchVec[i].getName().find(searchName) != string::npos) //seeing if any element(s) in the vector match the user input partially using string::npos referenced from http://www.cplusplus.com/reference/string/string/npos/
            {                                                               // as well as the string find function.
                cout << "Year: " << searchVec[i].getYear() << endl; //if so, output the result(s) to the user
                cout << "Award: " << searchVec[i].getAward() << endl;
                if(searchVec[i].getWinner() == 0)
                {
                    cout << "Winner: No" << endl;
                }
                else
                {
                    cout << "Winner: Yes" << endl;
                }
                cout << "Name: " << searchVec[i].getName() << endl;
                cout << "Film: " << searchVec[i].getFilm() << endl;
                cout << endl;
            }
        }
    }
    else if(searchTerm == "award" || searchTerm == "Award") //same as above for the award category
    {
        cout << "Enter a partial part of an award name for your search: (searches are case sensitive) " << endl;
        getline(cin, searchAward);
        for(int i = 0; i < searchVec.size(); i++)
        {
            if(searchVec[i].getAward().find(searchAward) != string::npos)
            {
                cout << "Year: " << searchVec[i].getYear() << endl;
                cout << "Award: " << searchVec[i].getAward() << endl;
                if(searchVec[i].getWinner() == 0)
                {
                    cout << "Winner: No" << endl;
                }
                else
                {
                    cout << "Winner: Yes" << endl;
                }
                cout << "Name: " << searchVec[i].getName() << endl;
                cout << "Film: " << searchVec[i].getFilm() << endl;
                cout << endl;
            }
        }
    }
    else if(searchTerm == "film" || searchTerm == "Film") //same as above for the film category
    {
        cout << "Enter a partial part of a film name for your search: (searches are case sensitive) " << endl;
        getline(cin, searchFilm);
        for(int i = 0; i < searchVec.size(); i++)
        {
            if(searchVec[i].getFilm().find(searchFilm) != string::npos)
            {
                cout << "Year: " << searchVec[i].getYear() << endl;
                cout << "Award: " << searchVec[i].getAward() << endl;
                if(searchVec[i].getWinner() == 0)
                {
                    cout << "Winner: No" << endl;
                }
                else
                {
                    cout << "Winner: Yes" << endl;
                }
                cout << "Name: " << searchVec[i].getName() << endl;
                cout << "Film: " << searchVec[i].getFilm() << endl;
                cout << endl;
            }
        }
    }
    else {
        cout << "Please enter a listed valid field to do an 'contains' search by." << endl; //else, error message reporting bad input
        return;
    }
}
void partSearchMovie(string searchTerm, BSTree<Movie, string> &tree)
{
    vector<Movie> searchVec; //use another vector to execute the exact search
    searchVec = tree.TreeToVec(searchVec); //transfer info from tree to vector


                            //user input variables, only searchable fields are ones that contain strings. integer partial searches wouldn't make much sense in this case.
    string searchGenre1;
    string searchGenre2;
    string searchRelease;
    string searchSynopsis;

    if(searchTerm == "genre 1" || searchTerm == "Genre 1") //checking for user input of search field for specified categories
    {
        cout << "Enter a partial genre 1 name for your search: (searches are case sensitive)" << endl;
        getline(cin, searchGenre1);
        for(int i = 0; i < searchVec.size(); i++) //iterating through the vector
        {
            if(searchVec[i].getGenre1().find(searchGenre1) != string::npos) //seeing if any element(s) in the vector match the user input partially using string::npos referenced from http://www.cplusplus.com/reference/string/string/npos/
            {                                                               //in conjunction with the string find function
                cout << "Name: " <<  searchVec[i].getName() << endl;
                cout << "Year: " << searchVec[i].getYear() << endl;
                cout << "Nominations: " << searchVec[i].getNominations() << endl;
                cout << "Rating: " << searchVec[i].getRating() << endl;
                cout << "Duration : " << searchVec[i].getDuration() << endl;
                cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                cout << "Release: " << searchVec[i].getRelease() << endl;
                cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                cout << endl;
            }
        }
    }
    else if(searchTerm == "genre 2" || searchTerm == "Genre 2") //same as above for genre2
    {
        cout << "Enter a partial genre 2 name for your search: (searches are case sensitive)" << endl;
        getline(cin, searchGenre2);
        for(int i = 0; i < searchVec.size(); i++)
        {
            if(searchVec[i].getGenre2().find(searchGenre2) != string::npos)
            {
                cout << "Name: " <<  searchVec[i].getName() << endl;
                cout << "Year: " << searchVec[i].getYear() << endl;
                cout << "Nominations: " << searchVec[i].getNominations() << endl;
                cout << "Rating: " << searchVec[i].getRating() << endl;
                cout << "Duration : " << searchVec[i].getDuration() << endl;
                cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                cout << "Release: " << searchVec[i].getRelease() << endl;
                cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                cout << endl;
            }
        }
    }
    else if(searchTerm == "release" || searchTerm == "Release") //same as above for release
    {
        cout << "Enter a partial name of a release month for your search: (searches are case sensitive)" << endl;
        getline(cin, searchRelease);
        for(int i = 0; i < searchVec.size(); i++)
        {
            if(searchVec[i].getRelease().find(searchRelease) != string::npos)
            {
                cout << "Name: " <<  searchVec[i].getName() << endl;
                cout << "Year: " << searchVec[i].getYear() << endl;
                cout << "Nominations: " << searchVec[i].getNominations() << endl;
                cout << "Rating: " << searchVec[i].getRating() << endl;
                cout << "Duration : " << searchVec[i].getDuration() << endl;
                cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                cout << "Release: " << searchVec[i].getRelease() << endl;
                cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                cout << endl;
            }
        }
    }
    else if(searchTerm == "synopsis" || searchTerm == "Synopsis") //same as above for synopsis
    {
        cout << "Enter a partial part of any synopsis for your search: (searches are case sensitive) " << endl;
        cin >> searchSynopsis;
        for(int i = 0; i < searchVec.size(); i++)
        {
            if(searchVec[i].getSynopsis().find(searchSynopsis) != string::npos)
            {
                cout << "Name: " <<  searchVec[i].getName() << endl;
                cout << "Year: " << searchVec[i].getYear() << endl;
                cout << "Nominations: " << searchVec[i].getNominations() << endl;
                cout << "Rating: " << searchVec[i].getRating() << endl;
                cout << "Duration : " << searchVec[i].getDuration() << endl;
                cout << "Genre 1: " << searchVec[i].getGenre1() << endl;
                cout << "Genre 2: "<< searchVec[i].getGenre2() << endl;
                cout << "Release: " << searchVec[i].getRelease() << endl;
                cout << "Metacritic Score: " << searchVec[i].getMetacritic() << endl;
                cout << "Synopsis: " << searchVec[i].getSynopsis() << endl;
                cout << endl;
            }
        }
    }
    else
    {
        cout << "Please enter a listed field to do an 'contains' search by." << endl; //else, error message reporting bad input
        return;
    }


}

void printActors(ofstream& outfile, BSTree<Actor, string> &tree)
{
    vector<Actor> actorvec;
    actorvec = tree.TreeToVec(actorvec); //converting tree to vector once again

    for(int i = 0; i < actorvec.size(); i++) //iterating through vector
    {
        outfile << "Year: " << actorvec[i].getYear() << endl;
        outfile << "Award: " << actorvec[i].getAward() << endl; //getting each actor object into the outfile separated by a newline
        if(actorvec[i].getWinner() == 0)
        {
            outfile << "Winner: No" << endl;
        }
        else
        {
            outfile << "Winner: Yes" << endl;
        }
        outfile << "Name: " << actorvec[i].getName() << endl;
        outfile << "Film: " << actorvec[i].getFilm() << endl;
        outfile << endl;
    }
}

void printMovies(ofstream& outfile, BSTree<Movie, string> &tree)
{
    vector<Movie> movievec;
    movievec = tree.TreeToVec(movievec); //converting tree info to vector

    for(int i = 0; i < movievec.size(); i++) //iterating through vector
    {
        outfile << "Name: " <<  movievec[i].getName() << endl;
        outfile << "Year: " << movievec[i].getYear() << endl;
        outfile << "Nominations: " << movievec[i].getNominations() << endl; //getting each movie object into the outfile separated by a newline
        outfile << "Rating: " << movievec[i].getRating() << endl;
        outfile << "Duration : " << movievec[i].getDuration() << endl;
        outfile << "Genre 1: " << movievec[i].getGenre1() << endl;
        outfile << "Genre 2: "<< movievec[i].getGenre2() << endl;
        outfile << "Release: " << movievec[i].getRelease() << endl;
        outfile << "Metacritic Score: " << movievec[i].getMetacritic() << endl;
        outfile << "Synopsis: " << movievec[i].getSynopsis() << endl;
        outfile << endl;
    }
}
