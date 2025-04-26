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