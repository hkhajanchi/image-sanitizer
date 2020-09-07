#!/bin/sh

docker run -v $PWD:/hack -v /home/data/GrassClover/:/images --workdir /hack -it hussain/dev
