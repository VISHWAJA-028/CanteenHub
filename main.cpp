#include <iostream>
#include<string>
#include<queue>
using namespace std;
class order{
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
        void processOrder(const string& counterType){
            if(counterType =="beverage"){
                if(beverageQueue.empty()){
                    cout<<"no orders at the beverage counter to process.\n";
                }
                else{
                    order current  = beverageQueue.front();
                    beverageQueue.pop();
                    cout<<"processing Beverage order ID "<< current.tokenID<< << " (Payment: " << current.paymentType << ").\n";

                }
            } else if (counterType == "Lunch") {
                if (lunchQueue.empty()) {
                    cout << "No orders at the Lunch Counter to process.\n";
                    
                } else {
                    Order current = lunchQueue.front();
                    lunchQueue.pop();
                    cout << "Processing Lunch Order ID " << current.orderID << " (Payment: " << current.paymentType << ").\n";
                }
            } else {
                cout << "Invalid counter type.\n";
            }
        }
     }
        }

        }
