OUT = out/out

run:
	g++ -I $(CURDIR) -o $(OUT) start.cpp

exe: 
	out/out.exe