#include <iostream>

using namespace std;

class MirrorMode{
  private:
    int neighborCount;
    int row;
    int column;
    char **board;
    char **board2;

  public:
    MirrorMode();
    MirrorMode(int row, int column, char** board);
    ~MirrorMode();
    void simulation();
    void getBoard(int i, int j, int neighborCount);
    char** printBoard();
    bool isEqual();
    char** fileBoard(string fileInput, int count);
};
