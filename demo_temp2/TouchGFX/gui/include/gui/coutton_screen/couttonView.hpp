#ifndef COUTTONVIEW_HPP
#define COUTTONVIEW_HPP

#include <gui_generated/coutton_screen/couttonViewBase.hpp>
#include <gui/coutton_screen/couttonPresenter.hpp>

class couttonView : public couttonViewBase
{
public:
    couttonView();
    virtual ~couttonView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // COUTTONVIEW_HPP
