#!/bin/sh


rm -f mp4/*.mp4 ; ./kill_process.sh nvrd ;./kill_process.sh nvr; make clean ; make ; ./nvrd
