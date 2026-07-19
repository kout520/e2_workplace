#ifndef MAIN_PAGEVIEW_HPP
#define MAIN_PAGEVIEW_HPP

#include <gui_generated/main_page_screen/main_pageViewBase.hpp>
#include <gui/main_page_screen/main_pagePresenter.hpp>

class main_pageView : public main_pageViewBase
{
public:
    main_pageView();
    virtual ~main_pageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void led_task();
        void beef_task();
    void fan_task();
        void zhendong_task();
protected:
};

#endif // MAIN_PAGEVIEW_HPP
