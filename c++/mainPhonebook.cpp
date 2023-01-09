#include "contact2.hpp"
#include "phonebook2.hpp"

int main(){
    phonebook P;
    int i=0;
    while(i!=3){
        cout<<endl<<"~~~Please choose the index of the command you would like to perform~~~"<<endl;
        cout<<"   1 - ADD"<<endl;
        cout<<"   2 - SEARCH"<<endl;
        cout<<"   3 - EXIT"<<endl;
        cout<<"your choice: ";
        cin>>i;
        while(i!=1 & i!=2 & i!=3){
            cout<<"You entered an invalid choice."<<endl;
            cout<<"your choice: ";
            cin>>i; 
        }
        cout<<endl;
        if(i==1){
            P.add();
        }
        if(i==2){
            P.search();
        }
        if(i==3){
            cout<<"The program will quit and the contacts will be lost forever!"<<endl;
            cout<<"are you sure, you want that (y/n)? : ";
            char r;
            cin>>r;
            if(r=='n')
                i=0;
            else
                P.exit_p();
        }
    }
    return 0;
}
