#include <gui/timer_screen/timerView.hpp>

timerView::timerView()
{

}

void timerView::setupScreen()
{
    timerViewBase::setupScreen();
}

void timerView::tearDownScreen()
{
    timerViewBase::tearDownScreen();
}

    
void timerView::showTime(int year,int month,int data,int hour,int min,int sec)
{
    Unicode::snprintf(text_111Buffer, TEXT_111_SIZE, "%04d", year) ;
    text_111.invalidate();
    Unicode::snprintf(text_222Buffer1, TEXT_222BUFFER1_SIZE, "%02d",month ) ;
    text_222.invalidate();
    Unicode::snprintf(text_222Buffer2, TEXT_222BUFFER2_SIZE, "%02d", data) ;
    text_222.invalidate();
    Unicode::snprintf(text_333Buffer1, TEXT_333BUFFER1_SIZE, "%02d",hour ) ;
    text_333.invalidate();
    Unicode::snprintf(text_333Buffer2, TEXT_333BUFFER2_SIZE, "%02d", min) ;
    text_333.invalidate();
    Unicode::snprintf(text_444Buffer, TEXT_444_SIZE, "%02d", sec);
    text_444.invalidate();
    
    
}

void timerView::showStep(int step)
{

    
    Unicode::snprintf(text_555Buffer, TEXT_555_SIZE, "%d", step);
    text_555.invalidate();
}










