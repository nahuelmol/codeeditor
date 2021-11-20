OUT = out/out

compile:
	g++ -I $(CURDIR) -o $(OUT) resou.obj start.cpp

run: 
	out/out.exe
