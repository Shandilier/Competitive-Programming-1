#include<bits/stdc++.h>
using namespace std;

class Board
{
    private:
        int start,end,size;
    public:
        Board(int size)
        {
            this->start = 1;
            this->size = size;
            this.end = start+size-1;
        }
        int getStart()
        {
            return start;
        }
        int getSize()
        {
            return size;
        }
};