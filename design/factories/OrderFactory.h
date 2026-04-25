#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include<bits/stdc++.h>
#include "Order.h"
#include "DeliveryOrder.h"
#include "User.h"
#include "Cart.h"
#include "Resturant.h"
#include "PaymentStrategy.h"
#include "MenuItem.h"

class OrderFactory{
      virtual Order* createOrder(User* user,Cart* cart,Restaurant* restaurant,vector<MenuItem>& menuItem,PaymentStrategy* PaymentStrategy,double totalCost,string orderType)=0;
      virtual ~OrderFactory(){}
};

#endif

