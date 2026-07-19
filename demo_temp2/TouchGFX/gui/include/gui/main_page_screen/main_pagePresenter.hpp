#ifndef MAIN_PAGEPRESENTER_HPP
#define MAIN_PAGEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class main_pageView;

class main_pagePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    main_pagePresenter(main_pageView& v);

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

    virtual ~main_pagePresenter() {};
    void led_task();
        void beef_task();
    void fan_task();
        void zhendong_task();

private:
    main_pagePresenter();

    main_pageView& view;
};

#endif // MAIN_PAGEPRESENTER_HPP
