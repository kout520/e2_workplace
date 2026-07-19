#include <gui/oula_screen/oulaView.hpp>

oulaView::oulaView()
{

}

void oulaView::setupScreen()
{
    oulaViewBase::setupScreen();
}

void oulaView::tearDownScreen()
{
    oulaViewBase::tearDownScreen();
}

    
void oulaView::showOrg(float pitch,float roll,float yaw)
{
    
    Unicode::snprintfFloat(text_o2Buffer, TEXT_O2_SIZE, "%.3f", pitch) ;//¸©Ñö½Ç
    text_o2.invalidate();
    Unicode::snprintfFloat(text_o1Buffer, TEXT_O1_SIZE, "%.3f", roll) ;//·­¹ö½Ç
    text_o1.invalidate();
    Unicode::snprintfFloat(text_o3Buffer, TEXT_O3_SIZE, "%.3f", yaw) ;//Æ«º½½Ç
    text_o3.invalidate();
    
}