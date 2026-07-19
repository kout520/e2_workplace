#include <gui/are_screen/areView.hpp>
#include <gui/are_screen/arePresenter.hpp>

arePresenter::arePresenter(areView& v)
    : view(v)
{

}

void arePresenter::activate()
{

}

void arePresenter::deactivate()
{

}
//计数
void arePresenter::showNum(int num)
{
    view.showNum(num);
}

    //温湿度
void arePresenter::showTempHum(float temp,float hum)
{
    view.showTempHum(temp,hum);
}

    //温湿度
void arePresenter::showLight(int light,int hongwai,int IR_light)
{
    view.showLight(light,hongwai,IR_light);
}    