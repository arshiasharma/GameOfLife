#include "MirrorMode.h"
#include <iostream>
#include <fstream>

using namespace std;

MirrorMode::MirrorMode(){
  neighborCount = 0;
  row = 0;
  column = 0;
}

MirrorMode::MirrorMode(int r, int c, char** b){
  row = r;
  column  = c;

  board = b;
  board2 = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   board2[i] = new char[column];
  	}
}

MirrorMode::~MirrorMode(){
  delete board;
  delete board2;
}

void MirrorMode::simulation(){

  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){

      neighborCount = 0;

      //corner cells
      if((i == 0) && (j == 0)){
        if(board[i][j] == 'X'){
          neighborCount += 3;
        }if(board[i][j+1] == 'X'){
          neighborCount += 2;
        }if(board[i+1][j] == 'X'){
          neighborCount+=2;
        }if(board[i+1][j+1] == 'X'){
          neighborCount++;
        }
        getBoard(i, j, neighborCount);
        neighborCount = 0;

        //corner cells
      }else if((i == 0) && (j == (column - 1))){
        if(board[i][j] == 'X'){
          neighborCount += 3;
        }if(board[i][j-1] == 'X'){
          neighborCount += 2;
        }if(board[i+1][j-1] == 'X'){
          neighborCount += 2;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }
        getBoard(i, j, neighborCount);
        neighborCount = 0;

        //corner cells
      }else if((i == (row - 1)) && (j == (column - 1))){
        if(board[i][j] == 'X'){
          neighborCount += 3;
        }if(board[i][j-1] == 'X'){
          neighborCount += 2;
        }if(board[i-1][j] == 'X'){
          neighborCount += 2;
        }if(board[i-1][j-1] == 'X'){
          neighborCount++;
        }
        cout << neighborCount << endl;
        getBoard(i, j, neighborCount);
        neighborCount = 0;

        //corner cells
      }else if((i == (row - 1)) && (j == 0)){
        if(board[i][j] == 'X'){
          neighborCount += 3;
        }if(board[i][j+1] == 'X'){
          neighborCount+=2;
        }if(board[i-1][j] == 'X'){
          neighborCount+=2;
        }if(board[i-1][j+1] == 'X'){
          neighborCount++;
        }
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      }else if((!(i == 0) || (!(i == (row - 2)))) && (j == 0)){
        if(board[i][j] == 'X'){
          neighborCount ++;
        }if(board[i-1][j] == 'X'){
          neighborCount += 2;
        }if(board[i-1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j+1] == 'X'){
          neighborCount++;
        }if(board[i+1][j+1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount += 2;
        }
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      }else if((0 < i <= (row - 2)) && (j == (column - 1))){
        if(board[i][j] == 'X'){
          neighborCount ++;
        }if(board[i-1][j] == 'X'){
          neighborCount += 2;
        }if(board[i-1][j-1] == 'X'){
          neighborCount++;
        }if(board[i][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount += 2;
        }
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      }else if((i == 0) && (0 < j <= (column - 2))){
        if(board[i][j] == 'X'){
          neighborCount ++;
        }if(board[i][j-1] == 'X'){
          neighborCount += 2;
        }if(board[i+1][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }if(board[i+1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j+1] == 'X'){
          neighborCount += 2;
        }
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      }else if((i == (row - 1)) && (0 < j <= (column - 2))){
        if(board[i][j] == 'X'){
          neighborCount ++;
        }if(board[i][j-1] == 'X'){
          neighborCount += 2;
        }if(board[i-1][j-1] == 'X'){
          neighborCount++;
        }if(board[i-1][j] == 'X'){
          neighborCount++;
        }if(board[i-1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j+1] == 'X'){
          neighborCount += 2;
        }
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      }else{
        if(board[i-1][j-1] == 'X'){
          neighborCount++;
        }if(board[i-1][j] == 'X'){
          neighborCount++;
        }if(board[i-1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j-1] == 'X'){
          neighborCount++;
        }if(board[i][j+1] == 'X'){
          neighborCount++;
        }if(board[i+1][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }if(board[i+1][j+1] == 'X'){
          neighborCount++;
        }
        getBoard(i, j, neighborCount);
        neighborCount = 0;
      }
    }
  }
}

void MirrorMode::getBoard(int i, int j, int count){

    if(count == 3){
      board2[i][j] = 'X';

    }else if(count == 4){
      board2[i][j] = '-';

    }else if(count == 1 || count == 0){
      board2[i][j] = '-';

    }else if(count == 2){
      board2[i][j] = board[i][j];
    }else{
      board2[i][j] = '-';
    }
}

char** MirrorMode::printBoard(){

  if(board == board2){
    cout << "Board is the same" << endl;

  }
  for(int i = 0; i < row; i++){
    cout << endl;
    for(int j = 0; j < column; j++){
     cout << board2[i][j] << "\t";
    }
  }
  cout << endl;
  return board2;
}

bool MirrorMode::isEqual(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
        if (board[i][j] != board2[i][j]){
            return false;
        }
      }
    }
  return true;
}

char** MirrorMode::fileBoard(string file, int count){
  ofstream answerFile;

  answerFile.open(file, fstream::app);

  answerFile << "Board " << count << endl;

  for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
       answerFile << board2[i][j] << "\t";
      }
      answerFile << "\n";
    }
    answerFile << endl;
    answerFile.close();
    return board2;
}
