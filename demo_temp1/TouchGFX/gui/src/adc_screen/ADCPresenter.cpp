#include <gui/adc_screen/ADCView.hpp>
#include <gui/adc_screen/ADCPresenter.hpp>

ADCPresenter::ADCPresenter(ADCView& v)
    : view(v)
{

}

void ADCPresenter::activate()
{

}

void ADCPresenter::deactivate()
{

}

void ADCPresenter::showADC(float ADC_cc,float ADC_ma)
{
    view.showADC( ADC_cc,ADC_ma);
}