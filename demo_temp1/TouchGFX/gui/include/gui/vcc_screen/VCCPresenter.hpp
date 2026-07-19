#ifndef VCCPRESENTER_HPP
#define VCCPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class VCCView;

class VCCPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    VCCPresenter(VCCView& v);

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

    virtual ~VCCPresenter() {};
        //µÁ—π
        void showVCC(float VCC,float CVV,float RTC_VCC);

private:
    VCCPresenter();

    VCCView& view;
};

#endif // VCCPRESENTER_HPP
