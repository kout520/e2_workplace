#ifndef WIFIVIEW_HPP
#define WIFIVIEW_HPP

#include <gui_generated/wifi_screen/WIFIViewBase.hpp>
#include <gui/wifi_screen/WIFIPresenter.hpp>

class WIFIView : public WIFIViewBase
{
public:
    WIFIView();
    virtual ~WIFIView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // WIFIVIEW_HPP
