#!/bin/bash

rm -rf libft
rm -rf gnl
cp -r ../gnlylibft/origin/ ./
git add -all
git add *.sh
git commit -m "casa1"
git push
cp -r ../gnlylibft/modificado/ ./

