# Volume

WAV files are a common file format for representing audio. WAV files store audio as a sequence of “samples”: numbers that represent the value of some audio signal at a particular point in time. WAV files begin with a 44-byte “header” that contains information about the file itself, including the size of the file, the number of samples per second, and the size of each sample. After the header, the WAV file contains a sequence of samples, each a single 2-byte (16-bit) integer representing the audio signal at a particular point in time.

Scaling each sample value by a given factor has the effect of changing the volume of the audio. Multiplying each sample value by 2.0, for example, will have the effect of doubling the volume of the origin audio. Multiplying each sample by 0.5, meanwhile, will have the effect of cutting the volume in half.

In a file called volume.c in a folder called volume, write a program to modify the volume of an audio file.

![alt text](https://cs50.harvard.edu/x/2025/psets/4/volume/wav_file.png)

## Distribution code

For this problem, you’ll extend the functionality of code provided to you by CS50’s staff.

## Download the distribution code
Log into cs50.dev, click on your terminal window, and execute cd by itself. You should find that your terminal window’s prompt resembles the below:
```
$
````
Next execute
```
wget https://cdn.cs50.net/2024/fall/psets/4/volume.zip
````
in order to download a ZIP called ```volume.zip``` into your codespace.

Then execute
```
unzip volume.zip
```
to create a folder called volume. You no longer need the ZIP file, so you can execute
```
rm volume.zip
```
and respond with “y” followed by Enter at the prompt to remove the ZIP file you downloaded.

Now type
```
cd volume
```
followed by Enter to move yourself into (i.e., open) that directory. Your prompt should now resemble the below.
```
volume/ $
```
If all was successful, you should execute
```
ls
```
and see a file named ```volume.c.``` Executing code ```volume.c``` should open the file where you will type your code for this problem set. If not, retrace your steps and see if you can determine where you went wrong!

## Implementation Details
Complete the implementation of ```volume.c```, such that it changes the volume of a sound file by a given factor.

- The program should accept three command-line arguments. The first is ```input```, which represents the name of the original audio file. The second is ```output```, which represents the name of the new audio file that should be generated. The third is ```factor```, which is the amount by which the volume of the original audio file should be scaled.
  - For example, if ```factor``` is ```2.0```, then your program should double the volume of the audio file in input and save the newly generated audio file in output.

- Your program should first read the header from the input file and write the header to the output file.
- Your program should then read the rest of the data from the WAV file, one 16-bit (2-byte) sample at a time. Your program should multiply each sample by the ```factor``` and write the new sample to the output file.
  -  You may assume that the WAV file will use 16-bit signed values as samples. In practice, WAV files can have varying numbers of bits per sample, but we’ll assume 16-bit samples for this problem.
- Your program, if it uses ```malloc```, must not leak any memory.

## How to Test
Your program should behave per the examples below.
```
$ ./volume input.wav output.wav 2.0
```
When you listen to ```output.wav``` (as by control-clicking on ```output.wav``` in the file browser, choosing Download, and then opening the file in an audio player on your computer), it should be twice as loud as ```input.wav```!
```
$ ./volume input.wav output.wav 0.5
```
When you listen to ```output.wav```, it should be half as loud as ```input.wav```!

## Correctness
```
check50 cs50/problems/2025/x/volume
```
## Style
```
style50 volume.c
````

## How to Submit
```
submit50 cs50/problems/2025/x/volume
```
