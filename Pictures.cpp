//
// Created by Ravisher Singh on 12/10/20.
//
#include "Pictures.h"
void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while (clock() - start < a)
    {

    }
}


// this will load all the data into database
void loadPicturesTree(BST<string , Pictures> *&pictures_database) {

    fstream fin;
    fin.open("pictures.csv");


    string tempName;
    string tempYear;
    string tempNominations;
    string tempRating;
    string tempDuration;
    string tempGenre1;
    string tempGenre2;
    string tempRelease;
    string tempMetacritic;
    string tempSynopsis;

    string line;

    int cnt = 0;
    bool ok = false;
    while (getline(fin , line))
    {
        if (!ok) {ok = true; continue ; }

        stringstream ss(line);
        getline(ss , tempName , ',');
        getline(ss , tempYear , ',');
        getline(ss , tempNominations , ',');
        getline(ss , tempRating , ',');
        getline(ss , tempDuration , ',');
        getline(ss , tempGenre1 , ',');
        getline(ss , tempGenre2 , ',');
        getline(ss , tempRelease , ',');
        getline(ss , tempMetacritic , ',');
        getline(ss , tempSynopsis , '\n');

        Pictures picture;
        picture.name = tempName;
        /*
         *https://www.geeksforgeeks.org/converting-strings-numbers-cc/
         */
        stringstream ss1(tempYear);
        int year = 0;
        ss1 >> year;
        picture.year = year;

        //nominations

        stringstream ss2(tempNominations);
        int nominations = 0;
        ss2 >> nominations;
        picture.nominations = nominations;
        //rating
        stringstream ss3(tempRating);
        double ratings = 0.0;
        ss3 >> ratings;
        picture.ratings = ratings;
        //duration
        stringstream ss4(tempDuration);
        int duration = 0;
        ss4 >> duration;
        picture.duration = duration;

        picture.genre1 = tempGenre1;
        picture.genre2 = tempGenre2;
        picture.release = tempRelease;
        // metaCritic
        stringstream ss5(tempMetacritic);
        int metaCritic = 0;
        ss5 >> metaCritic;
        picture.metacritic = metaCritic;

        picture.synopsis = tempSynopsis;

        pictures_database->insert(picture.name, picture); //adding to database

        cnt++;

    }


    fin.close();
}


//display the main menu within the pictures database
void picturesMenu(BST<string, Pictures> *&pictures_database)
{
    int choice  = 0;
    char buffer = 0;
    while (choice != 9)
    {
        cout << "Welcome to picture database.\n\n";
        cout << "Press 1 to add a record.\n";
        cout << "Press 2 to search a record of picture by name and modify the fields.\n";
        cout << "Press 3 to sort a  record of picture and print the database by any field.\n";
        cout << "Press 4 to do  a complete search on any field.\n";
        cout << "Press 5 to do  a partial search on any field.\n";
        cout << "Press 6 to add picture database to a new csv file\n";
        cout << "Press 7 to print updated picture database\n";
        cout << "Press 8 to return to main menu.\n";
        cout << "Press 9 Exit\n";

        cin >> buffer;
        choice = buffer - '0';

        if (choice < 1 || choice > 9)
        {
            cout << "Please enter a valid choice\n\n";
        }
        else if (choice == 1)
        {
            addRecord(pictures_database);

            cout << "Record added successfully\n\n";
            cout << "Taking you back to the pictures menu in 2 seconds\n\n";
            delay(2000);
        }
        else if (choice == 2)
        {
            cout << "enter the name of movie you want to search \n";
            string tname ;
            cin.ignore();
            getline(cin , tname);
            string t = " ";
            string ss  = t + tname;

            pair<bool , Node<string , Pictures>*> found = pictures_database->search(ss , pictures_database->root);

            if (found.first == false)cout << "the entered movie doesn't exist\n";
            else
            {
                cout << "the entered movie is present in the database \n\n";
                cout << "do you want to modify any details ?\n";

                int x ;
                cout << "enter 0 if you don't want to modify the details and 1 if you  want to modify\n";
                cin >> x;

                while (x != 0  && x != 1 )
                {
                    cout << "please enter valid input\n";
                    cout << "enter 0 if you don't  want to modify the details and 1 if you  want to modify\n";
                    cin >> x;
                }

                if (x == 0)
                {
                    cout << "Taking you back to the pictures menu in 2 seconds\n\n";
                    delay(2000);
                }
                else if (x == 1)
                {
                    modifyField(found.second , pictures_database);
                }

            }

        }
        else if (choice == 3)
        {
            int choice = 0;
            char buffer3 = 0;
            while (choice != 5)
            {
                cout << "Press 1 to see movie names sorted by name\n";
                cout << "Press 2 to see movie names sorted by release year\n";
                cout << "Press 3 to see movie names sorted by rating\n";
                cout << "Press 4 to see movie names sorted by duration\n";
                cout << "Press 5 to return to pictures menu\n";

                cin >> buffer3;
                choice = buffer3 - '0';
                if (choice < 1 || choice > 5)
                {
                    cout << "Please enter a valid choice\n\n";
                }
                else if (choice == 1)
                {
                    displayTreeInorder(pictures_database->root);
                    cout << '\n';
                    cout << "Taking you back to the pictures menu in 2 seconds\n\n";
                    delay(2000);
                }
                else if (choice == 2)
                {
                    map<int, vector<string>> mp = sortByYear(pictures_database);
                    for (auto i : mp)
                    {
                        cout << "year : " << i.first << '\n';
                        for (auto j : i.second )
                        {
                            cout << j << '\n';
                        }
                        cout << '\n';
                    }
                    cout << "Taking you back to the pictures menu in 2 seconds\n\n";
                    delay(2000);
                }
                else if (choice == 3)
                {
                    map<double, vector<string>> mp = sortByRating(pictures_database);
                    for (auto i : mp)
                    {
                        cout << "rating : " << i.first << '\n';
                        for (auto j : i.second)
                        {
                            cout << j << '\n';
                        }
                        cout << '\n';
                    }

                    cout << '\n';

                }
                else if (choice == 4)
                {

                    map<int, vector<string>> mp = sortByDuration(pictures_database);
                    for (auto i : mp)
                    {
                        cout << "duration : " << i.first << '\n';
                        for (auto j : i.second)
                        {
                            cout << j << '\n';
                        }
                        cout << '\n';
                    }
                    cout << '\n';
                }
                else if (choice == 5)
                {
                    cout << "Taking you back to the pictures menu in 2 seconds\n\n";
                    delay(2000);
                }
            }


        }
        else if (choice == 4)
        {
            int choice  = 0;
            char buffer4 = 0;
            while (choice != 5)
            {
                cout << "Press 1 if you want to do a full search by name\n";
                cout << "Press 2 if you want to do a full search by year\n";
                cout << "Press 3 if you want to do a full search by Genre\n";
                cout << "Press 4 if you want to do a full search by rating\n";
                cout << "Press 5 to return to pictures menu \n";

                cin >> buffer4;
                choice = buffer4 - '0';
                if (choice < 1 || choice > 5)
                {
                    cout << "please enter a valid choice\n";
                }
                else if (choice == 1)
                {
                    fullSearchByName(pictures_database);
                }
                else if (choice == 2)
                {
                    fullSearchByYear(pictures_database);
                }
                else if (choice == 3)
                {
                    fullSearchByGenre(pictures_database);
                }
                else if (choice == 4)
                {
                    fullSearchByRatings(pictures_database);
                }
                else if (choice == 5)
                {
                    cout << "taking you back to the pictures menu in 2 seconds\n";
                    delay(2000);
                }


            }

        }
        else if (choice == 5)
        {

            int choice = 0;
            char buffer5 = 0;
            while (choice != 3 )
            {
                cout << "Press 1 if you want to do a partial search by name\n";
                cout << "Press 2 if you want to do a partial search by genre\n";
                cout << "Press 3 to return to pictures menu\n";

                cin >> buffer5;
                choice = buffer5 - '0';
                if (choice < 1 || choice > 3)
                {
                    cout << "Please enter a valid input\n\n";
                }
                else if (choice == 1)
                {
                    partialSearchByName(pictures_database);
                }
                else if (choice == 2)
                {
                    partialSearchByGenre(pictures_database);
                }
                else if (choice == 3)
                {
                    cout << "taking you back to the pictures menu in 2 seconds\n";
                    delay(2000);
                }
            }

        }
        else if (choice == 6)
        {
            cout << "writing data to csv file....\n\n";
            writeToCSV(pictures_database);
            cout << "CSV write successful\n\n";

            cout << "Taking you back to the pictures menu in 2 seconds\n\n";
            delay(2000);

        }
        else if (choice == 7)
        {
            cout << "The database consists of the following movies :\n\n";
            delay(1500);
            if (pictures_database->root == NULL)
                cout << "The Database is empty\n\n";
            else
            {
                displayTreeInorder(pictures_database->root);
                cout << '\n';
            }

            cout << "Taking you back to the pictures menu in 2 seconds\n\n";
            delay(2000);

        }
        else if (choice == 8)
        {
            cout << "Taking you back to the main menu in 2 seconds\n";
            delay(2000);
            break;
        }
        else if (choice == 9)
        {
            cout << "you have decided to exit ... bye bye \n";
            delay(2000);
            exit(0);
        }


    }

}


//print entire tree in order
void displayTreeInorder(Node<string , Pictures> *t)
{
    if (t == NULL)return;

    displayTreeInorder(t->left);
    cout << t->key << '\n';
    // cout << "  " << t->data.name << " " << t->data.year << " ";
    // cout << t->data.nominations << " " << t->data.year << " " << t->data.ratings;
    // cout << " " << t->data.duration << " " << t->data.year << " " << t->data.genre1;
    // cout << " " << t->data.genre2 << " " << t->data.release << " ";
    // cout << t->data.metacritic << " " << t->data.synopsis << '\n' << '\n';
    displayTreeInorder(t->right);
}

//Obtain the info from user and add to the tree
void addRecord(BST<string, Pictures> *&pictures_database)
{
    cout << "enter the details for the record you want to add to the database\n\n";

    cout << "enter the name\n";
    string tname;
    cin.ignore();
    getline(cin , tname);

    int tyear;
    cout << "enter the year\n";
    cin >> tyear;

    int tnominations;
    cout << "enter the nominations\n";
    cin >> tnominations;

    double tratings;
    cout << "enter the ratings on a scale of  0 - 10 \n";
    cin >> tratings;

    while (tratings < 0 || tratings > 10)
    {
        cout << "please enter a correct response\n\n";
        cout << "enter the ratings on a scale of  0 - 10 \n";
        cin >> tratings;
    }

    int tduration;
    cout << "enter the duration\n";
    cin >> tduration;

    string tgenre1;
    cout << "enter genre1\n";
    cin >> tgenre1;

    string tgenre2;
    cout << "enter genre2\n";
    cin >> tgenre2;

    string trelease;
    cout << "enter the release month\n";
    cin >> trelease;

    int tmetacritic;
    cout << "enter the metacritic score on a scale of 0 - 100\n";
    cin >> tmetacritic;

    string tsynopsis;
    cout << "enter the movie synopsis\n";
    cin >> tsynopsis;

    Pictures p;
    string temp = " ";
    p.name = temp + tname;
    p.year = tyear;
    p.nominations = tnominations;
    p.ratings = tratings;
    p.duration = tduration;
    p.genre1 = tgenre1;
    p.genre2 = tgenre2;
    p.release = trelease;
    p.metacritic = tmetacritic;
    p.synopsis = tsynopsis;

    pictures_database->insert(p.name , p);

}

// function to modify any specific field
void modifyField(Node<string , Pictures> *t  , BST<string, Pictures> *&pictures_database)
{
    int choice = 0 ;
    char buffer = 0 ;
    while (choice != 11)
    {
        cout << " Which field you want to modify?" << endl;
        cout << "1:Name\n";
        cout << "2:Year\n";
        cout << "3:Total Nominations\n";
        cout << "4:Rating\n";
        cout << "5:Duration\n";
        cout << "6:Genre 1\n";
        cout << "7:Genre 2\n";
        cout << "8:Release Month\n";
        cout << "9:Meta Critic Score\n";
        cout << "10:Synopsis\n";
        cout << "11:Return \n";

        cin >> buffer;
        choice = buffer - '0';

        if (choice < 1 || choice > 11)
        {
            cout << "please enter a valid choice\n";
        }
        else if (choice == 1)
        {
            Pictures p = t->data;
            string oldName = p.name;
            cout << "enter new name\n";
            string tname ;
            cin.ignore();
            getline(cin , tname);
            string te = " ";
            string newName = te + tname;

            // first remove the node corresponding to the given name and insert a new node with updated name
            pictures_database->remove(oldName);

            p.name = newName;
            pictures_database->insert(newName , p );


            cout << "the name has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);

        }
        else if (choice == 2)
        {
            cout << "enter year\n";
            int tyear;
            cin >> tyear;
            t->data.year = tyear;
            cout << "the year has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);
        }
        else if (choice == 3)
        {
            cout << "enter the number of nominations\n";
            int tnom ;
            cin >> tnom;
            t->data.nominations = tnom;
            cout << "the nominations has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);

        }
        else if (choice == 4)
        {
            cout << "enter the rating on a scale of 1-10\n";
            double trating;
            cin >> trating;
            t->data.ratings = trating;
            cout << "the ratings has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);
        }
        else if (choice == 5)
        {
            cout << "enter the movie duration\n";
            int tduration;
            cin >> tduration;
            t->data.duration = tduration;
            cout << "the duration has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);

        }
        else if (choice == 6)
        {
            cout << "enter the genre1 name\n";
            string tgen1;
            cin >> tgen1;
            t->data.genre1 = tgen1;
            cout << "the genre1 has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);

        }
        else if (choice == 7)
        {
            cout << "enter the genre2 name\n";
            string tgen2;
            cin >> tgen2;
            t->data.genre2 = tgen2;
            cout << "the genre2 has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);

        }
        else if (choice == 8)
        {
            cout << "enter the release month\n";
            string trelease;
            cin >> trelease;
            t->data.release = trelease;
            cout << "the release has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);
        }
        else if (choice == 9)
        {
            cout << "enter the metacritic score on a scale of 0 - 100\n";
            int tmetacritic;
            cin >> tmetacritic;
            t->data.metacritic = tmetacritic;
            cout << "the metacritic score has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);

        }
        else if (choice == 10)
        {
            cout << "enter the movie synopsis\n";
            string tsynopsis;
            cin >> tsynopsis;
            t->data.synopsis = tsynopsis;
            cout << "the movie synopsis has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay(2000);
        }
        else if (choice == 11)
        {
            cout << "Taking you back to the pictures menu in 2 seconds\n\n";
            delay(2000);
        }
    }

}


map<int , vector<string>> sortByYear(BST<string, Pictures> *&pictures_database)
{
    map<int, vector<string>> moviesByYear;
    sortByYearHelper(pictures_database , moviesByYear , pictures_database->root);

    return moviesByYear;
}

void sortByYearHelper(BST<string, Pictures> *&pictures_database , map<int, vector<string>> &moviesByYear , Node<string , Pictures> *t )
{
    if (t == NULL)return ;

    int yr = t->data.year;
    string movName = t->data.name;

    moviesByYear[yr].push_back(movName);

    sortByYearHelper(pictures_database , moviesByYear , t->left);
    sortByYearHelper(pictures_database , moviesByYear , t->right);

}

map<double , vector<string>> sortByRating(BST<string, Pictures> *&pictures_database)
{
    map<double, vector<string>> moviesByRating;
    sortByRatingHelper(pictures_database , moviesByRating , pictures_database->root);

    return moviesByRating;
}

void sortByRatingHelper(BST<string, Pictures> *&pictures_database , map<double, vector<string>> &moviesByRating , Node<string , Pictures> *t )
{
    if (t == NULL)return ;

    double movRating = t->data.ratings;
    string movName = t->data.name;

    moviesByRating[movRating].push_back(movName);

    sortByRatingHelper(pictures_database , moviesByRating , t->left);
    sortByRatingHelper(pictures_database , moviesByRating , t->right);
}

map<int , vector<string>> sortByDuration(BST<string, Pictures> *&pictures_database)
{
    map<int, vector<string>> moviesByDuration;
    sortByDurationHelper(pictures_database , moviesByDuration , pictures_database->root);

    return moviesByDuration;
}

void sortByDurationHelper(BST<string, Pictures> *&pictures_database , map<int, vector<string>> &moviesByDuration , Node<string , Pictures> *t )
{
    if (t == NULL)return ;

    double movDuration = t->data.duration;
    string movName = t->data.name;

    moviesByDuration[movDuration].push_back(movName);

    sortByDurationHelper(pictures_database , moviesByDuration , t->left);
    sortByDurationHelper(pictures_database , moviesByDuration , t->right);
}

void writeToCSV(BST<string, Pictures> *&pictures_database)
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("picturesDatabaseUpdated.csv", ios::out | ios::app);

    fout << "name" << ", " << "year" << ", " << "nominations" << ", " << "ratings" << ", " << "duration" << ", " << "genre1" << ", " << "genre2" << ", " << "release" << ", " << "metacritic" << ", " << "synopsis" << "\n";

    // Insert the data to file
    inorderWriteCSV(pictures_database->root , fout);

}

void inorderWriteCSV(Node<string, Pictures>* t  , fstream &fout)
{
    if (t == NULL)return;
    inorderWriteCSV(t->left , fout);

    fout << t->data.name << ", " << t->data.year << ", " << t->data.nominations << ", " << t->data.ratings << ", "
         << t->data.duration << ", " << t->data.genre1 << ", " << t->data.genre2 << ", " << t->data.release << ", "
         << t->data.metacritic << ", " << t->data.synopsis << "\n";

    inorderWriteCSV(t->right , fout);

}
//.....................................................................................................


// functions for pictures menu choice 4(complete search)

void inOrderMovieNameSearch(Node<string, Pictures> *t , string movName , vector<Node<string , Pictures> *> &nodes)
{
    if (t == NULL)return;

    if (t->key == movName)nodes.push_back(t);
    else if (movName < t->key)
        return inOrderMovieNameSearch(t->left , movName , nodes);

    return inOrderMovieNameSearch(t->right , movName , nodes);

}

void fullSearchByName(BST<string, Pictures> *&pictures_database)
{
    cout << "enter the complete name of the movie you want to search\n";
    string tname ;
    cin.ignore();
    getline(cin , tname);

    string te = " ";

    string movName = te + tname;

    vector<Node<string , Pictures> *> nodes;

    inOrderMovieNameSearch(pictures_database->root , movName , nodes);

    if (nodes.size() == 0 )
    {
        cout << "Sorry ,  no such movie found\n";
    }
    else
    {
        cout << "Here you are the movies that match the name you entered\n\n";

        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "    " << nodes[i]->data.genre1 << "    " << nodes[i]->data.ratings << '\n';
        }
    }

}


void inOrderMovieYearSearch(Node<string, Pictures> *t , int movYear , vector<Node<string , Pictures> *> &nodes)
{
    if (t == NULL)return;

    if (t->data.year == movYear)nodes.push_back(t);

    inOrderMovieYearSearch(t -> left , movYear , nodes);
    inOrderMovieYearSearch(t->right , movYear , nodes);

}

void fullSearchByYear(BST<string, Pictures> *&pictures_database)
{
    cout << "enter the year for which you want to search the movies\n";
    int tempYear;
    cin >> tempYear;

    vector<Node<string , Pictures> *> nodes;

    inOrderMovieYearSearch(pictures_database->root , tempYear , nodes);

    if (nodes.size() == 0)
    {
        cout << "No movies found for this year\n";
    }
    else
    {
        cout << "Here are the movies for the year : " << tempYear << "\n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "	 " << nodes[i]->data.genre1 << "	" << nodes[i]->data.ratings << '\n';
        }

    }

}



void inOrderMovieGenreSearch(Node<string, Pictures> *t , string movGenre , vector<Node<string , Pictures> *> &nodes)
{
    if (t == NULL)return;

    if (t->data.genre1 == movGenre || t->data.genre2 == movGenre )nodes.push_back(t);

    inOrderMovieGenreSearch(t->left , movGenre , nodes);
    inOrderMovieGenreSearch(t->right , movGenre , nodes);
}

void fullSearchByGenre(BST<string, Pictures> *&pictures_database)
{
    cout << "enter the genre for which you would like to see the movies\n";

    string tempGenre;
    cin.ignore();
    getline(cin , tempGenre);

    vector<Node<string , Pictures> *> nodes;

    inOrderMovieGenreSearch(pictures_database->root , tempGenre , nodes);

    if (nodes.size() == 0)
    {
        cout << "Sorry , no movie for this genre found\n";
    }
    else
    {
        cout << "here the movies for genre : " << tempGenre << "\n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "   " << nodes[i]->data.ratings << '\n';
        }
    }
}


void inOrderMovieRatingSearch(Node<string, Pictures> *t , double movRating , vector<Node<string , Pictures> *> &nodes)
{
    if (t == NULL)return;

    if (t->data.ratings >= movRating)nodes.push_back(t);

    inOrderMovieRatingSearch(t->left , movRating , nodes);
    inOrderMovieRatingSearch(t->right , movRating , nodes);
}

void fullSearchByRatings(BST<string, Pictures> *&pictures_database)
{
    cout << "enter the minimum rating for which you want to see movies\n";

    double tempRating;
    cin >> tempRating;

    vector<Node<string , Pictures> *> nodes;
    inOrderMovieRatingSearch(pictures_database->root , tempRating , nodes);

    if (nodes.size() == 0)
    {
        cout << "Sorry , no movies for the given rating found\n\n";
    }
    else
    {
        cout << "here are the movie having rating greater than : " << tempRating << '\n';
        for (int i = 0  ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "  " << nodes[i]->data.genre1 << "  " << nodes[i]->data.ratings << '\n';
        }
    }




}


//......................................................................................................

// functions for pictures menu choice 5(partial search)

bool search(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            return true;
    }

    return false;
}

void movieNameBSTSearch(Node<string, Pictures> *t , string movName, vector<Node<string , Pictures> *> &nodes)
{
    if (t == NULL)return;

    if (search(movName , t->key))nodes.push_back(t);

    movieNameBSTSearch(t->left , movName , nodes);
    movieNameBSTSearch(t->right , movName , nodes);
}

void partialSearchByName(BST<string, Pictures> *&pictures_database)
{
    cout << "enter the name of movie you wanna search \n";
    string movName;
    cin.ignore();
    getline(cin  , movName);

    vector<Node<string , Pictures> *> nodes;

    movieNameBSTSearch(pictures_database->root , movName  , nodes);

    if (nodes.size() == 0)
    {
        cout << "No movie matches the given provided name\n";
    }
    else
    {
        cout << "The following movies match the provided name\n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "    " << nodes[i]->data.genre1 << "   " << nodes[i]->data.ratings << '\n';
        }
    }

}


void  genreNameBSTSearch(Node<string, Pictures> *t , string genreName, vector<Node<string , Pictures> *> &nodes)
{
    if (t == NULL)return;

    if (search(genreName , t->data.genre1) || search(genreName , t->data.genre2))nodes.push_back(t);

    genreNameBSTSearch(t->left , genreName , nodes);
    genreNameBSTSearch(t->right , genreName , nodes);
}

void partialSearchByGenre(BST<string, Pictures> *&pictures_database)
{
    cout << "enter the genre name you wanna search\n";
    string genreName;
    cin.ignore();
    getline(cin , genreName);

    vector<Node<string , Pictures> *> nodes;

    genreNameBSTSearch(pictures_database->root , genreName , nodes);

    if (nodes.size() == 0)
    {
        cout << "No genre matches the provided name\n";
    }
    else
    {
        cout << "The following movies matches the provided genre \n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            string temp =  search(genreName , nodes[i]->data.genre1) ? nodes[i]->data.genre1  : nodes[i]->data.genre2;
            cout << nodes[i]->key << "   " << nodes[i]->data.ratings << "    " << temp << '\n';
        }
    }

}


//.....................................................................................................

