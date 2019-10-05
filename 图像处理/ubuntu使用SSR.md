# ubuntu使用SSR

## **安装git**

ubuntu

```bash
sudo apt-get install git 
```

## 克隆项目代码到本地

```bash
git clone http://git.mrwang.pw/Reed/Linux_ssr_script.git
```

进入仓库到本地并赋予ssr可执行权限

```bash
sudo mv ./ssr /usr/local/sbin/
```

放入可执行脚本目录

## 使用

1. 输入ssr

2. 首先执行

   ```bash
   ssr install
   ```

3. 执行ssr config，在其中输入节点连接信息

## 启动

ssr start ssr stop

## **使用全局代理或者PAC代理**

### 全局代理模式

1. 安装privoxy

2. 全局代理模式

   ```bash
   # 添加本地ssr服务到配置文件
   echo 'forward-socks5 / 127.0.0.1:1080 .' >> /etc/privoxy/config
   
   # Privoxy 默认监听端口是是8118
   export http_proxy=http://127.0.0.1:8118
   export https_proxy=http://127.0.0.1:8118
   export no_proxy=localhost
   
   # 启动服务
   systemctl start privoxy.service
   ```

### PAC模式

1. 在最开始git clone的目录下可以找到该脚本
	
	```bash
	[root@localhost ~]# cd gfwlist2privoxy/
	[root@localhost gfwlist2privoxy]# ls
	gfw.action  gfwlist2privoxy  README.md  ssr
	[root@localhost gfwlist2privoxy]# bash gfwlist2privoxy
	proxy(socks5): 127.0.0.1:1080		# 注意，如果你修改了ssr本地监听端口是需要设置对应的
	{+forward-override{forward-socks5 127.0.0.1:1080 .}}
	
	=================================================================
	
	"cp -af /root/gfwlist2privoxy/gfw.action /etc/privoxy/"
	
	[root@localhost ~]# cp -af gfw.action /etc/privoxy/
	[root@localhost ~]# echo 'actionsfile gfw.action' >> /etc/privoxy/config
	
	# Privoxy 默认监听端口是是8118
	export http_proxy=http://127.0.0.1:8118
	export https_proxy=http://127.0.0.1:8118
	export no_proxy=localhost
	
	# 启动服务
	systemctl start privoxy.service
	```
	
### 自动控制脚本

~~~bash
```bash
#!/bin/bash
# Author Samzong.lu

case $1 in
	start)
		ssr start &> /var/log/ssr-local.log
		systemctl start privoxy.service
		export http_proxy=http://127.0.0.1:8118
		export https_proxy=http://127.0.0.1:8118
		export no_proxy="localhost, ip.cn, chinaz.com"
		;;
	stop)
		unset http_proxy https_proxy no_proxy
		systemctl stop privoxy.service
		ssr stop &> /var/log/ssr-log.log
		;;
	autostart)
		echo "ssr start" >> /etc/rc.local
		systemctl enable privoxy.service
		echo "http_proxy=http://127.0.0.1:8118" >> /etc/bashrc
		echo "https_proxy=http://127.0.0.1:8118" >> /etc/bashrc
		echo "no_proxy='localhost, ip.cn, chinaz.com'" >> /etc/bashrc
		;;
	*)
		echo "usage: source $0 start|stop|autostart"
		exit 1
		;;
esac
```
~~~


​	

