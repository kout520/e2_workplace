#ifndef AREPRESENTER_HPP
#define AREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class areView;

class arePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    arePresenter(areView& v);

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

    virtual ~arePresenter() {};
        
    void showNum(int num);
       void showTempHum(float temp,float hum);
       void showLight(int light,int hongwai,int IR_light);

private:
    arePresenter();

    areView& view;
};

#endif // AREPRESENTER_HPP
