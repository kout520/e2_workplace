#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
extern "C" {
#include "stdint.h"
}


class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void showNum(int num){ }//如果数值更新通知前端
    
    virtual void showTempHum(float temp,float hum){ }//如果数值更新温度湿度
    
    virtual void showLight(int light,int hongwai,int IR_light){ }//如果数值更新温度湿度
    
    virtual void showVCC(float VCC,float CVV,float RTC_VCC){ }//更新芯片、参考、RTC电压
    
    virtual void showTime(int year,int month,int data,int hour,int min,int sec){ }//更新时间
    
    virtual void showStep(int step){ }//更新步数
    
    virtual void showOrg(float pitch,float roll,float yaw){ }//更新欧拉角
    
    virtual void showHR(int HR,int SP02,float HR_temp){ }//更新心率
    
    virtual void showADC(float ADC_cc,float ADC_ma){ }//更新电压采集
    
    
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
