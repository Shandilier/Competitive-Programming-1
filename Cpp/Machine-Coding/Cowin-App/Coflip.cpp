#include<bits/stdc++.h>
using namespace std;

class User;
class VaccineInventory
{
    public:
    string vaccineType;
    int count;
    VaccineInventory(string vaccineType,int count)
    {
        this->vaccineType = vaccineType;
        this->count = count;
    }
};
class Centre
{

    public:
    int centreId;
    vector<VaccineInventory *> vaccineInventory;
    vector<User *> user;
    int numberOfBookings = 0;
    Centre(int centreId,int numberOfBookings)
    {
        this->centreId = centreId;
        this->numberOfBookings = numberOfBookings;
    }
};

class User
{
    public:
    string name;
    string gender;
    string preferredVaccine;
    Centre *centre;
    User(string name, string gender, string preferredVaccine)
    {
        this->name = name;
        this->gender = gender;
        this->preferredVaccine = preferredVaccine;
    }
};

class Coflip
{
    public:
    // vector<User*> user;
    vector<Centre*> centreList;
    vector<User*> userList;
    public:
        bool compare(const Centre* &a, const Centre* &b)
        {
            // vector<VaccineInventory*>v1 = a->vaccineInventory;
            // vector<VaccineInventory*>v2 = b->vaccineInventory;
            // int sum1=0,sum2=0;
            // for(int i=0;i<v1.size();i++)
            // {
            //     sum1+=v1[i]->count;
            // }
            // for(int i=0;i<v2.size();i++)
            // {
            //     sum2+=v2[i]->count;
            // }           
            // if(sum1==sum2)
            //     return a->numberOfBookings <b->numberOfBookings;
            // return sum1>sum2;
            return a->centreId > b->centreId;
            // return true;
        }

        void registerUser(string userName, string gender, string vaccineType)
        {
            User *user = new User(userName,gender,vaccineType);
            userList.push_back(user);
            // cout<<"hello"<<endl;
        }  

        void registerCentre(int centreId, vector<VaccineInventory*> v)
        {
            // cout<<userList.size()<<endl;
            Centre *centre = new Centre(centreId,0);
            centre->vaccineInventory = v;
            centreList.push_back(centre);
        }

        vector<Centre*> getCentres(User *user)
        {
            vector<Centre*> cList;
            // cout<<user->name<<" "<<user->preferredVaccine<<" "<<user->gender<<endl;
            // cout<<centreList.size()<<endl;
            Centre *centre;
            for(int i=0;i<centreList.size();i++)
            {
                vector<VaccineInventory*>v = centreList[i]->vaccineInventory;

                for(int j=0;j<v.size();j++)
                {
                    // cout<<v[j]->vaccineType<<endl;
                    if(v[j]->vaccineType == user->preferredVaccine)
                    {
                        cList.push_back(centreList[i]);
                        break;
                    }
                }
            }
            // cout<<cList.size()<<endl;
            // sort(cList.begin(),cList.end(),this->compare);
            return cList;
        }
        bool bookSlot(User *user, Centre *centre)
        {
            return false;
        }
};

int main()
{
    Coflip *coflip = new Coflip();
    coflip->registerUser("Sachin","Male","Covaxine");
    VaccineInventory *v1 = new VaccineInventory("Covaxine",10);
    VaccineInventory *v2 = new VaccineInventory("Covaxine",20);
    VaccineInventory *v5 = new VaccineInventory("Covishield",5);
    vector<VaccineInventory*>v3={v1};
    vector<VaccineInventory*>v4={v2,v5};
    coflip->registerCentre(1,v3);
    coflip->registerCentre(2,v4);
    // cout<<coflip->centreList.size()<<endl;
    User *user = new User("Sachin","Male","Covaxine");
    vector<Centre*>v = coflip->getCentres(user);
    for(int i=0;i<v.size();i++)
    {
        Centre *c = v[i];
        vector<VaccineInventory*>temp = c->vaccineInventory;
        cout<<"Centre Id: "<<c->centreId<<endl;
        for(int j=0;j<temp.size();j++)
        {
            cout<<"Vaccine type: "<<temp[j]->vaccineType<<endl;
            cout<<"Count: "<<temp[j]->count<<endl;
        } 
        cout<<"****************************"<<endl;
    }
    // cout<<coflip->userList.size()<<endl;
    cout<<v.size()<<endl;
    return 0;
}