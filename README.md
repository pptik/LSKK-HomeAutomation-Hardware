# LSKK-HomeAutomation-Hardware
1. Local Server Raspberry Pi
   - SSH Enabled
   - Install dotnet dan SDK Runtime [here](https://github.com/pptik/.NET-Raspberry-pi/blob/master/README.md)
   - Install Visual Studio Code 
   ```
   wget https://packagecloud.io/headmelted/codebuilds/gpgkey -O - | sudo apt-key add -
   ```
   ```
   curl -L https://raw.githubusercontent.com/headmelted/codebuilds/master/docs/installers/apt.sh | sudo bash
   ```
   - Install Rabbit MQ
   ```
   sudo apt-get update
   ```
   ```
   sudo apt-get install –y erlang logrotate
   ```
   ```
   sudo apt-get install rabbitmq-server
   ```
   ```
   sudo rabbitmq-plugins enable rabbitmq_management
   sudo rabbitmqctl add_user [newuser] [password]
   sudo rabbitmqctl set_user_tags [newuser] administrator
   sudo rabbitmqctl set_permissions -p / [newuser] ".*" ".*" ".*"
   ```
   - Install Database Browser Sqlite
2. Lamp (Digital Output)
   - Register Device 
   - Scan QR Code
   - Controller
3. Button Remote (Digital Input)
4. Weather Station (Analog Input)
5. Water Level (Analog Input)
