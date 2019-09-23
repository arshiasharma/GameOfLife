#include <iostream>

using namespace std;

class ClassicMode{
  private:
    int neighborCount;
    int row;
    int column;
    char **board;
    char **board2;


  public:
    ClassicMode();
    ClassicMode(int row, int column, char** board);
    ~ClassicMode();
    void simulation();
    void getBoard(int i, int j, int neighborCount);
    char** printBoard();
    bool isEqual();
    char** fileBoard(string fileInput, int count);

};
