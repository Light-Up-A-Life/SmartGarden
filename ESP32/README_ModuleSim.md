Test module sim 7600 4G HAT
1.  Put sim dont break, put in the top coverpush back afeter forward
2. connect to computer usb
3. press power button 
4. Open arduino serial monitor to send command 
4.1 set serial to "both NL & CR" and baudrate to 115200
5. Send several AT commands
5.1 if the sim has a pin enter with AT+CPIN="****" --> the NET Led on the board should blink 

SEnd message
AT
OK
AT+CMGF=1
OK
AT+CMGS="+33770451126",
> CARE VERGAS

Press Ctrl+z using putty 
+CMGW: 1

OK
AT+CMSS=1
+CMSS: 20

OK


More info in https://www.waveshare.com/wiki/SIM7600G-H_4G_HAT
