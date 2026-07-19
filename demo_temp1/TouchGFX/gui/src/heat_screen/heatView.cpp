#include <gui/heat_screen/heatView.hpp>

heatView::heatView()
{

}

void heatView::setupScreen()
{
    heatViewBase::setupScreen();
}

void heatView::tearDownScreen()
{
    heatViewBase::tearDownScreen();
}

    
void heatView::showHR(int HR,int SP02,float HR_temp)
{
    Unicode::snprintf(text_222Buffer, TEXT_222_SIZE, "%d", HR) ;//心率
    text_222.invalidate();
        Unicode::snprintf(text_333Buffer, TEXT_333_SIZE, "%d", SP02) ;//血氧
    text_333.invalidate();
    Unicode::snprintfFloat(text_444Buffer, TEXT_444_SIZE, "%.1f", HR_temp) ;//体温
    text_444.invalidate();
}

//心率实现函数
void heatView::sp02_task()
{
    presenter->sp02_task();
}


