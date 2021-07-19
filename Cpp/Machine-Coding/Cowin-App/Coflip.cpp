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
        vector<VaccineInventory> vaccineInventory;
    // vector<User> user;
};

class User
{
    public:
        string name;
        string gender;
        string preferredVaccine;
        // Centre centre;
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
    // vector<User> user;
        vector<Centre> centreList;
        vector<User> userList;

        void registerUser(string userName, string gender, string vaccineType)
        {
            User user(userName,gender,vaccineType);
            userList.push_back(user);
            // cout<<"hello"<<endl;
        }  

        void registerCentre(int centreId, vector<VaccineInventory> v)
        {
            // cout<<userList.size()<<endl;
            Centre centre;
            centre.centreId = centreId;
            centre.vaccineInventory = v;
            centreList.push_back(centre);
        }

        vector<Centre> getCentres(User user)
        {
            vector<Centre> cList;
            // cout<<user.name<<" "<<user.preferredVaccine<<" "<<user.gender<<endl;
            // cout<<centreList.size()<<endl;
            Centre centre;
            for(int i=0;i<centreList.size();i++)
            {
                vector<VaccineInventory>v = centreList[i].vaccineInventory;

                for(int j=0;j<v.size();j++)
                {
                    // cout<<v[j].vaccineType<<endl;
                    if(v[j].vaccineType == user.preferredVaccine)
                    {
                        cList.push_back(centreList[i]);
                        break;
                    }
                }
            }
            // cout<<cList.size()<<endl;
            return cList;
        }
        bool bookSlot(User user, int centreId,vector<Centre>v)
        {
            Centre centre;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].centreId == centreId)
                {
                    centre = v[i];
                    break;
                }
            }
            vector<VaccineInventory>vi = centre.vaccineInventory;
            for(int i=0;i<vi.size();i++)
            {
                if(vi[i].vaccineType == user.preferredVaccine)
                {
                    if(vi[i].count>0)
                    {
                        vi[i].count-=1;
                        return true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            return false;
        }
};
bool compare(Centre a, Centre b)
{
    return a.centreId > b.centreId;
    // return true;
}
int main()
{
    Coflip coflip;
    coflip.registerUser("Sachin","Male","Covishield");
    VaccineInventory v1("Covaxine",10);
    VaccineInventory v2("Covaxine",20);
    VaccineInventory v5("Covishield",5);
    vector<VaccineInventory>v3={v1};
    vector<VaccineInventory>v4={v2,v5};
    coflip.registerCentre(1,v3);
    coflip.registerCentre(2,v4);
    // cout<<coflip.centreList.size()<<endl;
    User user("Sachin","Male","Covishield");
    vector<Centre>v = coflip.getCentres(user);
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        Centre c = v[i];
        vector<VaccineInventory>temp = c.vaccineInventory;
        cout<<"Centre Id: "<<c.centreId<<endl;
        for(int j=0;j<temp.size();j++)
        {
            cout<<"Vaccine type: "<<temp[j].vaccineType<<endl;
            cout<<"Count: "<<temp[j].count<<endl;
        } 
        cout<<"***************************"<<endl;
    }
    if(coflip.bookSlot(user,2,v))
    {
        cout<<"Booked"<<endl;
    }
    else
    {
        cout<<"Not booked"<<endl;
    }
    
    // cout<<coflip.userList.size()<<endl;
    // cout<<v.size()<<endl;
    return 0;
}