#!/bin/sh

gcc main.cpp -o vulk `sdl2-config --libs` -lvulkan

#-L/usr/lib/x86_64-linux-gnu -lvulkan
