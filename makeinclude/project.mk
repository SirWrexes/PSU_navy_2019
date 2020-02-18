##
## EPITECH PROJECT, 2019
## Multipart Makefile
## File description:
## Project/binary name and sources
##

#
# Project and binary name
################################################
NAME := Navy
BIN  := navy
################################################

#
# Libs to include
################################################
LIBS +=
################################################

#
# Custom CFLAGS
################################################
CUSTOM_CFLAGS :=
################################################

#
# Sources
################################################
MAIN := ./src/main.c
# -------------------------------------------- #
# -- Position data
SRC := ./src/positions/pos_open.c
SRC +=
################################################

#
# Test sources
################################################
# -- Position data
TST := ./tests/positions/pos_data_files.c
TST += ./tests/positions/test_pos_open.c
################################################


#
# Files created by unit tests functions
################################################
TESTTMP := *.tmp
TESTTMP +=
################################################
