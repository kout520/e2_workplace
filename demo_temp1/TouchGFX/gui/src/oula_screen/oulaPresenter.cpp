#include <gui/oula_screen/oulaView.hpp>
#include <gui/oula_screen/oulaPresenter.hpp>

oulaPresenter::oulaPresenter(oulaView& v)
    : view(v)
{

}

void oulaPresenter::activate()
{

}

void oulaPresenter::deactivate()
{

}
void oulaPresenter::showOrg(float pitch,float roll,float yaw)
{
    
    view.showOrg(pitch, roll,yaw);

}
