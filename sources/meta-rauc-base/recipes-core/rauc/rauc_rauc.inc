FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI:append := "file://system.conf"
# additional dependencies required to run RAUC on the target
RDEPENDS:${PN} += "grub-editenv e2fsprogs-mke2fs"
