# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := clogger
DEFS_Debug := \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-fPIC \
	-Wall \
	-pthread \
	-m64 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions

INCS_Debug := \
	-I/root/.node-gyp/0.6.12/src \
	-I/root/.node-gyp/0.6.12/deps/uv/include \
	-I/root/.node-gyp/0.6.12/deps/v8/include

DEFS_Release := \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION'

# Flags passed to all source files.
CFLAGS_Release := \
	-fPIC \
	-Wall \
	-pthread \
	-m64 \
	-O3 \
	-fdata-sections \
	-ffunction-sections \
	-fno-strict-aliasing

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions

INCS_Release := \
	-I/root/.node-gyp/0.6.12/src \
	-I/root/.node-gyp/0.6.12/deps/uv/include \
	-I/root/.node-gyp/0.6.12/deps/v8/include

OBJS := \
	$(obj).target/$(TARGET)/clogger.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-m64 \
	-rdynamic

LDFLAGS_Release := \
	-pthread \
	-m64 \
	-rdynamic

LIBS :=

$(obj).target/clogger.node: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/clogger.node: LIBS := $(LIBS)
$(obj).target/clogger.node: TOOLSET := $(TOOLSET)
$(obj).target/clogger.node: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,solink_module)

all_deps += $(obj).target/clogger.node
# Add target alias
.PHONY: clogger
clogger: $(builddir)/clogger.node

# Copy this to the executable output path.
$(builddir)/clogger.node: TOOLSET := $(TOOLSET)
$(builddir)/clogger.node: $(obj).target/clogger.node FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/clogger.node
# Short alias for building this executable.
.PHONY: clogger.node
clogger.node: $(obj).target/clogger.node $(builddir)/clogger.node

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/clogger.node

