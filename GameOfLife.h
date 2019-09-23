#include <iostream>

using namespace std;

class GameOfLife{
  protected:
    int row;
    int column;
    char **board;
    char **board2;
    float popDensity;
    string temp;


  public:
    GameOfLife();
    GameOfLife(int row, int column, float popDensity);
    GameOfLife(int row, int column, string temp);
    ~GameOfLife();

    //method for prompting the user
    char** randGen();
    char** fileGen();
    int getRow();
    int getColumn();



};
