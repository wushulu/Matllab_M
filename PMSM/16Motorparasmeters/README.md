# 16motor_parasmeters

## 简介
待补充

## 详细说明
### 需要注意点

- 初始化脚本设置
  -   根据实际电路设置
      -   Rds_on = 0.85;%0.73;
      -   Rshunt = 0.33;
      -    inverter.V_max = 3.3/(9.31/(9.31+169));% (9.31/(9.31+169)) --> Voltage divider gain
      -    inverter.I_max = 3.2679;
      -    串口波特率设置为2M set_param([hostModelName '/Host Serial Setup'],'BaudRate', '2e6');

-  Host 设置
   -  单独运行脚本会出问题需要打开'mcb_stm32_param_est_host_read.slx'运行 脚本变量会出现在工作区
   -  Host进入实际收发数据模块将串口设置为实际使用串口
   -  输入电压要设置成实际电压
- 硬件设置按照这个表格连接 (不要看硬件图片)
  - ![alt text](jumper-connection.png)
  
- 从机设置将G474改成G431并修改对应的模型文件注意是ADC采样部分
- 'nucleo_g431re_ihm07m1.slx' 修改名称后需要重新reload ioc文件
- ctrl+B 部署到MCU即可
<!-- 请在此处补充具体说明 -->
