# Tandy1400 PSU

A very rough potential replacement for a Tandy 1400 PSU. At this point the board has not been tested 
in any way, shape, or form and is only published for potential review.

## Status

2024-11-05 - Just ordered a set of boards via JLCPCB. I'll update when they are received and tested.

![Rev 1 circuit diagram](Tandy1400PSU-Rev1.png?raw=true "Rev1 PSU")
![Rev 1 board layout](Tandy1400PSU-Board-Rev1.png?raw=true "Rev1 PSU Board")

# Parts List

## Optional
* 5v Arduino Nano (ATmega 328p based was used in prototype)
** 2.54mm pin heade for the Arduino (28 pins)
* D4 - 31DQ06 - Diode

* J3 - EHR-15 and 14 ASEHSEH22K152 Jumpers - If you have an existing supply, this can be harvested off the old one.
** https://www.digikey.com/en/products/detail/jst-sales-america-inc/EHR-15/527237
** https://www.digikey.com/en/products/detail/jst-sales-america-inc/ASEHSEH22K152/6009479

## Required
* C1 - 100uF 50V
* C2 - 220uF 50V
* C3 - 220pf
* C4 - 0.1uF
* C5 - 22uF 25V
* C6, C9 - 10uF 50V
* C7 - 2.2uF 50V
* C8 - 0.22uF
* D1, D2 - 31DQ06 - 3A Power Diode
* F1 - Keystone 3568 (Mini Automotive Fuse Holder) - https://www.digikey.com/en/products/detail/keystone-electronics/3568/2137306
* F1 - 3Amp Mini Automotive fuse
* J2 - CP-063AH-ND Barrel Jack Connector - https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/pj-063ah/2161208  
* L1 - 330uH Inductor
* Q1 - IRF9540N P-Channel MOSFET in TO-220-3 - http://www.irf.com/product-info/datasheets/data/irf9540n.pdf
* R1, R4 - 1k 1/4w
* R2, R5, R8 - 10k 1/4w
* R3 - 1 1/4w
* R6 - 20k 1/4w
* R7, R9 - 150k 1/4w
* RV1 - 4.7k Trimmer 3296Y-1-472 or equivalent - https://www.digikey.com/en/products/detail/bourns-inc/3296Y-1-472/2536015
* SW1 - Z4418-ND - https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/A8L-21-12N2/1811713
** You might be able to harvest the switch off you're old supply, but the foot print is slightly different.
* U1 - MC34063 in either PDIP-8 or SOIC-8 form.
* U2 - MEZD41502A-C - 15V DC/DC boost converter (Digikey says it's obsolete, manufacturer didn't last I checked.) - https://www.digikey.com/en/products/detail/monolithic-power-systems-inc/MEZD41502A-C/6823857
* U3 - MEZD72401A-G - Drop in replacement for a TO-220-3 LM7805 - https://www.digikey.com/en/products/detail/monolithic-power-systems-inc/MEZD72401A-G/6823842
* U4 - LM340T-12 - Note: This is powered off of a 15V rail so you'll probably need an actual linear regulator.
* U5 - N7812-1PH - +/- 12V DC/DC Converter Used to generate -12V, cannot be used for +12V with a 15V supply. - https://www.digikey.com/en/products/detail/mean-well-usa-inc/N7812-1PH/22119016 
** Keep a close eye on the pin-out for this one, the inductor goes down to match the board wiring.
** DO NOT try to use this in place of the LM340T-12, this part needs 20V to produce a +12V supply and has been seen to dump 36V out when under-volted.


* Note: Resistor wattage ratings are currently and estimate.


# References
* https://forum.vcfed.org/index.php?threads/tandy-1400-any-varients-with-hdd-expansion-slots-please-help.35455/page-2
* https://forum.vcfed.org/index.php?threads/dc-dc-converter-modules.1250102/
* https://www.lo-tech.co.uk/wiki/Tandy_1400FD
* [PSU Pinouts](https://docs.google.com/spreadsheets/d/1nll-RFp76xCkyXyzz_ilaRExv62mEH7IuoLMoUgfZ3Y/edit?usp=sharing)


