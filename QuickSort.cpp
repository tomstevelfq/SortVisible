#include "QuickSort.h"
QuickSort::QuickSort(){
    srand(time(0));
    for(int i=0;i<M;i++){
        v.push_back(rand()%100);
    }
    tem=v;
}
void QuickSort::sort(){
    createWindow();
    quickSort(0,M-1);
}

void QuickSort::quickSort(int i,int j){
    if(i>=j){
        return;
    }
    int i_=i,j_=j;
    int p=v[i];
    while(i_<j_){
        while(i_<j_&&v[j_]<=p){
            j_--;
        }
        v[i_]=v[j_];
        while(i_<j_&&v[i_]>=p){
            i_++;
        }
        v[j_]=v[i_];
    }
    v[j_]=p;
    Event e;
    while(window.pollEvent(e)){
        if(e.type==Event::Closed){
            window.close();
        }
    }
    sleep(seconds(pause/M));
    windowshow(v);
    quickSort(i,j_-1);
    quickSort(j_+1,j);
}