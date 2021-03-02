<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="101" name="Hidden" color="15" fill="1" visible="yes" active="yes"/>
<layer number="102" name="Changes" color="12" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="diy-modules">
<description>&lt;b&gt;DIY Modules for Arduino, Raspberry Pi, CubieBoard etc.&lt;/b&gt;
&lt;br&gt;&lt;br&gt;
The library contains a list of symbols and footprints for popular, cheap and easy-to-use electronic modules.&lt;br&gt;
The modules are intend to work with microprocessor-based platforms such as &lt;a href="http://arduino.cc"&gt;Arduino&lt;/a&gt;, &lt;a href="http://raspberrypi.org/"&gt;Raspberry Pi&lt;/a&gt;, &lt;a href="http://cubieboard.org/"&gt;CubieBoard&lt;/a&gt;, &lt;a href="http://beagleboard.org/"&gt;BeagleBone&lt;/a&gt; and many others. There are many manufacturers of the modules in the world. Almost all of them can be bought on &lt;a href="ebay.com"&gt;ebay.com&lt;/a&gt;.&lt;br&gt;
&lt;br&gt;
By using this library, you can design a PCB for devices created with usage of modules. Even if you do not need to create PCB design, you can also use the library to quickly document your work by drawing schematics of devices built by you.&lt;br&gt;
&lt;br&gt;
The latest version, examples, photos and much more can be found at: &lt;b&gt;&lt;a href="http://diymodules.org/eagle"&gt;diymodules.org/eagle&lt;/a&gt;&lt;/b&gt;&lt;br&gt;&lt;br&gt;
Comments, suggestions and bug reports please send to: &lt;b&gt;&lt;a href="mailto:eagle@diymodules.org"&gt;eagle@diymodules.org&lt;/b&gt;&lt;/a&gt;&lt;br&gt;&lt;br&gt;
&lt;i&gt;Version: 1.8.0 (2017-Jul-02)&lt;/i&gt;&lt;br&gt;
&lt;i&gt;Created by: Miroslaw Brudnowski&lt;/i&gt;&lt;br&gt;&lt;br&gt;
&lt;i&gt;Released under the Creative Commons Attribution 4.0 International License: &lt;a href="http://creativecommons.org/licenses/by/4.0"&gt;http://creativecommons.org/licenses/by/4.0&lt;/a&gt;&lt;/i&gt;
&lt;br&gt;&lt;br&gt;
&lt;center&gt;
&lt;a href="http://diymodules.org/eagle"&gt;&lt;img src="http://www.diymodules.org/img/diymodules-lbr-image.php?v=1.8.0" alt="DIYmodules.org"&gt;&lt;/a&gt;
&lt;/center&gt;</description>
<packages>
<package name="DC-DC-STEP-DOWN-MP1584">
<description>&lt;b&gt;DC/DC Step-Down Regulator&lt;/b&gt; based on &lt;b&gt;MP1584&lt;/b&gt; chip</description>
<wire x1="-11.049" y1="8.382" x2="11.049" y2="8.382" width="0.127" layer="21"/>
<wire x1="11.049" y1="8.382" x2="11.049" y2="-8.382" width="0.127" layer="21"/>
<wire x1="11.049" y1="-8.382" x2="-11.049" y2="-8.382" width="0.127" layer="21"/>
<wire x1="-11.049" y1="-8.382" x2="-11.049" y2="8.382" width="0.127" layer="21"/>
<pad name="IN-.1" x="-9.271" y="6.604" drill="1.2" diameter="2"/>
<text x="0" y="9.525" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-9.525" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
<text x="-9.271" y="0" size="1.524" layer="21" rot="R90" align="center">IN</text>
<text x="9.271" y="0" size="1.524" layer="21" rot="R90" align="center">OUT</text>
<wire x1="-6.985" y1="-5.969" x2="-6.985" y2="-4.699" width="0.254" layer="21"/>
<wire x1="-6.35" y1="5.334" x2="-7.62" y2="5.334" width="0.254" layer="21"/>
<wire x1="-7.62" y1="-5.334" x2="-6.35" y2="-5.334" width="0.254" layer="21"/>
<pad name="IN+.2" x="-9.271" y="-6.604" drill="1.2" diameter="2" shape="square"/>
<pad name="OUT-.1" x="9.271" y="6.604" drill="1.2" diameter="2"/>
<pad name="IN-.2" x="-9.271" y="4.064" drill="1.2" diameter="2"/>
<pad name="OUT-.2" x="9.271" y="4.064" drill="1.2" diameter="2"/>
<pad name="IN+.1" x="-9.271" y="-4.064" drill="1.2" diameter="2" shape="square"/>
<pad name="OUT+.2" x="9.271" y="-6.604" drill="1.2" diameter="2" shape="square"/>
<pad name="OUT+.1" x="9.271" y="-4.064" drill="1.2" diameter="2" shape="square"/>
<wire x1="6.985" y1="-5.969" x2="6.985" y2="-4.699" width="0.254" layer="21"/>
<wire x1="7.62" y1="5.334" x2="6.35" y2="5.334" width="0.254" layer="21"/>
<wire x1="6.35" y1="-5.334" x2="7.62" y2="-5.334" width="0.254" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="DC-DC-STEP-DOWN-MP1584">
<description>&lt;b&gt;DC/DC Step-Down Regulator&lt;/b&gt; based on &lt;b&gt;MP1584&lt;/b&gt; chip</description>
<pin name="IN+.2" x="-17.78" y="-5.08" visible="pin" length="middle"/>
<pin name="IN-.1" x="-17.78" y="5.08" visible="pin" length="middle"/>
<pin name="OUT+.2" x="17.78" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="OUT-.1" x="17.78" y="5.08" visible="pin" length="middle" rot="R180"/>
<wire x1="-12.7" y1="10.16" x2="12.7" y2="10.16" width="0.254" layer="94"/>
<wire x1="12.7" y1="10.16" x2="12.7" y2="-10.16" width="0.254" layer="94"/>
<wire x1="12.7" y1="-10.16" x2="-12.7" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-10.16" x2="-12.7" y2="10.16" width="0.254" layer="94"/>
<text x="-12.7" y="15.24" size="1.778" layer="95">&gt;NAME</text>
<text x="-12.7" y="12.7" size="1.778" layer="96">&gt;VALUE</text>
<pin name="IN-.2" x="-17.78" y="2.54" visible="pin" length="middle"/>
<pin name="IN+.1" x="-17.78" y="-2.54" visible="pin" length="middle"/>
<pin name="OUT-.2" x="17.78" y="2.54" visible="pin" length="middle" rot="R180"/>
<pin name="OUT+.1" x="17.78" y="-2.54" visible="pin" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="DC-DC-STEP-DOWN-MP1584">
<description>&lt;b&gt;DC/DC Step-Down Regulator&lt;/b&gt; based on &lt;b&gt;MP1584&lt;/b&gt; chip
&lt;p&gt;&lt;b&gt;MP1584&lt;/b&gt; datasheet available here:&lt;br /&gt;
&lt;a href="http://www.haoyuelectronics.com/Attachment/MP1584/MP1584.pdf"&gt;http://www.haoyuelectronics.com/Attachment/MP1584/MP1584.pdf&lt;/a&gt;&lt;/p&gt;
&lt;p&gt;&lt;b&gt;&lt;a href="http://www.ebay.com/sch/mp1584+module"&gt;Click here to find device on ebay.com&lt;/a&gt;&lt;/b&gt;&lt;/p&gt;
&lt;p&gt;&lt;img alt="photo" src="http://www.diymodules.org/img/device-photo.php?name=DC-DC-STEP-DOWN-MP1584"&gt;&lt;/p&gt;</description>
<gates>
<gate name="G$1" symbol="DC-DC-STEP-DOWN-MP1584" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DC-DC-STEP-DOWN-MP1584">
<connects>
<connect gate="G$1" pin="IN+.1" pad="IN+.1"/>
<connect gate="G$1" pin="IN+.2" pad="IN+.2"/>
<connect gate="G$1" pin="IN-.1" pad="IN-.1"/>
<connect gate="G$1" pin="IN-.2" pad="IN-.2"/>
<connect gate="G$1" pin="OUT+.1" pad="OUT+.1"/>
<connect gate="G$1" pin="OUT+.2" pad="OUT+.2"/>
<connect gate="G$1" pin="OUT-.1" pad="OUT-.1"/>
<connect gate="G$1" pin="OUT-.2" pad="OUT-.2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="ESP32">
<packages>
<package name="ESP32-36-GPIO">
<pad name="1" x="-22.87" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="2" x="-20.33" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="3" x="-17.79" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="4" x="-15.25" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="5" x="-12.71" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="6" x="-10.17" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="7" x="-7.63" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="8" x="-5.09" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="9" x="-2.55" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="10" x="-0.01" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="11" x="2.53" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="12" x="5.07" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="13" x="7.61" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="14" x="10.15" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="15" x="12.69" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="16" x="15.23" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="17" x="17.77" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="18" x="20.31" y="-11.42" drill="1" diameter="1.9304"/>
<pad name="36" x="-22.87" y="11.23" drill="1" diameter="1.9304"/>
<pad name="35" x="-20.33" y="11.23" drill="1" diameter="1.9304"/>
<pad name="34" x="-17.79" y="11.23" drill="1" diameter="1.9304"/>
<pad name="33" x="-15.25" y="11.23" drill="1" diameter="1.9304"/>
<pad name="32" x="-12.71" y="11.23" drill="1" diameter="1.9304"/>
<pad name="31" x="-10.17" y="11.23" drill="1" diameter="1.9304"/>
<pad name="30" x="-7.63" y="11.23" drill="1" diameter="1.9304"/>
<pad name="29" x="-5.09" y="11.23" drill="1" diameter="1.9304"/>
<pad name="28" x="-2.55" y="11.23" drill="1" diameter="1.9304"/>
<pad name="27" x="-0.01" y="11.23" drill="1" diameter="1.9304"/>
<pad name="26" x="2.53" y="11.23" drill="1" diameter="1.9304"/>
<pad name="25" x="5.07" y="11.23" drill="1" diameter="1.9304"/>
<pad name="24" x="7.61" y="11.23" drill="1" diameter="1.9304"/>
<pad name="23" x="10.15" y="11.23" drill="1" diameter="1.9304"/>
<pad name="22" x="12.69" y="11.23" drill="1" diameter="1.9304"/>
<pad name="21" x="15.23" y="11.23" drill="1" diameter="1.9304"/>
<pad name="20" x="17.77" y="11.23" drill="1" diameter="1.9304"/>
<pad name="19" x="20.31" y="11.23" drill="1" diameter="1.9304"/>
<wire x1="-22.85" y1="5.86" x2="-22.85" y2="2.02" width="0.4064" layer="21"/>
<wire x1="-22.85" y1="2.02" x2="-17.73" y2="2.02" width="0.4064" layer="21"/>
<wire x1="-17.73" y1="2.02" x2="-17.73" y2="0.74" width="0.4064" layer="21"/>
<wire x1="-17.73" y1="0.74" x2="-22.85" y2="0.74" width="0.4064" layer="21"/>
<wire x1="-22.85" y1="0.74" x2="-22.85" y2="-0.54" width="0.4064" layer="21"/>
<wire x1="-22.85" y1="-0.54" x2="-17.73" y2="-0.54" width="0.4064" layer="21"/>
<wire x1="-17.73" y1="-0.54" x2="-17.73" y2="-1.82" width="0.4064" layer="21"/>
<wire x1="-17.73" y1="-1.82" x2="-22.85" y2="-1.82" width="0.4064" layer="21"/>
<wire x1="-22.85" y1="-1.82" x2="-22.85" y2="-3.1" width="0.4064" layer="21"/>
<wire x1="-22.85" y1="-3.1" x2="-17.73" y2="-3.1" width="0.4064" layer="21"/>
<wire x1="-17.73" y1="-3.1" x2="-17.73" y2="-4.38" width="0.4064" layer="21"/>
<wire x1="-17.73" y1="-4.38" x2="-22.85" y2="-4.38" width="0.4064" layer="21"/>
<wire x1="-22.85" y1="-4.38" x2="-22.85" y2="-5.66" width="0.4064" layer="21"/>
<wire x1="-22.85" y1="-5.66" x2="-15.17" y2="-5.66" width="0.4064" layer="21"/>
<wire x1="-15.17" y1="-5.66" x2="-15.17" y2="0.74" width="0.4064" layer="21"/>
<text x="18.45" y="-9.99" size="1.016" layer="21" rot="R90">GND</text>
<text x="-8.74" y="-1.18" size="1.9304" layer="21">ESP32-36IO</text>
<wire x1="-24.13" y1="12.7" x2="21.59" y2="12.7" width="0.254" layer="21"/>
<wire x1="21.59" y1="12.7" x2="21.59" y2="-12.7" width="0.254" layer="21"/>
<wire x1="21.59" y1="-12.7" x2="-24.13" y2="-12.7" width="0.254" layer="21"/>
<wire x1="-24.13" y1="-12.7" x2="-24.13" y2="12.7" width="0.254" layer="21"/>
<text x="20.99" y="-9.99" size="1.016" layer="21" rot="R90">VIN+</text>
</package>
</packages>
<symbols>
<symbol name="ESP32-36-GPIO">
<wire x1="-25.4" y1="-12.7" x2="-25.4" y2="12.7" width="0.254" layer="94"/>
<wire x1="-25.4" y1="12.7" x2="22.86" y2="12.7" width="0.254" layer="94"/>
<wire x1="22.86" y1="12.7" x2="22.86" y2="-12.7" width="0.254" layer="94"/>
<wire x1="22.86" y1="-12.7" x2="-25.4" y2="-12.7" width="0.254" layer="94"/>
<pin name="EN" x="-22.86" y="-17.78" length="middle" rot="R90"/>
<pin name="IO36" x="-20.32" y="-17.78" length="middle" rot="R90"/>
<pin name="IO39" x="-17.78" y="-17.78" length="middle" rot="R90"/>
<pin name="IO34" x="-15.24" y="-17.78" length="middle" rot="R90"/>
<pin name="IO35" x="-12.7" y="-17.78" length="middle" rot="R90"/>
<pin name="IO32" x="-10.16" y="-17.78" length="middle" rot="R90"/>
<pin name="IO33" x="-7.62" y="-17.78" length="middle" rot="R90"/>
<pin name="IO25" x="-5.08" y="-17.78" length="middle" rot="R90"/>
<pin name="IO26" x="-2.54" y="-17.78" length="middle" rot="R90"/>
<pin name="IO27" x="0" y="-17.78" length="middle" rot="R90"/>
<pin name="IO14" x="2.54" y="-17.78" length="middle" rot="R90"/>
<pin name="IO12" x="5.08" y="-17.78" length="middle" rot="R90"/>
<pin name="IO13" x="7.62" y="-17.78" length="middle" rot="R90"/>
<pin name="IO9" x="10.16" y="-17.78" length="middle" rot="R90"/>
<pin name="IO10" x="12.7" y="-17.78" length="middle" rot="R90"/>
<pin name="IO11" x="15.24" y="-17.78" length="middle" rot="R90"/>
<pin name="GND" x="17.78" y="-17.78" length="middle" rot="R90"/>
<pin name="VIN" x="20.32" y="-17.78" length="middle" rot="R90"/>
<pin name="3V3" x="20.32" y="17.78" length="middle" rot="R270"/>
<pin name="IO6" x="17.78" y="17.78" length="middle" rot="R270"/>
<pin name="IO7" x="15.24" y="17.78" length="middle" rot="R270"/>
<pin name="IO8" x="12.7" y="17.78" length="middle" rot="R270"/>
<pin name="IO0" x="10.16" y="17.78" length="middle" rot="R270"/>
<pin name="IO15" x="7.62" y="17.78" length="middle" rot="R270"/>
<pin name="IO2" x="5.08" y="17.78" length="middle" rot="R270"/>
<pin name="IO4" x="2.54" y="17.78" length="middle" rot="R270"/>
<pin name="IO16" x="0" y="17.78" length="middle" rot="R270"/>
<pin name="IO17" x="-2.54" y="17.78" length="middle" rot="R270"/>
<pin name="IO5" x="-5.08" y="17.78" length="middle" rot="R270"/>
<pin name="IO18" x="-7.62" y="17.78" length="middle" rot="R270"/>
<pin name="IO19" x="-10.16" y="17.78" length="middle" rot="R270"/>
<pin name="IO21" x="-12.7" y="17.78" length="middle" rot="R270"/>
<pin name="IO3" x="-15.24" y="17.78" length="middle" rot="R270"/>
<pin name="IO1" x="-17.78" y="17.78" length="middle" rot="R270"/>
<pin name="IO22" x="-20.32" y="17.78" length="middle" rot="R270"/>
<pin name="IO23" x="-22.86" y="17.78" length="middle" rot="R270"/>
<text x="-26.67" y="5.08" size="1.27" layer="95" rot="R90">&gt;NAME</text>
<text x="25.4" y="-12.7" size="1.27" layer="95" rot="R90">ESP32-36IO</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ESP32-36IO">
<gates>
<gate name="G$1" symbol="ESP32-36-GPIO" x="-5.08" y="5.08"/>
</gates>
<devices>
<device name="" package="ESP32-36-GPIO">
<connects>
<connect gate="G$1" pin="3V3" pad="19"/>
<connect gate="G$1" pin="EN" pad="1"/>
<connect gate="G$1" pin="GND" pad="17"/>
<connect gate="G$1" pin="IO0" pad="23"/>
<connect gate="G$1" pin="IO1" pad="34"/>
<connect gate="G$1" pin="IO10" pad="15"/>
<connect gate="G$1" pin="IO11" pad="16"/>
<connect gate="G$1" pin="IO12" pad="12"/>
<connect gate="G$1" pin="IO13" pad="13"/>
<connect gate="G$1" pin="IO14" pad="11"/>
<connect gate="G$1" pin="IO15" pad="24"/>
<connect gate="G$1" pin="IO16" pad="27"/>
<connect gate="G$1" pin="IO17" pad="28"/>
<connect gate="G$1" pin="IO18" pad="30"/>
<connect gate="G$1" pin="IO19" pad="31"/>
<connect gate="G$1" pin="IO2" pad="25"/>
<connect gate="G$1" pin="IO21" pad="32"/>
<connect gate="G$1" pin="IO22" pad="35"/>
<connect gate="G$1" pin="IO23" pad="36"/>
<connect gate="G$1" pin="IO25" pad="8"/>
<connect gate="G$1" pin="IO26" pad="9"/>
<connect gate="G$1" pin="IO27" pad="10"/>
<connect gate="G$1" pin="IO3" pad="33"/>
<connect gate="G$1" pin="IO32" pad="6"/>
<connect gate="G$1" pin="IO33" pad="7"/>
<connect gate="G$1" pin="IO34" pad="4"/>
<connect gate="G$1" pin="IO35" pad="5"/>
<connect gate="G$1" pin="IO36" pad="2"/>
<connect gate="G$1" pin="IO39" pad="3"/>
<connect gate="G$1" pin="IO4" pad="26"/>
<connect gate="G$1" pin="IO5" pad="29"/>
<connect gate="G$1" pin="IO6" pad="20"/>
<connect gate="G$1" pin="IO7" pad="21"/>
<connect gate="G$1" pin="IO8" pad="22"/>
<connect gate="G$1" pin="IO9" pad="14"/>
<connect gate="G$1" pin="VIN" pad="18"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-amp-quick" urn="urn:adsk.eagle:library:125">
<description>&lt;b&gt;AMP Connectors, Type QUICK&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="03P" urn="urn:adsk.eagle:footprint:5912/1" library_version="2">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<wire x1="-1.651" y1="1.778" x2="-1.524" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="1.651" x2="-1.27" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.397" x2="-1.016" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="1.651" x2="-0.889" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="-2.159" x2="-1.524" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="-2.286" x2="-3.556" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="-2.159" x2="-1.524" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="-2.159" x2="-1.016" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="2.54" x2="-3.556" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="1.778" x2="-3.556" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="-1.778" x2="-3.556" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="-1.778" x2="-3.175" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.778" x2="-1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.778" x2="-3.175" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.27" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.524" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="-0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.524" x2="-1.524" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="-1.524" x2="-1.016" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="-1.524" x2="-0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.524" x2="-3.556" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.524" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="-1.524" x2="-3.556" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="2.54" x2="-2.794" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="2.54" x2="-2.794" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.54" x2="-2.286" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.667" x2="-2.794" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="2.54" x2="-0.254" y2="2.667" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.54" x2="0.254" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.413" x2="-1.016" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="2.413" x2="-1.524" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.397" x2="1.524" y2="1.651" width="0.1524" layer="21"/>
<wire x1="1.524" y1="1.651" x2="1.651" y2="1.778" width="0.1524" layer="21"/>
<wire x1="1.524" y1="-2.159" x2="1.016" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="1.524" y1="-2.159" x2="1.524" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="3.556" y1="-2.286" x2="1.524" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="1.651" y1="1.778" x2="3.556" y2="1.778" width="0.1524" layer="21"/>
<wire x1="3.556" y1="1.778" x2="3.556" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.556" y1="-1.778" x2="3.556" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="3.556" y1="-1.778" x2="3.175" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="3.556" y1="1.778" x2="3.556" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.778" x2="3.175" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.27" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.778" x2="0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.524" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.778" x2="1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.524" x2="1.016" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.016" y1="-1.524" x2="1.524" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.524" y1="-1.524" x2="1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.524" x2="3.556" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.524" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.556" y1="-1.524" x2="3.556" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="2.286" y1="2.54" x2="2.286" y2="2.667" width="0.1524" layer="21"/>
<wire x1="2.794" y1="2.54" x2="3.556" y2="2.54" width="0.1524" layer="21"/>
<wire x1="2.794" y1="2.54" x2="2.794" y2="2.667" width="0.1524" layer="21"/>
<wire x1="2.794" y1="2.667" x2="2.286" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.413" x2="1.524" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.54" x2="2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.413" x2="1.016" y2="2.413" width="0.1524" layer="21"/>
<wire x1="1.016" y1="2.413" x2="1.016" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.889" y1="1.778" x2="1.016" y2="1.651" width="0.1524" layer="21"/>
<wire x1="1.016" y1="1.651" x2="1.27" y2="1.397" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.54" x2="1.016" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.667" x2="-0.254" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.54" x2="-0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="2.413" x2="-1.016" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="2.54" x2="-2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.651" y1="1.778" x2="-3.556" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-0.889" y1="1.778" x2="0.889" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="1.651" x2="-1.016" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="1.651" x2="-1.524" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.016" y1="1.651" x2="1.016" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.524" y1="1.651" x2="1.524" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.27" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="-1.905" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="-2.286" x2="1.016" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.778" x2="1.905" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="1.016" y1="-2.159" x2="1.016" y2="-2.286" width="0.1524" layer="21"/>
<pad name="1" x="-2.54" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="2" x="0" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="3" x="2.54" y="0" drill="0.9144" shape="long" rot="R90"/>
<text x="-2.032" y="0.9398" size="0.9906" layer="21" ratio="12" rot="R90">1</text>
<text x="-3.556" y="2.9464" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.556" y="-3.8354" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-2.8702" y1="-0.3302" x2="-2.2098" y2="0.3302" layer="51"/>
<rectangle x1="-0.3302" y1="-0.3302" x2="0.3302" y2="0.3302" layer="51"/>
<rectangle x1="2.2098" y1="-0.3302" x2="2.8702" y2="0.3302" layer="51"/>
</package>
<package name="04P" urn="urn:adsk.eagle:footprint:5913/1" library_version="2">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<wire x1="-2.921" y1="1.778" x2="-2.794" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="1.651" x2="-2.54" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.397" x2="-2.286" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.651" x2="-2.159" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-2.159" x2="-2.794" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-2.286" x2="-4.826" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-2.159" x2="-2.794" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-2.159" x2="-2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="2.54" x2="-4.826" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="1.778" x2="-4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-1.778" x2="-4.826" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-1.778" x2="-4.445" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.778" x2="-3.175" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.778" x2="-4.445" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.524" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.778" x2="-1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.524" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.524" x2="-2.794" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-1.524" x2="-2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.524" x2="-1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.524" x2="-4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.524" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-1.524" x2="-4.826" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="2.54" x2="-4.064" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-4.064" y1="2.54" x2="-4.064" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="2.54" x2="-3.556" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="2.667" x2="-4.064" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="2.54" x2="-1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.54" x2="-1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.413" x2="-2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="2.413" x2="-2.794" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-2.159" x2="-0.254" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-2.159" x2="0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-2.286" x2="0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.778" x2="1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="-0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.778" x2="0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.524" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-1.524" x2="0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.016" y1="2.54" x2="1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.54" x2="2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.54" x2="1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.667" x2="1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.413" x2="0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.54" x2="1.016" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.413" x2="-0.254" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="2.413" x2="-0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.54" x2="-0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.667" x2="-1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.54" x2="-1.524" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="2.413" x2="-2.286" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="2.54" x2="-3.556" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.921" y1="1.778" x2="-4.826" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-2.159" y1="1.778" x2="-0.254" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.778" x2="0.254" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.651" x2="-2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="1.651" x2="-2.794" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.778" x2="-0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.778" x2="0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.778" x2="-3.175" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-2.286" x2="-0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="0.635" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-2.159" x2="-0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="4.826" y1="1.778" x2="4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-1.778" x2="4.826" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-2.159" x2="2.286" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-2.159" x2="2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-2.159" x2="2.794" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-2.286" x2="2.794" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-1.778" x2="4.445" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.778" x2="4.445" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.524" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.524" x2="4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.778" x2="3.175" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.524" x2="2.794" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-1.524" x2="3.175" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.524" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="1.651" x2="2.794" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.651" x2="2.54" y2="1.397" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.651" x2="2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="2.159" y1="1.778" x2="2.286" y2="1.651" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.397" x2="2.921" y2="1.778" width="0.1524" layer="21"/>
<wire x1="2.921" y1="1.778" x2="4.826" y2="1.778" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.778" x2="3.175" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-1.778" x2="4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="2.286" y1="2.413" x2="2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="2.794" y1="2.413" x2="2.286" y2="2.413" width="0.1524" layer="21"/>
<wire x1="2.794" y1="2.54" x2="3.556" y2="2.54" width="0.1524" layer="21"/>
<wire x1="2.794" y1="2.413" x2="2.794" y2="2.54" width="0.1524" layer="21"/>
<wire x1="3.556" y1="2.54" x2="3.556" y2="2.667" width="0.1524" layer="21"/>
<wire x1="4.064" y1="2.667" x2="3.556" y2="2.667" width="0.1524" layer="21"/>
<wire x1="4.064" y1="2.54" x2="4.064" y2="2.667" width="0.1524" layer="21"/>
<wire x1="4.064" y1="2.54" x2="4.826" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.826" y1="2.54" x2="4.826" y2="1.778" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.778" x2="2.159" y2="1.778" width="0.1524" layer="21"/>
<pad name="1" x="-3.81" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="2" x="-1.27" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="0" drill="0.9144" shape="long" rot="R90"/>
<text x="-3.302" y="0.9398" size="0.9906" layer="21" ratio="12" rot="R90">1</text>
<text x="-4.826" y="2.9464" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-4.826" y="-3.8354" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-4.1402" y1="-0.3302" x2="-3.4798" y2="0.3302" layer="51"/>
<rectangle x1="-1.6002" y1="-0.3302" x2="-0.9398" y2="0.3302" layer="51"/>
<rectangle x1="0.9398" y1="-0.3302" x2="1.6002" y2="0.3302" layer="51"/>
<rectangle x1="3.4798" y1="-0.3302" x2="4.1402" y2="0.3302" layer="51"/>
</package>
<package name="02P" urn="urn:adsk.eagle:footprint:5910/1" library_version="2">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<wire x1="-2.286" y1="2.54" x2="-2.286" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.778" x2="-0.381" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-0.381" y1="1.778" x2="-0.254" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.651" x2="0" y2="1.397" width="0.1524" layer="21"/>
<wire x1="0" y1="1.397" x2="0.254" y2="1.651" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.651" x2="0.381" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-2.159" x2="-0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-2.286" x2="-2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-2.159" x2="-0.254" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-2.159" x2="0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-2.286" x2="0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="0.381" y1="1.778" x2="2.286" y2="1.778" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.778" x2="2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.778" x2="-2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.778" x2="-2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.778" x2="-1.905" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.778" x2="2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.778" x2="1.905" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.778" x2="2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.778" x2="1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="-0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.778" x2="-1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="0.635" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.778" x2="0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.524" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-1.524" x2="0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-1.524" x2="0.254" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.524" x2="-0.254" y2="1.651" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.524" x2="2.286" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.524" x2="-2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.524" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.524" x2="-2.286" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.54" x2="-1.524" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="2.54" x2="-1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.54" x2="-1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.667" x2="-1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.016" y1="2.54" x2="1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.54" x2="2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.54" x2="1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.667" x2="1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.413" x2="0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.54" x2="1.016" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.413" x2="-0.254" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="2.413" x2="-0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="2.54" x2="-1.016" y2="2.54" width="0.1524" layer="21"/>
<pad name="1" x="-1.27" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="2" x="1.27" y="0" drill="0.9144" shape="long" rot="R90"/>
<text x="-0.762" y="0.9398" size="0.9906" layer="21" ratio="12" rot="R90">1</text>
<text x="-2.286" y="2.9464" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-2.286" y="-3.8354" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-1.6002" y1="-0.3302" x2="-0.9398" y2="0.3302" layer="51"/>
<rectangle x1="0.9398" y1="-0.3302" x2="1.6002" y2="0.3302" layer="51"/>
</package>
<package name="06P" urn="urn:adsk.eagle:footprint:5917/1" library_version="2">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<wire x1="-5.461" y1="1.778" x2="-5.334" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="1.651" x2="-5.08" y2="1.397" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.397" x2="-4.826" y2="1.651" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="1.651" x2="-4.699" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="-2.159" x2="-5.334" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="-2.286" x2="-7.366" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-2.159" x2="-5.334" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-2.159" x2="-4.826" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="2.54" x2="-7.366" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="1.778" x2="-7.366" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="-1.778" x2="-7.366" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="-1.778" x2="-6.985" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.778" x2="-5.715" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.778" x2="-6.985" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.27" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.524" x2="-5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.778" x2="-4.445" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.524" x2="-4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.715" y1="-1.524" x2="-5.334" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="-1.524" x2="-4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-1.524" x2="-4.445" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.524" x2="-7.366" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-6.985" y1="-1.524" x2="-6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="-1.524" x2="-7.366" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="2.54" x2="-6.604" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-6.604" y1="2.54" x2="-6.604" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="2.54" x2="-6.096" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="2.667" x2="-6.604" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-4.064" y1="2.54" x2="-4.064" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="2.54" x2="-3.556" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="2.413" x2="-4.826" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="2.413" x2="-5.334" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-2.159" x2="-2.794" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-2.159" x2="-2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-2.286" x2="-2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.778" x2="-0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.778" x2="-0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.778" x2="-3.175" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.524" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.778" x2="-1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-1.524" x2="-1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.524" x2="-2.794" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-1.524" x2="-2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.524" x2="-1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-1.524" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="2.54" x2="-1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.54" x2="-0.254" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.54" x2="-1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="2.667" x2="-1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.413" x2="-2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.54" x2="-1.524" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="2.413" x2="-2.794" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="2.413" x2="-2.794" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="2.54" x2="-2.794" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="2.667" x2="-4.064" y2="2.667" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="2.54" x2="-4.064" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="2.413" x2="-4.826" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="2.54" x2="-6.096" y2="2.54" width="0.1524" layer="21"/>
<wire x1="-5.461" y1="1.778" x2="-7.366" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-4.699" y1="1.778" x2="-2.794" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="1.778" x2="-2.286" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="1.651" x2="-4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="1.651" x2="-5.334" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="1.778" x2="-2.794" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.778" x2="-2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.27" x2="-3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.445" y1="-1.778" x2="-5.715" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-2.286" x2="-2.794" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-1.778" x2="-1.905" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-2.159" x2="-2.794" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-2.159" x2="2.286" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-2.286" x2="0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-2.159" x2="2.286" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-2.159" x2="2.794" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.778" x2="0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.778" x2="1.905" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.778" x2="0.635" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="1.905" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.778" x2="3.175" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.524" x2="3.175" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.905" y1="-1.524" x2="2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.524" x2="2.794" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-1.524" x2="3.175" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.524" x2="0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.524" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.54" x2="1.016" y2="2.54" width="0.1524" layer="21"/>
<wire x1="1.016" y1="2.54" x2="1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.54" x2="1.524" y2="2.667" width="0.1524" layer="21"/>
<wire x1="1.524" y1="2.667" x2="1.016" y2="2.667" width="0.1524" layer="21"/>
<wire x1="3.556" y1="2.54" x2="3.556" y2="2.667" width="0.1524" layer="21"/>
<wire x1="4.064" y1="2.54" x2="4.064" y2="2.667" width="0.1524" layer="21"/>
<wire x1="2.794" y1="2.413" x2="2.794" y2="2.54" width="0.1524" layer="21"/>
<wire x1="2.286" y1="2.413" x2="2.286" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.397" x2="5.334" y2="1.651" width="0.1524" layer="21"/>
<wire x1="5.334" y1="1.651" x2="5.461" y2="1.778" width="0.1524" layer="21"/>
<wire x1="5.334" y1="-2.159" x2="4.826" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="5.334" y1="-2.159" x2="5.334" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="7.366" y1="-2.286" x2="5.334" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="5.461" y1="1.778" x2="7.366" y2="1.778" width="0.1524" layer="21"/>
<wire x1="7.366" y1="1.778" x2="7.366" y2="2.54" width="0.1524" layer="21"/>
<wire x1="7.366" y1="-1.778" x2="7.366" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="7.366" y1="-1.778" x2="6.985" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="7.366" y1="1.778" x2="7.366" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.778" x2="6.985" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.27" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.778" x2="4.445" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.524" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.778" x2="5.715" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="5.715" y1="-1.524" x2="5.715" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.524" x2="4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-1.524" x2="5.334" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="5.334" y1="-1.524" x2="5.715" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.524" x2="7.366" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="6.985" y1="-1.524" x2="6.985" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="7.366" y1="-1.524" x2="7.366" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="6.096" y1="2.54" x2="6.096" y2="2.667" width="0.1524" layer="21"/>
<wire x1="6.604" y1="2.54" x2="7.366" y2="2.54" width="0.1524" layer="21"/>
<wire x1="6.604" y1="2.54" x2="6.604" y2="2.667" width="0.1524" layer="21"/>
<wire x1="6.604" y1="2.667" x2="6.096" y2="2.667" width="0.1524" layer="21"/>
<wire x1="5.334" y1="2.413" x2="5.334" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.334" y1="2.54" x2="6.096" y2="2.54" width="0.1524" layer="21"/>
<wire x1="5.334" y1="2.413" x2="4.826" y2="2.413" width="0.1524" layer="21"/>
<wire x1="4.826" y1="2.413" x2="4.826" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.699" y1="1.778" x2="4.826" y2="1.651" width="0.1524" layer="21"/>
<wire x1="4.826" y1="1.651" x2="5.08" y2="1.397" width="0.1524" layer="21"/>
<wire x1="4.064" y1="2.54" x2="4.826" y2="2.54" width="0.1524" layer="21"/>
<wire x1="4.064" y1="2.667" x2="3.556" y2="2.667" width="0.1524" layer="21"/>
<wire x1="2.794" y1="2.54" x2="3.556" y2="2.54" width="0.1524" layer="21"/>
<wire x1="2.286" y1="2.413" x2="2.794" y2="2.413" width="0.1524" layer="21"/>
<wire x1="2.286" y1="2.54" x2="1.524" y2="2.54" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.778" x2="2.286" y2="1.778" width="0.1524" layer="21"/>
<wire x1="2.794" y1="1.778" x2="2.794" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.778" x2="2.286" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="4.826" y1="1.651" x2="4.826" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="5.334" y1="1.651" x2="5.334" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.27" x2="4.445" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.175" y1="-1.778" x2="1.905" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-2.286" x2="4.826" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="4.445" y1="-1.778" x2="5.715" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-2.159" x2="4.826" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.778" x2="-0.254" y2="1.778" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.778" x2="2.794" y2="1.778" width="0.1524" layer="21"/>
<wire x1="2.794" y1="1.778" x2="4.699" y2="1.778" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-2.159" x2="-0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-2.159" x2="0.254" y2="-2.286" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-2.159" x2="-0.254" y2="-2.159" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.778" x2="-0.635" y2="-1.778" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-1.524" x2="-0.254" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.778" x2="-0.254" y2="1.778" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.413" x2="-0.254" y2="2.413" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="2.54" x2="-0.254" y2="2.413" width="0.1524" layer="21"/>
<wire x1="0.254" y1="2.54" x2="0.254" y2="2.413" width="0.1524" layer="21"/>
<pad name="1" x="-6.35" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="0.9144" shape="long" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="0.9144" shape="long" rot="R90"/>
<text x="-5.842" y="0.9398" size="0.9906" layer="21" ratio="12" rot="R90">1</text>
<text x="-7.366" y="2.9464" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.366" y="-3.8354" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-6.6802" y1="-0.3302" x2="-6.0198" y2="0.3302" layer="51"/>
<rectangle x1="-4.1402" y1="-0.3302" x2="-3.4798" y2="0.3302" layer="51"/>
<rectangle x1="-1.6002" y1="-0.3302" x2="-0.9398" y2="0.3302" layer="51"/>
<rectangle x1="0.9398" y1="-0.3302" x2="1.6002" y2="0.3302" layer="51"/>
<rectangle x1="3.4798" y1="-0.3302" x2="4.1402" y2="0.3302" layer="51"/>
<rectangle x1="6.0198" y1="-0.3302" x2="6.6802" y2="0.3302" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="03P" urn="urn:adsk.eagle:package:5957/1" type="box" library_version="2">
<description>AMP QUICK CONNECTOR</description>
<packageinstances>
<packageinstance name="03P"/>
</packageinstances>
</package3d>
<package3d name="04P" urn="urn:adsk.eagle:package:5958/1" type="box" library_version="2">
<description>AMP QUICK CONNECTOR</description>
<packageinstances>
<packageinstance name="04P"/>
</packageinstances>
</package3d>
<package3d name="02P" urn="urn:adsk.eagle:package:5956/1" type="box" library_version="2">
<description>AMP QUICK CONNECTOR</description>
<packageinstances>
<packageinstance name="02P"/>
</packageinstances>
</package3d>
<package3d name="06P" urn="urn:adsk.eagle:package:5960/1" type="box" library_version="2">
<description>AMP QUICK CONNECTOR</description>
<packageinstances>
<packageinstance name="06P"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="M03" urn="urn:adsk.eagle:symbol:5911/1" library_version="2">
<wire x1="3.81" y1="-5.08" x2="-2.54" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="2.54" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-2.54" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-5.08" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<text x="-2.54" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.54" y="5.842" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="M04" urn="urn:adsk.eagle:symbol:5918/1" library_version="2">
<wire x1="1.27" y1="-5.08" x2="-5.08" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="-2.54" x2="0" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-5.08" y1="7.62" x2="-5.08" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-5.08" x2="1.27" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="7.62" x2="1.27" y2="7.62" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="0" y2="5.08" width="0.6096" layer="94"/>
<text x="-5.08" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<text x="-5.08" y="8.382" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="5.08" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="5.08" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="5.08" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="5.08" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="M02" urn="urn:adsk.eagle:symbol:5909/1" library_version="2">
<wire x1="3.81" y1="-2.54" x2="-2.54" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="2.54" y2="2.54" width="0.6096" layer="94"/>
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.6096" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="-2.54" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-2.54" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-2.54" y1="5.08" x2="3.81" y2="5.08" width="0.4064" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.54" y="5.842" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="M06" urn="urn:adsk.eagle:symbol:5916/1" library_version="2">
<wire x1="1.27" y1="-7.62" x2="-5.08" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="-2.54" x2="0" y2="-2.54" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="-5.08" x2="0" y2="-5.08" width="0.6096" layer="94"/>
<wire x1="-5.08" y1="10.16" x2="-5.08" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="1.27" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="10.16" x2="1.27" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="5.08" x2="0" y2="5.08" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="2.54" x2="0" y2="2.54" width="0.6096" layer="94"/>
<wire x1="-1.27" y1="7.62" x2="0" y2="7.62" width="0.6096" layer="94"/>
<text x="-5.08" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-5.08" y="10.922" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="5.08" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="5.08" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="5.08" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="5.08" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="5.08" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="5.08" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="M03" urn="urn:adsk.eagle:component:5984/2" prefix="SL" uservalue="yes" library_version="2">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="M03" x="-2.54" y="0"/>
</gates>
<devices>
<device name="" package="03P">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5957/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="12" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="M04" urn="urn:adsk.eagle:component:5989/2" prefix="SL" uservalue="yes" library_version="2">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="M04" x="-2.54" y="0"/>
</gates>
<devices>
<device name="" package="04P">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5958/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="19" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="M02" urn="urn:adsk.eagle:component:5982/2" prefix="SL" uservalue="yes" library_version="2">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="M02" x="-2.54" y="0"/>
</gates>
<devices>
<device name="" package="02P">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5956/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="33" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="M06" urn="urn:adsk.eagle:component:5994/2" prefix="SL" uservalue="yes" library_version="2">
<description>&lt;b&gt;AMP QUICK CONNECTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="M06" x="-2.54" y="0"/>
</gates>
<devices>
<device name="" package="06P">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:5960/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="5" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="5VOUT" library="diy-modules" deviceset="DC-DC-STEP-DOWN-MP1584" device=""/>
<part name="ESP32" library="ESP32" deviceset="ESP32-36IO" device=""/>
<part name="SOIL_M" library="con-amp-quick" library_urn="urn:adsk.eagle:library:125" deviceset="M03" device="" package3d_urn="urn:adsk.eagle:package:5957/1"/>
<part name="TEMP" library="con-amp-quick" library_urn="urn:adsk.eagle:library:125" deviceset="M04" device="" package3d_urn="urn:adsk.eagle:package:5958/1"/>
<part name="7V" library="con-amp-quick" library_urn="urn:adsk.eagle:library:125" deviceset="M02" device="" package3d_urn="urn:adsk.eagle:package:5956/1"/>
<part name="GPS" library="con-amp-quick" library_urn="urn:adsk.eagle:library:125" deviceset="M04" device="" package3d_urn="urn:adsk.eagle:package:5958/1"/>
<part name="SD" library="con-amp-quick" library_urn="urn:adsk.eagle:library:125" deviceset="M06" device="" package3d_urn="urn:adsk.eagle:package:5960/1"/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="5VOUT1" library="diy-modules" deviceset="DC-DC-STEP-DOWN-MP1584" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="5VOUT" gate="G$1" x="-134.62" y="200.66" smashed="yes">
<attribute name="NAME" x="-147.32" y="215.9" size="1.778" layer="95"/>
<attribute name="VALUE" x="-147.32" y="213.36" size="1.778" layer="96"/>
</instance>
<instance part="ESP32" gate="G$1" x="-43.18" y="190.5" smashed="yes" rot="R270">
<attribute name="NAME" x="-38.1" y="217.17" size="1.27" layer="95"/>
</instance>
<instance part="SOIL_M" gate="G$1" x="-101.6" y="116.84" smashed="yes" rot="MR90">
<attribute name="VALUE" x="-109.22" y="114.3" size="1.778" layer="96" rot="MR90"/>
<attribute name="NAME" x="-95.758" y="114.3" size="1.778" layer="95" rot="MR90"/>
</instance>
<instance part="TEMP" gate="G$1" x="-83.82" y="119.38" smashed="yes" rot="MR90">
<attribute name="VALUE" x="-91.44" y="114.3" size="1.778" layer="96" rot="MR90"/>
<attribute name="NAME" x="-75.438" y="114.3" size="1.778" layer="95" rot="MR90"/>
</instance>
<instance part="7V" gate="G$1" x="-172.72" y="172.72" smashed="yes" rot="MR180">
<attribute name="VALUE" x="-175.26" y="177.8" size="1.778" layer="96" rot="MR180"/>
<attribute name="NAME" x="-175.26" y="166.878" size="1.778" layer="95" rot="MR180"/>
</instance>
<instance part="GPS" gate="G$1" x="-83.82" y="175.26" smashed="yes" rot="MR90">
<attribute name="VALUE" x="-91.44" y="170.18" size="1.778" layer="96" rot="MR90"/>
<attribute name="NAME" x="-75.438" y="170.18" size="1.778" layer="95" rot="MR90"/>
</instance>
<instance part="SD" gate="G$1" x="-106.68" y="175.26" smashed="yes" rot="MR90">
<attribute name="VALUE" x="-116.84" y="170.18" size="1.778" layer="96" rot="MR90"/>
<attribute name="NAME" x="-95.758" y="170.18" size="1.778" layer="95" rot="MR90"/>
</instance>
<instance part="GND1" gate="1" x="-134.62" y="172.72" smashed="yes">
<attribute name="VALUE" x="-137.16" y="170.18" size="1.778" layer="96"/>
</instance>
<instance part="5VOUT1" gate="G$1" x="-137.16" y="147.32" smashed="yes">
<attribute name="NAME" x="-149.86" y="162.56" size="1.778" layer="95"/>
<attribute name="VALUE" x="-149.86" y="160.02" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="5VOUT" gate="G$1" pin="OUT-.2"/>
<wire x1="-116.84" y1="203.2" x2="-106.68" y2="203.2" width="0.1524" layer="91"/>
<label x="-109.22" y="203.2" size="1.778" layer="95" align="bottom-right"/>
</segment>
<segment>
<pinref part="GPS" gate="G$1" pin="2"/>
<label x="-83.82" y="187.96" size="1.778" layer="95" rot="R90" align="bottom-right"/>
<wire x1="-83.82" y1="180.34" x2="-83.82" y2="205.74" width="0.1524" layer="91"/>
<pinref part="5VOUT" gate="G$1" pin="OUT-.1"/>
<wire x1="-116.84" y1="205.74" x2="-99.06" y2="205.74" width="0.1524" layer="91"/>
<label x="-109.22" y="205.74" size="1.778" layer="95" align="bottom-right"/>
<pinref part="SD" gate="G$1" pin="6"/>
<label x="-99.06" y="187.96" size="1.778" layer="95" rot="R90" align="bottom-right"/>
<wire x1="-99.06" y1="205.74" x2="-99.06" y2="180.34" width="0.1524" layer="91"/>
<wire x1="-83.82" y1="205.74" x2="-99.06" y2="205.74" width="0.1524" layer="91"/>
<junction x="-99.06" y="205.74"/>
</segment>
<segment>
<pinref part="SOIL_M" gate="G$1" pin="2"/>
<label x="-101.6" y="132.08" size="1.778" layer="95" rot="R90" align="bottom-right"/>
<pinref part="5VOUT1" gate="G$1" pin="OUT-.1"/>
<wire x1="-119.38" y1="152.4" x2="-101.6" y2="152.4" width="0.1524" layer="91"/>
<label x="-111.76" y="152.4" size="1.778" layer="95" align="bottom-right"/>
<wire x1="-101.6" y1="124.46" x2="-101.6" y2="152.4" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="TEMP" gate="G$1" pin="2"/>
<label x="-83.82" y="132.08" size="1.778" layer="95" rot="R90" align="bottom-right"/>
<wire x1="-83.82" y1="124.46" x2="-83.82" y2="149.86" width="0.1524" layer="91"/>
<pinref part="5VOUT1" gate="G$1" pin="OUT-.2"/>
<wire x1="-83.82" y1="149.86" x2="-119.38" y2="149.86" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="7V" gate="G$1" pin="2"/>
<wire x1="-165.1" y1="170.18" x2="-157.48" y2="170.18" width="0.1524" layer="91"/>
<wire x1="-157.48" y1="170.18" x2="-157.48" y2="175.26" width="0.1524" layer="91"/>
<pinref part="5VOUT" gate="G$1" pin="IN-.1"/>
<wire x1="-157.48" y1="175.26" x2="-157.48" y2="205.74" width="0.1524" layer="91"/>
<wire x1="-157.48" y1="205.74" x2="-152.4" y2="205.74" width="0.1524" layer="91"/>
<wire x1="-157.48" y1="170.18" x2="-157.48" y2="152.4" width="0.1524" layer="91"/>
<junction x="-157.48" y="170.18"/>
<pinref part="5VOUT1" gate="G$1" pin="IN-.1"/>
<wire x1="-157.48" y1="152.4" x2="-154.94" y2="152.4" width="0.1524" layer="91"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="-134.62" y1="175.26" x2="-157.48" y2="175.26" width="0.1524" layer="91"/>
<junction x="-157.48" y="175.26"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="GND"/>
<wire x1="-60.96" y1="172.72" x2="-71.12" y2="172.72" width="0.1524" layer="91"/>
<label x="-68.58" y="172.72" size="1.778" layer="95"/>
</segment>
</net>
<net name="CS" class="0">
<segment>
<pinref part="ESP32" gate="G$1" pin="IO5"/>
<wire x1="-25.4" y1="195.58" x2="-17.78" y2="195.58" width="0.1524" layer="91"/>
<label x="-20.32" y="195.58" size="1.778" layer="95" align="bottom-right"/>
</segment>
<segment>
<pinref part="SD" gate="G$1" pin="1"/>
<wire x1="-111.76" y1="180.34" x2="-111.76" y2="187.96" width="0.1524" layer="91"/>
<label x="-111.76" y="185.42" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
</net>
<net name="CLK" class="0">
<segment>
<pinref part="SD" gate="G$1" pin="2"/>
<wire x1="-109.22" y1="180.34" x2="-109.22" y2="190.5" width="0.1524" layer="91"/>
<label x="-109.22" y="187.96" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="IO18"/>
<wire x1="-25.4" y1="198.12" x2="-15.24" y2="198.12" width="0.1524" layer="91"/>
<label x="-17.78" y="198.12" size="1.778" layer="95" align="bottom-right"/>
</segment>
</net>
<net name="MOSI" class="0">
<segment>
<pinref part="SD" gate="G$1" pin="3"/>
<wire x1="-106.68" y1="180.34" x2="-106.68" y2="193.04" width="0.1524" layer="91"/>
<label x="-106.68" y="190.5" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="IO23"/>
<wire x1="-25.4" y1="213.36" x2="-12.7" y2="213.36" width="0.1524" layer="91"/>
<label x="-15.24" y="213.36" size="1.778" layer="95" align="bottom-right"/>
</segment>
</net>
<net name="MISO" class="0">
<segment>
<pinref part="SD" gate="G$1" pin="4"/>
<wire x1="-104.14" y1="180.34" x2="-104.14" y2="193.04" width="0.1524" layer="91"/>
<label x="-104.14" y="190.5" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="IO19"/>
<wire x1="-25.4" y1="200.66" x2="-12.7" y2="200.66" width="0.1524" layer="91"/>
<label x="-15.24" y="200.66" size="1.778" layer="95" align="bottom-right"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<pinref part="SD" gate="G$1" pin="5"/>
<label x="-101.6" y="185.42" size="1.778" layer="95" rot="R90" align="bottom-right"/>
<wire x1="-101.6" y1="180.34" x2="-101.6" y2="198.12" width="0.1524" layer="91"/>
<pinref part="5VOUT" gate="G$1" pin="OUT+.1"/>
<label x="-111.76" y="198.12" size="1.778" layer="95" align="bottom-right"/>
<wire x1="-101.6" y1="198.12" x2="-116.84" y2="198.12" width="0.1524" layer="91"/>
<wire x1="-101.6" y1="198.12" x2="-86.36" y2="198.12" width="0.1524" layer="91"/>
<junction x="-101.6" y="198.12"/>
<pinref part="GPS" gate="G$1" pin="1"/>
<label x="-86.36" y="185.42" size="1.778" layer="95" rot="R90" align="bottom-right"/>
<wire x1="-86.36" y1="198.12" x2="-86.36" y2="180.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="TX" class="0">
<segment>
<pinref part="GPS" gate="G$1" pin="3"/>
<wire x1="-81.28" y1="180.34" x2="-81.28" y2="187.96" width="0.1524" layer="91"/>
<label x="-81.28" y="185.42" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="IO16"/>
<wire x1="-25.4" y1="190.5" x2="-17.78" y2="190.5" width="0.1524" layer="91"/>
<label x="-20.32" y="190.5" size="1.778" layer="95" align="bottom-right"/>
</segment>
</net>
<net name="RX" class="0">
<segment>
<pinref part="GPS" gate="G$1" pin="4"/>
<wire x1="-78.74" y1="180.34" x2="-78.74" y2="187.96" width="0.1524" layer="91"/>
<label x="-78.74" y="185.42" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="IO17"/>
<wire x1="-25.4" y1="193.04" x2="-17.78" y2="193.04" width="0.1524" layer="91"/>
<label x="-20.32" y="193.04" size="1.778" layer="95" align="bottom-right"/>
</segment>
</net>
<net name="VIN" class="0">
<segment>
<pinref part="5VOUT" gate="G$1" pin="OUT+.2"/>
<wire x1="-116.84" y1="195.58" x2="-106.68" y2="195.58" width="0.1524" layer="91"/>
<label x="-109.22" y="195.58" size="1.778" layer="95" align="bottom-right"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="VIN"/>
<wire x1="-60.96" y1="170.18" x2="-71.12" y2="170.18" width="0.1524" layer="91"/>
<label x="-68.58" y="170.18" size="1.778" layer="95"/>
</segment>
</net>
<net name="3.3V" class="0">
<segment>
<pinref part="5VOUT1" gate="G$1" pin="OUT+.1"/>
<wire x1="-119.38" y1="144.78" x2="-104.14" y2="144.78" width="0.1524" layer="91"/>
<label x="-111.76" y="144.78" size="1.778" layer="95" align="bottom-right"/>
<pinref part="SOIL_M" gate="G$1" pin="1"/>
<wire x1="-104.14" y1="124.46" x2="-104.14" y2="144.78" width="0.1524" layer="91"/>
<label x="-104.14" y="132.08" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
<segment>
<pinref part="TEMP" gate="G$1" pin="1"/>
<wire x1="-86.36" y1="124.46" x2="-86.36" y2="142.24" width="0.1524" layer="91"/>
<label x="-86.36" y="132.08" size="1.778" layer="95" rot="R90" align="bottom-right"/>
<pinref part="5VOUT1" gate="G$1" pin="OUT+.2"/>
<wire x1="-119.38" y1="142.24" x2="-86.36" y2="142.24" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SCK" class="0">
<segment>
<pinref part="TEMP" gate="G$1" pin="3"/>
<wire x1="-81.28" y1="124.46" x2="-81.28" y2="134.62" width="0.1524" layer="91"/>
<label x="-81.28" y="132.08" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="IO22"/>
<wire x1="-25.4" y1="210.82" x2="-15.24" y2="210.82" width="0.1524" layer="91"/>
<label x="-17.78" y="210.82" size="1.778" layer="95" align="bottom-right"/>
</segment>
</net>
<net name="SDA" class="0">
<segment>
<pinref part="TEMP" gate="G$1" pin="4"/>
<wire x1="-78.74" y1="124.46" x2="-78.74" y2="134.62" width="0.1524" layer="91"/>
<label x="-78.74" y="132.08" size="1.778" layer="95" rot="R90" align="bottom-right"/>
</segment>
<segment>
<pinref part="ESP32" gate="G$1" pin="IO21"/>
<wire x1="-25.4" y1="203.2" x2="-15.24" y2="203.2" width="0.1524" layer="91"/>
<label x="-17.78" y="203.2" size="1.778" layer="95" align="bottom-right"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="7V" gate="G$1" pin="1"/>
<wire x1="-165.1" y1="172.72" x2="-162.56" y2="172.72" width="0.1524" layer="91"/>
<wire x1="-162.56" y1="172.72" x2="-162.56" y2="198.12" width="0.1524" layer="91"/>
<pinref part="5VOUT" gate="G$1" pin="IN+.1"/>
<wire x1="-162.56" y1="198.12" x2="-152.4" y2="198.12" width="0.1524" layer="91"/>
<wire x1="-162.56" y1="172.72" x2="-162.56" y2="144.78" width="0.1524" layer="91"/>
<junction x="-162.56" y="172.72"/>
<pinref part="5VOUT1" gate="G$1" pin="IN+.1"/>
<wire x1="-162.56" y1="144.78" x2="-154.94" y2="144.78" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
<note version="9.0" severity="warning">
Since Version 9.0, EAGLE supports the align property for labels. 
Labels in schematic will not be understood with this version. Update EAGLE to the latest version 
for full support of labels. 
</note>
</compatibility>
</eagle>
