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
SOURCEFILES_QUOTED_IF_SPACED=../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c ../src/config/pic32mk_gp_db/initialization.c ../src/config/pic32mk_gp_db/interrupts.c ../src/config/pic32mk_gp_db/exceptions.c ../src/main.c ../src/delay.c ../src/crc.c ../src/shortprotocol.c ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/210254357/plib_clk.o ${OBJECTDIR}/_ext/2071980296/plib_evic.o ${OBJECTDIR}/_ext/2071926468/plib_gpio.o ${OBJECTDIR}/_ext/469099581/xc32_monitor.o ${OBJECTDIR}/_ext/1368358199/initialization.o ${OBJECTDIR}/_ext/1368358199/interrupts.o ${OBJECTDIR}/_ext/1368358199/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/delay.o ${OBJECTDIR}/_ext/1360937237/crc.o ${OBJECTDIR}/_ext/1360937237/shortprotocol.o ${OBJECTDIR}/_ext/2071523525/plib_uart3.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/210254357/plib_clk.o.d ${OBJECTDIR}/_ext/2071980296/plib_evic.o.d ${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d ${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d ${OBJECTDIR}/_ext/1368358199/initialization.o.d ${OBJECTDIR}/_ext/1368358199/interrupts.o.d ${OBJECTDIR}/_ext/1368358199/exceptions.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/delay.o.d ${OBJECTDIR}/_ext/1360937237/crc.o.d ${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d ${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/210254357/plib_clk.o ${OBJECTDIR}/_ext/2071980296/plib_evic.o ${OBJECTDIR}/_ext/2071926468/plib_gpio.o ${OBJECTDIR}/_ext/469099581/xc32_monitor.o ${OBJECTDIR}/_ext/1368358199/initialization.o ${OBJECTDIR}/_ext/1368358199/interrupts.o ${OBJECTDIR}/_ext/1368358199/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/delay.o ${OBJECTDIR}/_ext/1360937237/crc.o ${OBJECTDIR}/_ext/1360937237/shortprotocol.o ${OBJECTDIR}/_ext/2071523525/plib_uart3.o

# Source Files
SOURCEFILES=../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c ../src/config/pic32mk_gp_db/initialization.c ../src/config/pic32mk_gp_db/interrupts.c ../src/config/pic32mk_gp_db/exceptions.c ../src/main.c ../src/delay.c ../src/crc.c ../src/shortprotocol.c ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c



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
${OBJECTDIR}/_ext/210254357/plib_clk.o: ../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c  .generated_files/flags/pic32mk_gp_db/739422b6071cc45ca3cc0ef75b8c5f57c857df7c .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/210254357" 
	@${RM} ${OBJECTDIR}/_ext/210254357/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/210254357/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210254357/plib_clk.o.d" -o ${OBJECTDIR}/_ext/210254357/plib_clk.o ../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071980296/plib_evic.o: ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c  .generated_files/flags/pic32mk_gp_db/d703d2d41aca8a41b80ca348584afb1e0ae96d14 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071980296" 
	@${RM} ${OBJECTDIR}/_ext/2071980296/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071980296/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071980296/plib_evic.o.d" -o ${OBJECTDIR}/_ext/2071980296/plib_evic.o ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071926468/plib_gpio.o: ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c  .generated_files/flags/pic32mk_gp_db/e57ec3cc444edbe01db75b9af5d7ec01751c258e .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071926468" 
	@${RM} ${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071926468/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/2071926468/plib_gpio.o ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/469099581/xc32_monitor.o: ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c  .generated_files/flags/pic32mk_gp_db/fbd46923053e3fdd161f10638075047f1956ccc5 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/469099581" 
	@${RM} ${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/469099581/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/469099581/xc32_monitor.o ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/initialization.o: ../src/config/pic32mk_gp_db/initialization.c  .generated_files/flags/pic32mk_gp_db/a60c370d9fff6c4882c423caf69f04e933f2c6a .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/initialization.o.d" -o ${OBJECTDIR}/_ext/1368358199/initialization.o ../src/config/pic32mk_gp_db/initialization.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/interrupts.o: ../src/config/pic32mk_gp_db/interrupts.c  .generated_files/flags/pic32mk_gp_db/6742d9e02dc39d104ff9aa5b4d9ca9d2f90253ce .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/interrupts.o.d" -o ${OBJECTDIR}/_ext/1368358199/interrupts.o ../src/config/pic32mk_gp_db/interrupts.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/exceptions.o: ../src/config/pic32mk_gp_db/exceptions.c  .generated_files/flags/pic32mk_gp_db/62f65a93686c51f370308590d12744d76ef81982 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/exceptions.o.d" -o ${OBJECTDIR}/_ext/1368358199/exceptions.o ../src/config/pic32mk_gp_db/exceptions.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/pic32mk_gp_db/16a3b40e94e6e5ccb71b5ca27bb4ba00937757ce .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/delay.o: ../src/delay.c  .generated_files/flags/pic32mk_gp_db/545e67a4e1252619fb37cba5284c9c30a8f2e8d9 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/delay.o.d" -o ${OBJECTDIR}/_ext/1360937237/delay.o ../src/delay.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/crc.o: ../src/crc.c  .generated_files/flags/pic32mk_gp_db/871a4d19066bef2bb9a09e474e8ae103ec7a5057 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/crc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/crc.o.d" -o ${OBJECTDIR}/_ext/1360937237/crc.o ../src/crc.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/shortprotocol.o: ../src/shortprotocol.c  .generated_files/flags/pic32mk_gp_db/8e45813f7778cc2a8563948549b0e70590bdc504 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shortprotocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d" -o ${OBJECTDIR}/_ext/1360937237/shortprotocol.o ../src/shortprotocol.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071523525/plib_uart3.o: ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c  .generated_files/flags/pic32mk_gp_db/536f20e507560fcb0be2a4092cd1cea18b5bbdea .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071523525" 
	@${RM} ${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071523525/plib_uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d" -o ${OBJECTDIR}/_ext/2071523525/plib_uart3.o ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/_ext/210254357/plib_clk.o: ../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c  .generated_files/flags/pic32mk_gp_db/9630cc12b97c8e5189631373d9d8f368c9c66a9c .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/210254357" 
	@${RM} ${OBJECTDIR}/_ext/210254357/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/210254357/plib_clk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210254357/plib_clk.o.d" -o ${OBJECTDIR}/_ext/210254357/plib_clk.o ../src/config/pic32mk_gp_db/peripheral/clk/plib_clk.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071980296/plib_evic.o: ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c  .generated_files/flags/pic32mk_gp_db/7ed89ed252931cd367d92c5e1691e09a817ee1bc .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071980296" 
	@${RM} ${OBJECTDIR}/_ext/2071980296/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071980296/plib_evic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071980296/plib_evic.o.d" -o ${OBJECTDIR}/_ext/2071980296/plib_evic.o ../src/config/pic32mk_gp_db/peripheral/evic/plib_evic.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071926468/plib_gpio.o: ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c  .generated_files/flags/pic32mk_gp_db/a5c678e66e01b10c439fff7a15f815b3a3bb4295 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071926468" 
	@${RM} ${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071926468/plib_gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071926468/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/2071926468/plib_gpio.o ../src/config/pic32mk_gp_db/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/469099581/xc32_monitor.o: ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c  .generated_files/flags/pic32mk_gp_db/df48ac4f4ee6eb02296cca9cb161693974531f7b .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/469099581" 
	@${RM} ${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/469099581/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/469099581/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/469099581/xc32_monitor.o ../src/config/pic32mk_gp_db/stdio/xc32_monitor.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/initialization.o: ../src/config/pic32mk_gp_db/initialization.c  .generated_files/flags/pic32mk_gp_db/d56c73d2968480b2f1d2cfc4113f29c12c230ef7 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/initialization.o.d" -o ${OBJECTDIR}/_ext/1368358199/initialization.o ../src/config/pic32mk_gp_db/initialization.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/interrupts.o: ../src/config/pic32mk_gp_db/interrupts.c  .generated_files/flags/pic32mk_gp_db/dc59c94ef7de0f844b8ad412f785e7b16f6ef2f7 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/interrupts.o.d" -o ${OBJECTDIR}/_ext/1368358199/interrupts.o ../src/config/pic32mk_gp_db/interrupts.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1368358199/exceptions.o: ../src/config/pic32mk_gp_db/exceptions.c  .generated_files/flags/pic32mk_gp_db/de7101653c5dfa7b6f938a19e3e87c627e42a0ed .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1368358199" 
	@${RM} ${OBJECTDIR}/_ext/1368358199/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1368358199/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1368358199/exceptions.o.d" -o ${OBJECTDIR}/_ext/1368358199/exceptions.o ../src/config/pic32mk_gp_db/exceptions.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/pic32mk_gp_db/ca9e903346561705fb4bf31332be7bd4db8d2526 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/delay.o: ../src/delay.c  .generated_files/flags/pic32mk_gp_db/3da20a52ce957bd3663ec22409f38d0b7aa70d49 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/delay.o.d" -o ${OBJECTDIR}/_ext/1360937237/delay.o ../src/delay.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/crc.o: ../src/crc.c  .generated_files/flags/pic32mk_gp_db/ba02b2b7d1eb0b6b607e04d795e938ba6d90db80 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/crc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/crc.o.d" -o ${OBJECTDIR}/_ext/1360937237/crc.o ../src/crc.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/shortprotocol.o: ../src/shortprotocol.c  .generated_files/flags/pic32mk_gp_db/8c2d356e0ca2ad485c13367beb606009ec9e250e .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shortprotocol.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/shortprotocol.o.d" -o ${OBJECTDIR}/_ext/1360937237/shortprotocol.o ../src/shortprotocol.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/2071523525/plib_uart3.o: ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c  .generated_files/flags/pic32mk_gp_db/bbcdc4ed1a009c0033523d2c44683f82e7af0ba1 .generated_files/flags/pic32mk_gp_db/27b433b3cb799db635785ac5cf3e18bf8dea64a1
	@${MKDIR} "${OBJECTDIR}/_ext/2071523525" 
	@${RM} ${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d 
	@${RM} ${OBJECTDIR}/_ext/2071523525/plib_uart3.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -I"../src" -I"../src/config/pic32mk_gp_db" -I"../src/packs/PIC32MK1024GPE100_DFP" -Werror -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2071523525/plib_uart3.o.d" -o ${OBJECTDIR}/_ext/2071523525/plib_uart3.o ../src/config/pic32mk_gp_db/peripheral/uart/plib_uart3.c    -DXPRJ_pic32mk_gp_db=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
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
