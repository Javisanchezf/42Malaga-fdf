<div id="header" align = center>
  <img src="https://github.com/Javisanchezf/media/blob/main/pc-gif.webp" width="200"/>
</div>

<h1 align = center>42 Malaga FDF</h1>

> School 42 Málaga cursus project.

This repository contains all archives for the project __fdf__ in the __School 42 Málaga core cursus__.

<h2 align = center>
	<a href="#about">About</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instuctions</a>
	<span> · </span>
	<a href="#testing">Testing</a>
	<span> · </span>
	<a href="#references">References</a>
	<span> · </span>
	<a href="#tips">Tips</a>
	<span> · </span>
	<a href="#license">License</a>
</h2>

## About

FDF is a project that aims to create a simple 3D height-map renderer. The program takes a map file as input and creates a graphical representation of it. The program allows for basic manipulations of the map and the rendering. [You can find more information in the subject](https://github.com/Javisanchezf/42Malaga-pdfs/blob/main/fdf_subject.pdf).

The code in this repository follows [the rules of the Norminette](https://github.com/Javisanchezf/42Malaga-pdfs/blob/master/norme.pdf).

This is the result of the program:

<div align = center>
  <img src="https://github.com/Javisanchezf/42Malaga-fdf/blob/main/images/juliafdf.webp" width="800"/>
</div>
<div align = center>
  <img src="https://github.com/Javisanchezf/42Malaga-fdf/blob/main/images/t2fdf.webp" width="800"/>
</div>
<div align = center>
  <img src="https://github.com/Javisanchezf/42Malaga-fdf/blob/main/images/earth1fdf.webp" width="800"/>
</div>
<div align = center>
  <img src="https://github.com/Javisanchezf/42Malaga-fdf/blob/main/images/earth2fdf.webp" width="800"/>
</div>

## Requirements
The project is written in __C language__ and needs:
- Compiler `gcc`.
-  The following  standard libraries:
	- `<stdlib.h>`
	- `<unistd.h>`
	- `<stdlib.h>`
	- `<math.h>`
- Software development tool `GNU Libtool`.

## Instructions

### 1. Download the repository

To download the repository, go to the console and run:
```
git clone --recursive https://github.com/Javisanchezf/42Malaga-fdf.git
cd 42Malaga-fdf
```

### 2. Compiling the library

To compile the library, go to its path and run:

```
make
```


### 3. Cleaning all binary (.o) executable files (.a) and the program

To delete all files generated with make, go to the path and run:
```
make fclean
```
If you have a fault, it is possible that you do not meet the aforementioned requirements. The most common is not having libtool installed, you can do it by:
```
brew install libtool
```

If you don't want to install libtool or you have an ubuntu device you can run the program but the library will be created every time you run the command:
```
make nolibtool
```
### 4. Using it


You can test the FDF with different maps, you have several maps to test in the maps folder, try the following:
```
./fdf maps/42.fdf
```

## Testing
This library have been tested by several students from Fundación 42 following the correction script provided by the school.

## References
- MLX42	by codam: https://github.com/codam-coding-college/MLX42
- MLX42 guide https://harm-smits.github.io/42docs/libs/minilibx
- 42 Map generator https://github.com/jgigault/42MapGenerator
- Others
	- https://en.wikipedia.org/wiki/Rotation_matrix
	- https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
## Tips

To rotate the figure:

At the beginning angle1 = angle2 = 0º, and to rotate the figure you only have to vary those angles.
- x (With angles) = x * cos(angle1) - y * sin(angle1)
- y (With angles) = x * sin(angle1) + y * cos(angle1) * cos(angle2) - z * sin(angle2)
- z (With angles) = y * sin(angle2) - z * cos(angle2)


Perspectives to convert in FDF:
- Isometric
	- Xi =  x * cos(30º) + y * sen(30º)
	- Yi =  x * sen(30º) + y * cos(30º) - z
- Cavalier
	- Xc = (x - z * cos(45º)) - (y - z * sen(45º)) * cos(45º)
	- Yc = y - z * sen(45º)
- Top view
	- Xt = x
	- Yt = y
- Frontal view
	- Xf = x + y
	- Yf = -z

Conversions:
- 1 ° × π / 180 = 0,01745 rad

## License
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/).

You are free to:
* Share: copy and redistribute the material in any medium or format.
* Adapt: remix, transform, and build upon the material.

Under the following terms:
* Attribution: You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
* NonCommercial: You may not use the material for commercial purposes.
* ShareAlike: If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.

<h3 align = right>Share the content!</h3>

[<img src="https://github.com/Javisanchezf/media/blob/main/whatsapp-icon.png" width="50" height="50" align = right></img>](https://api.whatsapp.com/send?text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github.%20%0ahttps://github.com/Javisanchezf/42Malaga-fdf)
[<img src="https://github.com/Javisanchezf/media/blob/main/telegram-icon.webp" width="50" height="50" align = right></img>](https://t.me/share/url?url=https://github.com/javisanchezf/42Malaga-fdf&text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github.)
[<img src="https://github.com/Javisanchezf/media/blob/main/twitter-icon.png" width="50" height="50" align = right></img>](https://twitter.com/intent/tweet?url=https://github.com/Javisanchezf/42Malaga-fdf&text=Hey!%20Check%20out%20this%20cool%20repository%20I%20found%20on%20Github)
[<img src="https://github.com/Javisanchezf/media/blob/main/linkedin-icon.png" width="50" height="50" align = right></img>](https://www.linkedin.com/sharing/share-offsite/?url=https://github.com/javisanchezf/42Malaga-fdf)
