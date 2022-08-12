#include "SortVisible.h"
RectangleShape& SortVisible::getrec(int h,int i){
    rec.setPosition(1.0*i*W/M+1.0*gap,0);
    rec.setSize(Vector2f((1.0*W/M-2.0*gap),h*4));
    rec.setFillColor(color1);
    return rec;
}
void SortVisible::windowshow(vector<int>& v){
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
void SortVisible::closeWindow(){
    RenderWindow wind(VideoMode(100,200),"close window");
    Text text;
    text.setString("game over");
    wind.draw(text);
    wind.display();
    while(wind.isOpen()){
        Event e;
        while(wind.pollEvent(e)){
            if(e.type==Event::Closed){
                wind.close();
            }
        }
    }
}
void SortVisible::createWindow(){
    color1=Color(231,76,60);
    color2=Color(0,153,204);
    window.create(VideoMode(W,H),"sort visible");
    View view;
    auto siz=window.getSize();
    view.setSize(Vector2f(siz.x,siz.y));
    view.setCenter(siz.x/2,siz.y/2);
    view.rotate(180);
    window.setView(view);
}