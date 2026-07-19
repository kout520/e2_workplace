#ifndef HEATPRESENTER_HPP
#define HEATPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class heatView;

class heatPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    heatPresenter(heatView& v);

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

    virtual ~heatPresenter() {};
        
        void showHR(int HR,int SP02,float HR_temp);
        void sp02_task();

private:
    heatPresenter();

    heatView& view;
};

#endif // HEATPRESENTER_HPP
