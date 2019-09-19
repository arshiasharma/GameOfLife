#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (){

  string b;

  int config;
  bool loop = true;
  int row;
  int column;
  float popDensity;
  string file;

  while(loop){
    cout << "Do you wish to start with a random configuration, or specify a flatfile configuration" << endl;
    cout << "Enter 1 for random or 2 for flatfile: ";
    cin >> config;

    if(config == 1){
      cout << "Please enter the dimenisions for the world" << endl;

      cout << "Enter rows: ";
      cin >> row;
      cout << "Enter columns: ";
      cin >> column;

      cout << "Enter a decimal for the population density: ";
      cin >> popDensity;

      loop = false;

    }else if(config == 2){

      string line = "";
      cout << "Enter the file: ";
      cin >> file;
      
      loop = false;

      //read the file and have row and columns answered

    }else{
      cout << "Please enter 1 or 2";
    }
  }

  GameOfLife* g = new GameOfLife(row, column, popDensity, file);
  g->RandGen();

  /**
  cout << "Pick a board to begin to play: Classic (C), Donut (D), Mirror (M): ";
  cin >> b.ToLower();

  if((b == "c") || (b == "classic")){

    //Classic class c->Prompt();

  }else if((b == "d") || (b == "donut")){

    //Donut class d->Prompt();

  }else if(b == "m") || (b == "mirror")){

    //Mirror class m->Prompt();

  }
  */
}
