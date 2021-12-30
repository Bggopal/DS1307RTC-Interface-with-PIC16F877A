# DS1307RTC-Interface-with-PIC16F877A
This page shows, interface of DS1307 RTC with PIC16F877A microcontroller and display time, date and day on a 16x2 LCD
## DS1307
Real Time Clock or RTC is a system that keeps track of the current time and can be used in any device which needs to keep accurate time. DS1307 module is one of the most affordable and common RTCs modules. It can accurately keep track of seconds, minutes, hours, days, months, and years. **DS1307 RTC communicates with the microcontroller using I2C protocol**. 

<p align="center">
    <img src="https://user-images.githubusercontent.com/59637425/147726669-ca5cdbd6-3691-4b30-9bd2-b18326e8de15.png" width="500" height="200">
</p>

**DATASHEET for DS1307** [ Here ](https://datasheets.maximintegrated.com/en/ds/DS1307.pdf)

## I2C Communication in PIC16F877A

I2C is a multi-master, multi-slave (half-duplex) communication protocol. On an I2C bus, one can have more than 1 Master and multiple slaves. It communicates over two lines and can handle data speeds of several kHz. SDA and SCL, or Serial data and Serial clock, are the two pins for I2C communication in most microcontrollers. The SDA line transmits and receives data, whereas the SCL line generates clock pulses for required communication. 

**PIC16f887A provides an MSSP(Master synchronous Serial port) module which can be configured to work either as SPI or an I2C.** In all, there are 6 registers associated with the MSSP module including 2 control registers and 1 status register. These registers have individual bits for SPI as well as I2C, with certain bits having functions for both. Typical I2C ciruit connection in PIC16F877A

<p align="center">
    <img src="https://user-images.githubusercontent.com/59637425/147727388-a724eff2-489c-49ca-bc91-deafc4fe093f.png" width="240" height="160">
</p>

More details on PIC I2C regeisters Can be found [HERE](https://techetrx.com/pic-microcontroller/i2c-communication-pic-microcontroller/) and in [DATE SHEET](https://ww1.microchip.com/downloads/en/devicedoc/39582b.pdf) page num 74

## Circuit Diagram to Interface DS1307 with PIC16F877A

<p align="center">
    <img src="https://user-images.githubusercontent.com/59637425/147726947-9b2a804a-dcda-44f3-8735-aa8ee0c0b15c.png" width="720" height="480">
</p>

<p align="center">
    <img src="https://user-images.githubusercontent.com/59637425/147727065-e65fb815-7e3a-4cdf-8714-4ee5d3b947dd.png" width="720" height="480">
</p>

## DOWNLOADS

<p align="center">
  <b>DOWNLOAD THE PROJECT FOLDER and SIMULATION FILES</b><br>
  <a href="https://github.com/Bggopal/DS1307RTC-Interface-with-PIC16F877A/archive/refs/heads/main.zip">HERE</a> 
  <br><br>
</p>
