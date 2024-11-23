# Tandy1400 PSU

A very rough potential replacement for a Tandy 1400 PSU. At this point the board has not been tested 
in any way, shape, or form and is only published for potential review.

## Status

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

## Optional
* A1 - 5v Arduino Nano (ATmega 328p based was used in prototype)
  * 2.54mm pin heade for the Arduino (28 pins)

* Charging and Battery - Experimental
  * D1, D4 - 31DQ06 - Diode - D4 may just be a jumper, my TP5100 modules didn't like being connected to the battery unpowered.
  * U6 - TP5100 Charging module - https://www.amazon.com/Charging-Management-Voltage-Regulator-Batteries/dp/B0C781VGYY
  * J1 - Jumper lead for battery connection. Size to match pack but should be able to handle at least 2A.
  * Q1 - IRF9540N P-Channel MOSFET in TO-220-3 - http://www.irf.com/product-info/datasheets/data/irf9540n.pdf

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
* F1 - 3Amp Mini Automotive fuse
* J2 - CP-063AH-ND Barrel Jack Connector - https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/pj-063ah/2161208  
* J3 - EHR-15 and 14 ASEHSEH22K152 Jumpers - If you have an existing supply, this can be harvested off the old one.
  * https://www.digikey.com/en/products/detail/jst-sales-america-inc/EHR-15/527237
  * https://www.digikey.com/en/products/detail/jst-sales-america-inc/ASEHSEH22K152/6009479
* L1 - 330uH Inductor
* R1, R6 - 1k 1/4w
* R2, R5, R8 - 10k 1/4w
* R3 - 1 1/4w 
* R4 - 15k 1/4w
* R7, R9 - 150k 1/4w
* RV1 - 4.7k Trimmer 3296Y-1-472 or equivalent - https://www.digikey.com/en/products/detail/bourns-inc/3296Y-1-472/2536015 you want one with the adjustment on top or facing to the outer edge of the board when installed.
* SW1 - Z4418-ND - https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/A8L-21-12N2/1811713
  * I've adjusted the footprint so that it's theoretically possible to harvest the original if you have one.
  * You might be able to harvest the switch off you're old supply, but the foot print is slightly different.
* U1 - MC34063 in either PDIP-8 or SOIC-8 form.
* U2 - MEZD41502A-C - 15V DC/DC boost converter (Digikey says it's obsolete, manufacturer didn't last I checked.) - https://www.digikey.com/en/products/detail/monolithic-power-systems-inc/MEZD41502A-C/6823857
* U3 - MEZD72401A-G - Drop in replacement for a TO-220-3 LM7805 - https://www.digikey.com/en/products/detail/monolithic-power-systems-inc/MEZD72401A-G/6823842
  * This is a 7805 equivalent rated for 1A. You could theoretically put a 7805 here, but you'd need to keep in mind heat dissipation and efficiency.
* U4 - LM340T-12 - Note: This is powered off of a 15V rail so you'll probably need an actual linear regulator.
  * DO NOT try to use an N7812-1PH in place of the LM340T-12, this part needs a minimum of 20V to produce a +12V supply and has been seen to dump 36V out when under-voltaged.
* U5 - N7812-1PH - +/- 12V DC/DC Converter Used to generate -12V, cannot be used for +12V with a 15V supply. - https://www.digikey.com/en/products/detail/mean-well-usa-inc/N7812-1PH/22119016 
  * Keep a close eye on the pin-out for this one, the inductor goes down to match the board wiring. If installed incorrectly, the regulator is effectively dead.


* Note: Resistor wattage ratings are currently and estimate.


# References
* https://forum.vcfed.org/index.php?threads/tandy-1400-any-varients-with-hdd-expansion-slots-please-help.35455/page-2
* https://forum.vcfed.org/index.php?threads/dc-dc-converter-modules.1250102/
* https://www.lo-tech.co.uk/wiki/Tandy_1400FD
* [PSU Pinouts](https://docs.google.com/spreadsheets/d/1nll-RFp76xCkyXyzz_ilaRExv62mEH7IuoLMoUgfZ3Y/edit?usp=sharing)


