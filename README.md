# Fightstick Layout for UnoJoy
Are you building your own arcade fightstick but don't have a PCB to connect to your console of choice?

Have an Arduino? Check out UnoJoy! - *https://github.com/AlanChatham/UnoJoy*

FightStickv1.ino will allow you to quickly program your Arduino to an 11-button (8 face buttons, 3 menu buttons) fightstick. Upload this code to your Arduino and test the output using UnoJoy's Processing Visualizer. Then reprogram the communications chip by going to DFU mode and you should have your fightstick all set!

### Pin Assignment for Buttons
```
13 - Ground (GND)

2 - Light Punch (LP/Jab)
3 - Medium Punch (MP/Strong)
4 - Heavy Punch (HP/Fierce)
5 - Punch Macro (PPP)

6 - Light Kick (LK/Short)
7 - Medium Kick (MK/Forward)
8 - Heavy Kick (HK/Roundhouse)
9 - Kick Macro (KKK)

10 - Home/Menu
11 - Start
12 - Select
```
*The following pins are read as digital.*
```
A1 - Up
A2 - Down
A3 - Left
A4 - Right
```
