#ifndef OULAVIEW_HPP
#define OULAVIEW_HPP

#include <gui_generated/oula_screen/oulaViewBase.hpp>
#include <gui/oula_screen/oulaPresenter.hpp>

class oulaView : public oulaViewBase
{
public:
    oulaView();
    virtual ~oulaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
        
        void showOrg(float pitch,float roll,float yaw);
protected:
};

#endif // OULAVIEW_HPP
