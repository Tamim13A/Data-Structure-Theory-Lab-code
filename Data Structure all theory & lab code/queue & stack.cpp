#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//Structure for payment
struct payment{
    string name;
    int amount;
};

int main(){
    //create queue for GG payment
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
    cout<< "Payment in Campus Store:" <<endl;
    while(!campusStore.empty()){
        payment currentpayment=campusStore.top();
        cout<< currentpayment.name<< " paid: "<<currentpayment.amount<< " TK"<<endl;
        campusStore.pop();
    }
    return 0;
}