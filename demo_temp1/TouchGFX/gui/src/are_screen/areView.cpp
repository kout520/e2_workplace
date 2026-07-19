#include <gui/are_screen/areView.hpp>

areView::areView()
{

}

void areView::setupScreen()
{
    areViewBase::setupScreen();
}

void areView::tearDownScreen()
{
    areViewBase::tearDownScreen();
}
//计数
void areView::showNum(int num)
{
    Unicode::snprintf(text_300Buffer, TEXT_300_SIZE, "%d", num) ;
    text_300.invalidate();
}
//温度湿度显示
void areView::showTempHum(float temp,float hum)
{
    Unicode::snprintfFloat(text_200Buffer, TEXT_200_SIZE, "%.2f", temp) ;
    text_200.invalidate();
        Unicode::snprintfFloat(text_100Buffer, TEXT_100_SIZE, "%.2f", hum) ;
    text_100.invalidate();
}

    //温度湿度显示
void areView::showLight(int light,int hongwai,int IR_light)
{
    Unicode::snprintf(text_400Buffer, TEXT_400_SIZE, "%d", light) ;
    text_400.invalidate();
    Unicode::snprintf(text_500Buffer, TEXT_500_SIZE, "%d",IR_light ) ;
    text_500.invalidate();
    Unicode::snprintf(text_600Buffer, TEXT_600_SIZE, "%d", hongwai) ;
    text_600.invalidate();
    
    
}