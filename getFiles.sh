#!/bin/bash
NUM_EM=16000
for name in `seq 8000`
do
    ((NUM_EM++))
	wget "http://195.128.78.52/${name}_150106_160106.txt?market=25&em=${NUM_EM}&df=6&mf=0&yf=2015&from=06.01.2015&dt=6&mt=0&yt=2016&to=06.01.2016&p=2&f=${name}_150106_160106&e=.txt&dtf=1&tmf=1&MSOR=1&mstime=on&mstimever=1&sep=1&sep2=1&datf=1&at=1" -O yeardata/${name}
done
