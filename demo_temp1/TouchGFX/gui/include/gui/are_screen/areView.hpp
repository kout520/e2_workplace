#ifndef AREVIEW_HPP
#define AREVIEW_HPP

#include <gui_generated/are_screen/areViewBase.hpp>
#include <gui/are_screen/arePresenter.hpp>

class areView : public areViewBase
{
public:
    areView();
    virtual ~areView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
        
        
        //ÏÔÊ¾¼ÆÊý
    void showNum(int num);
     void showTempHum(float temp,float hum);
       void showLight(int light,int hongwai,int IR_light);
protected:
};

#endif // AREVIEW_HPP
