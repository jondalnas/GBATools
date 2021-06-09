SOURCES = src/main.cpp src/Color.cpp
INCDIR = lib
OBJECTS = ${patsubst src/%, obj/%, $(SOURCES:.cpp=.o)}
DEPEND  = ${patsubst src/%, obj/%, $(SOURCES:.cpp=.d)}

CPPFLAGS = -Wall

a.out: $(OBJECTS) $(DEPEND)
	$(CXX) -I $(INCDIR) $(CPPFLAGS) $(OBJECTS) -o $@ $(LIBS)

obj/%.o: src/%.cpp
	$(CXX) -c $^ -I $(INCDIR) $(CPPFLAGS) -o $@

obj/%.d: src/%.cpp
	@set -e
	rm -f $@
	$(CXX) -MM -I $(INCDIR) $(CPPFLAGS) $< > $@.tmp
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@
	rm -f $@.tmp

include $(DEPEND)

clean:
	rm -f obj/*
	rm -f a.out