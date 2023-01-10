#ifndef PHONEBOOK2_H
#define PHONEBOOK2_H

#include<iostream>
#include<array>
#include<string>
#include<cstdlib>
#include "contact2.hpp"
#define EXIT_SUCCESS 0

class phonebook{
    private:
    std::array<contact,8> contacts_array;
    public:
    void add();
    void truncate_string(string s);
    void search();
    int exit_p();
};

#endif
