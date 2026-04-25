#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include<bits/stdc++.h>
#include "OrderFactory.h"
#include "DeliveryOrder.h"
#include "PickupOrder.h"
#include "Resturant.h"

class NowOrderFactory:public OrderFactory{
    public:
    Order* createOrder(User* user,Cart* cart,Restaurant* restaurant,vector<MenuItem>& menuItem,PaymentStrategy* paymentStrategy,double totalCost,string orderType) override{
        Order* order=nullptr;
        if(orderType=="Delivery"){
            DeliveryOrder* deliveryOrder=new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order=deliveryOrder;
        }else{
            PickupOrder* pickupOrder=new PickupOrder();
            pickupOrder->setPickupAddress(restaurant->getLocation());
            order=pickupOrder;
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItem);
        order->setPaymentStrategy(paymentStrategy);
        order->setTotal(totalCost);
        return order;
    }
};