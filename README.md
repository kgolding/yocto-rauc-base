
# **genericx86-64 rauc base Image Creation**




**Requirements:**

*Packages: gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm*

`$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm`


## Image Creation :

**Clone the source layers repo into the sources directory with the kirkstone branch:**

`$ git clone git://git.yoctoproject.org/poky -b kirkstone` 

`$ git clone https://github.com/rauc/meta-rauc.git -b kirkstone `

**Enter the yocto-rauc-base directory:**

`$ cd yocto-rauc-base`


**Initialize build directory to configure the build system and start the build process**

`$ source sources/poky/oe-init-build-env x86-64-build`

**Change MACHINE name (if different) in conf/local.conf to: genericx86-64**
>(line38)   MACHINE ??= "genericx86-64"


**To install additional tools (e.g: gcc, git etc.) add the corresponding line to the of file local.conf


        gcc+Make:              IMAGE_INSTALL += "packagegroup-core-buildessential"
        git:                   IMAGE_INSTALL += "git"
        gdbserver:             IMAGE_INSTALL += "gdbserver"
        gdb:                   IMAGE_INSTALL += "gdb"
        nano:                  IMAGE_INSTALL += "nano mtd-utils"





**Generating rauc CA certiface :**

`$ ../sources/meta-rauc-base/create-example-keys.sh`
## Image config/build using Bitbake  :

**To build a small image provided by Yocto Project:**

`$ bitbake core-image-minimal`


**To launch kernel menuconfig:**

`$ bitbake -c menuconfig virtual/kernel`





**The final output image is**

Go to the output directory : tmp/deploy/images/genericx86-64,

`$ cd tmp/deploy/images/genericx86-64 `

**run image in virtual machine qemu**

`$ runqemu nographic slirp ovmf wic core-image-minimal`


