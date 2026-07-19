#ifndef OULAPRESENTER_HPP
#define OULAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class oulaView;

class oulaPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    oulaPresenter(oulaView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~oulaPresenter() {};
        
        void showOrg(float pitch,float roll,float yaw);

private:
    oulaPresenter();

    oulaView& view;
};

#endif // OULAPRESENTER_HPP
