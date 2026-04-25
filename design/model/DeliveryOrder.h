#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "Order.h"
using namespace std;

class DeliveryOrder:public Order{
    private:
    string userAddress;

    public:
    DeliveryOrder(){
        userAddress="";
    }
    
    string getType() override{
        return "Delivery";
    }

    void setUserAddress(string addr){
        userAddress=addr;
    }
    string getUserAddress(){
        return userAddress;
    }
};
#endif