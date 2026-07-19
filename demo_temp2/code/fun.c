#include "user_app.h"

//void Fan_task(void)
//{
//    
//    
//      HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_SET);
//    
//    
//}

void ZhengDong_task(void)
{
    
    
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_7);
    
    
}

void LED_task(void)
{
    
//      HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
//      HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_4);
    
}
void Beef_task(void)
{
    
    HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_15);
    //HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,GPIO_PIN_SET);
    
    
}

//c5,c8,c9



uint8_t B1_state;
uint8_t B1_last_state;
uint8_t B2_state;
uint8_t B2_last_state;
uint8_t B3_state;
uint8_t B3_last_state;




void key_scan(void)
{
    static uint32_t last_tick;
    uint32_t current_tick = HAL_GetTick();
    if(current_tick - last_tick <20)return;
    last_tick = current_tick;
    //B1_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5);
    B2_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);
    B3_state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);

//    if(B1_state == 0 && B1_last_state == 1)
//    {
//        ZhengDong_task();
//    }
    if(B2_state == 0 && B2_last_state == 1)
    {
        LED_task();
    }    
    if(B3_state == 0 && B3_last_state == 1)
    {
        Beef_task();
    }    

    
//    B1_last_state  = B1_state;
    B2_last_state  = B2_state;
    B3_last_state  = B3_state;
}




