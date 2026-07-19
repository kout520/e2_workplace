#ifndef TIMERPRESENTER_HPP
#define TIMERPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class timerView;

class timerPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    timerPresenter(timerView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~timerPresenter() {};
        void showTime(int year,int month,int data,int hour,int min,int sec);
        void showStep(int step);

private:
    timerPresenter();

    timerView& view;
};

#endif // TIMERPRESENTER_HPP
