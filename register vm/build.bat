@echo off

del /Q bin

make 

start cmd /k bin\app