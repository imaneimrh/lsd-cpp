#include "phonebook2.hpp"

void phonebook::add(){

    int i=0;
    //I'm trying to find the index which will be occupied by this contact
    while(contacts_array[i].get_first_name().length()!=0){
        i++;
    }
    //If the user tries to add a 9th contact,replace the oldest one by the new one.
    if(i==8){
        cout<<"the phonebook is full."<<endl;
        cout<<"Do you want to replace the last contact? (y/n): ";
        char choice;
        cin>>choice;
        if(choice=='n')
            return;
        else
            cout<<"okay the oldest one will be replaced by the new one.";
    }
    string fn;
    string ln;
    string nk;
    int num;
    cout<<"~~Please enter the information about the new contact you want to add~~"<<endl;
    //cout<<"(spaces in names are not permissible)";
    cout<<endl;
    cout<<"First name: ";
    cin>>fn;
    while(fn.length()==0){ //to make sure the field is not empty
        cout<<"Please enter the First name: ";
        cin>>fn;
    }
    contacts_array[i].set_first_name(fn);
    cout<<"Last name: ";
    cin>>ln;
    while(ln.length()==0){ //to make sure the field is not empty
        cout<<"Please enter the Last name: ";
        cin>>ln;
    }
    contacts_array[i].set_last_name(ln);
    cout<<"Nickname: ";
    cin>>nk;
    while(nk.length()==0){ //to make sure the field is not empty
        cout<<"Please enter the nickname: ";
        cin>>nk;
    }
    contacts_array[i].set_nickname(nk);
    cout<<"Phone number: ";
    cin>>num;
    contacts_array[i].set_number(num);
    cout<<endl<<"contact " <<i<<" was added successfully."<<endl;
}

/*The text must be right-aligned. If the text is longer than
the column, it must be truncated and the last displayable character
must be replaced by a dot (’.’). */

void phonebook::truncate_string(string s){
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

void phonebook::search(){
    /*Display the saved contacts as a list of 4 columns: 
    index, first name, last name and nickname*/
    if(contacts_array[0].get_first_name().length()==0){
        //we check if it's empty by testing whether the first contact's name if it's empty, 
        //normally if the phone book was not empty, the first name of the first element should have a value (it's a condition)

        cout<<("Empty phonebook.")<<endl;
        return;
    }
    int i=0;
    while(contacts_array[i].get_first_name().length()!=0){
        cout<<endl<<"|index:"<<i<<"|";
        truncate_string(contacts_array[i].get_first_name());
        truncate_string(contacts_array[i].get_last_name());
        truncate_string(contacts_array[i].get_nickname());
        
        i++;
    }
    int index;
    cout<<endl<<"please enter the index of the entry to display: "<<endl;;
    cin>>index;
    if(index>8 || index<0)
        cout<<"index not valid. (out of range)";
    else{
        cout<<"~~Information of the Contact searched~~"<<endl;
        cout<<"~First name: "<<contacts_array[index].get_first_name()<<endl;
        cout<<"~Last name: "<<contacts_array[index].get_last_name()<<endl;
        cout<<"~Nickname: "<<contacts_array[index].get_nickname()<<endl;
        cout<<"~Phone number: "<<contacts_array[index].get_number()<<endl;
    }

}

int phonebook::exit_p(){

    return EXIT_SUCCESS;
}