#include <iostream>
#include <array>
#include <vector>
using namespace std;


//-------------------------------------------------------------------------------CLASS FILE
class file{       
    // Access specifier
    protected:
    // Private attribute
    string name;
    string location;
    int permissions;
    string date; //format J-M-Y

    public:
    //constructor
    file(string n, string l, int p, string d) {
        name = n;
        location = l;
        permissions = p;
        date = d;
    }
    // Setters
    void setfile_name(string n) {
        name = n;
    }
    void setfile_loc(string l) {
        location = l;
    }
    void setfile_perm(int p) {
        permissions = p;
    }
    void setfile_date(string d) {
        date = d;
    }

    // Getters
    string getfile_name(){
        return name;
    }
    string getfile_loc(){
        return location;
    }
    int getfile_perm(){
        return permissions;
    }
    string getfile_date(){
        return date;
    }
    };

//----------------------------------------------------------------------------TEXT FILE

class textfile : public file{ 
    
    protected:
    string directory;
    public:
    //constructor + setter
    textfile(string d){
        directory = d;
    }
    //getter
    string gettextfile_dir(){
        return directory;
    }
    };

//-------------------------------------------------------------------------------EXECUTABLE FILES
template <typename T>
template <typename Y>
class execfile:public textfile{ 
/*the user cannot create an executable file. And all the executable
files exist in the directory home/bin.*/
//bi m3na ma3ndoch constructor ...?

    private:
    string directory = "home/bin";
    boolean flag;
    T(*foo)(Y);
    foo = &triggered_func;

    public:
        void operate(){
            if (flag)
                printf("the command can operate on every file type.\n");
            else
                printf("the command can operate on directories only.\n")
        }


    

//-------------------------------------------------------------------------------CLASS DIRECTORY

class directory : public file{     
   // Access specifier
   private:
    class directory * parent_d;
    vector<class directory> subdirectories;
    vector<class textfile> textfiles;
    vector<class execfile> executables;

    public:
    // Constructor with parameters
    directory(class directory* p, vector<class directory> sub, vector<class textfile> tf, vector<class execfile> ex) { 
        parent_d = p;
        subdirectories = sub;
        textfiles = tf;
        executables = ex;
    }
    //setters
    void setdirectory_parent(class directory* p) {
        parent_d = p;
    }
    void setdirectory_sub(vector<class directory> sub) {
        subdirectories = sub;
    }
    void setdirectory_tf(vector<class textfile> tf) {
        textfiles = tf;
    }
    void setdirectory_ex(vector<class execfile> ex) {
        executables = ex;
    }

    //getters
    class directory* getdirectory_parent() {
        return parent_d;
    }
    vector<class directory> getdirectory_sub() {
        return subdirectories;
    }
    vector<class textfile> getdirectory_tf() {
        return textfiles;
    }
    vector<class execfile> getdirectory_ex() {
        return executables;
    }

};

//-------------------------------------------------------------------------------CLASS SHELL
class shell{
// Access specifier
    private:
    directory rootdir;
    directory bindir;
    rootdir.setfile_name("home");
    bindir.setdirectory_parent(&rootdir);
    bindir.setfile_name("bin");
    std::map<rootdir, bindir> environment_var;
    vector<execfile> commands;

    public:
    // Constructor with parameters
    shell(std::map<rootdir, bindir> ev, vector<execfile> cm){
        environment_var = ev;
        commands = cm;
    }

    //setters
    void setshell_ev(std::map<rootdir, bindir> ev){
        environment_var = ev;
    }
    void setshell_cm(vector<execfile> cm){
        commands = cm;
    }
    //getters
    std::map<rootdir, bindir>getshell_ev() {
        return environment_var;
    }
    vector<execfile> getshell_ex() {
        return commands;
    }
   
};
