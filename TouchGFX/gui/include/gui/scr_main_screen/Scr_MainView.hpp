#ifndef SCR_MAINVIEW_HPP
#define SCR_MAINVIEW_HPP

#include <gui_generated/scr_main_screen/Scr_MainViewBase.hpp>
#include <gui/scr_main_screen/Scr_MainPresenter.hpp>
#include <touchgfx/Color.hpp>

extern Model::slot slots[4];

class Scr_MainView : public Scr_MainViewBase
{
public:
    Scr_MainView();
    virtual ~Scr_MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    int tickCounter = 0;
    int minCounter = 0;
    int secCounter = 0;

    virtual void handleTickEvent();

protected:
};

#endif // SCR_MAINVIEW_HPP
