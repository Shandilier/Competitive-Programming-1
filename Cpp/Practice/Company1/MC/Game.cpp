#include<bits/stdc++.h>
using namespace std;
class Game
{
    private:
        int numberOfSnakes;
        int numberOfLadders;
        deque<Players> players;
        vector<Ladder> ladders;
        vector<Snake> snakes;
        Board board;
        Dice dice;
    public:
        Game(int numberOfSnakes,int numberOfLadders,int boardSize)
        {
            this->numberOfSnakes = numberOfSnakes;
            this->numberOfLadders = numberOfLadders;
            this->players = deque<Players>d;
            ladders = vector<Ladder>(numberOfLadders);
            snakes = vector<Snake>(numberOfSnakes);
            board = new Board(boardSize);
            dice = new Dice(1,6,boardSize);
        }

        initBoard();

    private:
        void initBoard()
        {
            set<pair<int,int> >s;
            for(int i=0;i<=numberOfSnakes;i++)
            {
                while(true)
                {
                    int head = (rand() % (board.getSize() - board.getStart()+1));
                    int tail = (rand() % (board.getSize() - board.getStart()+1));
                    if(tail>=head)
                        continue;
                    if(s.find(make_pair(head,tail))==s.end())
                    {
                        Snake snake = new Snake(head,tail);
                        snakes.push_back(snake);
                        s.insert(make_pair(head,tail));
                        break;
                    }
                }
            }
            for(int i=0;i<=numberOfLadders;i++)
            {
                while(true)
                {
                    int start = (rand() % (board.getSize() - board.getStart()+1));
                    int end = (rand() % (board.getSize() - board.getStart()+1));
                    if(end<=start)
                        continue;
                    if(s.find(make_pair(start,end))==s.end())
                    {
                        Ladder ladder = new Snake(start,end);
                        ladders.push_back(ladder);
                        s.insert(make_pair(start,end));
                        break;
                    }
                }
            }
        }

        public:
            void addPlayer(Player player)
            {
                players.push_back(player);
            }

            void playGame()
            {
                while(true)
                {
                    Player player = players.front();
                    int val = dice.roll();
                    int initialPosition = player.getPosition(player);
                    if(initialPosition+val>board.getSize())
                    {
                        cout<<"Can't move"<<endl;
                        continue;
                    }
                    else
                    {
                        int newPos = initialPosition+val;
                        player.setPosition(player.getPosition,newPos);
                        if(player.getPosition(player)==board.getSize())
                        {
                            player.setWon(true);
                        }
                        else
                        {
                            players.pop_front();
                        }
                        
                    }
                }
            }
}