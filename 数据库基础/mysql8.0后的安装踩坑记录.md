# 记录

1. 使用命令安装过后,按照弹出的语句提示进行操作,在文件目录中创建数据库

2. 鉴于mysql8.0或是mariadb采用的"功能",使用系统超级用户登录
   
   ```bash
   sudo mysql
   ```

3. 创建新的用户,使用密码登录并授予权限(他们说新的这种安全那就安全吧,坑B)
   
   1. 使用`sudo`登录
   
   2. 输入以下语句如果需要账户可以远程登录的话既要设置`'%'`,也要设置`localhost`,因为有的会创建`''@'localhost'`账户,会使新创建的用户无法登录(鬼知道啥原理)
   
   ```sql
   CREATE USER 'admin'@'%' IDENTIFIED BY 'password';
   CREATE USER 'admin'@'localhost' IDENTIFIED BY 'password';
   GRANT ALL ON *.* TO 'admin'@'%';
   GRANT ALL ON *.* TO 'admin'@'localhost';
   flush privileges;
   ```

4. 重启服务
