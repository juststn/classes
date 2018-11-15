#include <iostream>
#include <string>
#include <vector> 
#include "music.h"
#include "movie.h"
#include "video.h"

using namespace std;

void addMedia(vector<Media*>* mediaList);
void printMedia(vector<Media*>* mediaList);
void searchMedia(vector<Media*>* mediaList);
void deleteMedia(vector<Media*>* mediaList);

//Classes by Justin He
//media database for videogames, music, and movies
//ADD to add an entry
//SEARCH to search for existing entries
//DELETE to delete an entry
//PRINT to print all existing entries
//QUIT to quit the program

int main(){
  string in = "";
  int i = 0;

  vector<Media*>* mediaList = new vector<Media*>;
  
  while(i == 0){
  cout<<"enter command:[ADD, SEARCH, DELETE, PRINT, QUIT]"<<endl;
  cin>>in;
  if(in=="ADD"){
    addMedia(mediaList);
  }

  if (in == "SEARCH") {
    searchMedia(mediaList);
  }
  
  if(in=="PRINT"){
    printMedia(mediaList);
  }
  if(in=="DELETE"){
    deleteMedia(mediaList);
  }
  if(in=="QUIT"){
    i = 1;
  }

  }

}

// add media
//ask for media type, then add information to store
void addMedia(vector<Media*>* mediaList)  {

  string input = "";
  string in; 
  
  cout << "Enter media type [MUSIC,VIDEO,MOVIE]: ";
  cin >> input;
  cin.ignore();
  
  if (input == "MUSIC") {
    music* m = new music();
       
    m->setType("MUSIC");
    cout << "enter title: ";
    getline(cin, in); 
    m->setTitle(in);

    cout << "enter artist: ";
    getline(cin, in);
    m->setArtist(in);

    cout << "enter year: ";
    getline(cin, in); 
    m->setYear(in);

    cout << "enter duration: ";
    getline(cin, in);
    m->setDuration(in);

    cout << "enter publisher: ";
    getline(cin, in); 
    m->setPublisher(in);

    mediaList->push_back((Media*)m);
    cout << "Music added" << endl << endl;
    
  }

  if (input == "VIDEO") {
    video* a = new video();
    a->setType("VIDEO");
    cout << "enter title: ";
    getline(cin, in);
    a->setTitle(in);

    cout << "enter year: ";
    getline(cin, in);
    a->setYear(in);

    cout << "enter publisher: ";
    getline(cin, in);
    a->setPublisher(in);

    cout << "enter rating: ";
    getline(cin, in);
    a->setRating(in);

    mediaList->push_back((Media*)a);
    cout << "Video game added" << endl << endl;
    
  }

  if (input == "MOVIE") {
    movie* b = new movie();
    b->setType("MOVIE");
    cout << "enter title: ";
    getline(cin, in);
    b->setTitle(in);

    cout << "enter director: ";
    getline(cin, in);
    b->setDirector(in);

    cout << "enter year: ";
    getline(cin, in);
    b->setYear(in);

    cout << "enter duration: ";
    getline(cin, in);
    b->setDuration(in);

    cout << "enter rating: ";
    getline(cin, in);
    b->setRating(in);

    mediaList->push_back((Media*)b);
    cout << "Movie added" << endl << endl;

  }

}

//print all entries
void printMedia(vector<Media*>* mediaList) {

  cout << "Total number of entries: " << mediaList->size() << endl;

  //if list size is 0 return
  if(mediaList->size() == 0){
    return;
  }

  //iterate through vector
  string type;
  for (vector<Media*>::iterator v = mediaList->begin(); v < mediaList->end(); v++) {
    type = (*v)->getType();

    if (type=="MUSIC") {
      music* m = (music*)(*v);
      
      cout<< "MUSIC: " << m->getTitle() << ", " <<  m->getArtist() << "," << m->getYear() << ", " << m->getDuration() << ", " << m->getPublisher()<<endl;
    }
    
 
    if (type == "VIDEO") {
      video* a = (video*)(*v);
      cout<<"VIDEO: "<< a->getTitle() << ", "<< a->getPublisher() << ", " << a->getYear() << ", " << a->getRating()<<endl;
    }

    if (type == "MOVIE") {
      movie* b = (movie*)(*v);
      cout<<"MOVIE: "<< b->getTitle() << ", " << b->getDirector() << ", " << b->getYear()<<", " << b->getDuration() <<", " << b->getRating()<<endl;

    }
    
   }

  cout << endl;



  
}

//search for an entry by inputing a word that matches the title or year, then outputs information that matches it
void searchMedia(vector<Media*>* mediaList) {
  string in;
  string inTitle ="";
  string inYear  ="";
  
  cin.ignore();
  cout << "search by title or year [enter 1 for title, 2 for year]? ";
  getline(cin, in);

  if (in == "1") {
    cout << "enter title: ";
    getline(cin, inTitle);
  }

  if (in == "2") {
    cout << "enter year: ";
    getline(cin, inYear);
  }

  //  cout<<"enter search value (title or year): ";
  //  getline(cin,in);
  
  //iterate through vector
  string type;
  for (vector<Media*>::iterator v = mediaList->begin(); v < mediaList->end(); v++) {
    type = (*v)->getType();

    if (type=="MUSIC") {
      music* m = (music*)(*v);

      if(m->getTitle() == inTitle || m->getYear() == inYear){
        cout<<"MUSIC: "<< m->getTitle() << ", " <<  m->getArtist() << ", " << m->getYear() << ", " << m->getDuration() << ", " << m->getPublisher()<<endl;
      }
    }


    if (type == "VIDEO") {
      video* a = (video*)(*v);

      if(a->getTitle() == inTitle || a->getYear() == inYear){
	cout<<"VIDEO: "<< a->getTitle() << ", "<< a->getPublisher() << ", " << a->getYear() << ", " << a->getRating()<<endl;
      }
    }

    if (type == "MOVIE") {
      movie* b = (movie*)(*v);

      if(b->getTitle() == inTitle || b->getYear() == inYear){
	cout<<"MOVIE: "<< b->getTitle() << ", " << b->getDirector() << ", " << b->getYear()<<", " << b->getDuration() <<", " << b->getRating()<<endl;

      }
    }

   }

  cout << endl;

}

//delete an entry
void deleteMedia(vector<Media*>* mediaList) {
  string input; 
  string yn;
  string type;
  
  cin.ignore();
  cout<<"which title should be deleted?" << endl;
  getline(cin, input);

  //loop through vector to find id and erase/delete it
  for (vector<Media*>::iterator v = mediaList->begin(); v < mediaList->end(); v++)
    {

      if ((*v)->getTitle() == input) {
 	 type = (*v)->getType();

         if (type == "MUSIC"){
	    music* m = (music*)(*v); 
	    cout<<"MUSIC: "<< m->getTitle() << ", " <<  m->getArtist() << ", " << m->getYear() << ", "
		<< m->getDuration() << ", " << m->getPublisher()<<endl;
	 }
	 
         if (type == "VIDEO") {
	   video* a = (video*)(*v);
	   cout<<"VIDEO: "<< a->getTitle() << ", "<< a->getPublisher() << ", " << a->getYear() << ", " << a->getRating()<<endl;
         }
	  

        if (type == "MOVIE") {
	   movie* b = (movie*)(*v);
            cout<<"MOVIE: "<< b->getTitle() << ", " << b->getDirector() << ", " << b->getYear()<<", " << b->getDuration() <<", " << b->getRating()<<endl;

	}    

	cout<<"ARE YOU SURE YOU WANT TO DELETE THIS [Y/N]? "<<endl;

        cin>>yn;
        cin.ignore();

        if (yn == "Y"){
           delete (*v);
           mediaList->erase(v);
           v--;
	   
	   cout << "Media deleted" << endl;  
        }
	
      }
    }

      cout << endl;
}

