#ifndef VCCVIEW_HPP
#define VCCVIEW_HPP

#include <gui_generated/vcc_screen/VCCViewBase.hpp>
#include <gui/vcc_screen/VCCPresenter.hpp>

class VCCView : public VCCViewBase
{
public:
    VCCView();
    virtual ~VCCView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
        
        void showVCC(float VCC,float CVV,float RTC_VCC);
protected:
};

#endif // VCCVIEW_HPP
