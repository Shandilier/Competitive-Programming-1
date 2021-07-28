#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Node
{
    Node *next=NULL;
    Node *prev=NULL;
}

class Product
{
    public:
        virtual double getPrice() = 0;
};
class Coke: public Product
{
    public:
        double getPrice()
        {
            return 1.0;
        }
};

class Water: public Product
{
    public:
        double getPrice()
        {
            return 0.8;
        }
};

class Chips: public Product
{
    public:
        double getPrice()
        {
            return 0.9;
        }   
};

class Payment
{
    public:
        virtual double checkout(Product *p) = 0;
};

class Cash: public Payment
{
    public:
        double checkout(Product *p)
        {
            return p->getPrice()*12;
        }
};

class Card: public Payment
{
    public:
        double checkout(Product *p)
        {
            return p->getPrice()*10;
        }
};

class VendingMachine
{
    private:
        unordered_map<string,Product*>slots;
        int capacity;
    public:
        VendingMachine(int cap) : capacity(cap){};

        bool addProduct(string position,Product *p)
        {
            if(slots.size()>=capacity)
            {
                return false;
            }
            slots.insert({position,p});
            return true;
        }

        Product *order(string slot)
        {
            unordered_map<string,Product*> ::iterator it;
            it = slots.find(slot);
            if(it==slots.end())
            {
                slots.erase(it);
                return NULL;
            }
            return it->second;
        }
};

class Customer
{
    private:
        VendingMachine *vm;
        vector<Product*> cart;
    public:
        Customer(VendingMachine *v): vm(v){};

        bool select(string slot)
        {
            Product *p = vm->order(slot);
            if(p)
            {
                cart.push_back(p);
                return true;
            }
            return false;
        }

        double checkOut(Payment *payment)
        {
            double total_cost = 0.0;
            for(auto x:cart)
            {
                total_cost+=(payment->checkout(x));
            }
            return total_cost;
        }
};

int main()
{
    auto coke = new Coke();
    auto water = new Water();
    auto chips = new Chips();
    auto vm = new VendingMachine(5);
    vm->addProduct("A1",coke);
    vm->addProduct("A2",water);
    vm->addProduct("A3",chips);
    Customer *customer = new Customer(vm);
    customer->select("A1");
    customer->select("A2");
    auto card = new Cash();
    double cost = customer->checkOut(card);
    cout<<cost<<endl;
    return 0;
}