#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<string>
using namespace std;

class book{

    private:
    string name;
    int isbn;
    string author;
    string link;
    public:

    
    void set_name(string n){
        name = n;
    }
    string get_name(){
        return name;
    }

    void set_isbn(int x){
        isbn = x;
    }
    int get_isbn(){
        return isbn;
    }

    void set_author(string n){
        author = n;
    }
    string get_author(){
        return author;
    }

    void set_link(string n){
        link = n;
    }
    string get_link(){
        return link;
    }
};

#endif