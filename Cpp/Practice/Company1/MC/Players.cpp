#include<bits/stdc++.h>
using namespace std;
class Players
{
    private:
        string name;
        int position;
        bool won;
    public:
        Players(string name)
        {
            this->name = name;
            this->position = 0;
            this->won = false;
        }
        void setPosition(Player player,int pos)
        {
            player.position = pos;
        }
        int getPosition(Players player)
        {
            return player.position;
        }

        void setWon(Player player,bool res)
        {
            player.won = res;
        }
        bool getResult(Player player)
        {
            return player.won;
        }
};