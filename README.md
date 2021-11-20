## codeeditor

Here I've utilized the GoRc resource compiler http://www.godevtool.com/ResourceFrame.htm directly.

Even some .dll libraries were included for my Makefile script working.

## for .res files creation
```
GoRc /r resou.rc
```

with the .res file created, it should be created an obj file

```
cvtres /MACHINE:x86 resou.res
```

Finally, utilize the obj file in our Makefile for the final compiling

```
OUT = out/out
compile:
	g++ -I $(CURDIR) -o $(OUT) resou.obj start.cpp
```