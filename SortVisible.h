#ifndef SORT_VISIBLE_H
#define SORT_VISIBLE_H
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<algorithm>
#include<time.h>
using namespace std;
using namespace sf;

class SortVisible{
    public:
        virtual void sort()=0;
    protected:
        const int M=500;
        float interval=0;
        const int W=1200;
        const int H=900;
        Color color1;
        Color color2;
        const float pause=4.0;
        vector<int> tem;
        RectangleShape rec;
        const int upd=max(M/100,1);
        const float gap=1.0*W/M/10;
        vector<int> v;
        RectangleShape& getrec(int h,int i);
        void windowshow(vector<int>& v);
        void closeWindow();
        void createWindow();
        RenderWindow window;
};
#endif