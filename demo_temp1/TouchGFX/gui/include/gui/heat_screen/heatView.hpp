#ifndef HEATVIEW_HPP
#define HEATVIEW_HPP

#include <gui_generated/heat_screen/heatViewBase.hpp>
#include <gui/heat_screen/heatPresenter.hpp>

class heatView : public heatViewBase
{
public:
    heatView();
    virtual ~heatView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
        void showHR(int HR,int SP02,float HR_temp);
        void sp02_task();
protected:
};

#endif // HEATVIEW_HPP
