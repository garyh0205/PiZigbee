# PiZigbee

##==================================================================<br /><br />The Development of this repository move to OpenISDM/Lbeacon-zigbee<br /><br />https://github.com/OpenISDM/Lbeacon-zigbee<br /><br />===================================================================


## Zigbee on Respberry Pi

> The library we use fork from Attie's repository "libxbee3". 

> The Original repository is https://github.com/attie/libxbee3
> This repository is for the use of Zigbee module(xbee S2) on Respberry pi.<br />The following is the manual of Zigbee(xbee Series 2):
https://www.digi.com/resources/documentation/digidocs/PDFs/90000976.pdf


### === Licensing of libxbee ===
libxbee v3 is licensed using LGPLv3 from v3.0.5 onwards.<br />


### === Environment ===
The OS on the Respberry pi is RASPBIAN STRETCH LITE 2017-11-29 version.<br />
The official website of Raspberry Pi is https://www.raspberrypi.org<br />
The download link of RASPBIAN STRETCH LITE(2017-11-29 version) is <br />http://vx2-downloads.raspberrypi.org/raspbian_lite/images/raspbian_lite-2017-12-01/2017-11-29-raspbian-stretch-lite.zip


### === Building libxbee library ===
If you are building libxbee, then there are a number of options avaliable to you.<br />
Initially you should run the following command:
<pre><code>$ make configure</code></pre>
	
This will retrieve a default `config.mk` that is suitable for your Respberry Pi.<br />You
should review this file and then run the following command:
<pre><code>$ make all</code></pre>

	
After the build process has completed, you should find suitable files in **./lib**.<br />
E.g: for a Unix-like OS you can expect to find **.so** and **.a** files<br />
        for Windows you can expect to find a **.dll** file<br /><br />

It is highly recommended that you don't modify any of the build system.


### === Installation of libxbee library ===
To install libxbee simply type (you will require **root permissions**):
<pre><code>$ sudo make install</code></pre>


### === Usage ===
Compile your applications, including **xbee.h** in the relevant source files.<br />
Ensure you link with libxbee (e.g: using `gcc -lxbee`)

If you are compiling the object file directly into your executable instead
of making use of the library, you must include the following link flags.<br />These
flags are also necessary for newer versions of Ubuntu, and possibly others.
<pre><code>-lpthread -lrt</code></pre>


### === Samples ===
Todo
