
#ifndef CONTACT2_H
#define CONTACT2_H

#include<iostream>
#include<string>

using namespace std;

class contact{

    private:
    string first_name;
    string last_name;
    string nickname;
    int number;

    public:

    //constructor of a contact
    //contact(string x, string y, string z, int num):first_name(x), last_name(y), nickname(z), number(num){}
    
    // ~~~~~~~~~first_name set and get~~~~~~~~~

    //setter function for first name
    void set_first_name(string x){
        first_name=x;
    }
    //getter function for first name
    string get_first_name(){
        return first_name;
    }

    // ~~~~~~~~~last_name set and get~~~~~~~~~

    //setter function for last name
    void set_last_name(string x){
        last_name=x;
    }
    //getter function for last name
    string get_last_name(){
        return last_name;
    }

    // ~~~~~~~~~nickname set and get~~~~~~~~~

    //setter function for nickname
    void set_nickname(string x){
        nickname=x;
    }
    //getter function for nickname
    string get_nickname(){
        return nickname;
    }

    // ~~~~~~~~~phonenumber set and get~~~~~~~~~

    //setter function for phone number
    void set_number(int x){
        number=x;
    }
    //getter function for phone number 
    int get_number(){
        return number;
    }
};

#endif
