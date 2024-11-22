#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct payment{
    string name;
    int amount;
};

// Function for linear search
bool linearSearchinStack(stack<payment>s,const string& targetName,payment& result){
    while(!s.empty()){
        payment currentpayment=s.top();
        s.pop();
        if(currentpayment.name==targetName){
            result=currentpayment;
            return true;
        }
    }
    return false;
}

int main(){
    queue<payment>greenGarden;
    greenGarden.push({"Tamim", 110});
    greenGarden.push({"Naim", 120});
    greenGarden.push({"Munna", 140});
    greenGarden.push({"Parvez", 135});

    //create stack for CS payment
    stack<payment>campusStore;

    //Payment transfer GG to CS
    while(!greenGarden.empty()){
        campusStore.push(greenGarden.front());
        greenGarden.pop();
    }
    payment naimpayment;
    if(linearSearchinStack(campusStore, "Naim" , naimpayment)){
        cout<< "Found Naim payment: "<< naimpayment.amount<< " TK "<<endl;
    }else{
        cout<<"Naim`s payment not found"<<endl;
    }
    return 0;
}