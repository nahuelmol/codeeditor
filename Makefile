OUT = out/out

rs:
	GoRc /r resou.rc
	cvtres /MACHINE:x86 resou.res

compile:
	g++ -I $(CURDIR) -o $(OUT) resou.obj start.cpp

run: 
	out/out.exe
