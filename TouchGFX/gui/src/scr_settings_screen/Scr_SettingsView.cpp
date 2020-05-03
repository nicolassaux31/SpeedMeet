#include <gui/scr_settings_screen/Scr_SettingsView.hpp>

//**********LAYOUT**************//
//1. SCREEN BASIC FUNCTIONS
//1.1. Screen Main
//1.2. Screen Setup
//1.3. Screen TearDown

//2. BUTTON INTERACTIONS

//3. DIGIT SCROLLERS
//3.1. Change Handlers
//3.2. Text Initializers

//******************************//

//=================== 1. SCREEN BASIC FUNCTIONS =========================//

//------------- 1.1. Screen Main ----------------------//
Scr_SettingsView::Scr_SettingsView() :
scroll_numofslots_changed(this, &Scr_SettingsView::scroll_numofslots_changed_handler),
scroll_min1_changed(this, &Scr_SettingsView::scroll_min1_changed_handler),
scroll_sec1_changed(this, &Scr_SettingsView::scroll_sec1_changed_handler)
{
	keyboard.setPosition(450, 230, 320, 240);
	add(keyboard);

}

//------------- 1.2. Screen Setup ----------------------//
void Scr_SettingsView::setupScreen()
{
    Scr_SettingsViewBase::setupScreen();

    //Set initial values on screen local vars
    curr_edited_slot = 1;
    total_timing[1] = 0;
    total_timing[0] = 0;

//    for(i=0;i<MAX_SLOTS_NUM;i++){
//    	scroll_digits_positions[i] = 110*(i+1);
//    }

    //Associate Callbacks to Handlers
    scroll_numofslots.setAnimateToCallback(scroll_numofslots_changed);
    scroll_min1.setAnimateToCallback(scroll_min1_changed);
    scroll_sec1.setAnimateToCallback(scroll_sec1_changed);

    //Print initial texts
    Unicode::snprintf(txt_slotnumBuffer, TXT_SLOTNUM_SIZE, "%d", curr_edited_slot);
    txt_slotnum.invalidate();

    Unicode::snprintf(txt_total_numsBuffer1, TXT_TOTAL_NUMSBUFFER1_SIZE, "%d", total_timing[1]);
    Unicode::snprintf(txt_total_numsBuffer2, TXT_TOTAL_NUMSBUFFER2_SIZE, "%d", total_timing[0]);
    txt_total_nums.invalidate();
}

void Scr_SettingsView::tearDownScreen()
{
    Scr_SettingsViewBase::tearDownScreen();


}

//------------- 1.3. Screen TearDown --------------------//


//=================== 2. BUTTON INTERACTIONS =====================//

void Scr_SettingsView::fcn_nextslot_settings(){
	curr_edited_slot++;
	if(curr_edited_slot > num_of_slots)
		curr_edited_slot = num_of_slots;
	else{
		scroll_min1.animateToPosition(0);
		scroll_sec1.animateToPosition(0);
	}

	Unicode::snprintf(txt_slotnumBuffer, TXT_SLOTNUM_SIZE, "%d", curr_edited_slot);
	txt_slotnum.invalidate();
}

void Scr_SettingsView::fcn_prevslot_settings(){
	curr_edited_slot--;
	if(curr_edited_slot < 1)
		curr_edited_slot = 1;
	else{
		scroll_min1.animateToPosition(0);
		scroll_sec1.animateToPosition(0);
	}
	Unicode::snprintf(txt_slotnumBuffer, TXT_SLOTNUM_SIZE, "%d", curr_edited_slot);
	txt_slotnum.invalidate();
}

void Scr_SettingsView::fcn_moreslots(){
	//TODO: Scroll wheel is going to wrong position
//	num_of_slots++;
//	if(num_of_slots>MAX_SLOTS_NUM)
//		num_of_slots = MAX_SLOTS_NUM;
//	scroll_numofslots.animateToPosition(1000);
}

void Scr_SettingsView::fcn_lessslots(){
	//TODO: Scroll wheel is going to wrong position
//	num_of_slots--;
//	if(num_of_slots<1)
//		num_of_slots = 1;
//	scroll_numofslots.animateToPosition(scroll_digits_positions[MAX_SLOTS_NUM-num_of_slots]);
}

void Scr_SettingsView::update_total_timing_txt(){

	if(total_timing[0] >= 60){
		total_timing[1] += total_timing[0] / 60;
		total_timing[0] = total_timing[0] % 60;
	}
	Unicode::snprintf(txt_total_numsBuffer1, TXT_TOTAL_NUMSBUFFER1_SIZE, "%d", total_timing[1]);
	Unicode::snprintf(txt_total_numsBuffer2, TXT_TOTAL_NUMSBUFFER2_SIZE, "%d", total_timing[0]);
	txt_total_nums.invalidate();
}

//=================== 3. DIGIT SCROLLERS =========================//

//----------3.1. Change Handlers -------------//
void Scr_SettingsView::scroll_numofslots_changed_handler(int16_t itemSelected){

	num_of_slots = MAX_SLOTS_NUM-itemSelected;
	//Given that the scroll indexing starts at the top, indexes are inverted
	//with respect with the natural direction of adding numbers
}

void Scr_SettingsView::scroll_min1_changed_handler(int16_t itemSelected){

	volatile int i;
	volatile int buffer = 0;

	slots[curr_edited_slot-1].minutes = itemSelected;
	//TODO: update the total timing variables only when the check button is pressed
	//Update Total Timing minutes
	for(i=0;i<num_of_slots;i++){
		buffer += slots[i].minutes;
		total_timing[1] = buffer;
	}
	update_total_timing_txt();
}

void Scr_SettingsView::scroll_sec1_changed_handler(int16_t itemSelected){

	volatile int i;
	volatile int buffer = 0;

	slots[curr_edited_slot-1].seconds = itemSelected;
	//TODO: update the total timing variables only when the check button is pressed
	//Update Total Timing seconds
	for(i=0;i<num_of_slots;i++){
		buffer += slots[i].seconds;
		total_timing[0] = buffer;
	}
	update_total_timing_txt();
}

//----------3.2. Text Initializers -----------//

void Scr_SettingsView::scroll_min1UpdateItem(custom_num_scroll_side& item, int16_t itemIndex)
{
	item.set_txt_num(itemIndex);
}

void Scr_SettingsView::scroll_min1UpdateCenterItem(custom_num_scroll_sel& item, int16_t itemIndex)
{
	item.set_txt_num(itemIndex);
}

void Scr_SettingsView::scroll_sec1UpdateItem(custom_num_scroll_side& item, int16_t itemIndex)
{
	item.set_txt_num(itemIndex);
}

void Scr_SettingsView::scroll_sec1UpdateCenterItem(custom_num_scroll_sel& item, int16_t itemIndex)
{
	item.set_txt_num(itemIndex);
}

void Scr_SettingsView::scroll_numofslotsUpdateItem(custom_num_scroll_side& item, int16_t itemIndex)
{
	item.set_txt_num(MAX_SLOTS_NUM-itemIndex);
}

void Scr_SettingsView::scroll_numofslotsUpdateCenterItem(custom_num_scroll_sel& item, int16_t itemIndex)
{
	item.set_txt_num(MAX_SLOTS_NUM-itemIndex);
}
