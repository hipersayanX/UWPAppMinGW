COPY = cp -f
MKDIR = mkdir -p
RMDIR = rm -rvf

all: UWPApp.exe

UWPApp.exe: app.o
	g++ -Wl,-subsystem,windows -o $@ $<

app.o: app.cpp
	g++ -c $<

clean:
	- rm app.o UWPApp.exe UWPApp.msix priconfig.xml resources.pri

package:
	./package.bat
