#include "Library.hpp"
#include "book.hpp"
using namespace std;

/*  void add();
    void search();
    void truncate();
    void exit_l()*/


// name{x}, isbn{y}, author{z}, link{l} {};
void library::add(){
    string n, a, l;
    int isbn;
    int i=0;
    while(books[i].get_name().length()!=0){
        i++; //since a book can't have an empty field all the books that exist exist in the library have a valid name
        //so we iterate until we reach the index of an an empty spot, to add the book. 
    }
    if(i==8){
        cout<<"the Library is full."<<endl;
        cout<<"would you like to replace the last book? (y/n): ";
        char r;
        cin>>r;
        if(r=='n')
            return;
    }
    else{
        cout<<"~~Please enter the informations of the book :~~"<<endl;

        cout<<endl<<"Name of the book: ";
        cin>>n; 
        books[i].set_name(n);

        cout<<endl<<"The ISBN of the book (number): ";
        cin>>isbn;
        books[i].set_isbn(isbn);

        cout<<endl<<"The author of the book: ";
        cin>>a;
        books[i].set_author(a);

        cout<<endl<<"The link of the book: ";
        cin>>l;
        books[i].set_link(l);
    }
    cout<<"Book number "<<i<<" has been added."<<endl;
}


void library::truncate(string s){
    if(s.length()>9){
        for(int i=0;i<9;i++){
            cout<<s[i];
        }
        cout<<".";
    }
    else{
        for(int i=0;i<s.length();i++)
            cout<<s[i];
    }
    cout<<"|";
}

void library::search(){
    if(books[0].get_name().length()==0){
        cout<<"The Library is empty."<<endl;
    }
    else{
    int i=0;
    while(books[i].get_name().length()!=0){
        cout<<endl<<"|index:"<<i<<"|";
        truncate(books[i].get_name());
        truncate(books[i].get_author());
        
        i++;
    }
    cout<<endl<<endl<<"~~Which book do you want to display ? "<<endl;
    cout<<endl<<"~~Please enter its index: ";
    int index;
    cin>>index;
    if(index < 0 || index>8){
        cout<<"invalid index (out of range)."<<endl;
    }
    else{
    cout<<endl<<"The book information: "<<endl;
    cout<<endl<<"Name of the book: "<< books[index].get_name()<<endl;
    cout<<endl<<"The ISBN of the book: "<<books[index].get_isbn()<<endl;
    cout<<endl<<"The author of the book: "<<books[index].get_author()<<endl;
    cout<<endl<<"The link of the book: "<<books[index].get_link()<<endl;
    }
    }
}

void library::exit_l(){
    exit(0);
}

