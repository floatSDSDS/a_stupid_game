/******************************************************************************
  * �ļ��� main.c
  * ���ߣ�
  * ���ڣ� 2015��07-08
  * �汾�� 1.0
  * ˵���� ʵ��ţ�TFTҺ����ʾʵ��
  *
  ******************************************************************************/

#include "system.h"  //��ͷ�ļ�
#include "device.h"  //����ͷ�ļ�

/*ʵ�ֹ��ܣ�1.���Һ����ʾ�⺯���������Ӧ·��
 *          2.ʹ����亯����˸���ֲ�ͬ����Ļ��ʱ
 *          3.�ֿ鶯̬��ʾ�������
 *
 *
 *          */


//#define WHITE         	 0xFFFF
//#define BLACK         	 0x0000
//#define RED           	 0x001F//
//#define BLUE         	 0xF800
//#define GREEN         	 0x07E0
//#define GBLUE			 0X07FF
//#define PURPLE			 0XF01F //��ɫ
//#define MAGENTA       	 0xF81F
//#define CYAN          	 0x7FFF
//#define YELLOW        	 0xFFE0
//#define BROWN 			 0XBC40 //��ɫ
//#define BRRED 			 0XFC07 //�غ�ɫ
//#define GRAY  			 0X8430 //��ɫ
//#define DARKBLUE      	 0X01CF	//����ɫ
//#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ
//#define GRAYBLUE       	 0X5458 //����ɫ
//#define LIGHTGREEN     	 0X841F //ǳ��ɫ
//#define LGRAY 			 0XC618 //ǳ��ɫ(PANNEL)
//#define LGRAYBLUE        0XA651 //ǳ����ɫ
//#define LBBLUE           0X2B12 //ǳ����ɫ


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






