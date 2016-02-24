
#include "stm32f10x.h"
//Макрос для проверки состояние определенного светодиода.
#define   get_led_state(pin) ((GPIOC->ODR & pin) != 0)

//Функция отправляет байт в UART
void send_to_uart(uint8_t data)  {
 while(!(USART1->SR & USART_SR_TC));
 USART1->DR=data;
}

//Функция отправляет строку в UART
void send_str(char * string) {
 uint8_t i=0;
 while(string[i]) {
  send_to_uart(string[i]);
  i++;
 }
 send_to_uart('\r');
 send_to_uart('\n');
}

int main(void)
{
 uint8_t uart_data;
 uint16_t led;
 //Включаем порты и UART1
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC  , ENABLE);
 //Выключаем JTAG (он занимает ноги нужные нам)
 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

 //Настраиваем первые 10 ног порта B на выход
 GPIO_InitTypeDef gpio_port;
 gpio_port.GPIO_Pin = GPIO_Pin_13;
 gpio_port.GPIO_Mode = GPIO_Mode_Out_PP;
 gpio_port.GPIO_Speed = GPIO_Speed_2MHz;
 GPIO_Init(GPIOC, &gpio_port);
 GPIOB->ODR=0x00;

    // Настраиваем ногу PA10 как вход UARTа (RxD)
 gpio_port.GPIO_Pin   = GPIO_Pin_10;
 gpio_port.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &gpio_port);

    // Настраиваем ногу PA9 как выход UARTа (TxD)
    // Причем не просто выход, а выход с альтернативной функцией

    gpio_port.GPIO_Pin   = GPIO_Pin_9;
    gpio_port.GPIO_Speed = GPIO_Speed_50MHz;
    gpio_port.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &gpio_port);

    //Заполняем структуру настройками UARTa
    USART_InitTypeDef uart_struct;
    uart_struct.USART_BaudRate            = 9600;
    uart_struct.USART_WordLength          = USART_WordLength_8b;
    uart_struct.USART_StopBits            = USART_StopBits_1;
    uart_struct.USART_Parity              = USART_Parity_No ;
    uart_struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    uart_struct.USART_Mode                =  USART_Mode_Tx;
    //Инициализируем UART
    USART_Init(USART1, &uart_struct);
    //Включаем UART
    USART_Cmd(USART1, ENABLE);

    while(1) //Бесконечный цикл в нем мы проверяем ...
    {
    	GPIOC->ODR^=GPIO_Pin_13;
    	send_str("=================");

    }

}

/**************************************************************************************/

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**************************************************************************************/
