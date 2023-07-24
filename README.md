# gpt.vxp

![image](https://github.com/raspiduino/gpt.vxp/assets/68118236/4a1a016f-4e1f-444b-a227-58467fa9a24f)

## What is this?
This is a ChatGPT client running on MRE platform.

## What does it run on?
[MRE platform](https://web.archive.org/web/20150922183623/http://mre.mediatek.com/), for example [Nokia S30+](https://en.wikipedia.org/wiki/Series_30%2B) phones like Nokia 220 (tested), Nokia 225 (tested),... and some other (mostly Chinese) phones. If your (cell / feature) phone can run `.vxp` apps, it's likely to be able to run this app.

## How does it work?
gpt.vxp = ChatGPT client (= TCP socket + payload stuff) + Terminal emulator

## How to use?
When you open the app, there will be a prompt for you to input. Just type in what you want, then press OK key to send.
<br>Debug mode is available through <kbd>*</kbd> -> <kbd>6</kbd> (`Log`)
<br>**Note:** You need to escape the string yourself (if you need to), since escape engine in this version haven't implemented.

## Virtual keyboard

It's designed by Ximik Boda to type 1 key just by pressing 2 times (much quicker than default cellphone typing method)

To know the keyboard layout, press the right soft key (the key that above the call key), it will print the keyboard layout to you.

For typing, look at the phone's physical keyboard: the key 1 has some special characters, the key 2 has some letter a, b, c,...

If you want to type key `a`, for example, press key 2, then look at the small virtual keyboard appear on the screen, you will find the key `a` at the location of key 1 now. Press key 1 to finally send the key `a`

Special keys are at key 1 and key *

Up / Down / Left / Right key is the D-Pad keys.

## Author
- [Ximik Boda](https://github.com/XimikBoda) for Terminal emulator (from TelnetVXP)
- [gvl610](https://github.com/raspiduino) for other stuffs
