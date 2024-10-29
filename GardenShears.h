//
// Created by zagrad on 10/28/2024.
//

#ifndef GARDENSHEARS_H
#define GARDENSHEARS_H



class GardenShears: public Weapon {
 public:
    GardenShears() {}
    bool use(Direction dir, Game* game) override;
 };



#endif //GARDENSHEARS_H
