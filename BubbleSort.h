#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<time.h>
#include<algorithm>
#include"SortVisible.h"
using namespace std;
using namespace sf;

class BubbleSort:public SortVisible{
    public:
        BubbleSort();
        void sort();
};
#endif