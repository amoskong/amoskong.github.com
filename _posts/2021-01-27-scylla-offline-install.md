---
layout: post
title: Scylla offline install
date: 2021-01-27 07:37
tags: [scylla, scylladb, install, tutorial]
categories: scylladb
---

Offline install of Unified package was supported in [Scylla 4.3](https://www.scylladb.com/2021/01/18/scylla-open-source-release-4-3/).

## Why do we need offline install?

Some users want to deploy scylla in private datacenter, they can't access internet naturally. They need an install package which contains everything.

In extreme situation, users might have not super permission, they can only install scylla in their home directory, and mange the scylla service by user mode of systemd (`systemctl --user`). They can't setup RAID.

## Offline Install Concepts

- Offline install: download a install package and install scylla offline
- Root Offline Install: install scylla offline with root permission, the installed scylla is completely same as regual installation.
- NonRoot Offline Install: install scylla offline without root permission, the scylla is installed in ~/scylladb/ directory by default, and the services are managed by user mode of systemd.
- Unified Package Offline Install: uncompress the package and execute the install.sh to install scylla offline, the package is for all distros. You can install it `with or without` root permission.

## Offline Install Solutions

### RPM/Deb Collection Installer

- All dependencies will be contained in the installer
- You have to generate installer by yourself on same distro (same as the install machine), the installer can only be used on one kind of distro.
- You need network in building the installer, the pacakges are downloaded from scylla repo.
- You need super permission to run the installer
- You can upgrade/rollback by rpm / yum

You can find some scripts (eg: [./dist/offline_installer/redhat/build_offline_installer.sh](https://github.com/scylladb/scylla/blob/master/dist/offline_installer/redhat/build_offline_installer.sh)) to build offline installer, it will generate a single shell script, all scylla pacakges and dependencies are contained in the script itself.

You can copy the single script to your machine, and install scylla by execute the script.

Example to build offline installer for CentOS7:

```
 # ./dist/offline_installer/redhat/build_offline_installer.sh \
--repo http://downloads.scylladb.com/rpm/centos/scylla-4.3.repo
....
Self-extractable archive "scylla_offline_installer.sh" successfully created.
$ ls -lh build/scylla_offline_installer.sh
-rwxrwxr-x 1 amos amos 208M Jan 27 00:03 build/scylla_offline_installer.sh
```

Example to build offline installer for Ubuntu 16.04:

```
./dist/offline_installer/debian/build_offline_installer.sh \
--repo https://s3.amazonaws.com/downloads.scylladb.com/deb/ubuntu/scylla-$VERSION-xenial.list \
--suite xenial
```

More detail: [https://github.com/scylladb/scylla/wiki/Offline-Installer](https://github.com/scylladb/scylla/wiki/Offline-Installer)

### Unified Package

- You need to solve the basic depency (Openjdk 8 or 11), which is used by scylla-jmx. xfsprogs and mdadm also need to be installed for root offline install)
- The unified pacakge is shared for all distros
- You can only upgrade/rollback by `install.sh` and `uninstall.sh`

Get the unified package url in [https://www.scylladb.com/download/?platform=tar](https://www.scylladb.com/download/?platform=tar)

```
curl http://downloads.scylladb.com/downloads/scylla/relocatable/scylladb-4.3/scylla-unified-package-4.3.0.0.20210110.000585522.tar.gz \
 -o scylla-unified-package-4.3.tar.gz
tar xvfz scylla-unified-package-4.3.tar.gz

# Solve the dependency
sudo yum install -y java-1.8.0-openjdk
```

### Option 1: Root Offline Install

```
# Install
sudo ./install.sh --housekeeping

# Scylla setup
sudo scylla_setup

# Start scylla
sudo systemctl start scylla-server

# Check db log
sudo journalctl -u scylla-server -xe
```

### Option 2: NonRoot Offline Install

```
# Install
sh -x ./install.sh --nonroot

# Scylla setup
~/scylladb/sbin/scylla_setup

# Start scylla
systemctl --user start scylla-server

# Check db log
journalctl --user scylla-server -xe

# Usage
~/scylladb/share/cassandra/bin/cqlsh --version
~/scylladb/share/cassandra/bin/nodetool status
~/scylladb/share/cassandra/bin/cassandra-stress write -node xxx
```

More detail: [https://docs.scylladb.com/getting-started/install_scylla/unified-installer/](https://docs.scylladb.com/getting-started/install_scylla/unified-installer/)

## References

* [https://www.scylladb.com/2021/01/18/scylla-open-source-release-4-3/](https://www.scylladb.com/2021/01/18/scylla-open-source-release-4-3/)
* [https://github.com/scylladb/scylla/wiki/Offline-Installer](https://github.com/scylladb/scylla/wiki/Offline-Installer)
* [https://docs.scylladb.com/getting-started/install_scylla/unified-installer/](https://docs.scylladb.com/getting-started/install_scylla/unified-installer/)
* [https://www.scylladb.com/download/?platform=tar](https://www.scylladb.com/download/?platform=tar)