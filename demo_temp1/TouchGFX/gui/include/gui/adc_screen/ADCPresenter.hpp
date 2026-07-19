#ifndef ADCPRESENTER_HPP
#define ADCPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ADCView;

class ADCPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ADCPresenter(ADCView& v);

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

    virtual ~ADCPresenter() {};
        void showADC(float ADC_cc,float ADC_ma);

private:
    ADCPresenter();

    ADCView& view;
};

#endif // ADCPRESENTER_HPP
