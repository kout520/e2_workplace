#include <gui/timer_screen/timerView.hpp>
#include <gui/timer_screen/timerPresenter.hpp>

timerPresenter::timerPresenter(timerView& v)
    : view(v)
{

}

void timerPresenter::activate()
{

}

void timerPresenter::deactivate()
{

}

    
void timerPresenter::showTime(int year,int month,int data,int hour,int min,int sec)
{
    view.showTime(year,month,data,hour,min,sec);
}
void timerPresenter::showStep(int step)
{
        view.showStep(step);
}
