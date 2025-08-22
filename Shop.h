//Simon N. Nganga - 2655389

#ifndef SHOP_H
#define SHOP_H



enum shopType {
    None,
    ClothingShop,
    TechnologyShop,
    AccessoriesShop,
    BeautyShop
};


class shop:public business {
private:
    shopType type;

public:
    shop();
    shop(const char*, int,   shopType );
    shopType getShopType();
    void setShopType(shopType );
    void printBusiness();
    void printBusinessEmployees();
    int getType();
    const char* getShopTypeName(int );




};







#endif //SHOP_H
