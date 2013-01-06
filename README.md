daktronics
==========

A python-based and AVR serial data decoder for the Daktronics omnisport 2000 timing console.

The console has an RTD port used normally for Venus scoreboards. It is a simple 19200 baud 8N1 serial signal, and carries the running time, splits, and swimmer names.

Decoded data is fed into Autobahn with python and then to the browser for graphic rendering. The websockets server and rendering engine is in the [IASAS_swimming_2013 repository](https://github.com/xyk2/IASAS_swimming_2013).

Data
-----------
There are two types of data packets: running time and splits. Each packet is composed of a prefix (`t` for running time and `s` for splits), the packet data, and a carriage return, which serves as the delimiting character. 

Typical data packets would look like this:
`t1:02.1` - pretty self explanatory
`s3 1 1:11.63 2` - four data points, which are ordered as follows:

* Lane number
* Place
* Time (split times are accurate to a hundredth of a second)
* Laps of the pool completed


Test Mode
----------
The decoder can be put into test mode by resetting with the split button set to the OFF position. This mode ignores data from the console and simulates a test race, which is useful for testing the rendering engine. 
Schematic of the hardware-based decoder:

<!-- <img src='https://raw.github.com/xyk2/daktronics/master/img/back_panel.png'/>
<img src='https://raw.github.com/xyk2/daktronics/master/img/decoder_schematic.png'/>
<img src='https://raw.github.com/xyk2/daktronics/master/img/graphic_sample.png'/> -->
<img src='https://raw.github.com/xyk2/daktronics/master/img/readme.png'/>



License
-
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0;" src="https://raw.github.com/xyk2/daktronics/master/img/cc_a_nc_sa.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/3.0/deed.en_US">Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License</a>.
