/******************************************************************************
  * 文件： main.c
  * 作者：
  * 日期： 2015—07-08
  * 版本： 1.0
  * 说明： 实验九：TFT液晶显示实验
  *
  ******************************************************************************/

#include "system.h"  //库头文件
#include "device.h"  //外设头文件

/*实现功能：1.添加液晶显示库函数并添加相应路径
 *          2.使用填充函数闪烁几种不同的屏幕延时
 *          3.分块动态显示填充区域
 *
 *
 *          */


//#define WHITE         	 0xFFFF
//#define BLACK         	 0x0000
//#define RED           	 0x001F//
//#define BLUE         	 0xF800
//#define GREEN         	 0x07E0
//#define GBLUE			 0X07FF
//#define PURPLE			 0XF01F //紫色
//#define MAGENTA       	 0xF81F
//#define CYAN          	 0x7FFF
//#define YELLOW        	 0xFFE0
//#define BROWN 			 0XBC40 //棕色
//#define BRRED 			 0XFC07 //棕红色
//#define GRAY  			 0X8430 //灰色
//#define DARKBLUE      	 0X01CF	//深蓝色
//#define LIGHTBLUE      	 0X7D7C	//浅蓝色
//#define GRAYBLUE       	 0X5458 //灰蓝色
//#define LIGHTGREEN     	 0X841F //浅绿色
//#define LGRAY 			 0XC618 //浅灰色(PANNEL)
//#define LGRAYBLUE        0XA651 //浅灰蓝色
//#define LBBLUE           0X2B12 //浅棕蓝色


#define XMax   240
#define YMax   400


void main()
 {

	uint32_t SysClock;
//	uint16_t i;

	LED_Init();
	Button_Init();
	Timer_Init();

//    UART_Init();

   // FPUEnable();
   // FPULazyStackingEnable();
    //
    // Run from the PLL at 120 MHz.
    //


	SysClock=SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
				 SYSCTL_OSC_MAIN |
				 SYSCTL_USE_PLL |
				 SYSCTL_CFG_VCO_480), OSC_120MHZ);

    EPIGPIOinit();
    TFT_400x240_OTM4001Ainit(SysClock);

    // Open BackLight.
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
    ledclose();
    video_tutorial_Init();
    while(1){
    }
}






