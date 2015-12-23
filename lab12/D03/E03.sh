#!/bin/sh
sed -i "1,5 c HEADER" $1
sed -i -e "/^\./d" -e "/\.$/d" $1
sed -i "6,$ s/^/   /g" $1
