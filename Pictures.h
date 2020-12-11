//
// Created by Ravisher Singh on 12/10/20.
//

#ifndef CSCI2421FINALRS_PICTURES_H
#define CSCI2421FINALRS_PICTURES_H

#pragma once

#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<time.h>
#include<fstream>
#include<algorithm>
#include "BST.h"
using namespace std;


void delay(clock_t a);

// ;oad entire csv file to BST
void loadPicturesTree(BST<string , Pictures> *&pictures_database);

//display the main menu within the pictures database
void picturesMenu(BST<string, Pictures> *&pictures_database);

//pictures info is obtained from user and added to picture tree
void addRecord(BST<string, Pictures> *&pictures_database);

//display the entire content of database
void displayTreeInorder(Node<string , Pictures> *t);

// modify any specific field
void modifyField(Node<string , Pictures> *t , BST<string, Pictures> *&pictures_database);

map<int, vector<string>> sortByYear(BST<string, Pictures> *&pictures_database);
void sortByYearHelper(BST<string, Pictures> *&pictures_database , map<int, vector<string>> &moviesByYear , Node<string , Pictures> *t );

map<double , vector<string>> sortByRating(BST<string, Pictures> *&pictures_database);
void sortByRatingHelper(BST<string, Pictures> *&pictures_database , map<double, vector<string>> &moviesByRating , Node<string , Pictures> *t );


map<int , vector<string>> sortByDuration(BST<string, Pictures> *&pictures_database);
void sortByDurationHelper(BST<string, Pictures> *&pictures_database , map<int, vector<string>> &moviesByDuration , Node<string , Pictures> *t );
//....................................................................................................

// functions for pictures menu choice 6(writing to csv file)


void writeToCSV(BST<string, Pictures> *&pictures_database);
void inorderWriteCSV(Node<string, Pictures>* t  , fstream &fout);
//..................................................................................................

// functions for pictures menu choice 4(complete search)

void inOrderMovieNameSearch(Node<string, Pictures> *t , string movName , vector<Node<string , Pictures> *> &nodes);
void fullSearchByName(BST<string, Pictures> *&pictures_database);

void inOrderMovieYearSearch(Node<string, Pictures> *t , int movYear , vector<Node<string , Pictures> *> &nodes);
void fullSearchByYear(BST<string, Pictures> *&pictures_database);

void inOrderMovieGenreSearch(Node<string, Pictures> *t , string movGenre , vector<Node<string , Pictures> *> &nodes);
void fullSearchByGenre(BST<string, Pictures> *&pictures_database);

void inOrderMovieRatingSearch(Node<string, Pictures> *t , double movRating , vector<Node<string , Pictures> *> &nodes);
void fullSearchByRatings(BST<string, Pictures> *&pictures_database);


//................................................................................................

// functions for pictures menu choice 5(partial search)

bool search(string pat, string txt) ;

void movieNameBSTSearch(Node<string, Pictures> *t , string movName, vector<Node<string , Pictures> *> &nodes);
void partialSearchByName(BST<string, Pictures> *&pictures_database);

void genreNameBSTSearch(Node<string, Pictures> *t , string genreName, vector<Node<string , Pictures> *> &nodes);
void partialSearchByGenre(BST<string, Pictures> *&pictures_database);








#endif //CSCI2421FINALRS_PICTURES_H
