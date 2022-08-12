#ifndef QUICK_SOTR_H
#define QUICK_SORT_H
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<algorithm>
#include<time.h>
#include"SortVisible.h"
using namespace std;
using namespace sf;

class QuickSort:public SortVisible{
    public:
        QuickSort();
        void sort();
    private:
        void quickSort(int i,int j);
        float timer=0;
        int cal=0;
};
#endif