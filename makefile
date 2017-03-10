TARGET = CppTest

CC = g++
CPP = g++
INC = -I.
CFLAGS = -O2 -fPIC -fno-omit-frame-pointer -fno-strict-aliasing -rdynamic -Wall -Wno-deprecated -fstack-protector -Wshadow -ffunction-sections -fdata-sections -std=c++0x
DEFS = -DDEBUG_MODE -D_REENTRANT -D_THREAD_SAFE -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64
TOT_DIRS := $(shell find ./ -type d | grep -v ".svn" | sed 1d)
TOT_DIRS += .
TOT_SRCS := $(foreach dir, $(TOT_DIRS), $(wildcard $(dir)/*.cpp))
TOT_SRCS += $(foreach dir, $(TOT_DIRS), $(wildcard $(dir)/*.c))
TOT_OBJS := $(patsubst %.cpp,%.o,$(TOT_SRCS))
TOT_OBJS := $(patsubst %.c,%.o,$(TOT_OBJS))
TOT_DEPS := $(TOT_OBJS:.o=.d)

all: $(TARGET)

$(TARGET) : $(TOT_OBJS)
	@echo "CREATE [$(TARGET)]"
	@$(CC) $(CFLAGS) $(INC) $(DEFS) -o $(TARGET) $(TOT_OBJS)

%.o : %.c
	@echo "Compile $< ==> $@"
	@$(CC) -c $(LOCAL_CFLAGS) -o $@ $<

%.o : %.cpp
	@echo "Compile $< ==> $@"
	@$(CPP) -c $(LOCAL_CFLAGS) -o $@ $<

clean:
	rm -f $(TOT_OBJS) $(TOT_DEPS) $(TOT_DEPS:.d=.d.*) $(TARGET)

ifneq ($(MAKECMDGOALS),clean)
-include $(TOT_DEPS)
endif

%.d : %.c
	@echo "Dependency Reset $< ==> $@"
	@set -e; rm -f $@; \
	$(CC) $(LOCAL_INCPATH_PARAM) -MT '$(objpfx)$*.o' -MM $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.d : %.cpp
	@echo "Dependency Reset $< ==> $@"
	@set -e; rm -f $@; \
	$(CC) $(LOCAL_INCPATH_PARAM) -MT '$(objpfx)$*.o' -MM $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
