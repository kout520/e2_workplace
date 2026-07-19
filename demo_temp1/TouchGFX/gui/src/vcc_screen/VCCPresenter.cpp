#include <gui/vcc_screen/VCCView.hpp>
#include <gui/vcc_screen/VCCPresenter.hpp>

VCCPresenter::VCCPresenter(VCCView& v)
    : view(v)
{

}

void VCCPresenter::activate()
{

}

void VCCPresenter::deactivate()
{

}

    
void VCCPresenter::showVCC(float VCC,float CVV,float RTC_VCC)
{
    view.showVCC(VCC,CVV,RTC_VCC);
}