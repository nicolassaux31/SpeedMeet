#include <gui/containers/custom_cnt_slot.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

custom_cnt_slot::custom_cnt_slot()
{

}

void custom_cnt_slot::initialize()
{
    custom_cnt_slotBase::initialize();
}

void custom_cnt_slot::set_txt_slotnum(int val){
	Unicode::snprintf(txt_slotnumBuffer, TXT_SLOTNUM_SIZE, "%d", val);
}

void custom_cnt_slot::set_txt_slotname(string name){
	Unicode::strncpy(txt_slotnameBuffer, name.c_str(), TXT_SLOTNAME_SIZE);
}
