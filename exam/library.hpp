#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.hpp"
#include<array>
using namespace std;

class library{
    
    private:
    std::array<book, 8> books;

    public:
    void add();
    void search();
    void truncate(string s);
    void exit_l();

};

#endif
