#include"BubbleSort.h"

BubbleSort::BubbleSort(){}
void BubbleSort::sort(){
    createWindow();
    srand(time(0));
    for(int i=0;i<M;i++){
        v.push_back(rand()%100+1);
    }
    tem=v;
    int U=upd;
    vector<RectangleShape> vrec(M);
    for(int i=M;i>0;i--){
        Event e;
        while(window.pollEvent(e)){
            if(e.type==Event::Closed){
                //closeWindow();
                window.close();
                goto loop;
            }
        }
        sleep(seconds(pause/M));
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
            windowshow(v);
        }
    }
    loop:return;
}