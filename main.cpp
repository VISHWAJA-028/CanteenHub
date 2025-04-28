#include <iostream>
#include<string>
#include<queue>
using namespace std;
class order;
 public:
    int tokenId;
    string itemType;
    string paymentType;
    int takingTime;
    order(int id;string item; string payment; int time)
        :tokenID(id), itemType(item), paymentType(payment), takingTime(time) {}
};
class QueueManager {
    priavte:
        queue<order> beverageQueue;
        queue<order> lunchQueue;
    public:
        void addOrder(const Order& object order){
            if(order.iteamType == "beverage"){
                beverageQueue.push(order);
                cout<<" added tokenID:"<<order.tokenID<< "to the beverage counter \n";
            }
            else if (order.itemType =="lunch"){
                lunchQueue.push(order);
                cout<<"added tokenID"<< order.tokenID<< "to the lunch counter\n";
            }
            else{
                cout<< "Invalid order type.\n";
            }
            }
        }
}