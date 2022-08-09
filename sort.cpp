#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;
using namespace sf;

const int M=10000;
RenderWindow window;
float interval=0;
const int W=1200;
const int H=900;
Color color1(231,76,60);
Color color2(0,153,204);
vector<int> tem;
RectangleShape rec;
const int upd=max(M/1000,1);
const float gap=1.0*W/M/10;
RectangleShape& getrec(int h,int i){
    rec.setPosition(1.0*i*W/M+gap,0);
    rec.setSize(Vector2f((1.0*W/M-2*gap),h*4));
    rec.setFillColor(color1);
    return rec;
}
void bubbleSort(vector<int>& v){
    int U=upd;
    vector<RectangleShape> vrec(M);
    for(int i=M;i>0;i--){
        U--;
        for(int j=1;j<i;j++){
            if(v[j]>v[j-1]){
                int tem=v[j];
                v[j]=v[j-1];
                v[j-1]=tem;
            }
        }
        if(U==0){
            U=upd;
            window.clear();
            for(int k=0;k<M;k++){
                auto& rec=getrec(v[k],k);
                if(tem[k]!=v[k]){
                    tem[k]=v[k];
                    rec.setFillColor(color2);
                }
                window.draw(rec);
            }
            window.display();
        }
        //sleep(seconds(interval));
    }
}
void windowshow(vector<int>& v){
    window.clear();
    for(int k=0;k<M;k+=upd){
        auto& rec=getrec(v[k],k);
        window.draw(rec);
    }
    window.display();
}
int main(){
    window.create(VideoMode(W,H),"sort visible");
    View view;
    auto siz=window.getSize();
    view.setSize(Vector2f(siz.x,siz.y));
    view.setCenter(siz.x/2,siz.y/2);
    view.rotate(180);
    window.setView(view);
    vector<int> v;
    srand(time(0));
    for(int i=0;i<M;i++){
        v.push_back(rand()%100+1);
    }
    tem=v;
    auto time1=clock();
    bubbleSort(v);
    auto time2=clock();
    cout<<time2-time1<<endl;
    return 0;
}