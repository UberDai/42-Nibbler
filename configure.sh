#!/bin/sh

git submodule init ;
git submodule update ;

cmake --version;

if [[ $? == 127 ]]; then
	echo "Plz, install cmake" ;
	exit ;
fi

(cd lib2/SFML && cmake . && make);
(cd lib3/glfw && cmake . && make);
