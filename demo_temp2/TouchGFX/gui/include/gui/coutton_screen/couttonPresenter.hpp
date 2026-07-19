#ifndef COUTTONPRESENTER_HPP
#define COUTTONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class couttonView;

class couttonPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    couttonPresenter(couttonView& v);

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

    virtual ~couttonPresenter() {};

private:
    couttonPresenter();

    couttonView& view;
};

#endif // COUTTONPRESENTER_HPP
