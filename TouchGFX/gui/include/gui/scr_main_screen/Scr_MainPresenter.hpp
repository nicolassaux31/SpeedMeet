#ifndef SCR_MAINPRESENTER_HPP
#define SCR_MAINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Scr_MainView;

class Scr_MainPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Scr_MainPresenter(Scr_MainView& v);

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

    virtual ~Scr_MainPresenter() {};

private:
    Scr_MainPresenter();

    Scr_MainView& view;
};

#endif // SCR_MAINPRESENTER_HPP
