# RansomwareLocker

RansomwareLocker is a honeyfile-based ransomware detection tool for Linux environments. It uses _inotify-tools_ and 
_auditd_ utilities to monitor a honeyfile.

The program requires **admin** privileges to run and can run indefinitely in the background. The trap file is created 
in a location that the user would not access. The file is additionally saved with a _**.pdf**_ extension to ensure that 
the ransomware definitely encounters it. 

#### Basic steps involved:
1. A trap file of arbitrary size is created (~4KB).
2. Symbolic links are set up across the file system in order to ensure that the ransomware encounters it eventually
3. Using the _auditctl_ facility, the trap file is audited/monitored.
4. _inotifywait_ is used to constantly check for either of the following events on our trap file
    1. access --> file or directory contents were read
    2. attrib --> file or directory attributes changed
    3. close --> file or directory closed, regardless of read/write mode
    4. open --> file or directory opened
    5. modify --> file or directory contents were written
5. If the above condition is true, then the PID of the accessor is extracted from the audit.log file using _auditd's_ 
_ausearch_ utility and passed as an argument to _kill_.
6. Once the process is killed, a notification is sent to the user saying 'A potentially malicious process was killed'.

To install the additional utilities, refer to the following:
* [inotify-tools](https://github.com/rvoicilas/inotify-tools/wiki)
* `apt install auditd` on Debian/Ubuntu
* `yum install auditd` on RedHat

This tool was used against [bash-ransomware](https://www.github.com/SubtleScope/bash-ransomware), an open-source Linux 
ransomware (on a system running Ubuntu 16.04.2 64-bit), which gave promising results.

The technique was inspired by [this paper](https://www.sciencedirect.com/science/article/pii/S0167404817302560).