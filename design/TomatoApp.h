#ifndef TOMATO_APP_H
#define TOMATO_APP_H
#include "model/User.h"
#include "Restaurant.h"
#include "model/Cart.h"
#include "model/Order.h"    
#include "model/PickupOrder.h"
#include "model/DeliveryOrder.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"  
#include "strategies/PaymentStrategy.h"
#include "strategies/CreditCartPaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/OrderFactory.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"

#include <bits/stdc++.h>
using namespace std;

class TomatoApp{
    public:
    TomatoApp(){
        initializeRestaurants();
    }
    void initializeRestaurants(){
        Restaurant* r1=new Restaurant("star123","safaliya");
        r1->addMenuItem(MenuItem("m1","paneer tikka",150));
        r1->addMenuItem(MenuItem("m2","chicken tikka",200)); 

        Restaurant* r2=new Restaurant("haldiram","sankalp");
        r2->addMenuItem(MenuItem("p1","masala Dosa",90));
        r2->addMenuItem(MenuItem("p2","Idli vada",60));

        RestaurantManager* restaurantManager=RestaurantManager::getInstance();
        restaurantManager->addRestaurant(r1);
        restaurantManager->addRestaurant(r2);

    }

    vector<Restaurant*>searchRestaurant(string location){
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

    void selectRestaurant(User* user,Restaurant* restaurant){
        Cart* cart=user->getCart();
        cart->setRestaurant(restaurant);
    }

    void addToCart(User* user,string itemCode){
        Restaurant* restaurant=user->getCart()->getRestaurant();
        if(!restaurant){
            cout<<"please select a restaurant first"<<endl;
            return;
        }
        for(auto item:restaurant->getMenu()){
            if(item.getCode()==itemCode){
                user->getCart()->addItem(item);
                break;
            }
        }
    }

    Order* checkoutNow(User* user,string orderType,PaymentStrategy* paymentStrategy){
        return checkout(user,orderType,paymentStrategy,new NowOrderFactory());
    }

    Order* checkout(User* user,string orderType,PaymentStrategy,OrderFactory* OrderFactory){
           
    }
};
#endif // TOMATO_APP_H