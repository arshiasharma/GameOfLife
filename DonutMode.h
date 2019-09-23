#include <iostream>

using namespace std;

class DonutMode{
  private:
    int neighborCount;
    int row;
    int column;
    char **board;
    char **board2;

  public:
    DonutMode();
    DonutMode(int row, int column, char** board);
    ~DonutMode();
    void simulation();
    void getBoard(int i, int j, int neighborCount);
    char** printBoard();
    bool isEqual();
    char** fileBoard(string fileInput, int count);
};
