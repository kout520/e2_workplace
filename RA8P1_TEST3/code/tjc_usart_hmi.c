/**
ʹ��ע������:
    1.��tjc_usart_hmi.c��tjc_usart_hmi.h �ֱ��빤��
    2.����Ҫʹ�õĺ������ڵ�ͷ�ļ������ #include "tjc_usart_hmi.h"
*/
#include "tjc_usart_hmi.h"
#include "headfile.h"


#define FRAME_LENGTH 7
#define u8 uint8_t

uint8_t lock_flag = 0;

typedef struct
{
    uint16_t Head;
    uint16_t Tail;
    uint16_t Length;
    uint8_t  Ring_data[RINGBUFFER_LEN];
}RingBuffer_t;

RingBuffer_t ringBuffer;	//����һ��ringBuffer�Ļ�����
uint8_t RxBuffer[1];


void UART_HIM_Init(void)
{
    fsp_err_t err6;
    
    err6 = g_uart6.p_api->open(g_uart6.p_ctrl, g_uart6.p_cfg);//����UAERT6
    
    
    
    initRingBuffer();//���λ�������ʼ��
    
}

/********************************************************
��������  		intToStr
���ڣ�    	2024.09.18
���ܣ�    	������ת��Ϊ�ַ���
���������		Ҫת������������,������ַ�������
����ֵ�� 		��
�޸ļ�¼��
**********************************************************/
void intToStr(int num, char* str) {
    int i = 0;
    int isNegative = 0;

    // ������
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    // ��ȡÿһλ����
    do {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num);

    // ����Ǹ�������Ӹ���
    if (isNegative) {
        str[i++] = '-';
    }

    // ����ַ�����ֹ��
    str[i] = '\0';

    // ��ת�ַ���
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return ;
}


/********************************************************
��������  		uart_send_char
���ڣ�    	2024.09.18
���ܣ�    	���ڷ��͵����ַ�
���������		Ҫ���͵ĵ����ַ�
����ֵ�� 		��
�޸ļ�¼��
**********************************************************/
void uart_send_char(char ch)
{
    uint8_t ch2 = (uint8_t)ch;
    
    
    
        /* ���������ַ� */
    g_uart6.p_api->write(g_uart6.p_ctrl, &ch2, 1);

    /* �ȴ�������� */
    uart6_wait_for_tx();
    
//    // ���͵����ַ�
//    USART_SendData(USART2, ch2);
//    
//    // �ȴ��������
//    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
//    
//    return;
}

// /********************************************************
// ��������  		uart_send_char
// ���ڣ�    	2024.09.18
// ���ܣ�    	���ڷ��͵����ַ�
// ���������		Ҫ���͵ĵ����ַ�
// ����ֵ�� 		��
// �޸ļ�¼��
// **********************************************************/
// void uart_send_char(char ch)
// {
// 	uint8_t ch2 = (uint8_t)ch;
//     //������0æ��ʱ��ȴ�����æ��ʱ���ٷ��ʹ��������ַ�
// 	//while(__HAL_UART_GET_FLAG(&TJC_UART, UART_FLAG_TXE) == RESET);	//�ȴ��������
// 	while(__HAL_UART_GET_FLAG(&TJC_UART, UART_FLAG_TC) == RESET);
//     //���͵����ַ�
// 	HAL_UART_Transmit_IT(&TJC_UART, &ch2, 1);



    
//     // USART_SendData(pUSARTx, data);
    
//     // while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);



// 	return;
// }



void uart_send_string(char* str)
{
    //��ǰ�ַ�����ַ���ڽ�β ���� �ַ����׵�ַ��Ϊ��
    while(*str!=0&&str!=0)
    {
        //�����ַ����׵�ַ�е��ַ��������ڷ������֮���׵�ַ����
        uart_send_char(*str++);
    }
	return;
}

/********************************************************
��������  		tjc_send_string
���ڣ�    	2024.09.18
���ܣ�    	���ڷ����ַ����ͽ�����
���������		Ҫ���͵��ַ���
����ֵ�� 		��
ʾ��:			tjc_send_val("n0", "val", 100); ���������ݾ��� n0.val=100
�޸ļ�¼��
**********************************************************/
void tjc_send_string(char* str)
{
    //��ǰ�ַ�����ַ���ڽ�β ���� �ַ����׵�ַ��Ϊ��
    while(*str!=0&&str!=0)
    {
        //�����ַ����׵�ַ�е��ַ��������ڷ������֮���׵�ַ����
        uart_send_char(*str++);
    }
	uart_send_char(0xff);
	uart_send_char(0xff);
	uart_send_char(0xff);
	return;
}

/********************************************************
��������  		tjc_send_txt
���ڣ�    	2024.09.18
���ܣ�    	���ڷ����ַ����ͽ�����
���������		Ҫ���͵��ַ���
����ֵ�� 		��
ʾ��:			tjc_send_txt("t0", "txt", "ABC"); ���������ݾ���t0.txt="ABC"
�޸ļ�¼��
**********************************************************/
void tjc_send_txt(char* objname, char* attribute, char* txt)
{

    uart_send_string(objname);
    uart_send_char('.');
    uart_send_string(attribute);
    uart_send_string("=\"");
    uart_send_string(txt);
    uart_send_char('\"');
	uart_send_char(0xff);
	uart_send_char(0xff);
	uart_send_char(0xff);
	return;
}


/********************************************************
��������  		tjc_send_val
���ڣ�    	2024.09.18
���ܣ�    	���ڷ����ַ����ͽ�����
���������		Ҫ���͵��ַ���
����ֵ�� 		��
�޸ļ�¼��
**********************************************************/
void tjc_send_val(char* objname, char* attribute, int val)
{
	//ƴ���ַ���,����n0.val=123
    uart_send_string(objname);
    uart_send_char('.');
    uart_send_string(attribute);
    uart_send_char('=');
    //C���������ε�ȡֵ��Χ�ǣ���-2147483648 ~ 2147483647��, �Ϊ-2147483648,���Ͻ�����\0һ��12���ַ�
    char txt[12]="";
    intToStr(val, txt);
    uart_send_string(txt);
	uart_send_char(0xff);
	uart_send_char(0xff);
	uart_send_char(0xff);
	return;
}

/********************************************************
��������  		tjc_send_nstring
���ڣ�    	2024.09.18
���ܣ�    	���ڷ����ַ����ͽ�����
���������		Ҫ���͵��ַ���,�ַ�������
����ֵ�� 		��
�޸ļ�¼��
**********************************************************/
void tjc_send_nstring(char* str, unsigned char str_length)
{
    //��ǰ�ַ�����ַ���ڽ�β ���� �ַ����׵�ַ��Ϊ��
    for (int var = 0; var < str_length; ++var)
    {
        //�����ַ����׵�ַ�е��ַ��������ڷ������֮���׵�ַ����
        uart_send_char(*str++);
    }
	uart_send_char(0xff);
	uart_send_char(0xff);
	uart_send_char(0xff);
	return;
}

u8 USART_Rbuffer_Num = 0;
u8 USART_Tbuffer_Num = 0;
// u8 USART_Rbuffer[buffer_len];//���ջ���������



/********************************************************
��������  		initRingBuffer
���ڣ�    	2022.10.08
���ܣ�    	��ʼ�����λ�����
���������
����ֵ�� 		void
�޸ļ�¼��
**********************************************************/
void initRingBuffer(void)
{
	//��ʼ�������Ϣ
	ringBuffer.Head = 0;
	ringBuffer.Tail = 0;
	ringBuffer.Length = 0;
	return;
}

//�����ж�
//void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//void USART2_IRQHandler(void)
//{
//    
//    // ��ȷ��ȡ���յ��� HEX ����
//    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
//    {
//        
//        uint8_t receivedData = (uint8_t)USART_ReceiveData(USART2);
//        USART_ClearITPendingBit(USART2, USART_IT_RXNE);
//        
//        write1ByteToRingBuffer(receivedData);
//        USART_Rbuffer_Num++;
//        
//    }
//}
/**********************************************************/
static volatile int g_uart6_tx_complete = 0;
static volatile int g_uart6_rx_complete = 0;

void uart6_wait_for_tx(void)
{
    while (!g_uart6_tx_complete);
    g_uart6_tx_complete = 0;
}

void uart6_wait_for_rx(void)
{
    while (!g_uart6_rx_complete);
    g_uart6_rx_complete = 0;
}
//�����ж�
// �����жϻص�����
void uart6_callback(uart_callback_args_t * p_args)
{
    static uint8_t rx_data;
    
    switch (p_args->event)
    {
        case UART_EVENT_TX_COMPLETE: // �������
        {
            g_uart6_tx_complete = 1;
            break;
        }
        
        case UART_EVENT_RX_CHAR: // �����ַ������жϣ���Ҫ����
        {
            // ��ȡ����
            rx_data = (uint8_t)p_args->data;
            
            // д�뻷������
            write1ByteToRingBuffer(rx_data);
            
            // ���ӻ���������
            USART_Rbuffer_Num++;
            
            
            break;
        }
        
        case UART_EVENT_RX_COMPLETE: // �������ɣ�DMA�����ָ��������
        {
            g_uart6_rx_complete = 1;
            // ������Դ����������ݽ������
            break;
        }
        
        case UART_EVENT_ERR_PARITY:   // ��żУ�����
        case UART_EVENT_ERR_FRAMING:  // ֡����
        {
            // ������
            // �������ô����־�������������
            break;
        }
        
        default:
        {
            break;
        }
    }
}

int a = 0;
char str[100];
//���������ݻ�ͨ
// ����WiFi��Ϣ������
#define WIFI_SSID_MAX_LEN 32
#define WIFI_PWD_MAX_LEN 64

static char wifi_ssid[WIFI_SSID_MAX_LEN] = {0};
static char wifi_pwd[WIFI_PWD_MAX_LEN] = {0};
static uint8_t wifi_ssid_len = 0;
static uint8_t wifi_pwd_len = 0;
static uint8_t wifi_data_type = 0; // 0:���� 1:�ȴ�SSID 2:�ȴ�����
static uint8_t wifi_frame_received = 0; // ����Ƿ��ѽ�������֡

//���������ݻ�ͨ
void HIM_connection(void)
{
    a++;
    while (usize >= 4)
    {
        // ������֡��55 XX 00 00 FF FF FF
        if (usize >= 7 && u(0) == 0x55 && u(2) == 0x00 && u(3) == 0x00 && 
            u(4) == 0xff && u(5) == 0xff && u(6) == 0xff)
        {
            if (u(1) == 0x01) // ����
            {

            } 
            else if (u(1) == 0x02) // ��ǽ�������WiFi����
            {
                wifi_data_type = 1;
                wifi_frame_received = 0; // ���ý��ձ��
                wifi_ssid_len = 0;
                memset(wifi_ssid, 0, WIFI_SSID_MAX_LEN);
                printf("��ʼ����SSID\r\n");
            } 
            else if (u(1) == 0x03) // ��ǽ�������WiFi����
            {
                printf("SSID�������: %s\r\n", wifi_ssid);
                wifi_data_type = 2;
                wifi_frame_received = 0; // ���ý��ձ��
                wifi_pwd_len = 0;
                memset(wifi_pwd, 0, WIFI_PWD_MAX_LEN);
                printf("��ʼ��������\r\n");
            } 
            else if (u(1) == 0x04) // ����WiFi��Ϣ
            {
                // ����ֹͣ����
                wifi_data_type = 0;
                wifi_frame_received = 0;
                
                // �������
                printf("WiFi SSID: %s\r\n", wifi_ssid);
                printf("WiFi PWD: %s\r\n", wifi_pwd);
                
                // һ���Է���������WiFi��Ϣ��ESP32
                send_wifi_to_esp32(wifi_ssid, wifi_pwd);
                
                // ��ջ�����
                memset(wifi_ssid, 0, WIFI_SSID_MAX_LEN);
                memset(wifi_pwd, 0, WIFI_PWD_MAX_LEN);
                wifi_ssid_len = 0;
                wifi_pwd_len = 0;
            }
            else if (u(1) == 0x05) //��������
            {
                a = 0;
                lock_flag = 1;
                R_IOPORT_PinWrite(g_ioport.p_ctrl, BSP_IO_PORT_04_PIN_11, BSP_IO_LEVEL_HIGH);
            }
            else if (u(1) == 0x06) //���ָ��
            {
                    sprintf(str, "t0.txt=\"�����\"");
                    tjc_send_string(str);
                    finger_addtion();
                    R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);
                    sprintf(str, "t0.txt=\"%d\"",AS608_GetFRNumber());
                    tjc_send_string(str);
            }
            else if (u(1) == 0x07) //ɾ��ָ��
            {
                    AS608_DeleteFR(0xffff);
                    R_BSP_SoftwareDelay(50, BSP_DELAY_UNITS_MILLISECONDS);
                    sprintf(str, "t0.txt=\"%d\"",AS608_GetFRNumber());
                    tjc_send_string(str);
            }
            else if (u(1) == 0x08) //��������ͷ��
            {
                    uart8_send_value(222);
            }
            else if (u(1) == 0x09) //ɾ��ָ��
            {

            }
            udelete(7);
        }
        // �������֡��70 XX XX ... FF FF FF
        else if (u(0) == 0x70 && wifi_data_type != 0 && wifi_frame_received == 0) 
        {
            // ֻ�ڽ���״̬��δ���չ�����֡ʱ�Ŵ���
            
            // ���ҽ�β�� FF FF FF
            uint8_t frame_end = 0;
            for (uint8_t i = 1; i < usize - 2; i++)
            {
                if (u(i) == 0xff && u(i+1) == 0xff && u(i+2) == 0xff)
                {
                    frame_end = i;
                    break;
                }
            }
            
            if (frame_end > 0) // �ҵ�����֡
            {
                uint8_t data_len = frame_end - 1; // ���ݳ��ȣ�ȥ��0x70֡ͷ��
                
                if (wifi_data_type == 1) // ����SSID
                {
                    if (data_len < WIFI_SSID_MAX_LEN)
                    {
                        for (uint8_t i = 0; i < data_len; i++)
                        {
                            wifi_ssid[wifi_ssid_len++] = u(i + 1);
                        }
                        wifi_ssid[wifi_ssid_len] = '\0';
                        wifi_frame_received = 1; // ����ѽ���
                        printf("����SSID����: %s (����:%d)\r\n", wifi_ssid, wifi_ssid_len);
                    }
                }
                else if (wifi_data_type == 2) // ��������
                {
                    if (data_len < WIFI_PWD_MAX_LEN)
                    {
                        for (uint8_t i = 0; i < data_len; i++)
                        {
                            wifi_pwd[wifi_pwd_len++] = u(i + 1);
                        }
                        wifi_pwd[wifi_pwd_len] = '\0';
                        wifi_frame_received = 1; // ����ѽ���
                        printf("������������: %s (����:%d)\r\n", wifi_pwd, wifi_pwd_len);
                    }
                }
                
                udelete(frame_end + 3); // ɾ����������֡������3��0xFF��
            }
            else
            {
                break; // ���ݲ��������ȴ���������
            }
        }
        else
        {
            udelete(1); // ��ƥ��ɾ��1�ֽ�
        }
    }
}






/********************************************************
��������  		write1ByteToRingBuffer
���ڣ�    	2022.10.08
���ܣ�    	�����λ�����д������
���������		Ҫд���1�ֽ�����
����ֵ�� 		void
�޸ļ�¼��
**********************************************************/
void write1ByteToRingBuffer(uint8_t data)
{
	if(ringBuffer.Length >= RINGBUFFER_LEN) //�жϻ������Ƿ�����
	{
	return ;
	}
	ringBuffer.Ring_data[ringBuffer.Tail]=data;
	ringBuffer.Tail = (ringBuffer.Tail+1)%RINGBUFFER_LEN;//��ֹԽ��Ƿ�����
	ringBuffer.Length++;
	return ;
}
/********************************************************
��������  		read1ByteFromRingBuffer
���ߣ�
���ڣ�    	2022.10.08
���ܣ�    	�Ӵ��ڻ�������ȡ1�ֽ�����
���������		position:��ȡ��λ��
����ֵ�� 		����λ�õ�����(1�ֽ�)
�޸ļ�¼��
**********************************************************/
uint8_t read1ByteFromRingBuffer(uint16_t position)
{
	uint16_t realPosition = (ringBuffer.Head + position) % RINGBUFFER_LEN;

	return ringBuffer.Ring_data[realPosition];
}





/********************************************************
��������  		deleteRingBuffer
���ߣ�
���ڣ�    	2022.10.08
���ܣ�    	ɾ�����ڻ���������Ӧ���ȵ�����
���������		Ҫɾ���ĳ���
����ֵ�� 		void
�޸ļ�¼��
**********************************************************/
void deleteRingBuffer(uint16_t size)
{
	if(size >= ringBuffer.Length)
	{
	    initRingBuffer();
	    return;
	}
	for(int i = 0; i < size; i++)
	{
		ringBuffer.Head = (ringBuffer.Head+1)%RINGBUFFER_LEN;//��ֹԽ��Ƿ�����
		ringBuffer.Length--;
		return;
	}

}






/********************************************************
��������  		getRingBufferLength
���ߣ�
���ڣ�    	2022.10.08
���ܣ�    	��ȡ���ڻ���������������
���������
����ֵ�� 		���ڻ���������������
�޸ļ�¼��
**********************************************************/
uint16_t getRingBufferLength()
{
	return ringBuffer.Length;
}


/********************************************************
��������  		isRingBufferOverflow
���ߣ�
���ڣ�    	2022.10.08
���ܣ�    	�жϻ��λ������Ƿ�����
���������
����ֵ�� 		0:���λ��������� , 1:���λ�����δ��
�޸ļ�¼��
**********************************************************/
uint8_t isRingBufferOverflow()
{
	return ringBuffer.Length < RINGBUFFER_LEN;
}



