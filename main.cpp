
#include<iostream>
#include "BST.h"
#include "Pictures.h"
#include "Actors.h"
using namespace std;

string interface1= "░█████╗░░██████╗░█████╗░░█████╗░██████╗░░██████╗  ██████╗░░█████╗░██████╗░░█████╗░\n██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝  ╚════██╗██╔══██╗╚════██╗██╔══██╗\n██║░░██║╚█████╗░██║░░╚═╝███████║██████╔╝╚█████╗░  ░░███╔═╝██║░░██║░░███╔═╝██║░░██║\n██║░░██║░╚═══██╗██║░░██╗██╔══██║██╔══██╗░╚═══██╗  ██╔══╝░░██║░░██║██╔══╝░░██║░░██║\n╚█████╔╝██████╔╝╚█████╔╝██║░░██║██║░░██║██████╔╝  ███████╗╚█████╔╝███████╗╚█████╔╝\n░╚════╝░╚═════╝░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░  ╚══════╝░╚════╝░╚══════╝░╚════╝░\n";

/*
* 1.Pictures Database
* i) Sub Menu
* 2. Actor Database
* i) Sub Menu
* (Validate the input)
* 3.Exit
* */
void mainMenu(BST<string , Pictures> *&pictures_database , BST<string , Actors> *&actors_database )
{
    int choice  = 0;
    char buffer = 0;
    while (choice != 3)
    {
      cout<<interface1 <<endl;
        cout << "Pick the number based on which database you would like to enter.\n";
        cout << "1 to enter actors database.\n";
        cout << "2 to enter pictures database.\n";
        cout << "3 Exit.\n";
        cin >> buffer;
        choice = buffer - '0';

        if (choice < 1 || choice > 3)
        {
            cout << "please enter a valid response\n\n";
        }
        else if (choice == 1)
        {
            actorsMenu(actors_database);

        }
        else if (choice == 2)
        {
            picturesMenu(pictures_database);
        }
        else if (choice == 3)
        {
            cout << "you have decided to exit ... bye bye \n";
            delay(3000);
            exit(0);
        }
    }
}


int main()
{
    BST<string , Pictures> *pictures_database = new BST<string , Pictures>;
    BST<string , Actors> *actors_database = new BST<string , Actors>;

    loadPicturesTree(pictures_database);
    loadActorsTree(actors_database);

    mainMenu(pictures_database , actors_database);





    return 0;
}
