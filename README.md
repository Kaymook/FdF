# FDF
The basics of graphic programming

To execute the project copy next 4 lines in your shell:

git clone https://github.com/nikGrape/FDF.git<br>
cd FDF<br>
make<br>
./fdf test_maps/42.fdf<br>

The&nbsp&nbspFDF project is oboult to create 3D model from a text map.<br>

Example of map:
<pre>
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
</pre>
Here the numbers are *z* cordinates and plase of a number is *x* and *y* cordinates,<br>
for examle the first 10 has [2:2:10] cordinates.<br><br>
<p>Here is the picture wich the fdf draw ftom the map.<br>
You can move, zoom and rotate it</p>
<img src="https://github.com/nikGrape/FDF/blob/master/Screen%20Shot%202019-10-05%20at%202.38.08%20PM.png" height="50%" width="50%">
