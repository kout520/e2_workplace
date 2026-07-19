#include <gui/main_page_screen/main_pageView.hpp>

main_pageView::main_pageView()
{

}

void main_pageView::setupScreen()
{
    main_pageViewBase::setupScreen();
}

void main_pageView::tearDownScreen()
{
    main_pageViewBase::tearDownScreen();
}

//灯实现函数
void main_pageView::led_task()
{
    
    presenter->led_task();
}
//声实现函数
void main_pageView::beef_task()
{
    
    presenter->beef_task();
}
//风实现函数
void main_pageView::fan_task()
{
    
    presenter->fan_task();
}
//动实现函数
void main_pageView::zhendong_task()
{
    
    presenter->zhendong_task();
}