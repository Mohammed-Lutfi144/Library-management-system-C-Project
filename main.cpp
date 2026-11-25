#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
static int bookId = 0 ; // a counter for the books' ids
struct Book{
        string title = "Unknown";
        string type = "Unknown";
        string author = "Unknown";
        int id = 0;
        int quantity = 0;    
};
class Library;
class Person;


string toLowerCase(string line);
vector<int> separateIdsFromPersonObject(vector<Person> objectiveList);
bool checkIfIdsEqual(int id1,int id2);
int findTheIndex(int id, vector<int> list);
bool checkIfIdfound(int id,vector<int> list);

vector<Book> listOfBooks; //*{"title","type","author",id,quantity}
vector<Person> listOfPersons; //? {"name","job",numberofBooks,personId}

class Person{
    
    private:
        string name = "Unknown";
        string job = "Unknown";
        int numberOfBooks = 0;
        int personId = 0;
        vector<int> listOfBorrowedBook;
        string listOfBorrowedBookAsString;
        //int fee = 0;
    public:      
        void setter(){  //SignIn
            system("cls");
            cout<<"-------------Creat new acount---------------"<<endl;
            cout<<"Enter your name : ";
            getline(cin,name);
            
            cout<<"Enter your job : ";
            cin>>job;
            
            cout<<"Enter your id : ";
            cin>>personId;
            cin.ignore();
            
            listOfPersons.push_back(*this);
            cout<<"--------------------------------------------"<<endl;
        }
        void borrowAbook(){
            //borrow a book and take all the details of the book and the person
            system("cls");
            cout<<"-------------Borrow A book---------------"<<endl;
            int id;
            int pid;
            cout<<"Please, Enter the book's ID : ";
            cin>>id;
            cout<<"Please, Enter your Id : ";
            cin>>pid;
            cin.ignore();
            if(checkIfIdfound(pid,separateIdsFromPersonObject(listOfPersons))){
                if(id <= listOfBooks.size()){
                        if(listOfBooks[id-1].quantity > 0){

                                int index = findTheIndex(pid,separateIdsFromPersonObject(listOfPersons));
                                if(index != -1){
                                //update the book for a particular person
                                listOfPersons[index].numberOfBooks++;
                                listOfPersons[index].listOfBorrowedBook.push_back(id);
                                listOfPersons[index].listOfBorrowedBookAsString += to_string(id)+",";
                                listOfBooks[id-1].quantity--; 
                                cout<<"Thanks,,, You have borrowed a new book\n\tEnjoy"<<endl;
                                }
                                else{
                                cout<<"Invalid person Id"<<endl;
                                }
                        }
                        else{
                            cout<<"Sorry,,, The book is not available"<<endl;
                        }
                }
                else{
                    cout<<"Invalid ID,,, please try again"<<endl;
                }
            }
            else{
                cout<<"Invalid person Id"<<endl;
            }
            cout<<"--------------------------------------------"<<endl;
        }
        void returnAbook(){
            system("cls");
            //return the book that is borrowed
            int id;
            int pid;
            cout<<"===========return books==========="<<endl;
            cout<<"Please, Enter the book's ID : ";
            cin>>id;
            cout<<"Please, Enter your Id : ";
            cin>>pid;
            
            cin.ignore();
            if(id <= listOfBooks.size()){

                        int index = findTheIndex(pid,separateIdsFromPersonObject(listOfPersons));
                if(index != -1){
                        if(checkIfIdfound(id,listOfPersons[index].listOfBorrowedBook)){

                            //upgrade the number of books
                            listOfPersons[index].numberOfBooks--;
                            //upgrade for list

                            int returnedBookId = findTheIndex(id,listOfPersons[index].listOfBorrowedBook);
                            listOfPersons[index].listOfBorrowedBook.erase(listOfPersons[index].listOfBorrowedBook.begin() + returnedBookId);

                            //upgrade the string of books list
                            string str;
                            for(int b : listOfPersons[index].listOfBorrowedBook){
                                str += to_string(b) + ",";
                            }
                            listOfPersons[index].listOfBorrowedBookAsString = str;
                            listOfBooks[id-1].quantity++; 
                            cout<<"Thanks,,, You have returned the book\n\tThanks"<<endl;
                        }
                        else{
                            cout<<"you do not have any book with "<<id<<" id"<<endl;
                        }
                        
                 }
                else{
                cout<<"Invalid person Id"<<endl;
                }
            }
            else{
                cout<<"Invalid ID,,, please try again"<<endl;
            }
            cout<<"--------------------------------------------"<<endl;
        }
        void displayMyBookList(){
            system("cls");
            cout<<"-------------Dispaly person bookList---------------"<<endl;
            int pid;
            cout<<"Please, Enter your Id : ";
            cin>>pid;
            if(checkIfIdfound(pid,separateIdsFromPersonObject(listOfPersons))){
                int index = findTheIndex(pid,separateIdsFromPersonObject(listOfPersons));
                if(index != -1){

                
                    if(listOfPersons[index].listOfBorrowedBook.empty()){
                        cout<<"You do not have any books"<<endl;
                    }
                    
                    for(size_t i = 0 ; i < listOfPersons[index].listOfBorrowedBook.size() ; i++)
                    {
                        int id = listOfPersons[index].listOfBorrowedBook[i];
                        cout<<"Id"<<setw(13)<<"Title"<<endl;
                        cout<<id<<setw(13)<<listOfBooks[id-1].title<<endl;
                    }
                }
                else{
                cout<<"Invalid person Id"<<endl;
                }
            }
            else{
                cout<<"Invalid Id"<<endl;
            }
            
        }


        //tool friend functions
        friend vector<int> separateIdsFromPersonObject(vector<Person> objectiveList);
        friend int findTheIndex(int id, vector<int> list);
        friend bool checkIfIdfound(int id,vector<int> list);
        friend class Library;
};

bool checkIfIdfound(int id,vector<int> list){
    for(size_t i = 0 ; i < list.size() ; i++){
        if(checkIfIdsEqual(list[i],id)){
            
            return true;
        }
    }
    return false;
}
int findTheIndex(int id, vector<int> list){
    
       int index;
            for(size_t i = 0 ; i < list.size() ; i++){
                if(checkIfIdsEqual(list[i],id)){   
                    index = i;
                    return index ;    
                }
            }
    return -1;
}
vector<int> separateIdsFromPersonObject(vector<Person> objectiveList){
    vector<int> newList;
    for(size_t i = 0; i < objectiveList.size() ; i++){
        newList.push_back(objectiveList[i].personId);
    }
    return newList;
}

string toLowerCase(string line){
   for(size_t i = 0 ; i < line.length() ; i++){
        if(line[i]>='a' && line[i]<='z'){
            line[i]-=32;
        }
    } 
}
class Library{ 
    public:
         Library(){
            // the data of books;
            Book book;
            Person person;
            //install all the data from the data file
            ifstream installbookData("datafile.txt",ios::app); // open a file
            ifstream installPersonData("PersonData.txt",ios::app);
            string line; 
            //for books
            while( !installbookData.eof() ){ 
                getline(installbookData,line);
                int counter = 0 ; 
                //separate the line
                    string word;
                    for(size_t i = 0 ; i < line.length() ; i++){
                        if(line[i] != '/'){
                            word += line[i];
                        }
                        else
                        {
                            counter++;
                            switch(counter){
                                case 1 :{
                                    book.title = word;
                                    break;
                                }
                                case 2 :{
                                    book.type = word;
                                    break;
                                }
                                case 3 :{
                                    book.author = word;
                                    break;
                                }
                                case 4 :{
                                    book.quantity = std::atoi(word.c_str());
                                    break;
                                }
                            }
                            word.clear();
                        }
                    }
                    book.id++;
                    bookId++;
                    listOfBooks.push_back(book);       
                   
            }
            // for person
            while( !installPersonData.eof()){ 
                getline(installPersonData,line);
                int counter = 0 ; 
                //separate the line
                    string word;
                    for(size_t i = 0 ; i < line.length() ; i++){
                        if(line[i] != '|'){
                            word += line[i];
                        }
                        else
                        {
                            counter++;
                            switch(counter){
                                case 1 :{
                                    person.name = word;
                                    break;
                                }
                                case 2 :{
                                    person.personId = std::atoi(word.c_str());
                                    break;
                                }
                                case 3 :{
                                    person.job = word;
                                    break;
                                }
                                case 4 :{
                                    person.numberOfBooks = std::atoi(word.c_str());
                                    break;
                                }
                                case 5 :{
                                    person.listOfBorrowedBookAsString = word;
                                    string strnum;
                                    int idBook;
                                    for(size_t i = 0 ; i < word.length() ; i++){
                                        if(word[i] != ','){
                                            strnum += word[i];
                                        }
                                        idBook = std::atoi(strnum.c_str());
                                        person.listOfBorrowedBook.push_back(idBook);
                                    }
                                    break;
                                }
                            }
                            word.clear();
                        }
                    }
                    
                    listOfPersons.push_back(person);       
                   
            }
        
        }
        void displayAllBooks(){
            //display all the books with detail
            cout<<"Id"<<setw(12)<<"Quantity "<<setw(13)<<"Title"<<endl;
            for(int i = 0 ; i < listOfBooks.size() ; i++){
                cout<<listOfBooks[i].id<<setw(10)<<listOfBooks[i].quantity<<setw(40)<<listOfBooks[i].title<<endl;
            }
        }
        void displayAllPersons(){
            // display all the persons who borrow a book
            cout<<"Id"<<setw(12)<<"name "<<setw(13)<<"borrowed_book"<<endl;
            for(int i = 0 ; i < listOfPersons.size() ; i++){
                cout<<listOfPersons[i].personId<<setw(20)<<listOfPersons[i].name<<setw(10)<<listOfPersons[i].numberOfBooks<<endl;
            }
        }
        void searchOfBook(){
            //search of a book using its id
            int id ;
            cout<<"=============BOOK'S SEARCHING============"<<endl;
            cout<<"please enter the id of the book : ";
            cin>>id;
            if(id <= listOfBooks.size()){
                cout<<"id : "<<id<<endl;
                cout<<"Title : "<<listOfBooks[id-1].title<<endl;
                cout<<"Type : "<<listOfBooks[id-1].type<<endl;
                cout<<"Author : "<<listOfBooks[id-1].author<<endl;
                cout<<"Quantity : "<<listOfBooks[id-1].quantity<<endl;
            }
            else{
                cout<<"Invalid ID,,, please try again"<<endl;
            }
                
        }
        void searchOfPerson(){
            //search of a person that borrow a book using his id
            int personId ;
            int index;
            if(listOfPersons.empty()){
                cout<<"NO ONE AT THE LIBRARY SYSTEM"<<endl;
                return ;
            }
            cout<<"=============PERSON'S SEARCHING============"<<endl;
            cout<<"please enter the Person's Id : ";
            cin>>personId;
            
            index = findTheIndex(personId,separateIdsFromPersonObject(listOfPersons));
            
            
            if(checkIfIdfound(personId,separateIdsFromPersonObject(listOfPersons))){
                cout<<"id : "<<personId<<endl;
                cout<<"Name : "<<listOfPersons[index].name<<endl;
                cout<<"job : "<<listOfPersons[index].job<<endl;
                cout<<"No.Borrow Books : "<<listOfPersons[index].numberOfBooks<<endl;
                
            }
            else{
                cout<<"Invalid ID,,, please try again"<<endl;
            }
        }
        void addBook(){
            Book newbook;
            //Add a book to the list
            cout<<"=============ADDING BOOK============="<<endl;
            cout<<"please enter the title : ";
            cin>>newbook.title;
            cout<<"please enter the type : ";
            cin>>newbook.type;
            cout<<"please enter the author : ";
            cin>>newbook.author;
            cout<<"please enter the quantity : ";
            cin>>newbook.quantity;
            newbook.id = ++bookId;
            listOfBooks.push_back(newbook);
            cout<<"================Done!!==============="<<endl;
            
        }
        bool Exit(){
            char exit;
            cout<<"Enter X or x to close the program : ";
            cin>> exit;
            return (exit == 'X' || exit == 'x')? false : true;
        }
        ~Library(){
            //keep all the list of the book in a txt file
            ofstream returnBookData("datafile.txt");
            ofstream returnPersonData("PersonData.txt");

            if(!returnBookData || !returnPersonData){
                cout<<"Fail to open the file!!"<<endl;
                return ;
            }

            for(int idOfBook = 0 ; idOfBook < listOfBooks.size() ; idOfBook++){
                returnBookData<<listOfBooks[idOfBook].title;
                returnBookData<<"/";
                returnBookData<<listOfBooks[idOfBook].type;
                returnBookData<<"/";
                returnBookData<<listOfBooks[idOfBook].author;
                returnBookData<<"/";
                returnBookData<<listOfBooks[idOfBook].quantity;
                returnBookData<<"/";
                if(idOfBook != listOfBooks.size()-1)
                    returnBookData<<endl;
            }


            for(int indexOfPerson = 0; indexOfPerson < listOfPersons.size() ; indexOfPerson++){
                returnPersonData<<listOfPersons[indexOfPerson].name;
                returnPersonData<<"|";
                returnPersonData<<listOfPersons[indexOfPerson].personId;
                returnPersonData<<"|";
                returnPersonData<<listOfPersons[indexOfPerson].job;
                returnPersonData<<"|";
                returnPersonData<<listOfPersons[indexOfPerson].numberOfBooks;
                returnPersonData<<"|";
                returnPersonData<<listOfPersons[indexOfPerson].listOfBorrowedBookAsString;
                returnPersonData<<"|";

                if(indexOfPerson != listOfPersons.size()-1)
                    returnPersonData<<endl;
            }



        }

};

int main(){
    
       Library library;
       Person person;
       int option;
       bool x = true;
       do{
        
        cout<<"1- Display all books     \n";
        cout<<"2- Display all Persons   \n";
        cout<<"3- Search of a book      \n";
        cout<<"4- Search of a perosn    \n";
        cout<<"5- Add a book            \n";
        cout<<"6- Display person list of Books\n";
        cout<<"7- Borrow a book         \n";
        cout<<"8- Return a book         \n"; 
        cout<<"9- creat a new acount\n";
        cout<<"10- Exit \n";
       
        cout<<"Enter the number of the task : ";
        cin>> option;
        cin.ignore();
        switch(option){
            case 1:
                library.displayAllBooks();
            break;
            case 2:
                library.displayAllPersons();
            break;
            case 3:
                library.searchOfBook();
            break;
            case 4:
                library.searchOfPerson();
            break;
            case 5:
                library.addBook();
            break;
            case 6:
                person.displayMyBookList();
            break;
            case 7:
                person.borrowAbook();
            break;
            case 8:
                person.returnAbook();
            break;
            case 9:
                person.setter();
            break;
            case 10:
                x = library.Exit();
            break;
            default:
                cout<<"Invalid option"<<endl;
        }

        
       }while(x);

    return 0;
}

bool checkIfIdsEqual(int id1,int id2){
    return id1 == id2;
}

