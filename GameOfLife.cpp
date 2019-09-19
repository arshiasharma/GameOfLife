#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;

//three subclasses - each subclass will call prompt

GameOfLife::GameOfLife(){
  row = 0;
  column  = 0;
  popDensity = 0;
  file = "";
}

GameOfLife::GameOfLife(int r, int c, float p, string f){
  row = r;
  column  = c;
  popDensity = p;
  file = f;
}


GameOfLife::~GameOfLife(){
  delete board;
}

void GameOfLife::RandGen(){
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
      cout << endl;
      for(int j = 0; j < column; j++){
        if(!(board[i][j] == 'X')){
          board[i][j] = '-';
          board2[i][j] = '-';
        }
       cout << board[i][j] << "\t";
      }
    }
    cout << endl;
  }

  //void GameOfLife::FileGen(){

//  }
