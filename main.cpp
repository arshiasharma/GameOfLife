#include "GameOfLife.h"
#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"
#include <iostream>
#include <fstream>
#include <cstdlib> //for pause
#include <stdlib.h>

using namespace std;

int main (){

  string a;
  string b;
  int config;
  bool loop = true;
  int row;
  int column;
  float popDensity;
  string file;
  string fileInput;
  char** board;
  char** board2;
  char answer;

  if(loop){
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

      GameOfLife* g = new GameOfLife(row, column, popDensity);
      board = g->randGen();

      loop = false;

    }else if(config == 2){

      cout << "Enter the file: ";
      cin >> file;

      string temp = "";
      string line = "";

      ifstream infile(file);

      while(getline(infile, line)){
        temp += line;
      }

      //the char is converted to the ASCII code, subtracted by 48 to make up for it - README
      row = int(temp[0]) - 48;
      column = int(temp[1]) - 48;


      GameOfLife* g = new GameOfLife(row, column, temp);
      board = g->fileGen();

      loop = false;

    }else{
      cout << "Please enter 1 or 2: " << endl;
      cin >> answer;

      //ERROR
    //  continue;
    }
  }

  cout << "Pick a board to begin to play: Classic (C), Donut (D), Mirror (M): ";
  cin >> b;

  cout << "Would you like the boards mapped to a file (y/n): ";
  cin >> a;

  if(a == "y"){
    cout << "Enter output file name: ";
    cin >> fileInput;
  }

  int count = 0;

  if((b == "c") || (b == "classic")){

      if(a == "y"){

          ofstream output;

          //will override what is in the file currently; will keep all the data that will be written until the program is executed again
          output.open (fileInput);
          output << "Board 0" << endl;

          for(int i = 0; i < row; i++){
              for(int j = 0; j < column; j++){
               output << board[i][j] << "\t";
              }
              output << "\n";
            }
            output.close();
            count++;

          while(count < 100){

            ClassicMode* c = new ClassicMode(row, column, board);

            c->simulation();
            board = c->fileBoard(fileInput, count);
            count++;

            if(c->isEqual()){
              cout << endl;
              cout << "Board repeats or is empty, program ends after " << count - 1 << " boards" << endl;
              cout << "Check " << fileInput << " for data" << endl;
              break;
            }
          }

      }else if (a == "n"){
        while(count < 100){

          ClassicMode* c = new ClassicMode(row, column, board);

          count++;
          c->simulation();
          board = c->printBoard();

          cout << "Board number: " << count << endl;
          cout << endl;
          cout << "Do you wish to continue (y/n): ";
          cin >> answer;

          if(answer == 'y' || answer == 'Y'){
            if(c->isEqual()){
              cout << "Board repeats or is empty, program ends" << endl;
              cout << "Press enter to quit" << endl;

              //HOW TO EXIT FROM ENTER
              break;
            }else{
              continue;
            }
          }else if(answer == 'n' || answer == 'N'){
            break;
          }else{
            cout << "Please answer y/n" << endl;
          }
        }
      }

    }else if((b == "d") || (b == "donut")){

      if(a == "y"){

        ofstream output;

        //will override what is in the file currently; will keep all the data that will be written until the program is executed again
        output.open (fileInput);
        output << "Board 0" << endl;

        for(int i = 0; i < row; i++){
          for(int j = 0; j < column; j++){
              output << board[i][j] << "\t";
          }
          output << "\n";
        }
        output.close();
        count++;

        while(count < 100){

          DonutMode* d = new DonutMode(row, column, board);

          d->simulation();
          board = d->fileBoard(fileInput, count);
          count++;

          if(d->isEqual()){
            cout << endl;
            cout << "Board repeats or is empty, program ends after " << count - 1 << " boards" << endl;
            cout << "Check " << fileInput << " for data" << endl;
            break;
          }
        }

      }else if (a == "n"){

        while(count < 100){

          DonutMode* d = new DonutMode(row, column, board);

          count++;
          d->simulation();
          board = d->printBoard();

          cout << "Board number: " << count << endl;
          cout << endl;
          cout << "Do you wish to continue (y/n): ";
          cin >> answer;

          if(answer == 'y' || answer == 'Y'){
            if(d->isEqual()){
              cout << "Board repeats or is empty, program ends" << endl;              cout << "Press enter to quit" << endl;

            //HOW TO EXIT FROM ENTER
              break;
            }else{
              continue;
            }
          }else if(answer == 'n' || answer == 'N'){
            break;
        }else{
          cout << "Please answer y/n" << endl;
        }
      }
    }

    }else if((b == "m") || (b == "mirror")){

      if(a == "y"){
        ofstream output;

        //will override what is in the file currently; will keep all the data that will be written until the program is executed again
        output.open (fileInput);
        output << "Board 0" << endl;

        for(int i = 0; i < row; i++){
          for(int j = 0; j < column; j++){
              output << board[i][j] << "\t";
          }
          output << "\n";
        }
        output.close();
        count++;

        while(count < 100){

          MirrorMode* m = new MirrorMode(row, column, board);

          m->simulation();
          board = m->fileBoard(fileInput, count);
          count++;

          if(m->isEqual()){
            cout << endl;
            cout << "Board repeats or is empty, program ends after " << count - 1 << " boards" << endl;
            cout << "Check " << fileInput << " for data" << endl;
            break;
          }
        }

      }else if (a == "n"){
        while(count < 100){

          MirrorMode* m = new MirrorMode(row, column, board);

          count++;
          m->simulation();
          board = m->printBoard();

          cout << "Board number: " << count << endl;
          cout << endl;
          cout << "Do you wish to continue (y/n): ";
          cin >> answer;

          if(answer == 'y' || answer == 'Y'){
            if(m->isEqual()){
              cout << "Board repeats or is empty, program ends" << endl;              cout << "Press enter to quit" << endl;

            //HOW TO EXIT FROM ENTER
              break;
            }else{
              continue;
            }
          }else if(answer == 'n' || answer == 'N'){
            break;
        }else{
          cout << "Please answer y/n" << endl;
        }
      }
    }
  }
}
