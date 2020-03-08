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
SRC += ./src/positions/pos_read.c
SRC += ./src/positions/pos_verif_line.c
# -- Map init
SRC += ./src/map/map_init_empty.c
SRC += ./src/map/map_create_from_file.c
SRC += ./src/map/map_create_from_posbuff.c
# -- Input/Output
SRC += ./src/io/navy_err.c
SRC += ./src/io/display_board.c
################################################

#
# Test sources
################################################
# -- Position data
TST := ./tests/positions/pos_data_files.c
TST += ./tests/positions/test_pos_open.c
TST += ./tests/positions/test_pos_read.c
TST += ./tests/positions/test_pos_verif_line.c
# -- Input/Output
################################################


#
# Files created by unit tests functions
################################################
TESTTMP := *.tmp
TESTTMP +=
################################################
