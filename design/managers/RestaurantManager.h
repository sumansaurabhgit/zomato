#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include "Resturant.h"
#include <bits/stdc++.h>
using namespace std;

class RestaurantManager{
    private:
    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;
        RestaurantManager() {}

    public:
    static RestaurantManager* getInstance(){
        if(!instance){
            instance=new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* r){
        restaurants.push_back(r);
    }

    vector<Restaurant*> searchByLocation(string location){
        vector<Restaurant*>result;
        transform(location.begin(), location.end(), location.begin(), ::tolower);
        for(auto r:restaurants){
            string resLoc=r->getLocation();
            transform(resLoc.begin(), resLoc.end(), resLoc.begin(), ::tolower);
            if(resLoc.find(location)!=string::npos){
                result.push_back(r);
            }
        }
        return result;
    }
};
RestaurantManager* RestaurantManager::instance = nullptr;
#endif // RESTAURANT_MANAGER_H