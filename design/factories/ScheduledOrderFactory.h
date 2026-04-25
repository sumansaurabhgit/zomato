#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H
#include<bits/stdc++.h>
#include "OrderFactory.h"
#include "Resturant.h"
#include "PickupOrder.h"

class ScheduledOrderFactory:public OrderFactory{
    private:
    string scheduleTime;
    public:
    ScheduledOrderFactory(string time){
        this->scheduleTime=time;
    }
    Order* createOrder(User* user,Cart* cart,Restaurant* restaurant,vector<MenuItem>& menuItem,PaymentStrategy* paymentStrategy,double totalCost,string orderType) override{
        Order* scheduledOrder=nullptr;
        if(orderType=="Delivery"){
            DeliveryOrder* deliveryOrder=new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            scheduledOrder=deliveryOrder;
        }else{
            PickupOrder* pickupOrder=new PickupOrder();
            pickupOrder->setPickupAddress(restaurant->getLocation());
            scheduledOrder=pickupOrder;
        }
        scheduledOrder->setUser(user);
        scheduledOrder->setRestaurant(restaurant);
        scheduledOrder->setItems(menuItem);
        scheduledOrder->setPaymentStrategy(paymentStrategy);
        scheduledOrder->setTotal(totalCost);
        cout<<"Enter the scheduled time for the order (e.g., 2023-12-31 18:30): ";
        string scheduledTime;
        cin>>scheduledTime;
        scheduledOrder->setScheduled(scheduledTime);
        return scheduledOrder;
    }
};  