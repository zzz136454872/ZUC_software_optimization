zuc.c

https://www.gsma.com/aboutus/wp-content/uploads/2014/12/eea3eia3zucv16.pdf
https://www.gsma.com/aboutus/wp-content/uploads/2014/12/EEA3_EIA3_specification_v1_7.pdf

基准测试
测试数据：
(4*32)*(20*1024*1024)

我把generatekeystream中的第一轮放到initialisation中了。

时间 3.49s。

查表实现L
使用8个256个int的表格
时间3.61s
