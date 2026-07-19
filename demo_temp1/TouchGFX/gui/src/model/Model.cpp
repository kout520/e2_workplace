#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

//头文件包含
extern "C"
{
	#include "user_app.h"
    
    extern volatile SHT20_TemRH_Val gTemRH_Val;	//存储温湿度值
    
    
    extern volatile uint16_t gChipTempVal;
    extern volatile uint16_t gVrefVal;
    extern volatile uint16_t gVbatVal;
    extern int32_t n_sp02; //SPO2 value
    extern int8_t ch_spo2_valid;   //indicator to show if the SP02 calculation is valid
    extern int32_t n_heart_rate;   //heart rate value
    extern float n_temperature;	//体表温度
    extern volatile uint16_t gCurrentVal;			//资源扩展板电流，通道IN8   
    extern volatile uint16_t gVoltageVal;			//资源扩展板电压，通道IN9 
    extern volatile float pitch,roll,yaw; 		//欧拉角
    
    extern RTC_DateTypeDef gSystemDate;  //获取日期结构体
    extern RTC_TimeTypeDef gSystemTime;	//获取时间结构体
    void BSP_SHT20_GetData(void);
    void Update_ChipInfo(void);
    void Update_HeartRateInfo(void);
    void Update_EulerAngle(void);
    void Update_System_Time(void);
    void Update_FiveKey_Value(void);
}


Model::Model() : modelListener(0),tickCD(0),num(0)
{
	
}

//20ms
void Model::tick()
{
    
    if(++tickCD >=25)
    {
        //电压系列
        Update_ChipInfo();
        VCC = gChipTempVal;
        CVV = gVrefVal*3.3f/4095;
        RTC_VCC = gVbatVal*4*3.3f/4095;
        modelListener->showVCC(VCC,CVV,RTC_VCC);
        
        //计数
        //num++;
        tickCD=0;
        //modelListener->showNum(num);
    }
    
    
    
    
    BSP_SHT20_GetData();
    temp = gTemRH_Val.Tem;
    hum = gTemRH_Val.Hum;
    modelListener->showTempHum(temp,hum);
    
    light = ap3216c_read_ambient_light();
    hongwai = ap3216c_read_ps_data();
    IR_light = ap3216c_read_ir_data();
    modelListener->showLight(light,hongwai,IR_light);
    
    //时间
    Update_System_Time();
    year = gSystemDate.Year+2000;
    month = gSystemDate.Month;
    data = gSystemDate.Date;
    hour = gSystemTime.Hours;
    min = gSystemTime.Minutes;
    sec = gSystemTime.Seconds;
    modelListener->showTime(year,month,data,hour,min,sec);
    
    //步数
    setp =gSportStep;
    modelListener->showStep(setp);
    
   //欧拉角
    modelListener->showOrg(pitch, roll,yaw);
    //身体数据
    HR= n_heart_rate/4;
    SP02=n_sp02;
    HR_temp = n_temperature;
    modelListener->showHR(HR,SP02,HR_temp);
    //电压采集
     ADC_cc= gCurrentVal*100*3.3f/4095;
    ADC_ma= gVoltageVal*3.3f/4095;
    modelListener->showADC( ADC_cc,ADC_ma);
}

//实现灯函数
void Model::led_task()
{
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_4);
}
//实现声音函数
void Model::beef_task()
{
    HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_15);  
}
//实现风扇函数
void Model::fan_task()
{
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_6);
}

//实现震动函数
void Model::zhendong_task()
{
    HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_7);
}
//实现心率测量函数
void Model::sp02_task()
{
    Update_HeartRateInfo();
}



void Model::ipStrToInt(uint8_t* sip, uint8_t* nip)
{
    char num[4];
    int numIndex = 0;
    int nipIndex = 0;
    while(1)
    {
        if(*sip=='.' || *sip=='\0')
        {
            num[numIndex] = '\0';
            numIndex = 0;
            nip[nipIndex++] = atoi(num);
        }
        else
        {
            num[numIndex++] = *sip;
        }
        if(*sip == '\0')
            break;
        sip++;
    }
}

