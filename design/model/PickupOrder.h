#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "Order.h"
class PickupOrder:public Order{
    private:
    string restaurantAddress;
    public:
    PickupOrder(){
        restaurantAddress="";
    }

    string getType() override{
        return "Pickup";
    }

    void setPickupAddress(string addr){
        restaurantAddress=addr;
    }
    string getUserAddress(){
        return restaurantAddress;
    }
};
#endif