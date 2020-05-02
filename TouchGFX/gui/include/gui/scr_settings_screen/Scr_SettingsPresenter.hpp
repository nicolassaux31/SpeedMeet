#ifndef SCR_SETTINGSPRESENTER_HPP
#define SCR_SETTINGSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Scr_SettingsView;

class Scr_SettingsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Scr_SettingsPresenter(Scr_SettingsView& v);

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

    virtual ~Scr_SettingsPresenter() {};

private:
    Scr_SettingsPresenter();

    Scr_SettingsView& view;
};

#endif // SCR_SETTINGSPRESENTER_HPP
