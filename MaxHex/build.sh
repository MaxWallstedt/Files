#!/bin/bash

AS="nasm"
CC="gcc"
LD="gcc"

AFLAGS="-f elf64"
#CFLAGS="-Wall -O3"
CFLAGS="-Wall -g"
LDFLAGS="-lncursesw"

SRCDIR="src"
OBJDIR="obj"
BINDIR="bin"

SOURCES=(
	main.c
	check_args.c
	help_version.asm
	check_file_changes.c
	screen_functions.c
	exec_command.c
	globl.c
	release_allocs.c
	streq.asm
	strlenM.asm
	str_to_int.c
	to_lower.c
	)

TARGET="MaxHex"

# Validate source files
for srcfile in ${SOURCES[@]}
do
	if [ ! -f $SRCDIR/$srcfile ]
	then
		echo "File $SRCDIR/$srcfile does not exist"
		exit 1
	fi
done

if [ ! -d $OBJDIR ]
then
	echo "MKDIR $OBJDIR"
	mkdir $OBJDIR
fi

CHANGES=false

for srcfile in ${SOURCES[@]}
do
	if [ -f $OBJDIR/${srcfile/%.*/.o} ]
	then
		OBJDATE=`stat -c %Y $OBJDIR/${srcfile/%.*/.o}`
		SRCDATE=`stat -c %Y $SRCDIR/$srcfile`

		if [ $OBJDATE -lt $SRCDATE ]
		then
			COMPILE=true
			CHANGES=true
		else
			COMPILE=false
		fi
	else
		COMPILE=true
		CHANGES=true
	fi

	if [ $COMPILE = true ]
	then
		if [ "${srcfile##*.}" = "asm" ]
		then
			echo "AS $SRCDIR/$srcfile"
			$AS $AFLAGS -o $OBJDIR/${srcfile/%.*/.o} $SRCDIR/$srcfile
		else
			echo "CC $SRCDIR/$srcfile"
			$CC -c $CFLAGS -o $OBJDIR/${srcfile/%.*/.o} $SRCDIR/$srcfile
		fi

		if [ $? -ne 0 ]
		then
			exit 1
		fi
	fi
done

if [ ! -d $BINDIR ]
then
	echo "MKDIR $BINDIR"
	mkdir $BINDIR
fi

if [ $CHANGES = true -o ! -f $BINDIR/$TARGET ]
then
	# Prepend every element in array SOURCES with object directory
	SOURCES=( ${SOURCES[@]/#/$OBJDIR/} )

	# Change ".*" to ".o" for every element in array SOURCES
	SOURCES=( ${SOURCES[@]/%.*/.o} )

	echo "LD ${SOURCES[@]}"
	$LD $CFLAGS -o $BINDIR/$TARGET ${SOURCES[@]} $LDFLAGS

	if [ $? -ne 0 ]
	then
		exit 1
	else
		echo "Output located at $BINDIR/$TARGET"
	fi
else
	echo "Nothing to do"
fi
