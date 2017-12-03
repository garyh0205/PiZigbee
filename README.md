# PiZigbee
Zigbee on Respberry Pi

The library we use fork from attie's repository "libxbee3". 
The Original repository is https://github.com/attie/libxbee3


This repository is for the use of Zigbee module(xbee S2) on Respberry pi. The following is the manual of Zigbee(xbee Series 2):
https://www.digi.com/resources/documentation/digidocs/PDFs/90000976.pdf


=== Licensing of libxbee ===
libxbee v3 is licensed using LGPLv3 from v3.0.5 onwards. For more
information on what this means for you, please see COPYING and COPYING.LESSER.


=== Environment ===
The OS on the Respberry pi is RASPBIAN STRETCH LITE 2017-11-29 version.
The official website of Raspberry Pi is https://www.raspberrypi.org
The download link of RASPBIAN STRETCH LITE(2017-11-29 version) is http://vx2-downloads.raspberrypi.org/raspbian_lite/images/raspbian_lite-2017-12-01/2017-11-29-raspbian-stretch-lite.zip


=== Building libxbee library ===
If you are building libxbee, then there are a number of options avaliable to you.
Initially you should run the following command:
	$ make configure
	
This will retrieve a default 'config.mk' that is suitable for your Respberry pi. You
should review this file and then run the following command:
	$ make all

	
After the build process has completed, you should find suitable files in ./lib.
E.g: for a Unix-like OS you can expect to find .so and .a files
     for Windows you can expect to find a .dll file

It is highly recommended that you don't modify any of the build system.


=== Installation of libxbee library ===
To install libxbee simply type (you will require root permissions):
  $ sudo make install


=== Usage ===
Compile your applications, including "xbee.h" in the relevant source files.
Ensure you link with libxbee (e.g: using 'gcc -lxbee')

If you are compiling the object file directly into your executable instead
of making use of the library, you must include the following link flags. These
flags are also necessary for newer versions of Ubuntu, and possibly others.
  -lpthread -lrt


=== Samples ===
Todo