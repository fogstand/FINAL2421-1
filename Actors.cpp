//
// Created by Ravisher Singh on 12/10/20.
//
#include "Actors.h"

void delay2(clock_t a)
{
    clock_t start;
    start  = clock();
    while (clock() - start < a)
    {

    }
}

void loadActorsTree(BST<string , Actors> *&actors_database)
{

    fstream fin;
    fin.open("actor-actress.csv");



    string tempYear;
    string tempAward;
    string tempIsWinner;
    string tempName;
    string tempFilm;

    string line;

    int cnt = 0;
    bool ok = false;
    while (getline(fin , line))
    {
        if (!ok) {ok = true; continue ; }

        stringstream ss(line);
        getline(ss , tempYear , ',');
        getline(ss , tempAward , ',');
        getline(ss , tempIsWinner , ',');
        getline(ss , tempName , ',');
        getline(ss , tempFilm , '\n');

        Actors actor;

        /*
         *https://www.geeksforgeeks.org/converting-strings-numbers-cc/
         */
        stringstream ss1(tempYear);
        int year = 0;
        ss1 >> year;
        actor.year = year;

        actor.award = tempAward;

        stringstream ss2(tempIsWinner);
        int isWinner;
        ss2 >> isWinner;
        actor.isWinner = true ? isWinner == 1 : 0;

        actor.name = tempName;
        actor.film = tempFilm;

        actors_database->insert(actor.name, actor); //adding to database

        cnt++;

    }


    fin.close();
}

void actorsMenu(BST<string, Actors> *&actors_database)
{
    int choice  = 0;
    char buffer = 0;
    while (choice != 9)
    {
        cout << "Welcome to actor database.\n\n";
        cout << "Press 1 to add a record.\n";
        cout << "Press 2 to search a record of actor by name and modify the fields.\n";
        cout << "Press 3 to sort a  record of actor and print the database by any field.\n";
        cout << "Press 4 to do  a complete search on any field.\n";
        cout << "Press 5 to do  a partial search on any field.\n";
        cout << "Press 6 to add actor database to a new csv file\n";
        cout << "Press 7 to print updated actor database\n";
        cout << "Press 8 to return to main menu.\n";
        cout << "Press 9 Exit\n\n";

        cin >> buffer;
        choice = buffer - '0';

        if (choice < 1 || choice > 9)
        {
            cout << "Please enter a valid choice\n\n";
        }
        else if (choice == 1)
        {
            addRecord(actors_database);

            cout << "Record added successfully\n\n";
            cout << "Taking you back to the actors menu in 2 seconds\n\n";
            delay2(2000);

        }
        else if (choice == 2)
        {
            cout << "enter the name of actor you wanna modify \n";
            string tempName;
            cin.ignore();
            getline(cin , tempName);

            pair<bool , Node<string , Actors>*> found = actors_database->search(tempName , actors_database->root);
            if (found.first == false)cout << "the entered actor doesn't exist\n";
            else
            {
                cout << "the entered actor is present in the database \n\n";
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
                    cout << "Taking you back to the actors menu in 2 seconds\n\n";
                    delay2(2000);
                }
                else if (x == 1)
                {
                    modifyField(found.second , actors_database);
                }

            }

        }
        else if (choice == 3)
        {
            int choice3 = 0 ;
            char buffer3 = 0;
            while (choice3 != 4)
            {
                cout << "Press 1 to see actors sorted by name\n";
                cout << "Press 2 to see actors sorted by year\n";
                cout << "Press 3 to see actors sorted by award\n";
                cout << "Press 4 to return to actors menu\n";

                cin >> buffer3;
                choice3 = buffer3 - '0';

                if (choice3 < 1 || choice3 > 4)
                {
                    cout << "Please enter a valid choice\n";
                }
                else if (choice3 == 1)
                {
                    nameSorted(actors_database);
                }
                else if (choice3 == 2)
                {
                    yearSorted(actors_database);
                }
                else if (choice3 == 3)
                {
                    awardSorted(actors_database);
                }
                else if (choice3 == 4)
                {
                    cout << "Taking you back to the actors menu in 2 seconds\n";
                    delay2(2000);
                }
            }

        }
        else if (choice == 4)
        {
            int choice4 = 0;
            char buffer4 = 0;

            while (choice4 != 4)
            {
                cout << "Press 1 to do a complete search by name\n";
                cout << "Press 2 to do a complete search by award\n";
                cout << "Press 3 to do a complete search by movie name\n";
                cout << "Press 4 to return to actor menu\n";

                cin >> buffer4;
                choice4 = buffer4 - '0';

                if (choice4 < 1 || choice4 > 4)
                {
                    cout << "Please enter a valid response\n";
                }
                else if (choice4 == 1)
                {
                    fullSearchByName(actors_database);

                }
                else if (choice4 == 2)
                {
                    fullSearchByAward(actors_database);

                }
                else if (choice4 == 3)
                {
                    fullSearchByMovie(actors_database);
                }
                else if (choice4 == 4)
                {
                    cout << "Taking you back to actor menu in 2 seconds\n";
                    delay2(2000);
                }
            }

        }
        else if (choice == 5)
        {
            int choice5 = 0;
            char buffer5 = 0;

            while (choice5 != 4)
            {
                cout << "Press 1 to do a partial search by name\n";
                cout << "Press 2 to do a partial search by award\n";
                cout << "Press 3 to do a partial search by movie name\n";
                cout << "Press 4 to return to actors menu\n";

                cin >> buffer5;
                choice5 = buffer5 - '0';

                if (choice5 < 1 || choice5 > 4)
                {
                    cout << "Please enter a valid choice\n\n";
                }
                else if (choice5 == 1)
                {
                    partialSearchByName(actors_database);
                }
                else if (choice5 == 2)
                {
                    partialSearchByAward(actors_database);
                }
                else if (choice5 == 3)
                {
                    partialSearchByMovie(actors_database);
                }
                else if (choice5 == 4)
                {
                    cout << "taking you back to actors menu in 2 seconds \n";
                    delay2(2000);
                }
            }

        }
        else if (choice == 6)
        {
            cout << "Writing data to CSV file\n\n";
            writeToCSV(actors_database);
            cout << "CSV write successful !\n\n";

            cout << "Taking you back to the actors menu in 2 seconds\n\n";
            delay2(2000);
        }
        else if (choice == 7)
        {
            cout << "The database consists of the following actors :\n\n";
            delay2(1000);
            if (actors_database->root == NULL)
                cout << "The Database is empty\n\n";
            else
            {
                displayTreeInorder(actors_database->root);
                cout << '\n';
            }
            cout << "Taking you back to the actors menu in 2 seconds\n\n";
            delay2(2000);
        }
        else if (choice == 8)
        {
            cout << "Taking you back to the main menu in 2 seconds\n";
            delay2(2000);
            break;
        }
        else if (choice == 9)
        {
            cout << "you have decided to exit ... bye bye \n";
            delay2(2000);
            exit(0);
        }


    }

}

void addRecord(BST<string, Actors> *&actors_database)
{
    cout << "enter the details for the record you wanna  add\n\n";
    cout << "enter the year\n";
    int tempYear ;
    cin >> tempYear;

    cout << "enter the award name\n";
    string tempAward;
    cin.ignore();
    getline(cin , tempAward);

    cout << "enter 1 if actor had won an award otherwise enter 0\n";
    int x = 3 ;
    cin >> x;

    while (x != 0 && x != 1 )
    {
        cout << "Please enter a valid input\n";
        cout << "enter 1 if actor had won an award otherwise enter 0\n";
        cin >> x;
    }

    cout << "enter the name of actor or actress\n";
    string tempName;
    cin.ignore();
    getline(cin , tempName);

    cout << "enter the film name\n";
    string tempFilm;
    cin.ignore();
    getline(cin , tempFilm);

    Actors actor;
    actor.year = tempYear;
    actor.award = tempAward;
    actor.isWinner = true ? x == 1 : 0;
    actor.name = tempName;
    actor.film = tempFilm;

    actors_database->insert(actor.name , actor);

}


//print entire tree in order
void displayTreeInorder(Node<string , Actors> *t)
{
    if (t == NULL)return;

    displayTreeInorder(t->left);
    cout << t->key << "                  " << t->data.film << '\n';

    displayTreeInorder(t->right);
}


void writeToCSV(BST<string, Actors> *&actors_database)
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("actorsDatabaseUpdated.csv", ios::out | ios::app);

    fout << "year" << ", " << "award" << ", " << "winner" << ", " << "name" << ", " << "film" << "\n";

    // Insert the data to file
    inorderWriteCSV(actors_database->root , fout);

}

void inorderWriteCSV(Node<string, Actors>* t  , fstream &fout)
{
    if (t == NULL)return;
    inorderWriteCSV(t->left , fout);

    fout << t->data.year << ", " << t->data.award << ", " << t->data.isWinner << ", " << t->data.name << ", " << t->data.film << "\n";

    inorderWriteCSV(t->right , fout);

}



//.............................................................................

//function for choice4(complete search)

void actorNameFullBSTSearch(Node<string  , Actors>* t, string actorName , vector<Node<string , Actors> *> &nodes)
{
if (t == NULL)return;

if (t->key  == actorName)nodes.push_back(t);

actorNameFullBSTSearch(t->left , actorName , nodes);
actorNameFullBSTSearch(t->right , actorName , nodes);

}

void fullSearchByName(BST<string, Actors> *&actors_database)
{
    cout << "enter the complete name of actor you wanna search\n";
    string tempName;
    cin.ignore();
    getline(cin , tempName);

    vector<Node<string , Actors> *> nodes;

    actorNameFullBSTSearch(actors_database->root , tempName , nodes);

    if (nodes.size() == 0)
    {
        cout << "no actor matches the provided name\n";
    }
    else
    {
        cout << "The following actors match the provided name\n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "     " << nodes[i]->data.award << "    " << nodes[i]->data.film << '\n';
        }
    }

}

void awardNameFullBSTSearch(Node<string  , Actors>* t, string awdName , vector<Node<string , Actors> *> &nodes)
{
if (t == NULL)return;

if (t->data.award == awdName)nodes.push_back(t);

awardNameFullBSTSearch(t->left , awdName , nodes);
awardNameFullBSTSearch(t->right , awdName , nodes);
}

void fullSearchByAward(BST<string, Actors> *&actors_database)
{
    cout << "enter the award name for which you want to see actors\n";
    string awdName;
    cin.ignore();
    getline(cin , awdName);

    vector<Node<string , Actors> *> nodes;

    awardNameFullBSTSearch(actors_database->root , awdName , nodes);

    if (nodes.size() == 0)
    {
        cout << "no actor had won the provided award\n";
    }
    else
    {
        cout << "The following actors had won the provided award : " << awdName << "\n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "     " << nodes[i]->data.film << '\n';
        }
    }


}

void movieNameFullBSTSearch(Node<string  , Actors>* t, string movName , vector<Node<string , Actors> *> &nodes)
{
if (t == NULL)return;

if (t->data.film == movName)nodes.push_back(t);

movieNameFullBSTSearch(t->left , movName  , nodes);
movieNameFullBSTSearch(t->right , movName  , nodes);
}

void fullSearchByMovie(BST<string, Actors> *&actors_database)
{
    cout << "enter the movie name for which you want to search actors\n";
    string movName;
    cin.ignore();
    getline(cin , movName);

    vector<Node<string , Actors> *> nodes;

    movieNameFullBSTSearch(actors_database->root , movName , nodes);

    if (nodes.size() == 0)
    {
        cout << "no actor found for the provided movie\n";
    }
    else
    {
        cout << "The following actors found for the provided movie  : " << movName << "\n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "     " << nodes[i]->data.award << '\n';
        }
    }

}




//......................................................................................................

// functions for pictures menu choice 5(partial search)

bool search2(string pat, string txt)
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



void actorNamePartialBSTSearch(Node<string  , Actors>* t, string actorName , vector<Node<string , Actors> *> &nodes)
{
if (t == NULL)return;

if (search2(actorName , t->key))nodes.push_back(t);

actorNamePartialBSTSearch(t->left , actorName , nodes);
actorNamePartialBSTSearch(t->right , actorName , nodes);
}


void partialSearchByName(BST<string, Actors> *&actors_database)
{
    cout << "enter the name of actor you wanna search\n";
    string tempName;
    cin.ignore();
    getline(cin , tempName);

    vector<Node<string , Actors> *> nodes;

    actorNamePartialBSTSearch(actors_database->root , tempName , nodes);

    if (nodes.size() == 0)
    {
        cout << "no actor found for the provided name\n";
    }
    else
    {
        cout << "The following actors found for the provided name \n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "     " << nodes[i]->data.film << '\n';
        }
    }

}

void movieNamePartialBSTSearch(Node<string  , Actors>* t, string movName , vector<Node<string , Actors> *> &nodes)
{
if (t == NULL)return ;

if (search2(movName , t->data.film))nodes.push_back(t);

movieNamePartialBSTSearch(t->left , movName , nodes);
movieNamePartialBSTSearch(t->right , movName , nodes);
}

void partialSearchByMovie(BST<string, Actors> *&actors_database)
{
    cout << "enter the name of movie for which you wanna search actors\n";
    string movName;
    cin.ignore();
    getline(cin , movName);

    vector<Node<string , Actors> *> nodes;

    movieNamePartialBSTSearch(actors_database->root , movName , nodes);

    if (nodes.size() == 0)
    {
        cout << "no actor found for the provided movie name\n";
    }
    else
    {
        cout << "The following actors found for the provided movie name \n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "     " << nodes[i]->data.film << '\n';
        }
    }


}


void awardNamePartialBSTSearch(Node<string  , Actors>* t, string awdName , vector<Node<string , Actors> *> &nodes)
{
if (t == NULL)return;

if (search2(awdName , t->data.award))nodes.push_back(t);

awardNamePartialBSTSearch(t->left , awdName , nodes);
awardNamePartialBSTSearch(t->right , awdName , nodes);
}

void partialSearchByAward(BST<string, Actors> *&actors_database)
{
    cout << "enter the award name for which you wanna search actors\n";
    string awdName;
    cin.ignore();
    getline(cin , awdName);

    vector<Node<string , Actors> *> nodes;

    awardNamePartialBSTSearch(actors_database->root , awdName , nodes);

    if (nodes.size() == 0)
    {
        cout << "no actor found for the provided award\n";
    }
    else
    {
        cout << "The following actors found for the provided award \n\n";
        for (int i = 0 ; i < nodes.size() ; i++)
        {
            cout << nodes[i]->key << "     " << nodes[i]->data.award << '\n';
        }
    }


}

//.....................................................................................
//funtion for choice3 (sorted by)

void nameSortedBSTTraversal(Node<string , Actors> *t)
{
    if (t == NULL)return;

    nameSortedBSTTraversal(t->left);
    cout << t->key << "                 " << t->data.film << '\n';
    nameSortedBSTTraversal(t->right);

}
void nameSorted(BST<string, Actors> *&actors_database )
{
    nameSortedBSTTraversal(actors_database->root);
}

void yearSortedBSTraversal(Node<string , Actors> *t , map<int , vector<Node<string , Actors>* >> &mp )
{
if (t == NULL)return;

mp[t->data.year].push_back(t);

yearSortedBSTraversal(t->left , mp);
yearSortedBSTraversal(t->right , mp);
}

void yearSorted(BST<string, Actors> *&actors_database)
{
    map<int , vector<Node<string , Actors>* >> mp;

    yearSortedBSTraversal(actors_database->root , mp);

    for (auto i : mp)
    {
        cout << "Year : " << i.first << '\n';
        for (auto j : i.second)
        {
            cout << j->key << "                " << j->data.film << '\n';
        }
        cout << '\n';
    }
}

void awardSortedBSTTraversal(Node<string , Actors> *t , map<string , vector<string> > &mp)
{
    if (t == NULL)return;

    mp[t->data.award].push_back(t->key);

    awardSortedBSTTraversal(t->left , mp);
    awardSortedBSTTraversal(t->right , mp);

}

void awardSorted(BST<string, Actors> *&actors_database)
{
    map<string ,  vector<string> > mp;

    awardSortedBSTTraversal(actors_database->root , mp);

    for (auto i : mp)
    {
        sort(i.second.begin(), i.second.end());

        cout << i.first << "\n\n";
        for (auto j : i.second)
        {
            cout << j << '\n';
        }

        cout << '\n';
    }

}


//...........................................................................................

// function to modify any specific field
void modifyField(Node<string , Actors> *t  , BST<string, Actors> *&actors_database)
{
    int choice = 0 ;
    char buffer  = 0;
    while (choice != 5)
    {
        cout << " Which field you want to modify?" << endl;
        cout << "Press 1 if you want to modify Name\n";
        cout << "Press 2 if you want to modify Year\n";
        cout << "Press 3 if you want to modify Award\n";
        cout << "Press 4 if you want to modify Film name\n";
        cout << "Press 5 to return to actor menu\n";
        cin >> buffer;
        choice = buffer - '0';

        if (choice < 1 || choice > 5)
        {
            cout << "please enter a valid choice\n";
        }
        else if (choice == 1)
        {
            Actors a = t->data;
            string oldName = a.name;
            cout << "enter new name\n";
            string newName ;
            cin.ignore();
            getline(cin , newName);

            // first remove the node corresponding to the given name and insert a new node with updated name
            actors_database->remove(oldName);

            a.name = newName;
            actors_database->insert(newName , a );


            cout << "the name has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay2(2000);

        }
        else if (choice == 2)
        {
            cout << "enter year\n";
            int tyear;
            cin >> tyear;
            t->data.year = tyear;
            cout << "the year has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay2(2000);
        }
        else if (choice == 3)
        {
            cout << "enter the new award name\n";
            string awdName;
            cin.ignore();
            getline(cin , awdName);
            t->data.award = awdName;
            cout << "the award has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay2(2000);

        }
        else if (choice == 4)
        {
            cout << "enter the film name\n";
            string filmName;
            cin.ignore();
            getline(cin , filmName);
            t->data.film = filmName;
            cout << "the filmName has been successfully modified\n";
            cout << "Taking you back to the modify menu in 2 seconds\n\n";
            delay2(2000);
        }
        else if (choice == 5)
        {
            cout << "taking you back to the actors menu in 2 seconds\n";
            delay2(2000);
        }

    }

}
