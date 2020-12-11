//
// Created by Ravisher Singh on 12/10/20.
//
#include<iostream>
using namespace std;
#ifndef CSCI2421FINALRS_BST_H
#define CSCI2421FINALRS_BST_H

template <typename KEY , typename DATA>
class Node
{
public:
    KEY key;
    DATA data;
    Node* left;
    Node* right;

    Node(KEY k , DATA d);
};


template <typename KEY , typename DATA>
Node<KEY , DATA>::Node(KEY k , DATA d)
{
    key = k;
    data = d;
    left = NULL;
    right = NULL;
}


template <typename KEY , typename DATA>
class BST
{
public:
    Node<KEY , DATA>* root;
    Node<KEY , DATA>* insert(KEY k , DATA d , Node<KEY , DATA> * &t);
    void inorder(Node<KEY , DATA> *t);
    Node<KEY , DATA>* findMin(Node<KEY , DATA> *t);
    Node<KEY , DATA>* findMax(Node<KEY , DATA> *t);
    Node<KEY , DATA>* remove(KEY k , Node<KEY , DATA> *t);



    BST();
    void insert(KEY k , DATA d);
    void inorderDisplay();
    void remove(KEY k);
    pair<bool , Node<KEY , DATA>*> search(KEY k , Node<KEY , DATA> *t);
};
///////////////////////////////////////////////////////////////////////////////////////



template <typename KEY , typename DATA>
Node<KEY , DATA>* BST<KEY , DATA>::insert(KEY k , DATA d,  Node<KEY , DATA> * &t )
{
    if (t == NULL)
    {
        t = new Node<KEY , DATA>(k , d);
    }
    else if (k <  t->key)
        t->left = insert(k , d , t->left);
    else
        t->right = insert(k , d, t->right);

    return t;
}

template <typename KEY , typename DATA>
void BST<KEY , DATA>::inorder(Node<KEY , DATA> *t)
{
    if (t == NULL)return ;

    inorder(t->left);
    cout << t->key << '\n';
    inorder(t->right);
}

template <typename KEY , typename DATA>
Node<KEY , DATA>* BST<KEY , DATA>::findMin(Node<KEY , DATA>* t)
{
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

template <typename KEY , typename DATA>
Node<KEY , DATA>* BST<KEY , DATA>::findMax(Node<KEY , DATA>* t) {
    if (t == NULL)
        return NULL;
    else if (t->right == NULL)
        return t;
    else
        return findMax(t->right);
}


template <typename KEY , typename DATA>
Node<KEY , DATA>* BST<KEY , DATA>::remove(KEY k, Node<KEY , DATA>* t) {
    Node<KEY , DATA>* temp;
    if (t == NULL)
        return NULL;
    else if (k < t->key)
        t->left = remove(k, t->left);
    else if (k > t->key)
        t->right = remove(k, t->right);
    else if (t->left && t->right)
    {
        temp = findMin(t->right);
        t->key = temp->key;
        t->right = remove(t->key, t->right);
    }
    else
    {
        temp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}

// public functions
template <typename KEY , typename DATA>
BST<KEY , DATA>::BST()
{
    root = NULL;
}

template <typename KEY , typename DATA>
void BST<KEY , DATA>::insert(KEY k , DATA d)
{
    insert(k , d , root);
}

template <typename KEY , typename DATA>
void BST<KEY , DATA>::inorderDisplay()
{
    inorder(root);
    cout << '\n';
}

template <typename KEY , typename DATA>
void BST<KEY , DATA>::remove(KEY k)
{
    root = remove(k, root);
}

template <typename KEY , typename DATA>
pair<bool , Node<KEY , DATA>*> BST<KEY , DATA>::search(KEY k  , Node<KEY , DATA> *t)
{
    if (t == NULL)return {false , NULL};

    if (t->key == k)return {true , t };
    else if (k < t->key)return search( k, t->left);

    return search( k , t->right);

}





/////////////////////////////////////////////////////////////////////////////////////////
struct Actors
{
    int year;
    string award;
    bool isWinner;
    string name;
    string film;

};

struct Pictures
{
    string name;
    int year;
    int nominations;
    double ratings;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;
};


#endif //CSCI2421FINALRS_BST_H
