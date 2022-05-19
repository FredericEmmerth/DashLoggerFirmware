#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-pic32mk_gp_db.mk)" "nbproject/Makefile-local-pic32mk_gp_db.mk"
include nbproject/Makefile-local-pic32mk_gp_db.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=pic32mk_gp_db
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/pic32mk_gp_db.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/pic32mk_gp_db.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c ../src/config/pic32mk_gp_db/initialization.c ../src/config/pic32mk_gp_db/interrupts.c ../src/config/pic32mk_gp_db/exceptions.c ../src/main.c ../src/delay.c ../src/crc.c ../src/shortprotocol.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/210254357/plib_clk.o ${OBJECTDIR}/_ext/2071980296/plib_evic.o ${OBJECTDIR}/_ext/2071926468/plib_gpio.o ${OBJECTDIR}/_ext/2071523525/plib_uart3.o ${OBJECTDIR}/_ext/469099581/xc32_monitor.o ${OBJECTDIR}/_ext/1368358199/initialization.o ${OBJECTDIR}/_ext/1368358199/interrupts.o ${OBJECTDIR}/_ext/1368358199/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/delay.o ${OBJECTDIR}/_ext/1360937237/crc.o ${OBJECTDIR}/_ext/1360937237/shortprotocol.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/210254357/plib_clk.o.d ${OBJECTDIR}/_ext/2071980296/plib_evic.o.d ${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d ${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d ${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d ${OBJECTDIR}/_ext/1368358199/initialization.o.d ${OBJECTDIR}/_ext/1368358199/interrupts.o.d ${OBJECTDIR}/_ext/1368358199/exceptions.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/delay.o.d ${OBJECTDIR}/_ext/1360937237/crc.o.d ${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/210254357/plib_clk.o ${OBJECTDIR}/_ext/2071980296/plib_evic.o ${OBJECTDIR}/_ext/2071926468/plib_gpio.o ${OBJECTDIR}/_ext/2071523525/plib_uart3.o ${OBJECTDIR}/_ext/469099581/xc32_monitor.o ${OBJECTDIR}/_ext/1368358199/initialization.o ${OBJECTDIR}/_ext/1368358199/interrupts.o ${OBJECTDIR}/_ext/1368358199/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/delay.o ${OBJECTDIR}/_ext/1360937237/crc.o ${OBJECTDIR}/_ext/1360937237/shortprotocol.o

# Source Files
SOURCEFILES=../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c ../src/config/pic32mk_gp_db/initialization.c ../src/config/pic32mk_gp_db/interrupts.c ../src/config/pic32mk_gp_db/exceptions.c ../src/main.c ../src/delay.c ../src/crc.c ../src/shortprotocol.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-pic32mk_gp_db.mk ${DISTDIR}/pic32mk_gp_db.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MK1024GPE100
MP_LINKER_FILE_OPTION=,--script="..\src\config\pic32mk_gp_db\p32MK1024GPE100.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/210254357/plib_clk.o: ../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c  .generated_files/flags/pic32mk_gp_db/e716ca3038e32b30ae485690414c1f1db317a7d5 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/210254357" 
	@${RM} ${OBJECTDIR}/_ext/210254357/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/210254357/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210254357/plib_clk.o.d" -o ${OBJECTDIR}/_ext/210254357/plib_clk.o ../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071980296/plib_evic.o: ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c  .generated_files/flags/pic32mk_gp_db/e2ad59a728b6c3d8eb801597456e052f6393d6b7 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071980296" 
	@${RM} ${OBJECTDIR}/_ext/2071980296/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071980296/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071980296/plib_evic.o.d" -o ${OBJECTDIR}/_ext/2071980296/plib_evic.o ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071926468/plib_gpio.o: ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c  .generated_files/flags/pic32mk_gp_db/74ba266b65ec5553840e52cdbb76eeb71841d81a .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071926468" 
	@${RM} ${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071926468/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/2071926468/plib_gpio.o ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071523525/plib_uart3.o: ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c  .generated_files/flags/pic32mk_gp_db/4cf327698dae441e977360669780973dca38156e .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071523525" 
	@${RM} ${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071523525/plib_uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d" -o ${OBJECTDIR}/_ext/2071523525/plib_uart3.o ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/469099581/xc32_monitor.o: ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c  .generated_files/flags/pic32mk_gp_db/6ca86e1a22f8badecebb79b61cc33bf5ec221acc .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/469099581" 
	@${RM} ${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/469099581/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/469099581/xc32_monitor.o ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/initialization.o: ../src/config/pic32mk_gp_db/initialization.c  .generated_files/flags/pic32mk_gp_db/a54d9a21abc93c371f5bdeefdb89fb42596b0e6c .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/initialization.o.d" -o ${OBJECTDIR}/_ext/1368358199/initialization.o ../src/config/pic32mk_gp_db/initialization.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/interrupts.o: ../src/config/pic32mk_gp_db/interrupts.c  .generated_files/flags/pic32mk_gp_db/f061545d369ec0ae964790be56cabb23def04cde .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/interrupts.o.d" -o ${OBJECTDIR}/_ext/1368358199/interrupts.o ../src/config/pic32mk_gp_db/interrupts.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/exceptions.o: ../src/config/pic32mk_gp_db/exceptions.c  .generated_files/flags/pic32mk_gp_db/247e195fcf362c5443363b98bfcb73ef93dc69f0 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/exceptions.o.d" -o ${OBJECTDIR}/_ext/1368358199/exceptions.o ../src/config/pic32mk_gp_db/exceptions.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/pic32mk_gp_db/3d1009dcb5e85da70d399674c56faca8c36c5fc2 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/delay.o: ../src/delay.c  .generated_files/flags/pic32mk_gp_db/a13d7ae8928feb5bb4b0b162b168c98e47ba75fb .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/delay.o.d" -o ${OBJECTDIR}/_ext/1360937237/delay.o ../src/delay.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/crc.o: ../src/crc.c  .generated_files/flags/pic32mk_gp_db/6bc271a31cc74165bda00a9969ba82954ba68441 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/crc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/crc.o.d" -o ${OBJECTDIR}/_ext/1360937237/crc.o ../src/crc.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/shortprotocol.o: ../src/shortprotocol.c  .generated_files/flags/pic32mk_gp_db/4a84d03f2a85272a75ae9c11ba0a2df4c81d6203 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shortprotocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d" -o ${OBJECTDIR}/_ext/1360937237/shortprotocol.o ../src/shortprotocol.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/_ext/210254357/plib_clk.o: ../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c  .generated_files/flags/pic32mk_gp_db/ed8791fc939a7c477d09b87ff1696edad8bb5cb5 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/210254357" 
	@${RM} ${OBJECTDIR}/_ext/210254357/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/210254357/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210254357/plib_clk.o.d" -o ${OBJECTDIR}/_ext/210254357/plib_clk.o ../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071980296/plib_evic.o: ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c  .generated_files/flags/pic32mk_gp_db/4aa2f5c1f46fe74976ff7772fb832d5f8b40d17a .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071980296" 
	@${RM} ${OBJECTDIR}/_ext/2071980296/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071980296/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071980296/plib_evic.o.d" -o ${OBJECTDIR}/_ext/2071980296/plib_evic.o ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071926468/plib_gpio.o: ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c  .generated_files/flags/pic32mk_gp_db/314debe86b66ce9a98568a6e2d45c7fdfc416e1d .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071926468" 
	@${RM} ${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071926468/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/2071926468/plib_gpio.o ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071523525/plib_uart3.o: ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c  .generated_files/flags/pic32mk_gp_db/fd84be28570252363ebcbe31b3361cc0bbb4adf3 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071523525" 
	@${RM} ${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071523525/plib_uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d" -o ${OBJECTDIR}/_ext/2071523525/plib_uart3.o ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/469099581/xc32_monitor.o: ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c  .generated_files/flags/pic32mk_gp_db/c5212ad1631b38900ca99541990281ce62979ec5 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/469099581" 
	@${RM} ${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/469099581/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/469099581/xc32_monitor.o ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/initialization.o: ../src/config/pic32mk_gp_db/initialization.c  .generated_files/flags/pic32mk_gp_db/1c6a598e024de8d464851bd0071f7aa9cbc9dd4d .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/initialization.o.d" -o ${OBJECTDIR}/_ext/1368358199/initialization.o ../src/config/pic32mk_gp_db/initialization.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/interrupts.o: ../src/config/pic32mk_gp_db/interrupts.c  .generated_files/flags/pic32mk_gp_db/6a47014dbb3b754f589e55d9a8e4dd2873f7ed99 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/interrupts.o.d" -o ${OBJECTDIR}/_ext/1368358199/interrupts.o ../src/config/pic32mk_gp_db/interrupts.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/exceptions.o: ../src/config/pic32mk_gp_db/exceptions.c  .generated_files/flags/pic32mk_gp_db/93b165c85d7bf60ffbc91482787023820b2f30fb .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/exceptions.o.d" -o ${OBJECTDIR}/_ext/1368358199/exceptions.o ../src/config/pic32mk_gp_db/exceptions.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/pic32mk_gp_db/ef784462a3133a586e7f4e94391c3226d4edd4c1 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/delay.o: ../src/delay.c  .generated_files/flags/pic32mk_gp_db/cadc9a5e206fd153a9071b9bffdadb57d80efa4b .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/delay.o.d" -o ${OBJECTDIR}/_ext/1360937237/delay.o ../src/delay.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/crc.o: ../src/crc.c  .generated_files/flags/pic32mk_gp_db/c12acbfe29844e1d12095354fe68af54068c8e24 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/crc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/crc.o.d" -o ${OBJECTDIR}/_ext/1360937237/crc.o ../src/crc.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/shortprotocol.o: ../src/shortprotocol.c  .generated_files/flags/pic32mk_gp_db/badbf9ee884e282efa5fad42d5cb8f68d1fe8e94 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shortprotocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d" -o ${OBJECTDIR}/_ext/1360937237/shortprotocol.o ../src/shortprotocol.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/pic32mk_gp_db.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/pic32mk_gp_db/p32MK1024GPE100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/pic32mk_gp_db.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x36F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/pic32mk_gp_db.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/pic32mk_gp_db/p32MK1024GPE100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/pic32mk_gp_db.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/pic32mk_gp_db.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
