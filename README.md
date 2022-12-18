# PyJ

Python, but javascript

Code is under the MIT license

Works on mac, will work on windows and linux in the future

Programmed in 100% c++ (repository code shows a small amount of python because of the input and output files)

By Paxon Kymissis

### Overview

PyJ is a python flavor, which makes the python syntax more like js, by adding braces instead of indentation, the 'var' keyword, optional semicolons, and more.


### Setup

### MacOS

Setup guide for mac

#### Download
Go to the 'binaries' folder, control click it, and press 'open in new tab'. Your browser will either download the file automatically, or bring you to a page with the file. If the latter happens to you, press the 'download' button on the screen.

#### Installation

After you download the file, locate it in the finder, and open a new terminal window. Next, paste the following into the terminal:

`chmod +x your-binary-path`

, and put the path to the downloaded file in place of 'your-binary-path'. If you do not know the path, drag the file into the terminal, and it will automatically give you the path. If this does not work, try using sudo.

if this has been done correctly, you will now have an executable file, which you will rename to 'PyJ'.

Next, go to: opt -> local -> bin, click 'get info', press the lock icon, and enter your password. Set permissions for 'everyone' to read/write. After, drag the binary into the folder, in order to add it to your path.

Currently, you have added it to a bin folder, but the bin is not registered with the terminal yet. To do this, go to etc -> paths, reuse the technique for accessing the bin folder, by going to get info, and changing permissions. Once you have done this, open the file with the text editor of your choice, and paste the following line in: 'opt/local/bin'. This will tell the terminal to see every file in the folder opt/local/bin as simply their name. Close and open the terminal app to refresh it.

To check if this works, type into the terminal: 'PyJ', and you should be greeted with a message asking for a file.

### Windows

Windows support coming soon!


### Linux

Linux support coming soon!















