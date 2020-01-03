# Snow Simulator
Snow simulator using OpenGL (as a try for particle system and as my CA assignment passingly )

（Idea from <https://github.com/Wajov/SnowSimulator>）

## Basic Function

Generate snow flowers from the top ( every time 0-10 snow flowers by default ).



## Attributes

* With snow flowers falling, their texture will become transparent;
* Their speed in y-axis is uniform, not accelerated , which is to simulate the situation in real world ( gravity counteracts air friction );
* And their acceleration in x-axis and z-axis is tiny, ensuring that they look falling to ground.

* Use life/age to replace the record of time, and set a static delta time.



## Result 

![Animation](https://github.com/Great-Keith/SnowSimulator/raw/assets/Animation.gif)