#include<bits/stdc++.h>
using namespace std;
class Dice
{
    private:
        int minValue,maxValue,initialPosition =0;
    
    public:
        Dice(int minValue,int maxvalue,int initialPosition)
        {
            this->minValue = minValue;
            this->maxValue = maxValue;
            this->initialPosition = initialPosition;
        }
        int roll()
        {
            int num = (rand() % (maxValue - minValue + 1)) + 1;
            return num;
        }
};