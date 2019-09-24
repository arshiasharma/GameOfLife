#include "GameOfLife.h"
#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (){

  string a;
  string b;
  int config  = 0;
  bool loop = true;
  bool mainLoop = true;
  int row;
  int column;
  float popDensity;
  string file;
  string fileInput;
  char** board;
  char** board2;
  char answer;
  string slow;
  int check = 0;

  //Loop for making a random generation or import from a file
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

      //makes Board 0
      GameOfLife* g = new GameOfLife(row, column, popDensity);
      board = g->randGen();

      loop = false;

    }else if(config == 2){

      cout << "Enter the file: ";
      cin >> file;

      string temp = "";
      string line = "";

      //opens a file - learned from Assignment 1
      ifstream infile(file);

      while(getline(infile, line)){
        temp += line;
      }

      //the char is converted to the ASCII code, subtracted by 48 to make up for it - README
      row = int(temp[0]) - 48;
      column = int(temp[1]) - 48;

      //makes Board 0
      GameOfLife* g = new GameOfLife(row, column, temp);
      board = g->fileGen();

      loop = false;


    }else{
      cout << "Please enter 1 or 2: " << endl;
      loop = true;
      continue;
    }
  }

  while(mainLoop){
    //Lets user choose what game mode
    cout << "Pick a board to begin to play: Classic (C), Donut (D), Mirror (M): ";
    cin >> b;

    //If the data should be in a file instead of the terminal
    cout << "Would you like the boards mapped to a file (y/n): ";
    cin >> a;

    if(a == "y"){
      cout << "Enter output file name: ";
      cin >> fileInput;
    }

    int count = 0;

    //ClassicMode loop
    if((b == "c") || (b == "classic")){

        if(a == "y"){

            //Opening a text file
            ofstream output;

            //will override what is in the file currently; will keep all the data that will be written until the program is executed again
            output.open (fileInput);
            output << "Board 0" << endl;

            //iterating through the 2D array
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                 output << board[i][j] << "\t";
                }
                output << "\n";
              }
              output.close();
              count++;

            //high number to ensure enough loops
            while(count < 100){

              //making an object of class ClassicMode
              ClassicMode* c = new ClassicMode(row, column, board);

              //Entering simulation method
              c->simulation();

              //method to print data to file
              board = c->fileBoard(fileInput, count);
              count++;

              //method to check if the boards are the same
              if(c->isEqual()){
                check++;

                if(check == 5){
                  cout << "Board stablizes or is empty, program ends" << endl;
                  cout << "Press enter to quit" << endl;
                  break;
                }
              }else{
                continue;
              }
            }

        //prints data to the terminal
        }else if (a == "n"){
          while(count < 1000){

            //making an object of class ClassicMode
            ClassicMode* c = new ClassicMode(row, column, board);

            count++;

            //Entering simulation method
            c->simulation();

            //prints board to the terminal
            board = c->printBoard();

            cout << "Board number: " << count << endl;
            cout << endl;


            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            if(c->isEqual()){
              check++;

              if(check == 5){
                cout << "Board stablizes or is empty, program ends" << endl;
                cout << "Press enter to quit" << endl;
                break;
              }
            }else{
              continue;
            }
          }
        }

        mainLoop = false;

      //Donut loop
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
              check++;

              if(check == 5){
                cout << "Board stablizes or is empty, program ends" << endl;
                cout << "Press enter to quit" << endl;
                break;
              }
            }else{
              continue;
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


            //slowing down the prgram
            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            //checking to see if the boards stabalize
            if(d->isEqual()){
              check++;

              if(check == 5){
                cout << "Board stablizes or is empty, program ends" << endl;
                cout << "Press enter to quit" << endl;
                break;
              }
            }else{
              continue;
            }
          }
        }

        mainLoop = false;

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
              check++;

              if(check == 5){
                cout << "Board stablizes or is empty, program ends" << endl;
                cout << "Press enter to quit" << endl;
                break;
              }
            }else{
              continue;
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

            //slowing down the prgram
            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            //checking to see if the boards stabalize
            if(m->isEqual()){
              check++;

              if(check == 5){
                cout << "Board stablizes or is empty, program ends" << endl;
                cout << "Press enter to quit" << endl;
                break;
              }
            }else{
              continue;
            }
          }
        }
        mainLoop = false;
      }else{
        cout << "Did not enter the right mode, please try again" << endl;
        mainLoop = true;
      }
    }
  }
