obj = game.o food.o rules.o snake.o window.o
CXX = g++
CPPFLAGS = -std=c++11 -Wall

game.exe : $(obj)
	$(CXX) $(CPPFLAGS) -o game.exe $(obj)
	make clean

$(obj):

.PHONY : clean
clean:
	-rm $(obj)
