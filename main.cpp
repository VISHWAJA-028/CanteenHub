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
        void estimateWaitTime(const string& counterType) {
            int totalTime = 0;
            if (counterType == "Beverage") {
            queue<Order> tempQueue = beverageQueue;
            while (!tempQueue.empty()) {
            totalTime += tempQueue.front().prepTime;
            tempQueue.pop();
            }
            cout << "Estimated wait time for Beverage Counter: " << totalTime << "
           minutes.\n";
            } else if (counterType == "Lunch") {
            queue<Order> tempQueue = lunchQueue;
            while (!tempQueue.empty()) {
            totalTime += tempQueue.front().prepTime;
            tempQueue.pop();
            }
            cout << "Estimated wait time for Lunch Counter: " << totalTime << "
           minutes.\n";
            } else {
            cout << "Invalid counter type.\n";
            }
            }
           };
           class Canteen {
            private:
             QueueManager queueManager;
             int orderCounter;
            public:
             Canteen() : orderCounter(0) {}
             void displayMenu() {
             cout << "Menu:\n";
             cout << "Beverages:\n";
             cout << "1. Coffee (5 mins)\n";
             cout << "2. Tea (4 mins)\n";
             cout << "3. Juice (3 mins)\n";
             cout << "Lunch:\n";
             cout << "4. Sandwich (10 mins)\n";
             cout << "5. Pizza (15 mins)\n";
             cout << "6. Burger (12 mins)\n";
             }
             void displayPaymentOptions(const string& itemType) {
             cout << "Payment Methods for " << itemType << ":\n";
             if (itemType == "Beverage") {
                cout << "1. Digital Wallet\n";
                } else if (itemType == "Lunch") {
                cout << "1. Cash\n";
                cout << "2. Card\n";
                } else {
                cout << "Invalid item type.\n";
                }
                }
                string selectPaymentMethod(int choice, const string& itemType) {
                if (itemType == "Beverage") {
                if (choice == 1) return "Digital Wallet";
                } else if (itemType == "Lunch") {
                if (choice == 1) return "Cash";
                if (choice == 2) return "Card";
                }
                return "Invalid";
                }
                void takeOrder(int menuChoice, int paymentChoice) {
                string itemType;
                int prepTime = 0;
                if (menuChoice == 1) { itemType = "Beverage"; prepTime = 5; }
                else if (menuChoice == 2) { itemType = "Beverage"; prepTime = 4; }
                else if (menuChoice == 3) { itemType = "Beverage"; prepTime = 3; }
                else if (menuChoice == 4) { itemType = "Lunch"; prepTime = 10; }
                else if (menuChoice == 5) { itemType = "Lunch"; prepTime = 15; }
                else if (menuChoice == 6) { itemType = "Lunch"; prepTime = 12; }
                else {
                cout << "Invalid menu choice.\n";
                return;
                }
                string paymentType = selectPaymentMethod(paymentChoice, itemType);
                if (paymentType == "Invalid") {
                cout << "Invalid payment choice.\n";
                return;
                }
                orderCounter++;
                Order newOrder(orderCounter, itemType, paymentType, prepTime);
                queueManager.addOrder(newOrder);
                }
                void processOrders(const string& counterType) {
                queueManager.processOrder(counterType);
                }
                void estimateWaitTimes(const string& counterType) {
                queueManager.estimateWaitTime(counterType);
                }
               };
               int main() {
                Canteen canteen;
                cout << "Welcome to the Smart Canteen Ordering System!\n";
                canteen.displayMenu();
                cout << "\nBeverage Payment Options:\n";
                canteen.displayPaymentOptions("Beverage");
                cout << "\nLunch Payment Options:\n";
                canteen.displayPaymentOptions("Lunch");
                cout << "\nTaking Orders:\n";
                canteen.takeOrder(1, 1);
                canteen.takeOrder(5, 2);
                cout << "\nEstimating Wait Times:\n";
                canteen.estimateWaitTimes("Beverage");
                canteen.estimateWaitTimes("Lunch");
                cout << "\nProcessing Orders:\n";
                canteen.processOrders("Beverage");
                canteen.processOrders("Lunch");
                return ;
               }