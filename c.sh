#!/bin/bash  

echo "Enter the commit message: "  
read msg
git add .
git commit -m "$msg"
git push origin master