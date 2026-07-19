#include <gui/main_page_screen/main_pageView.hpp>
#include <gui/main_page_screen/main_pagePresenter.hpp>

main_pagePresenter::main_pagePresenter(main_pageView& v)
    : view(v)
{

}

void main_pagePresenter::activate()
{

}

void main_pagePresenter::deactivate()
{

}
void main_pagePresenter::led_task()
{
    model->led_task();
}
void main_pagePresenter::beef_task()
{
    model->beef_task();
}
void main_pagePresenter::fan_task()
{
    model->fan_task();
}
void main_pagePresenter::zhendong_task()
{
    model->zhendong_task();
}