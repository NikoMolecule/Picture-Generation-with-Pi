# Picture-Generation-with-Pi

Hello, so i made a project about PI. i am generating random "binary" images with PI digits.

Let's Begin.

## How do you calculate pi?

First, i created my own structure "Based", which contains array. i allocated 10000 integers for array.
Next, i overloaded some operations ("multiplication", "subtraction", "addition", "division", "equal sign", "Less-than sign", "Greater-than sign").
using those operations i calculated 10000 digits of PI, using Leibniz formula for PI.

Leibniz Formula:
![](https://miro.medium.com/max/1116/1*p5K4UvnIu85CE6yB9Hg-Ww@2x.png)

## How do you create a image?

I am using [C++ Bitmap Library](https://www.partow.net/programming/bitmap/index.html#simpleexample14) to create image.

## What is logic behind creating the image?

I collect 16 random digits from already calculated PI. next i convert each of them into binary.
When program saw digit 1, it calculated up-left corner of square and created filled 16x16 blue square using line_segments.

## How to run the program?

```
g++ main.cpp -o main.exe
.\main.exe
```
