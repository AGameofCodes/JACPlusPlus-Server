#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Channel.o \
	${OBJECTDIR}/Client.o \
	${OBJECTDIR}/Server.o \
	${OBJECTDIR}/exceptions/AlreadyMemberOfChannelException.o \
	${OBJECTDIR}/exceptions/ChatException.o \
	${OBJECTDIR}/exceptions/NotMemberOfChannelException.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/net/Exception.o \
	${OBJECTDIR}/net/IllegalStateException.o \
	${OBJECTDIR}/net/Socket.o \
	${OBJECTDIR}/net/SocketException.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/jacplusplus-server

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/jacplusplus-server: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/jacplusplus-server ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Channel.o: Channel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Channel.o Channel.cpp

${OBJECTDIR}/Client.o: Client.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Client.o Client.cpp

${OBJECTDIR}/Server.o: Server.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Server.o Server.cpp

${OBJECTDIR}/exceptions/AlreadyMemberOfChannelException.o: exceptions/AlreadyMemberOfChannelException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exceptions
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exceptions/AlreadyMemberOfChannelException.o exceptions/AlreadyMemberOfChannelException.cpp

${OBJECTDIR}/exceptions/ChatException.o: exceptions/ChatException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exceptions
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exceptions/ChatException.o exceptions/ChatException.cpp

${OBJECTDIR}/exceptions/NotMemberOfChannelException.o: exceptions/NotMemberOfChannelException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exceptions
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exceptions/NotMemberOfChannelException.o exceptions/NotMemberOfChannelException.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/net/Exception.o: net/Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}/net
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/net/Exception.o net/Exception.cpp

${OBJECTDIR}/net/IllegalStateException.o: net/IllegalStateException.cpp 
	${MKDIR} -p ${OBJECTDIR}/net
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/net/IllegalStateException.o net/IllegalStateException.cpp

${OBJECTDIR}/net/Socket.o: net/Socket.cpp 
	${MKDIR} -p ${OBJECTDIR}/net
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/net/Socket.o net/Socket.cpp

${OBJECTDIR}/net/SocketException.o: net/SocketException.cpp 
	${MKDIR} -p ${OBJECTDIR}/net
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/net/SocketException.o net/SocketException.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/jacplusplus-server

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
