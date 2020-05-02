#ifndef SCR_SETTINGSVIEW_HPP
#define SCR_SETTINGSVIEW_HPP

#include <gui_generated/scr_settings_screen/Scr_SettingsViewBase.hpp>
#include <gui/scr_settings_screen/Scr_SettingsPresenter.hpp>

#include <gui/common/CustomKeyboard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class Scr_SettingsView : public Scr_SettingsViewBase
{
public:
    Scr_SettingsView();
    virtual ~Scr_SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    CustomKeyboard keyboard;

protected:

};

#endif // SCR_SETTINGSVIEW_HPP
