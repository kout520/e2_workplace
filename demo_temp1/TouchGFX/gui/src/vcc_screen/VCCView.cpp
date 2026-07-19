#include <gui/vcc_screen/VCCView.hpp>

VCCView::VCCView()
{

}

void VCCView::setupScreen()
{
    VCCViewBase::setupScreen();
}

void VCCView::tearDownScreen()
{
    VCCViewBase::tearDownScreen();
}

//电压
void VCCView::showVCC(float VCC,float CVV,float RTC_VCC)
{
    Unicode::snprintfFloat(text_220Buffer, TEXT_220_SIZE, "%.3f", VCC) ;//温度
    text_220.invalidate();
        Unicode::snprintfFloat(text_110Buffer, TEXT_110_SIZE, "%.3f", CVV) ;//芯片电压
    text_110.invalidate();
    Unicode::snprintfFloat(text_330Buffer, TEXT_330_SIZE, "%.3f", RTC_VCC) ;//RTC电压
    text_330.invalidate();
}