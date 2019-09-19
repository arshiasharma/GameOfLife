#include <iostream>

using namespace std;

class GameOfLife{
  private:
    int row;
    int column;
    char **board;
    char **board2;
    float popDensity;
    string file;


  public:
    GameOfLife();
    GameOfLife(int row, int column, float popDensity, string file);
    ~GameOfLife();

    //method for prompting the user
    void RandGen();
    void FileGen();



};
