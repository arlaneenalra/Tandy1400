# Tandy1400 PSU

A very rough potential replacement for a Tandy 1400 PSU. At this point the board has not been tested 
in any way, shape, or form and is only published for potential review.

> [!CAUTION]
> **Do not use the 12V 1.2A power brick that comes with the Tandy 1400FD (Catalog Number 25-3501).**
> This power brick is a simple unregulated supply that may output much higher voltages than the rated 12v. The unit I examined would output 15.86v unloaded. The maximum input voltages for the MEZD41502A-C 15v DC-DC converter is 13v and I have no idea what would happen if it saw 15.86v instead.
>
> The power adapter from the 1400HD model (12v 2.2A Catalog Number 25-3505) appears to be better regulated and is what I've been using for testing.

## Status

2024-12-01 - Bug fixes
* This should finally fix the MEZD41502A-C footprint.
* Validated the board in "wall power only" configuration.
* At this point, the basic design has been shown to work. I'm not going to order more boards until I have a fix for the [availability issue](https://github.com/arlaneenalra/Tandy1400/issues/3).

2024-11-24 - Bug fixes
* Reversed the switch footprint. - Should orient the stock switch correctly now.
* Reversed the 15v converter and pulled in slightly from the edge of the board. This should avoid solder joints on the back of the module being too close to the shield.
* Adjusted the one mounting whole that was too close to the edge of the board.
* Added a 330uF capacitor to prevent switch induced voltage spikes from killing a TP5100 module.
* Adjusted the through holes for battery leads.

2024-11-23 - Next iteration of the board arrived
* Switch footprint works but is backwards to the original
* 15v converter still too close to the edge, needs to come in about 2~3mm
* -22v rail seems to go between -30v and -27v, need to adjust the values a bit.
* Battery wire holes are too small.
* USB connected to the Arduino Nano can feed power into the dc in bus. It won't feed into the USB connector because of a diode in the Nano, but could power the 15v converter off of the USB port, less than ideal.
* Hmm, cooked the charger board when tried to plug in while on battery power. Not sure why.

2024-11-16 - Regenerating PCB layout for new order.
* A whole bunch of minor changes that should fix the -22v boost converter.
* New switch foot print should allow for harvesting the original switch.
* Added jumpers for operation without the Arduino.
* Screw holes are now actually grounded.

2024-11-11 - Boards arrived!
* Fixed pin size and overall footprint on U2. The holes were too small and it was too close to the edge.
* Fixed diode pin sizes, I had DO-41 and the diodes are actually D201AD.
* The whole -22v boost converter doesn't work ....
* Fixed incorrect inductor connections for negative boost converter
* Fixed R6 and R4 being reversed.

2024-11-05 - Just ordered a set of boards via JLCPCB. I'll update when they are received and tested.

![Rev 1 circuit diagram](Tandy1400PSU-Rev1.png?raw=true "Rev1 PSU")
![Rev 1 board layout](Tandy1400PSU-Board-Rev1.png?raw=true "Rev1 PSU Board")

# Ordering Boards

I recommend 1.6mm boards with 2oz copper. The pre-generated gerbers should be sufficient.

# Solder Jumpers

## JP1 ALWAYS_ON_5 and JP3 MCU_POWER
In the original board, there is a 5V rail that listed as always on. If you cut the 2-1 configuration of these jumpers and resolder them in 2-3 the MCU is always powered and the 5_ALWAYS
rail is powered off of the MCUs internal 5V linear regulator. I do not recommend this configuration, it is present primarily for experimentation.

## JP3 LOW_BATT and JP4 REALLY_LOW_BATT
There are two stages to the Tandy 1400s low battery behavior. The original PSU pulls these pins to ground when the battery is seen as fully charged. If you want to run without an Arduino
just short these two jumpers and it should stop the machine from continuously reporting low battery.

# Parts List

## Required
* C1 - 100uF 50V
* C2 - 47uF 50V
* C3 - 220pf
* C4 - 0.1uF
* C5 - 22uF 25V
* C6, C9 - 10uF 50V
* C7 - 2.2uF 50V
* C8 - 0.22uF
* D2 - 31DQ06 - 3A Power Diode
* D3 - 1N5819 - Schottky DO15 40V 1A 150C - This is like way overrated. I've been semi-successful with a 1N4148.
* F1 - Keystone 3568 (Mini Automotive Fuse Holder) - https://www.digikey.com/en/products/detail/keystone-electronics/3568/2137306
* F1 - 3 Amp Mini Automotive fuse - 2 Amp may be acceptable
* J2 - CP-063AH-ND Barrel Jack Connector - https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/pj-063ah/2161208  
* J3 - EHR-15 and 14 ASEHSEH22K152 Jumpers - If you have an existing supply, this can be harvested off the old one.
  * https://www.digikey.com/en/products/detail/jst-sales-america-inc/EHR-15/527237
  * https://www.digikey.com/en/products/detail/jst-sales-america-inc/ASEHSEH22K152/6009479
* L1 - 330uH Inductor
* R6 - 1k 1/4w
* R3 - 1 ohm 1/4w 
* R4 - 15k 1/4w
* RV1 - 4.7k Trimmer 3296Y-1-472 or equivalent - https://www.digikey.com/en/products/detail/bourns-inc/3296Y-1-472/2536015 you want one with the adjustment on top or facing to the outer edge of the board when installed.
* SW1 - Z4418-ND - https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/A8L-21-12N2/1811713
  * I've adjusted the footprint so that it's theoretically possible to harvest the original if you have one.
  * You might be able to harvest the switch off you're old supply, but the foot print is slightly different.
* U1 - MC34063 in either PDIP-8 or SOIC-8 form.
* U2 - MEZD41502A-C - 15V DC/DC boost converter (Digikey says it's obsolete, manufacturer didn't last I checked.) - https://www.digikey.com/en/products/detail/monolithic-power-systems-inc/MEZD41502A-C/6823857
* U3 - MEZD72401A-G - Drop in replacement for a TO-220-3 LM7805 - https://www.digikey.com/en/products/detail/monolithic-power-systems-inc/MEZD72401A-G/6823842
  * This is a 7805 equivalent rated for 1A. You could theoretically put a 7805 here, but you'd need to keep in mind heat dissipation and efficiency.
  * An alternative https://www.digikey.com/en/products/detail/monolithic-power-systems-inc/MEZD71201A-G/6823821 Should also work, really, this just needs to handle the 15v input voltage, match the 7805 pin out, and support up to 1A load.
* U4 - LM340T-12 - Note: This is powered off of a 15V rail so you'll probably need an actual linear regulator.
  * DO NOT try to use an N7812-1PH in place of the LM340T-12, this part needs a minimum of 20V to produce a +12V supply and has been seen to dump 36V out when under-voltaged.
* U5 - N7812-1PH - +/- 12V DC/DC Converter Used to generate -12V, cannot be used for +12V with a 15V supply. - https://www.digikey.com/en/products/detail/mean-well-usa-inc/N7812-1PH/22119016 
  * Keep a close eye on the pin-out for this one, the inductor goes down to match the board wiring. If installed incorrectly, the regulator is effectively dead.

## Suggested
* 3x TO-220 mounting kit - Something like https://www.digikey.com/en/products/detail/boyd-laconia-llc/4880SG/1625671
  * You may also want a bit of thermal compound (non-conductive).
  * None of the TO-220 parts should produce much heat so this may not strictly be necessary.
  * The N7812-1PH does not have a mounting hole.
  * The MEZD72401A-G uses 2.54mm header pins which are extremely difficult to bend. The board is laid out to allow it to be mounted to the board, but you may also need a small TO-220 heatsink similar to https://www.digikey.com/en/products/detail/cts-thermal-management-products/PB1-36CB/272680

* Multi-colored heatshrink tubing small diameter - If you are not harvesting the power lead off of an existing PSU board, this will help you distinguish which lead is witch in the JST connector.

## Optional
* A1 - 5v Arduino Nano (ATmega 328p based was used in prototype)
  * 2.54mm pin heade for the Arduino (28 pins)
  * R7, R9 - 150k 1/4w
  * R5, R8 - 10k 1/4w

* Battery Power
  * J1 - Jumper lead for battery connection. Size to match pack but should be able to handle at least 2A. (Through holes are sized for 18guage)
  * D1 - 31DQ06 - 3A Power Diode 
  * Q1 - IRF9540N P-Channel MOSFET in TO-220-3 - http://www.irf.com/product-info/datasheets/data/irf9540n.pdf
  * R1 - 1k 1/4w
  * R2 - 10k 1/4w
  * 2s Li-ion pack in the 3000mah range  - *Must have protection circuits* I would recommend 18650 based packs over Li-poly.
    * The current design uses a voltage divider at the Arduino. This could create a phantom load on the battery and drain it overtime.

* Charging - Experimental - *use at your own risk*
  * **WARNING: Cheap TP5100 charging modules have a high unexpected failure rate. If you do set this up, do not leave unattended while the machine is plugged in.**
  * D4 - 31DQ06 - Diode - D4 may just be a jumper, my TP5100 modules didn't like being connected to the battery unpowered.
  * U6 - TP5100 Charging module - https://www.amazon.com/Charging-Management-Voltage-Regulator-Batteries/dp/B0C781VGYY
    * It is recommended to remove one of the R100 resistors to drop to 1A charging.
  * C10 - 330uF 25v - The cheap TP5100 modules I've been using tend to blow up on voltage spikes without this.


* Note: Resistor wattage ratings are currently and estimate.

# References
* https://forum.vcfed.org/index.php?threads/tandy-1400-any-varients-with-hdd-expansion-slots-please-help.35455/page-2
* https://forum.vcfed.org/index.php?threads/dc-dc-converter-modules.1250102/
* https://www.lo-tech.co.uk/wiki/Tandy_1400FD
* [PSU Pinouts](https://docs.google.com/spreadsheets/d/1nll-RFp76xCkyXyzz_ilaRExv62mEH7IuoLMoUgfZ3Y/edit?usp=sharing)


