#include <gui/heat_screen/heatView.hpp>
#include <gui/heat_screen/heatPresenter.hpp>

heatPresenter::heatPresenter(heatView& v)
    : view(v)
{

}

void heatPresenter::activate()
{

}

void heatPresenter::deactivate()
{

}
void heatPresenter::showHR(int HR,int SP02,float HR_temp)
{
    view.showHR(HR,SP02,HR_temp);
}


void heatPresenter::sp02_task()
{
    model->sp02_task();
}