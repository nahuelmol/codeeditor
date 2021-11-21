## codeeditor

Here I've utilized the GoRc resource compiler http://www.godevtool.com/ResourceFrame.htm directly.

Even some .dll libraries were included for my Makefile script working.

### for .res files adding
First..
```
GoRc /r resou.rc
```

with the resou.res file created, it should be created a resou.obj file as follows

```
cvtres /MACHINE:x86 resou.res
```

Finally, use this obj file in our Makefile for the final compiling

```
OUT = out/out
compile:
	g++ -I $(CURDIR) -o $(OUT) resou.obj start.cpp
```
