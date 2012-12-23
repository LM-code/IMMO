#! /bin/sh
# recover the current directory path
path=$(pwd)
original_file=$(ls *.tar.gz)
repertoire=$(basename $original_file .tar.gz)
debian_file="$repertoire"".orig.tar.gz"

# Step 1
clear
echo " "
echo "     -- STEP 1 --     "
echo "----------------------"
echo "|  Rename the file   |"
echo "----------------------"
echo " $original_file "
mv "$path"/"$original_file" "$path"/"$fichier_debian"
rename  "s/-/_/g" *.tar.gz
debian_file=$(ls *.orig.tar.gz)
echo " $debian_file "
echo " "
read -p "Press any key to continue ..."

# Step 2
clear
echo "     -- STEP 2 --     "
echo "---------------------"
echo "|  Unzip the file   |"
echo "---------------------"
echo tar zxf "$path"/"$debian_file"
tar zxf "$path"/"$debian_file"
read -p "Press any key to continue ..."

# Step 3
clear
echo "     -- STEP 3 --     "
echo "------------------------------"
echo "|  Create directory /debian  |"
echo "------------------------------"
cd "$path"/"$repertoire"
dh_make -s -e webmaster@super-annonce.fr
cd debian/
rm -rf *ex *EX README*
cd ..

# Step 4
clear
echo "     -- STEP 4 --     "
echo "-----------------------------------------------------"
echo "|  Copy the files : changelog - control - copyright |"
echo "-----------------------------------------------------"
#cp $path/debian_file/changelog $path/$repertoire/debian/changelog
cp $path/debian_file/control $path/$repertoire/debian/control
cp $path/debian_file/copyright $path/$repertoire/debian/copyright

# Step 5
clear
echo "     -- STEP 5 --     "
echo "---------------------------"
echo "|  Create package DEBIAN  |"
echo "---------------------------"
dpkg-buildpackage -rfakeroot
cd ..
#echo "Rentre dans le répertoire"
#cd /home/laurent/Dropbox/cours\ C++/perso/Ubuntu/$repertoire
#debuild -S -sa --lintian-opts -i
#debuild -k0x8C572922 -S 
#cd /home/laurent/Dropbox/cours\ C++/perso/Ubuntu/
#sudo pbuilder build *.dsc
