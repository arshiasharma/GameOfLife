#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;

//three subclasses - each subclass will call prompt

GameOfLife::GameOfLife(){
  row = 0;
  column  = 0;
  popDensity = 0;
  temp = "";
}

GameOfLife::GameOfLife(int r, int c, float p){
  row = r;
  column  = c;
  popDensity = p;
}

GameOfLife::GameOfLife(int r, int c, string t){
  row = r;
  column  = c;
  temp = t;
}

int GameOfLife::getRow(){
  return row;
}

int GameOfLife::getColumn(){
  return column;
}


GameOfLife::~GameOfLife(){
  delete board;
}

char** GameOfLife::randGen(){
  srand(time(0)); //to make the rand actually random

  board = new char *[row];
		for(int i = 0; i < row ; i++){
		    board[i] = new char[column];
		}

  board2 = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   board2[i] = new char[column];
  	}

  int mult = row * column;

  int cells = mult * popDensity;
  //cout << cells << endl;

  //forloop to generate two random numbers from the sizes of row/column to populate board

  int i = 0;
  while(i < cells){
      int a =  rand() % row;
      int b =  rand() % column;

      if(board[a][b] == 'X'){
        continue;
      }else{
        board[a][b] = 'X';
        board2[a][b] = 'X';
        i++;
      }
    }

    for(int i = 0; i < row; i++){
      //cout << endl;
      for(int j = 0; j < column; j++){
        if(!(board[i][j] == 'X')){
          board[i][j] = '-';
          board2[i][j] = '-';
        }
      // cout << board[i][j] << "\t";
      }
    }
    cout << endl;
    return board;
  }

  char** GameOfLife::fileGen(){

    board = new char *[row];
  		for(int i = 0; i < row ; i++){
  		    board[i] = new char[column];
  		}

    board2 = new char *[row];
    	for(int i = 0; i < row ; i++){
    		   board2[i] = new char[column];
    	}

      //make a loop thing
      int count = 2;

      cout << "Board 0" << endl;
        for(int i = 0; i < row; i++){
          cout << endl;
          for(int j = 0; j < column; j++){
              board[i][j] = char(temp[count]);
              board2[i][j] = char(temp[count]);
              count++;

              cout << board[i][j] << "\t";
            }
        }
        cout << endl;
        return board;
    }
