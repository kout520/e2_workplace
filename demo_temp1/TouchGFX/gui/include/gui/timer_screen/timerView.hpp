#ifndef TIMERVIEW_HPP
#define TIMERVIEW_HPP

#include <gui_generated/timer_screen/timerViewBase.hpp>
#include <gui/timer_screen/timerPresenter.hpp>

class timerView : public timerViewBase
{
public:
    timerView();
    virtual ~timerView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
        void showTime(int year,int month,int data,int hour,int min,int sec);
        
        void showStep(int step);
protected:
};

#endif // TIMERVIEW_HPP
