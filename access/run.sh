sudo touch needroot
sudo chown root needroot
sudo chmod 700 needroot
cd cmake-build-debug
sudo chown root access
sudo chmod u+s access
sudo -k
./access

