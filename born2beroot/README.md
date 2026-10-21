*This project has been created as part of the 42 curriculum by dzotti.*

# Born2beRoot

## Description

A system administration project: setting up a Debian virtual machine with strict rules. LVM with encrypted partitions, SSH on port 4242, a UFW firewall, a strong password policy, `sudo` logging and a `monitoring.sh` script that reports system info every 10 minutes.

The repository only contains `signature.txt`: the SHA1 hash of the virtual disk that was evaluated, as the subject requires.

## Instructions

```bash
sha1sum Born2beRoot.vdi   # must match signature.txt
```

## What I learned

- Linux users, groups and permissions
- Partitioning with LVM, SSH, firewalls and cron
