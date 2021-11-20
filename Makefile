OUT = out/out

compile:
	g++ -I $(CURDIR) -o $(OUT) start.cpp

run: 
	out/out.exe