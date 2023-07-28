VERSION := 0.0.1

# Repository
SRC_DIR := src

PARSER_REPO_URL := $(shell git -C $(SRC_DIR) remote get-url origin )

ifeq (, $(capnp))
	capnp := $(shell basename $(PARSER_REPO_URL))
	capnp := $(subst tree-sitter-,,$(capnp))
	capnp := $(subst .git,,$(capnp))
endif

ifeq (, $(PARSER_URL))
	PARSER_URL := $(subst :,/,$(PARSER_REPO_URL))
	PARSER_URL := $(subst git@,https://,$(PARSER_URL))
	PARSER_URL := $(subst .git,,$(PARSER_URL))
endif

CAPNP := $(shell echo $(capnp) | tr a-z A-Z )

# install directory layout
PREFIX ?= /usr/local
INCLUDEDIR ?= $(PREFIX)/include
LIBDIR ?= $(PREFIX)/lib
PCLIBDIR ?= $(LIBDIR)/pkgconfig

# collect C++ sources, and link if necessary
CPPSRC := $(wildcard $(SRC_DIR)/*.cc)

ifeq (, $(CPPSRC))
	ADDITIONALLIBS :=
else
	ADDITIONALLIBS := -lc++
endif

# collect sources
SRC := $(wildcard $(SRC_DIR)/*.c)
SRC += $(CPPSRC)
OBJ := $(addsuffix .o,$(basename $(SRC)))

# ABI versioning
SONAME_MAJOR := 0
SONAME_MINOR := 0

CFLAGS ?= -O3 -Wall -Wextra -I$(SRC_DIR)
CXXFLAGS ?= -O3 -Wall -Wextra -I$(SRC_DIR)
override CFLAGS += -std=gnu99 -fPIC
override CXXFLAGS += -fPIC

# OS-specific bits
ifeq ($(shell uname),Darwin)
	SOEXT = dylib
	SOEXTVER_MAJOR = $(SONAME_MAJOR).dylib
	SOEXTVER = $(SONAME_MAJOR).$(SONAME_MINOR).dylib
	LINKSHARED := $(LINKSHARED)-dynamiclib -Wl,
	ifneq ($(ADDITIONALLIBS),)
	LINKSHARED := $(LINKSHARED)$(ADDITIONALLIBS),
	endif
	LINKSHARED := $(LINKSHARED)-install_name,$(LIBDIR)/libtree-sitter-$(capnp).$(SONAME_MAJOR).dylib,-rpath,@executable_path/../Frameworks
else
	SOEXT = so
	SOEXTVER_MAJOR = so.$(SONAME_MAJOR)
	SOEXTVER = so.$(SONAME_MAJOR).$(SONAME_MINOR)
	LINKSHARED := $(LINKSHARED)-shared -Wl,
	ifneq ($(ADDITIONALLIBS),)
	LINKSHARED := $(LINKSHARED)$(ADDITIONALLIBS)
	endif
	LINKSHARED := $(LINKSHARED)-soname,libtree-sitter-$(capnp).so.$(SONAME_MAJOR)
endif
ifneq (,$(filter $(shell uname),FreeBSD NetBSD DragonFly))
	PCLIBDIR := $(PREFIX)/libdata/pkgconfig
endif

all: libtree-sitter-$(capnp).a libtree-sitter-$(capnp).$(SOEXTVER) bindings/c/$(capnp).h bindings/c/tree-sitter-$(capnp).pc

libtree-sitter-$(capnp).a: $(OBJ)
	$(AR) rcs $@ $^

libtree-sitter-$(capnp).$(SOEXTVER): $(OBJ)
	$(CC) $(LDFLAGS) $(LINKSHARED) $^ $(LDLIBS) -o $@
	ln -sf $@ libtree-sitter-$(capnp).$(SOEXT)
	ln -sf $@ libtree-sitter-$(capnp).$(SOEXTVER_MAJOR)

bindings/c/$(capnp).h:
	sed -e 's|@UPPER_PARSERNAME@|$(CAPNP)|' \
		-e 's|@PARSERNAME@|$(capnp)|' \
		bindings/c/tree-sitter.h.in > $@

bindings/c/tree-sitter-$(capnp).pc:
	sed -e 's|@LIBDIR@|$(LIBDIR)|;s|@INCLUDEDIR@|$(INCLUDEDIR)|;s|@VERSION@|$(VERSION)|' \
		-e 's|=$(PREFIX)|=$${prefix}|' \
		-e 's|@PREFIX@|$(PREFIX)|' \
		-e 's|@ADDITIONALLIBS@|$(ADDITIONALLIBS)|' \
		-e 's|@PARSERNAME@|$(capnp)|' \
		-e 's|@PARSERURL@|$(PARSER_URL)|' \
		bindings/c/tree-sitter.pc.in > $@

install: all
	install -d '$(DESTDIR)$(LIBDIR)'
	install -m755 libtree-sitter-$(capnp).a '$(DESTDIR)$(LIBDIR)'/libtree-sitter-$(capnp).a
	install -m755 libtree-sitter-$(capnp).$(SOEXTVER) '$(DESTDIR)$(LIBDIR)'/libtree-sitter-$(capnp).$(SOEXTVER)
	ln -sf libtree-sitter-$(capnp).$(SOEXTVER) '$(DESTDIR)$(LIBDIR)'/libtree-sitter-$(capnp).$(SOEXTVER_MAJOR)
	ln -sf libtree-sitter-$(capnp).$(SOEXTVER) '$(DESTDIR)$(LIBDIR)'/libtree-sitter-$(capnp).$(SOEXT)
	install -d '$(DESTDIR)$(INCLUDEDIR)'/tree_sitter
	install -m644 bindings/c/$(capnp).h '$(DESTDIR)$(INCLUDEDIR)'/tree_sitter/
	install -d '$(DESTDIR)$(PCLIBDIR)'
	install -m644 bindings/c/tree-sitter-$(capnp).pc '$(DESTDIR)$(PCLIBDIR)'/

clean:
	rm -f $(OBJ) libtree-sitter-$(capnp).a libtree-sitter-$(capnp).$(SOEXT) libtree-sitter-$(capnp).$(SOEXTVER_MAJOR) libtree-sitter-$(capnp).$(SOEXTVER)
	rm -f bindings/c/$(capnp).h bindings/c/tree-sitter-$(capnp).pc

.PHONY: all install clean
