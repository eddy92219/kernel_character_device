# kernel_character_device
kernel driver practice
## Environment
Ubuntu 20.04.6 LTS GNU/Linux 5.4.0-159-generic
gcc version 9.4.0

## apt install gcc
```
sudo apt install build-essential linux-headers-$(uname-r)
```

## make file
```
$make
```
ioctl.ko will appear

Before insert module, check if the module exist
```
$lsmod
```

if list don't have ioctl module, could use follow command to insert `ioctl` module
```
$sudo insmod ioctl.ko
```

`lsmod` again, you should find `ioctl` in module list

## compile usrprg.c
compile `usrprg.c` to interact with `ioctl` module
```
gcc -o usrprg usrprg.c
```

`$ls -al` would find out usrprg appear in filelist

execute it
```
$./usrprg
```

## remove ioctl kernel
```
$sudo rmmod ioctl
```
