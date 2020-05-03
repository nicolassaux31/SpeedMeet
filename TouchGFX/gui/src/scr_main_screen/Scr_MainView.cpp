#include <gui/scr_main_screen/Scr_MainView.hpp>
#include <string>
#include <iostream>
using namespace std;

#define ticks_per_second 30

int TimeLeft[2] = {0,0};


Scr_MainView::Scr_MainView()
{

}

void Scr_MainView::setupScreen()
{
	Scr_MainViewBase::setupScreen();

	//Initialize Progress Indicators
	ind_progress_perc.setValue(100);
	ind_progress_perc.invalidate();
	ind_progress_line.setValue(100);
	ind_progress_line.invalidate();

	//Initialize Counter text
	Unicode::snprintf(txt_min1Buffer, TXT_MIN1_SIZE, "%d", slots[0].minutes / 10);
	txt_min0.invalidate();
	Unicode::snprintf(txt_min0Buffer, TXT_MIN0_SIZE, "%d", slots[0].minutes % 10);
	txt_min0.invalidate();
	Unicode::snprintf(txt_sec1Buffer, TXT_SEC1_SIZE, "%d", slots[0].seconds / 10);
	txt_sec1.invalidate();
	Unicode::snprintf(txt_sec0Buffer, TXT_SEC0_SIZE, "%d", slots[0].seconds % 10);
	txt_sec0.invalidate();

}

void Scr_MainView::tearDownScreen()
{
	Scr_MainViewBase::tearDownScreen();
}

/**
 * @fn virtual void Screen::handleTickEvent()
 *
 * @brief Called by the Application on the current screen with a frequency of
 *        Application::TICK_INTERVAL_MS.
 *
 *        Called by the Application on the current screen with a frequency of
 *        Application::TICK_INTERVAL_MS.
 */
void Scr_MainView::handleTickEvent()
{

	static char flag_first_minute_over = 0;
	static int percentage_left = 0;

	if(btn_countonoff.getState())
		tickCounter++;

	if (tickCounter == ticks_per_second/2){

		secCounter++; //Increment the second counter

		if(secCounter == 60 || (secCounter == (slots[0].seconds+1) && !flag_first_minute_over)) {
			//When a countable minute is over
			if(secCounter == (slots[0].seconds+1))  //If it is the first minute that is over
				flag_first_minute_over = 1;

			secCounter = 0; 			//Reinitialize second counter
			minCounter++;   			//Increment the min counter

			if(minCounter == slots[0].minutes + 1){ //When the configured time is over
				minCounter = 0;
				flag_first_minute_over = 0;
			}
		}

		//Compute minutes to display
		TimeLeft[1] = slots[0].minutes - minCounter;

		//Compute seconds to display
		if(!flag_first_minute_over){
			TimeLeft[0] = slots[0].seconds - secCounter;
		}else{
			TimeLeft[0] = 59 - secCounter;
		}

		//Compute percentage left
		percentage_left = (60*TimeLeft[1] + TimeLeft[0])*100 /
						  (60*slots[0].minutes + slots[0].seconds);

		//Update progress indicators
		ind_progress_perc.setValue(percentage_left);
		ind_progress_perc.invalidate();
		ind_progress_line.setValue(percentage_left);
		ind_progress_line.invalidate();

		//Modify text widgets and invalidate them so that they are rendered again
		Unicode::snprintf(txt_min1Buffer, TXT_MIN1_SIZE, "%d", TimeLeft[1]/10);
		txt_min1.invalidate();
		Unicode::snprintf(txt_min0Buffer, TXT_MIN0_SIZE, "%d", TimeLeft[1]%10);
		txt_min0.invalidate();
		Unicode::snprintf(txt_sec1Buffer, TXT_SEC1_SIZE, "%d", TimeLeft[0]/10);
		txt_sec1.invalidate();
		Unicode::snprintf(txt_sec0Buffer, TXT_SEC0_SIZE, "%d", TimeLeft[0]%10);
		txt_sec0.invalidate();

		//Make the colon toggle
		txt_colon.setAlpha(0);
		txt_colon.invalidate();
	}

	else if(tickCounter == ticks_per_second){
		tickCounter = 0;
		//Make the colon toggle
		txt_colon.setAlpha(255);
		txt_colon.invalidate();
	}
}
