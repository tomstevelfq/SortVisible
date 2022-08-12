#include"BubbleSort.h"
#include"QuickSort.h"
#include<thread>

int main(){
    BubbleSort bs;
    QuickSort qs;
    thread t1(&BubbleSort::sort,&bs);
    thread t2(&QuickSort::sort,&qs);
    t1.join();
    t2.join();
    return 0;
}
