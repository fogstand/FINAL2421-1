//
// Created by Ravisher Singh on 12/10/20.
//

#ifndef CSCI2421FINALRS_ACTORS_H
#define CSCI2421FINALRS_ACTORS_H
#pragma once

#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<time.h>
#include<fstream>
#include<sstream>
#include "BST.h"
using namespace std;

void delay2(clock_t a);

void loadActorsTree(BST<string , Actors> *&actors_database);

void actorsMenu(BST<string, Actors> *&actors_database);

void addRecord(BST<string, Actors> *&actors_database);

void displayTreeInorder(Node<string , Actors> *t);


//functions to write data to csv file
void writeToCSV(BST<string, Actors> *&actors_database);
void inorderWriteCSV(Node<string, Actors>* t  , fstream &fout);


//........................................................................................................

//function for choice4(complete search)

void actorNameFullBSTSearch(Node<string  , Actors>* t, string actorName , vector<Node<string , Actors> *> &nodes);
void fullSearchByName(BST<string, Actors> *&actors_database);

void awardNameFullBSTSearch(Node<string  , Actors>* t, string awdName , vector<Node<string , Actors> *> &nodes);
void fullSearchByAward(BST<string, Actors> *&actors_database);

void movieNameFullBSTSearch(Node<string  , Actors>* t, string movName , vector<Node<string , Actors> *> &nodes);
void fullSearchByMovie(BST<string, Actors> *&actors_database);




//......................................................................................................

// functions for pictures menu choice 5(partial search)

bool search2(string pat, string txt);


void actorNamePartialBSTSearch(Node<string  , Actors>* t, string actorName , vector<Node<string , Actors> *> &nodes);
void partialSearchByName(BST<string, Actors> *&actors_database);

void movieNamePartialBSTSearch(Node<string  , Actors>* t, string movName , vector<Node<string , Actors> *> &nodes);
void partialSearchByMovie(BST<string, Actors> *&actors_database);

void awardNamePartialBSTSearch(Node<string  , Actors>* t, string awdName , vector<Node<string , Actors> *> &nodes);
void partialSearchByAward(BST<string, Actors> *&actors_database);

//..........................................................................................................

//funtion for choice3 (sorted by)

void nameSortedBSTTraversal(Node<string , Actors> *t);
void nameSorted(BST<string, Actors> *&actors_database);

void yearSortedBSTraversal(Node<string , Actors> *t , map<int , vector<Node<string , Actors>* > > &mp );
void yearSorted(BST<string, Actors> *&actors_database);

void awardSortedBSTTraversal(Node<string , Actors> *t , map<string , vector<string> > &mp);
void awardSorted(BST<string, Actors> *&actors_database);


//.......................................................................................................

void modifyField(Node<string , Actors> *t  , BST<string, Actors> *&actors_database);



#endif //CSCI2421FINALRS_ACTORS_H
