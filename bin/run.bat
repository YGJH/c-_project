@echo off
set /a num=1
:loop
    echo %num%
    python3 gen.py
    test.exe < input > wa
    a.exe < input > ac
    fc ac wa
    set /a num=num+1
if not errorlevel 1 goto loop