#ifndef ADCVIEW_HPP
#define ADCVIEW_HPP

#include <gui_generated/adc_screen/ADCViewBase.hpp>
#include <gui/adc_screen/ADCPresenter.hpp>

class ADCView : public ADCViewBase
{
public:
    ADCView();
    virtual ~ADCView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
        void showADC(float ADC_cc,float ADC_ma);
protected:
};

#endif // ADCVIEW_HPP
