#ifndef MENUITEM_H
#define MENUITEM_H
#include <string>

using namespace std;

class MenuItem{
      private:
      string code;
      string name;
      int price;

      public:
      MenuItem(string code, string name, int price){
            this->code = code;
            this->name = name;
            this->price = price;
      }

        string getCode(){
                return code;
        }
        string getName(){
                return name;
        }
        int getPrice(){
                return price;
        }

        void setCode(string code){
                this->code = code;
        }
        void setName(string name){
                this->name = name;
        }
        void setPrice(int price){
                this->price = price;
        }
};

#endif // MENUITEM_H