#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <briey.h>


// 打印字符串函数
void print(char *str) {
    while (*str) {
        uart_write(UART, *(str++));  // 逐个字符发送
    }
}
void camera(int value)
{
    // GPIO_A_BASE->OUTPUT_ENABLE |= (1 << 7);
    // if (value == 1)
    //     GPIO_A_BASE->OUTPUT |= (1 << 7);
    // else
    //     GPIO_A_BASE->OUTPUT &= ~(1 << 7);
}
void robot_ready()
{
    uint16_t ready_jiaodu[6] = {200, 500, 100, 500, 500, 500};
    for(uint8_t i = 1; i < 7; i++)
    {   
        uint8_t ready_param1 = ready_jiaodu[i-1] & 0xFF;
        uint8_t ready_param2 = (ready_jiaodu[i-1] >> 8) & 0xFF;
        uint8_t ready_check_sum = ~(i + 0x07 + 0x01 + ready_param1 + ready_param2 + 0xE8 + 0x00) & 0xFF;
        uart_write(UART, 0x55);//帧头
	    uart_write(UART, 0x55);//帧头
	    uart_write(UART, i);//ID号
	    uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	    uart_write(UART, 0x01);//指令
	    uart_write(UART, ready_param1);//参数1
	    uart_write(UART, ready_param2);//参数2
	    uart_write(UART, 0xE8);//参数3
	    uart_write(UART, 0x00);//参数4
	    uart_write(UART, ready_check_sum);//校验和
    }
    for (int volatile i = 0; i < 3000000; i++) ;

}


void robot_catch()
{
    uint16_t catch_jiaodu[6] = {550, 501, 282, 829, 459, 500};
    for(uint8_t i = 6; i > 0; i--)
    {   
        if(i == 1)
            for (int volatile i = 0; i < 6000000; i++);
        uint8_t catch_param1 = catch_jiaodu[i-1] & 0xFF;
        uint8_t catch_param2 = (catch_jiaodu[i-1] >> 8) & 0xFF;
        uint8_t catch_check_sum = ~(i + 0x07 + 0x01 + catch_param1 + catch_param2 + 0xE8 + 0x00) & 0xFF;
        uart_write(UART, 0x55);//帧头
	    uart_write(UART, 0x55);//帧头
	    uart_write(UART, i);//ID号
	    uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	    uart_write(UART, 0x01);//指令
	    uart_write(UART, catch_param1);//参数1
	    uart_write(UART, catch_param2);//参数2
	    uart_write(UART, 0xE8);//参数3
	    uart_write(UART, 0x00);//参数4
	    uart_write(UART, catch_check_sum);//校验和
    }
    for (int volatile i = 0; i < 3000000; i++) ;

}

void robot_up()
{
    uint16_t up_jiaodu[6] = {550, 501, 117, 502, 501, 501};
    for(uint8_t i = 5; i > 0; i--)
    {   
        uint8_t up_param1 = up_jiaodu[i-1] & 0xFF;
        uint8_t up_param2 = (up_jiaodu[i-1] >> 8) & 0xFF;
        uint8_t up_check_sum = ~(i + 0x07 + 0x01 + up_param1 + up_param2 + 0xE8 + 0x00) & 0xFF;
        uart_write(UART, 0x55);//帧头
	    uart_write(UART, 0x55);//帧头
	    uart_write(UART, i);//ID号
	    uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	    uart_write(UART, 0x01);//指令
	    uart_write(UART, up_param1);//参数1
	    uart_write(UART, up_param2);//参数2
	    uart_write(UART, 0xE8);//参数3
	    uart_write(UART, 0x00);//参数4
	    uart_write(UART, up_check_sum);//校验和
    }
    for (int volatile i = 0; i < 3000000; i++) ;

}

void robot_turn_green()
{
    uint16_t turn_green_jiaodu[6] = {550, 498, 169, 786, 535, 96};
    for(uint8_t i = 6; i > 0; i--)
    {   
        uint8_t turn_green_param1 = turn_green_jiaodu[i-1] & 0xFF;
        uint8_t turn_green_param2 = (turn_green_jiaodu[i-1] >> 8) & 0xFF;
        uint8_t turn_green_check_sum = ~(i + 0x07 + 0x01 + turn_green_param1 + turn_green_param2 + 0xE8 + 0x00) & 0xFF;
        uart_write(UART, 0x55);//帧头
	    uart_write(UART, 0x55);//帧头
	    uart_write(UART, i);//ID号
	    uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	    uart_write(UART, 0x01);//指令
	    uart_write(UART, turn_green_param1);//参数1
	    uart_write(UART, turn_green_param2);//参数2
	    uart_write(UART, 0xE8);//参数3
	    uart_write(UART, 0x00);//参数4
	    uart_write(UART, turn_green_check_sum);//校验和
    }
    for (int volatile i = 0; i < 3000000; i++) ;
}

void robot_turn_red()
{
    uint16_t turn_green_jiaodu[6] = {550, 498, 169, 786, 535, 200};
    for(uint8_t i = 6; i > 0; i--)
    {   
        uint8_t turn_green_param1 = turn_green_jiaodu[i-1] & 0xFF;
        uint8_t turn_green_param2 = (turn_green_jiaodu[i-1] >> 8) & 0xFF;
        uint8_t turn_green_check_sum = ~(i + 0x07 + 0x01 + turn_green_param1 + turn_green_param2 + 0xE8 + 0x00) & 0xFF;
        uart_write(UART, 0x55);//帧头
	    uart_write(UART, 0x55);//帧头
	    uart_write(UART, i);//ID号
	    uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	    uart_write(UART, 0x01);//指令
	    uart_write(UART, turn_green_param1);//参数1
	    uart_write(UART, turn_green_param2);//参数2
	    uart_write(UART, 0xE8);//参数3
	    uart_write(UART, 0x00);//参数4
	    uart_write(UART, turn_green_check_sum);//校验和
    }
    for (int volatile i = 0; i < 3000000; i++) ;
}

void robot_turn_blue()
{
    uint16_t turn_green_jiaodu[6] = {550, 498, 169, 786, 535, 600};
    for(uint8_t i = 6; i > 0; i--)
    {   
        uint8_t turn_green_param1 = turn_green_jiaodu[i-1] & 0xFF;
        uint8_t turn_green_param2 = (turn_green_jiaodu[i-1] >> 8) & 0xFF;
        uint8_t turn_green_check_sum = ~(i + 0x07 + 0x01 + turn_green_param1 + turn_green_param2 + 0xE8 + 0x00) & 0xFF;
        uart_write(UART, 0x55);//帧头
	    uart_write(UART, 0x55);//帧头
	    uart_write(UART, i);//ID号
	    uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	    uart_write(UART, 0x01);//指令
	    uart_write(UART, turn_green_param1);//参数1
	    uart_write(UART, turn_green_param2);//参数2
	    uart_write(UART, 0xE8);//参数3
	    uart_write(UART, 0x00);//参数4
	    uart_write(UART, turn_green_check_sum);//校验和
    }
    for (int volatile i = 0; i < 3000000; i++) ;
}

void robot_release()
{
    uint16_t release_jiaodu[6] = {150, 498, 172, 815, 467, 96};
    for(uint8_t i = 1; i < 6; i++)
    {   
        uint8_t release_param1 = release_jiaodu[i-1] & 0xFF;
        uint8_t release_param2 = (release_jiaodu[i-1] >> 8) & 0xFF;
        uint8_t release_check_sum = ~(i + 0x07 + 0x01 + release_param1 + release_param2 + 0xE8 + 0x00) & 0xFF;
        uart_write(UART, 0x55);//帧头
	    uart_write(UART, 0x55);//帧头
	    uart_write(UART, i);//ID号
	    uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	    uart_write(UART, 0x01);//指令
	    uart_write(UART, release_param1);//参数1
	    uart_write(UART, release_param2);//参数2
	    uart_write(UART, 0xE8);//参数3
	    uart_write(UART, 0x00);//参数4
	    uart_write(UART, release_check_sum);//校验和
    }
    for (int volatile i = 0; i < 3000000; i++) ;
}

void GPIO_Write(int gpio, uint32_t value)
{
    GPIO_A_BASE->OUTPUT_ENABLE |= (1 << (10 + gpio));
    if (value)
        GPIO_A_BASE->OUTPUT |= (1 << (10 + gpio));
    else
        GPIO_A_BASE->OUTPUT &= ~(1 << (10 + gpio));
}

void GPIO_Set(int gpio, uint32_t value)
{
    if (value)
        GPIO_A_BASE->OUTPUT_ENABLE |= (1 << (10 + gpio));
    else
        GPIO_A_BASE->OUTPUT_ENABLE &= ~(1 << (10 + gpio));
}

uint32_t GPIO_Read(int gpio)
{
	GPIO_A_BASE->OUTPUT_ENABLE &= ~(1 << (10 + gpio));
    uint32_t input_value = GPIO_A_BASE->INPUT; // 读取整个 INPUT 值
    uint32_t bit = (input_value >> (10 + gpio)) & 0x1; // 取第 10 + gpio位
    return bit;  // 读取输入值
}
uint8_t JOYPAD_Read(void)
{
    volatile uint8_t temp = 0;
    int t;//ka zai zhe
    GPIO_Write(GPIO_LAT, 1);  // 将时钟线设置为高电平
    JOYPAD_Delay(80);
    GPIO_Write(GPIO_LAT, 0);  // 将时钟线设置为低电平
    // 读取 8 位数据
    for(t = 0; t < 8; t++)
    {
        temp >>= 1;  // 右移一位
        if(GPIO_Read(GPIO_DAT) == 0)  // 如果接收到低电平，则设置对应位为 1
            temp |= 0x80;

        GPIO_Write(GPIO_CLK, 1);  // 设置时钟线为高电平
        JOYPAD_Delay(80);
        GPIO_Write(GPIO_CLK, 0);  // 设置时钟线为低电平
        JOYPAD_Delay(80);
    }

    return temp;  // 返回读取的 8 位数据
}
void JOYPAD_Delay(uint32_t t)
{
    while(t--);
}


// 主函数
int main() {
    // UART 配置
    Uart_Config uartConfig;
	uartConfig.dataLength = 8;
	uartConfig.parity = NONE;
	uartConfig.stop = ONE;
	uartConfig.clockDivider = 50000000/8/115200-1;
	uart_applyConfig(UART,&uartConfig);
	print("Hello !\n");
	GPIO_A_BASE->OUTPUT_ENABLE = 0b111111;
    GPIO_A_BASE->OUTPUT = 0b110110;
    // GPIO_A_BASE->OUTPUT_ENABLE = 0b000000;
    uint8_t data = 0x00;
    // camera(1);
    while(1)
    {
        data = (GPIO_A_BASE->INPUT) & 0xFF;

        if(data == 0x05)//111切換手動控制模式
        {
            camera(1);
            for(uint8_t i = 1; i < 7; i++)
            {   
                uint8_t check_sum = ~(i + 0x07 + 0x01 + 0xF4 + 0x01 + 0xE8 + 0x03) & 0xFF;
                uart_write(UART, 0x55);//帧头
	            uart_write(UART, 0x55);//帧头
	            uart_write(UART, i);//ID号
	            uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	            uart_write(UART, 0x01);//指令
	            uart_write(UART, 0xF4);//参数1
	            uart_write(UART, 0x01);//参数2
	            uart_write(UART, 0xE8);//参数3
	            uart_write(UART, 0x03);//参数4
	            uart_write(UART, check_sum);//校验和
            }

            uint16_t jiaodu   = 500;
            uint16_t jiaodu1  = 500;
            uint16_t jiaodu3  = 500;
            uint16_t jiaodu45 = 500;
            uint16_t jiaodu6  = 500;
            uint8_t  id       = 0x00;
            uint8_t  two      = 0x00; 
            uint8_t  en       = 0;
            while (data == 0x05) {
                data = (GPIO_A_BASE->INPUT) & 0xFF;
                // 读取手柄状态
                uint8_t state = JOYPAD_Read();
                // 按键解析
                if (state & 0x01) { //A——張開
                    // 按键 A 被按下
                    if(jiaodu1 <= 995)
                        jiaodu1 = jiaodu1 + 10;
                    id = 0x01;
                    two = 0;
                    jiaodu = jiaodu1;
                    en = 1;
                }
                else if (state & 0x02) { //B——抓取
                    // 按键 B 被按下
                    if(jiaodu1 >= 12)
                        jiaodu1 = jiaodu1 - 10;
                    id = 0x01;
                    two = 0;
                    jiaodu = jiaodu1;
                    en = 1;
                }
                else if (state & 0x04) { //select——擡頭
                    if(jiaodu3 <= 992)
                        jiaodu3 = jiaodu3 + 4;
                    id = 0x03;
                    two = 0;
                    jiaodu = jiaodu3;
                    en = 1;
                }
                else if (state & 0x08) { //start——低頭
                    if(jiaodu3 >= 13)
                        jiaodu3 = jiaodu3 - 4;
                    id = 0x03;
                    two = 0;
                    jiaodu = jiaodu3;
                    en = 1;
                }
                else if (state & 0x20) { //up
                    if(jiaodu45 <= 995)
                        jiaodu45 = jiaodu45 + 2;
                    id = 0x04;
                    two = 1;
                    jiaodu = jiaodu45;
                    en = 1;
                }
                else if (state & 0x10) { //down
                    if(jiaodu45 >= 12)
                        jiaodu45 = jiaodu45 - 2;
                    id = 0x04;
                    two = 1;
                    jiaodu = jiaodu45;
                    en = 1;
                }
                else if (state & 0x40) { //left
                    if(jiaodu6 <= 992)
                        jiaodu6 = jiaodu6 + 4;
                    id = 0x06;
                    two = 0;
                    jiaodu = jiaodu6;
                    en = 1;
                }
                else if (state & 0x80) { //right
                    if(jiaodu6 >= 12)
                        jiaodu6 = jiaodu6 - 4;
                    id = 0x06;
                    two = 0;
                    jiaodu = jiaodu6;
                    en = 1;
                }
                else
                {
                    two = 0;
                    en = 0;
                }
                // 发送数据
                if(en == 1)
                {
                    uint8_t param1 = jiaodu & 0xFF;
	        	    uint8_t param2 = (jiaodu >> 8) & 0xFF;
	        	    uint8_t param3 = 0x01;
	        	    uint8_t param4 = 0x00;
	        	    uint8_t check_sum = ~(id + 0x07 + 0x01 + param1 + param2 + param3 + param4) & 0xFF;
                    // 简单延时，避免过于频繁的按键读取
                    uart_write(UART, 0x55);//帧头
                    uart_write(UART, 0x55);//帧头
                    uart_write(UART, id);//ID号
                    uart_write(UART, 0x07);//数据长度 + 3 = 总长度
                    uart_write(UART, 0x01);//指令id
                    uart_write(UART, param1);//参数1
                    uart_write(UART, param2);//参数2
                    uart_write(UART, param3);//参数3
                    uart_write(UART, param4);//参数4
                    uart_write(UART, check_sum);//校验和

                    if(two == 1)
                    {
                        uint16_t jiaodux = 1000 - jiaodu;
                        uint8_t param1x = jiaodux & 0xFF;
	        	        uint8_t param2x = (jiaodux >> 8) & 0xFF;
                        uint8_t check_sum1 = ~(0x05 + 0x07 + 0x01 + param1x + param2x + param3 + param4) & 0xFF;
                        uart_write(UART, 0x55);//帧头
                        uart_write(UART, 0x55);//帧头
                        uart_write(UART, 0x05);//ID号
                        uart_write(UART, 0x07);//数据长度 + 3 = 总长度
                        uart_write(UART, 0x01);//指令
                        uart_write(UART, param1x);//参数1
                        uart_write(UART, param2x);//参数2
                        uart_write(UART, param3);//参数3
                        uart_write(UART, param4);//参数4
                        uart_write(UART, check_sum1);//校验和
                    }
                }
                JOYPAD_Delay(100000);
            }
        }
        else if(data == 0x01)//跳舞
        {
            camera(1);
            uint16_t jiaodua1 = 500;
            uint32_t x = 0;
            while(data == 0x01)
            {
                data = (GPIO_A_BASE->INPUT) & 0xFF;
                x = x + 1;
                for(uint8_t i = 1; i < 7; i++)
                {                
                    if(x / 5 == 0)
                    {
                        uint16_t jiaodua1 = 800;
                    }
                    else if(x / 5 == 1)
                    {
                        uint16_t jiaodua1 = 300;

                    }
                    else if(x / 5 == 2)
                    {
                        uint16_t jiaodua1 = 200;
                    }
                    else if(x / 5 == 3)
                    {
                        uint16_t jiaodua1 = 400;
                    }
                    else if(x / 5 == 4)
                    {
                        uint16_t jiaodua1 = 600;
                    }
                    else
                    {
                        uint16_t jiaodua1 = 500;
                    }

                    uint8_t param1a = jiaodua1 & 0xFF;
                    uint8_t param2a = (jiaodua1 >> 8) & 0xFF;
                    uint8_t check_suma = ~(i + 0x07 + 0x01 + param1a + param2a + 0x08 + 0x00) & 0xFF;
                    uart_write(UART, 0x55);//帧头
	    	        uart_write(UART, 0x55);//帧头
	    	        uart_write(UART, i);//ID号
	    	        uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	    	        uart_write(UART, 0x01);//指令
	    	        uart_write(UART, param1a);//参数1
	    	        uart_write(UART, param2a);//参数2
	    	        uart_write(UART, 0x08);//参数3
	    	        uart_write(UART, 0x00);//参数4
	    	        uart_write(UART, check_suma);//校验和
                    for (int volatile i = 0; i < 2000000; i++) ;
                }
            }
        }
        else if(data == 0x02)//視覺識別模式
        {
            while(data == 0x02)
            {
                camera(0);
                data = (GPIO_A_BASE->INPUT) & 0xFF;
                
                if(GPIO_Read(BLUE) == 0)
                {
                    // print("BLUE\n");
                    for (int volatile i = 0; i < 10000000; i++) ;
                    if(GPIO_Read(BLUE) == 0)
                    {
                        robot_ready();
                        data = (GPIO_A_BASE->INPUT) & 0xFF;
                        robot_catch();
                        data = (GPIO_A_BASE->INPUT) & 0xFF;
                        robot_up();
                        data = (GPIO_A_BASE->INPUT) & 0xFF;
                        robot_turn_blue();
                        data = (GPIO_A_BASE->INPUT) & 0xFF;
                        robot_release();
                        data = (GPIO_A_BASE->INPUT) & 0xFF;
                        robot_up();
                        data = (GPIO_A_BASE->INPUT) & 0xFF;
                        robot_ready();
                        data = (GPIO_A_BASE->INPUT) & 0xFF;
                    }
                }
                else if(GPIO_Read(RED) == 0)
                {
                    // print("RED\n");
                    for (int volatile i = 0; i < 4000000; i++) ;
                    if(GPIO_Read(RED) == 0)
                    {
                        for (int volatile i = 0; i < 4000000; i++) ;
                        if(GPIO_Read(RED) == 0)
                        {
                            for (int volatile i = 0; i < 4000000; i++) ;
                            if(GPIO_Read(RED) == 0)
                            {
                                robot_ready();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_catch();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_up();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_turn_red();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_release();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_up();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_ready();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                            }
                        }
                    }
                }
                else if(GPIO_Read(GREEN) == 0)
                {
                    // print("GREEN\n");
                    for (int volatile i = 0; i < 4000000; i++) ;
                    if(GPIO_Read(GREEN) == 0)
                    {
                        for (int volatile i = 0; i < 4000000; i++) ;
                        if(GPIO_Read(GREEN) == 0)
                        {
                            for (int volatile i = 0; i < 4000000; i++) ;
                            if(GPIO_Read(GREEN) == 0)
                            {
                                robot_ready();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_catch();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_up();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_turn_green();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_release();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_up();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                                robot_ready();
                                data = (GPIO_A_BASE->INPUT) & 0xFF;
                            }
                        }
                    }
                }
                else
                {
                    camera(1);
                    // print("NO\n");
                    robot_ready();
                    data = (GPIO_A_BASE->INPUT) & 0xFF;
                }
            }
        }
        else
        {
            for(uint8_t i = 1; i < 7; i++)
            {   
                uint8_t check_sum_else = ~(i + 0x07 + 0x01 + 0xF4 + 0x01 + 0xE8 + 0x03) & 0xFF;
                uart_write(UART, 0x55);//帧头
	            uart_write(UART, 0x55);//帧头
	            uart_write(UART, i);//ID号
	            uart_write(UART, 0x07);//数据长度 + 3 = 总长度
	            uart_write(UART, 0x01);//指令
	            uart_write(UART, 0xF4);//参数1
	            uart_write(UART, 0x01);//参数2
	            uart_write(UART, 0xE8);//参数3
	            uart_write(UART, 0x03);//参数4
	            uart_write(UART, check_sum_else);//校验和
            }
        }

    }
    return 0;
}

// IRQ 回调函数
void irqCallback() {
    // 你可以在此处实现 IRQ 处理逻辑
}
