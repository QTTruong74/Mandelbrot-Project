# This is the name of the source file that contains the main() function
MAINSRC = mandelbrot.c

# This is a list of names of the source files that each represent a driver of a test suite. Each of them contains
# an individual main() function that drives the test for the corresponding unit.
TESTSRCS = \
	compute_test.c\
	zoom_test.c
# This is a list of all the other source files
OTHERSRCS = \
	compute.c\
	mandelbrot_draw.c\
	zoom.c\
	save_and_restore.c
# Specify optimization options like -O3
OPTIMIZE = -O3

# Specify compiler and code coverage tool based on the operating system
UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
    CC = gcc
    GCOV = gcov
endif

ifeq ($(UNAME), Darwin)
    CC = gcc-14
    GCOV = gcov-14
endif

# Specify additional compile flags
CFLAGS = -fanalyzer $(shell pkg-config --cflags sdl2 SDL2_ttf) --coverage

# Specify additional linker flags
LDFLAGS =

# Specify additional linker libs if needed (e.g., -lm)
LDLIBS = $(shell pkg-config --libs sdl2 SDL2_ttf) -lgcov -lm

####################################################################
# In theory, you don't need to change that much in the following
# section and after the next one, except for fixing bugs or adding
# new features

TARGETRELEASEDIR = build/release
TESTCOVERDIR     = build/coverage

OTHEROBJS = $(OTHERSRCS:.c=.o)

TARGETRELEASEOBJS = $(addprefix $(TARGETRELEASEDIR)/,$(MAINSRC:.c=.o) $(OTHEROBJS))
TARGETRELEASEDEPS = $(TARGETRELEASEOBJS:.o=.d)

TESTCOVEROBJS      = $(addprefix $(TESTCOVERDIR)/,$(TESTSRCS:.c=.o))
TESTCOVEROTHEROBJS = $(addprefix $(TESTCOVERDIR)/,$(OTHEROBJS))
TESTCOVERDEPS      = $(TESTCOVEROBJS:.o=.d) $(TESTCOVEROTHEROBJS:.o=.d)

TARGET            = $(addprefix $(TARGETRELEASEDIR)/,$(MAINSRC:.c=))
TESTCOVERTARGETS  = $(addprefix $(TESTCOVERDIR)/,$(TESTSRCS:.c=))

###########################################################################
# Adapt this section as needed

.PHONY: all
all: $(TARGET) $(TESTCOVERTARGETS)

.PHONY: clean
clean:
	rm -Rf build html latex *.gcov *.txt

.PHONY: test
test: $(TESTCOVERTARGETS)
# This is a tricky one, we have to call each test target individually
# We construct this by using a foreach statement and the shell command
# 'true' that just exists with a return value of 0 meaning success.
	$(foreach T, $(TESTCOVERTARGETS), $(T) && ) true

.PHONY: coverage
coverage: $(TESTCOVERTARGETS) $(TESTCOVEROBJS)
	$(foreach test_app, $(TESTCOVERTARGETS), $(test_app) && ) true
	$(foreach srcfile, $(OTHERSRCS), gcov $(srcfile) -o $(TESTCOVERDIR) && ) true
	$(foreach srcfile, $(OTHERSRCS), mv $(srcfile).gcov $(TESTCOVERDIR) && ) true
	$(foreach test_app, $(TESTCOVERTARGETS), gcovr --html-details  $(test_app) && ) true
	$(foreach test_app, $(TESTCOVERTARGETS), mv $(test_app) $(test_app).html && ) true

.PHONY: doxygen
doxygen: $(MAINSRC) $(OTHERSRCS)
	doxygen
	make -C latex
	cp -af latex/refman.pdf $(TARGET).pdf

###########################################################################
# This section most likely doesn't need to change

COMMONFLAGS=-Wall -Werror -MMD -MP $(CFLAGS) $(OPTIMIZE)

$(TARGETRELEASEDIR):
	mkdir -p $@

$(TARGETRELEASEOBJS): | $(TARGETRELEASEDIR)

$(TARGETRELEASEDIR)/%.o: %.c
	$(CC) -c $(COMMONFLAGS) $< -o $@

$(TARGET): $(TARGETRELEASEOBJS)
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@

-include $(TARGETRELEASEDEPS)

###########################################################################

$(TESTCOVERDIR):
	mkdir -p $@

$(TESTCOVEROBJS) $(TESTCOVEROTHEROBJS): | $(TESTCOVERDIR)

$(TESTCOVERDIR)/%.o: %.c
	$(CC) -c --coverage $(COMMONFLAGS) $< -o $@

$(TESTCOVERDIR)/%: $(TESTCOVERDIR)/%.o $(TESTCOVEROTHEROBJS)
	$(CC) $^ $(LDFLAGS) --coverage $(LDLIBS) -o $@

-include $(TESTCOVERDEPS)

###########################################################################
