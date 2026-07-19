#include <gui/adc_screen/ADCView.hpp>

ADCView::ADCView()
{

}

void ADCView::setupScreen()
{
    ADCViewBase::setupScreen();
}

void ADCView::tearDownScreen()
{
    ADCViewBase::tearDownScreen();
}

void ADCView::showADC(float ADC_cc,float ADC_ma)
{
    Unicode::snprintfFloat(text_ADC1Buffer, TEXT_ADC1_SIZE, "%.2f", ADC_cc) ;
    text_ADC1.invalidate();
    Unicode::snprintfFloat(text_ADC2Buffer, TEXT_ADC2_SIZE, "%.2f", ADC_ma) ;
    text_ADC2.invalidate();
}