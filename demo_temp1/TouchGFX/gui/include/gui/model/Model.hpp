#ifndef MODEL_HPP
#define MODEL_HPP

//头文件包含
extern "C"
{
	#include "user_app.h"
}

class ModelListener;


class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

	void tick();
  void ipStrToInt(uint8_t* sip, uint8_t* nip); 
    void led_task();//灯函数
    void beef_task();//声音函数
    void fan_task();//风扇函数
    void zhendong_task();//震动函数
    void sp02_task();//震动函数
    
    
    int tickCD;
    int num;
    
    float temp;//温度
    float hum;//湿度
    
    int light;//光强
    int hongwai;//红外
    int IR_light;//IR
    
    float VCC;//芯片温度
    float CVV;//参考电压修正值
    int ADC_DR;//ADC
    float RTC_VCC;//RTC电池电压
    
    int HR;//心率
    int SP02;//血氧
    float HR_temp;//体温
    
    int year;//年
    int month;//月
    int data;//日
    int hour;//时
    int min;//分
    int sec;//秒
    
    int setp;//步数
    
    float ADC_cc;
    float ADC_ma;

    
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
