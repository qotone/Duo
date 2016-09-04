# define a symbol MAKE_OS for the current operating system
# WINSOWS | LINUX | OSX

ifeq ($(OS),Windows_NT)
    MAKE_OS = WINDOWS
    ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
        CPU=AMD64
    endif
    ifeq ($(PROCESSOR_ARCHITECTURE),x86)
        CPU=IA32
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        MAKE_OS=LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        MAKE_OS=OSX
    endif
endif

CRC = crc32
XXD = xxd

crc32_path := $(shell which $(CRC))
ifeq ("$(crc32_path)", "")
    $(error "$(CRC) tool is not found")
endif

# Define the compiler/tools prefix
ARM_GCC_PATH = D:/GCC/bin
GCC_PREFIX = $(ARM_GCC_PATH)/arm-none-eabi-


# Define tools
CC = $(GCC_PREFIX)gcc
CPP = $(GCC_PREFIX)g++
AR = $(GCC_PREFIX)ar
AS = $(GCC_PREFIX)as
OBJCOPY = $(GCC_PREFIX)objcopy
SIZE = $(GCC_PREFIX)size

RM = rm -f
MKDIR = mkdir -p

# Recursive wildcard function
rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Define the build path, this is where all of the dependancies and
# object files will be placed.
# Note: Currently set to <project>/build/obj directory and set relative to
# the dir which makefile is invoked. If the makefile is moved to the project
# root, BUILD_PATH = build can be used to store the build products in
# the build directory.
BUILD_PATH = build

# Path to the root of source files, in this case root of the project to
# inclue ../src and ../lib dirs.
# Note: Consider relocating source files in lib to src, or build a
#       seperate library.
SRC_PATH = .


# Target this makefile is building.
TARGET = Demo

# Find all build.mk makefiles in each source directory in the src tree.
SRC_MAKEFILES := $(call rwildcard,$(SRC_PATH)/,build.mk)

# Include all build.mk defines source files.
include $(SRC_MAKEFILES)

# Paths to dependant projects, referenced from root of this project

#LIB_CORE_COMMON_PATH = ../core-common-lib
#LIB_CORE_COMMUNICATION_PATH = ../core-communication-lib

CORE_PATH = ../0.2.10/cores/RedBear_Duo

# Additional include directories, applied to objects built for this target.

INCLUDE_DIRS += $(CORE_PATH)/CMSIS/CMSIS/Include
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/A_user/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/E_rt-dynalib/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/F_wiring/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/H_platform/shared/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/H_platform/MCU/shared/STM32/inc
 INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/H_platform/MCU/STM32F2xx/STM32_StdPeriph_Driver/inc
 INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/H_platform/MCU/STM32F2xx/SPARK_Firmware_Driver/inc
 INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/H_platform/MCU/STM32F2xx/STM32_USB_Device_Driver/inc
 INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/H_platform/MCU/STM32F2xx/STM32_USB_OTG_Driver/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/H_platform/MCU/STM32F2xx/CMSIS/Device/ST/Include
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/I_modules/duo/user-part/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/I_modules/shared/stm32f2xx/inc

INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_define
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/shared
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/src/stm32f2xx
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/src/stm32
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/src/duo
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/src/duo/include 
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/src/duo/libraries/btstack/port
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/src/duo/libraries/btstack/src
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/src/duo/libraries/btstack/src/ble
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_hal/src/duo/libraries/btstack/src/classic
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_services/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_system/inc
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_communication/src
INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_lib
INCLUDE_DIRS += ../0.2.10/system/CMSIS/CMSIS/Include
INCLUDE_DIRS += $(CORE_PATH)

#INCLUDE_DIRS += $(CORE_PATH)/redbear_sdk/X_dynalib/inc

# Compiler flags
CFLAGS =  -g3 -gdwarf-2 -Os -mcpu=cortex-m3 -mthumb
# * <-------------------参照Arduino添加的部分
CFLAGS += -w -std=gnu99 -fno-common -fno-exceptions -fno-builtin-malloc -fno-builtin-free -fno-builtin-realloc -fdata-sections -fomit-frame-pointer -nostdlib --param max-inline-insns-single=500 -fno-exceptions -fno-rtti
CFLAGS += -DSTM32_DEVICE -DSTM32F2XX -DPLATFORM_THREADING=1 -DPLATFORM_ID=88 -DPLATFORM_NAME=duo -DUSBD_VID_SPARK=0x2B04 -DUSBD_PID_DFU=0xD058 -DUSBD_PID_CDC=0xC058 
CFLAGS += -DSTART_DFU_FLASHER_SERIAL_SPEED=14400 -DSTART_YMODEM_FLASHER_SERIAL_SPEED=28800 -DSTART_AVRDUDE_FLASHER_SERIAL_SPEED=19200
CFLAGS += -DRELEASE_BUILD -DINCLUDE_PLATFORM=1 -DUSE_STDPERIPH_DRIVER -DDFU_BUILD_ENABLE
CFLAGS += -DUSER_FIRMWARE_IMAGE_SIZE=0x40000 -DUSER_FIRMWARE_IMAGE_LOCATION=0x80C0000
CFLAGS += -DSYSTEM_VERSION_STRING=0.2.4
CFLAGS += -DMODULAR_FIRMWARE=1 -DMODULE_FUNCTION=5 -DMODULE_INDEX=1 -DMODULE_VERSION=7 -DMODULE_DEPENDENCY=4,2,7
CFLAGS += -DF_CPU=120000000 -DARDUINO=10611
# * ------------------------------------------------>
CFLAGS += $(patsubst %,-I$(SRC_PATH)/%,$(INCLUDE_DIRS)) -I.
CFLAGS += -ffunction-sections -Wall -Werror -fmessage-length=0

# Generate dependancy files automatically.
CFLAGS += -MD -MP -MF $@.d



# C++ specific flags
#CPPFLAGS = -fno-exceptions -fno-rtti
CPPFLAGS =  -g3 -gdwarf-2 -Os -mcpu=cortex-m3 -mthumb
# * <-------------------参照Arduino添加的部分
CPPFLAGS += -w -std=gnu++11 -fno-common -fno-exceptions -fno-builtin-malloc -fno-builtin-free -fno-builtin-realloc -fdata-sections -fomit-frame-pointer -nostdlib --param max-inline-insns-single=500 -fno-exceptions -fno-rtti
CPPFLAGS += -DSTM32_DEVICE -DSTM32F2XX -DPLATFORM_THREADING=1 -DPLATFORM_ID=88 -DPLATFORM_NAME=duo -DUSBD_VID_SPARK=0x2B04 -DUSBD_PID_DFU=0xD058 -DUSBD_PID_CDC=0xC058 
CPPFLAGS += -DSTART_DFU_FLASHER_SERIAL_SPEED=14400 -DSTART_YMODEM_FLASHER_SERIAL_SPEED=28800 -DSTART_AVRDUDE_FLASHER_SERIAL_SPEED=19200
CPPFLAGS += -DRELEASE_BUILD -DINCLUDE_PLATFORM=1 -DUSE_STDPERIPH_DRIVER -DDFU_BUILD_ENABLE
CPPFLAGS += -DUSER_FIRMWARE_IMAGE_SIZE=0x40000 -DUSER_FIRMWARE_IMAGE_LOCATION=0x80C0000
CPPFLAGS += -DSYSTEM_VERSION_STRING=0.2.4
CPPFLAGS += -DMODULAR_FIRMWARE=1 -DMODULE_FUNCTION=5 -DMODULE_INDEX=1 -DMODULE_VERSION=7 -DMODULE_DEPENDENCY=4,2,7
CPPFLAGS += -DF_CPU=120000000 -DARDUINO=10611
# * ------------------------------------------------>
CPPFLAGS += $(patsubst %,-I$(SRC_PATH)/%,$(INCLUDE_DIRS)) -I.
CPPFLAGS += -ffunction-sections -Wall -Werror -fmessage-length=0
CPPFLAGS += -MD -MP -MF $@.d

# combin  flags
COMBINFLAGS = -DSTM32_DEVICE -DSTM32F2XX -DPLATFORM_THREADING=1 -DPLATFORM_ID=88 -DPLATFORM_NAME=duo -DUSBD_VID_SPARK=0x2B04 -DUSBD_PID_DFU=0xD058 -DUSBD_PID_CDC=0xC058  
COMBINFLAGS += -g3 -gdwarf-2 -Os -mcpu=cortex-m3 -mthumb -fno-builtin
COMBINFLAGS += -DRELEASE_BUILD -DINCLUDE_PLATFORM=1 -DUSE_STDPERIPH_DRIVER -DDFU_BUILD_ENABLE
COMBINFLAGS += -DSYSTEM_VERSION_STRING=0.2.4 -Werror
COMBINFLAGS += $(patsubst %,-I$(SRC_PATH)/%,$(INCLUDE_DIRS)) -I.
COMBINFLAGS += -MD -MP -MF $@.d
COMBINFLAGS += -ffunction-sections -fdata-sections -Wall -Wno-switch -Wno-error=deprecated-declarations -fmessage-length=0 -fno-strict-aliasing -DSPARK=1 
COMBINFLAGS += -DSTART_DFU_FLASHER_SERIAL_SPEED=14400 -DSTART_YMODEM_FLASHER_SERIAL_SPEED=28800 -DSTART_AVRDUDE_FLASHER_SERIAL_SPEED=19200
COMBINFLAGS += -fno-builtin-malloc -fno-builtin-free -fno-builtin-realloc
COMBINFLAGS += -DUSER_FIRMWARE_IMAGE_SIZE=0x40000 -DUSER_FIRMWARE_IMAGE_LOCATION=0x80C0000
COMBINFLAGS += -DMODULAR_FIRMWARE=1 -DMODULE_FUNCTION=5 -DMODULE_INDEX=1 -DMODULE_VERSION=7 -DMODULE_DEPENDENCY=4,2,7

ARFLAGS = rcs

# Linker flags
LDSCRIPT = ../0.2.10/variants/RedBear_Duo/linker_scripts/gcc/duo/user-part/linker.ld
LDFLAGS = -Wl,--whole-archive $(CORE_PATH)/redbear_sdk/X_lib/STM32F2xx_Peripheral_Libraries.a 
LDFLAGS += -Wl,--no-whole-archive -nostartfiles -Xlinker --gc-sections 
LDFLAGS += -L../0.2.10/variants/RedBear_Duo/linker_scripts/linker
LDFLAGS += -L../0.2.10/variants/RedBear_Duo/linker_scripts/linker/stm32f2xx
LDFLAGS += -L$(CORE_PATH)/redbear_sdk/X_lib
LDFLAGS += -Wl,--whole-archive -lcore -lhal-dynalib -lservices-dynalib -lsystem-dynalib -lrt-dynalib -lwiring -lcommunication-dynalib -lplatform -lwiring_globals -Wl,--no-whole-archive -lnosys
LDFLAGS += -L../0.2.10/variants/RedBear_Duo/linker_scripts/gcc/duo/system-part1
LDFLAGS += -L../0.2.10/variants/RedBear_Duo/linker_scripts/gcc/duo/system-part2
LDFLAGS += -L../0.2.10/variants/RedBear_Duo/linker_scripts/gcc/duo/user-part 
LDFLAGS += -L../0.2.10/variants/RedBear_Duo/linker_scripts/gcc/shared/stm32f2xx
LDFLAGS += -L. -T$(LDSCRIPT) 
LDFLAGS += -Wl,--defsym,USER_FIRMWARE_IMAGE_SIZE=0x40000 -Wl,--defsym,USER_FIRMWARE_IMAGE_LOCATION=0x80C0000 -Wl,-Map,$(BUILD_PATH)/${TARGET}.map -lstdc++_nano -lm -Wl,--start-group -lgcc -lg_nano -lc_nano -Wl,--end-group -Wl,--start-group -lgcc -lc_nano -Wl,--end-group
LDFLAGS += -L$(CORE_PATH)/redbear_sdk/I_modules/duo/user-part/src



# Assember flags
#ASFLAGS =  -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb
#ASFLAGS += -x assembler-with-cpp -fmessage-length=0
ASFLAGS = -g -x assembler-with-cpp -mthumb

# Collect all object and dep files
ALLOBJ += $(addprefix $(BUILD_PATH)/, $(CSRC:.c=.o))
ALLOBJ += $(addprefix $(BUILD_PATH)/, $(CPPSRC:.cpp=.o))
ALLOBJ += $(addprefix $(BUILD_PATH)/, $(ASRC:.s=.o))

ALLDEPS += $(addprefix $(BUILD_PATH)/, $(CSRC:.c=.o.d))
ALLDEPS += $(addprefix $(BUILD_PATH)/, $(CPPSRC:.cpp=.o.d))
ALLDEPS += $(addprefix $(BUILD_PATH)/, $(ASRC:.s=.o.d))






# All Target
all: elf bin hex size

elf: $(TARGET).elf
bin: $(TARGET).bin
hex: $(TARGET).hex

# Display size
size: $(TARGET).elf 
	@echo Invoking: ARM GNU Print Size
	$(SIZE) --format=berkeley $<
	@echo

# Create a hex file from ELF file
%.hex : %.elf
	@echo Invoking: ARM GNU Create Flash Image
	$(OBJCOPY) -O ihex $< $@
	@echo

	
	
# generated by running xxd -p crc_block
CRC_LEN = 4
CRC_BLOCK_LEN = 38
DEFAULT_SHA_256 = 0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
MOD_INFO_SUFFIX_LEN ?= 2800
MOD_INFO_SUFFIX = $(DEFAULT_SHA_256)$(MOD_INFO_SUFFIX_LEN)
CRC_BLOCK_CONTENTS = $(MOD_INFO_SUFFIX)78563412

# OS X + debian systems have shasum, RHEL + windows have sha256sum
SHASUM_COMMAND_VERSION := $(shell shasum --version 2>/dev/null)
SHA256SUM_COMMAND_VERSION := $(shell sha256sum --version 2>/dev/null)
ifdef SHASUM_COMMAND_VERSION
SHA_256 = shasum -a 256
else ifdef SHA256SUM_COMMAND_VERSION
SHA_256 = sha256sum
else ifeq (WINDOWS,$(MAKE_OS))
SHA_256 = ../bin/win32/sha256sum
endif

ifeq (WINDOWS,$(MAKE_OS))
filesize=`stat --print %s $1`
else
ifeq (LINUX, $(MAKE_OS))
filesize=`stat -c %s $1`
else
filesize=`stat -f%z $1`
endif
endif

# Create a bin file from ELF file
# %.bin : %.elf
	# @echo Invoking: ARM GNU Create Flash Image
	# $(OBJCOPY) -O binary $< $@
	# @echo
%.bin : %.elf
	@echo Invoking: ARM GNU Create Flash Image
	$(OBJCOPY) -O binary $< $@.pre_crc
	if [ -s $@.pre_crc ]; then \
	head -c $$(($(call filesize,$@.pre_crc) - $(CRC_BLOCK_LEN))) $@.pre_crc > $@.no_crc && \
	tail -c $(CRC_BLOCK_LEN) $@.pre_crc > $@.crc_block && \
	test "$(CRC_BLOCK_CONTENTS)" = `xxd -p -c 500 $@.crc_block` && \
	$(SHA_256) $@.no_crc | cut -c 1-65 | $(XXD) -r -p | dd bs=1 of=$@.pre_crc seek=$$(($(call filesize,$@.pre_crc) - $(CRC_BLOCK_LEN))) conv=notrunc  && \
	head -c $$(($(call filesize,$@.pre_crc) - $(CRC_LEN))) $@.pre_crc > $@.no_crc && \
	 $(CRC) $@.no_crc | cut -c 1-10 | $(XXD) -r -p | dd bs=1 of=$@.pre_crc seek=$$(($(call filesize,$@.pre_crc) - $(CRC_LEN))) conv=notrunc ;\
	fi
	[ ! -f $@ ] || rm $@
	mv $@.pre_crc $@
	@echo
#check_external_deps
$(TARGET).elf : check_external_deps $(ALLOBJ) 
	@echo Building target: $@
	@echo Invoking: ARM GCC  Linker
	$(CPP) $(COMBINFLAGS) $(ALLOBJ) --output $@ $(LDFLAGS)
	@echo

# Check for external dependancies are up to date
# Note: Since this makefile has no knowledge of depenancies for
#       the external libs, make must be called on the libs for
#       every build. Targets which depend directly on this recipie
#       will then always be rebuilt, ie. $(TARGET).elf
check_external_deps:
	@echo Building libcore.a
	@$(MAKE) -C $(CORE_PATH)/redbear_sdk/I_modules/duo/user-part/src
#	cp $(CORE_PATH)/redbear_sdk/I_modules/duo/user-part/src/libcore.a $(BUILD_PATH)/ 
	@echo



# Tool invocations

# C compiler to build .o from .c in $(BUILD_DIR)
$(BUILD_PATH)/%.o : $(SRC_PATH)/%.c
	@echo Building file: $<
	@echo Invoking: ARM GCC C Compiler
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo

# Assember to build .o from .S in $(BUILD_DIR)
$(BUILD_PATH)/%.o : $(SRC_PATH)/%.S
	@echo Building file: $<
	@echo Invoking: ARM GCC Assember
	$(MKDIR) $(dir $@)
	$(AS) $(ASFLAGS) -c -o $@ $<
	@echo

# CPP compiler to build .o from .cpp in $(BUILD_DIR)
# Note: Calls standard $(CC) - gcc will invoke g++ as appropriate
$(BUILD_PATH)/%.o : $(SRC_PATH)/%.cpp
	@echo Building file: $<
	@echo Invoking: ARM GCC CPP Compiler
	$(MKDIR) $(dir $@)
	$(CPP) $(CPPFLAGS) -c -o $@ $<
	@echo

# Other Targets
clean:
	$(RM) $(ALLOBJ) $(ALLDEPS) $(TARGET).elf $(TARGET).bin $(TARGET).hex $(BUILD_PATH)/$(TARGET).map
	@echo
	@echo Clean libcore.a
# Should clean invoke clean on the dependant libs as well? Sure..
	@$(MAKE) -C $(CORE_PATH)/redbear_sdk/I_modules/duo/user-part/src clean --no-print-directory


.PHONY: all clean check_external_deps elf bin hex size
.SECONDARY:

# Include auto generated dependancy files
-include $(ALLDEPS)

