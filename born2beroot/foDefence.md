- [Mandatory](#mandatory)
- [User](#user)
- [Hostname and partitions](#hostname-and-partitions)
- [Sudo](#sudo)
- [UFW](#ufw)
- [SSH](#ssh)
- [Script monitoring](#script-monitoring)
- [Bonus](#bonus)

---

# Mandatory

Ensure that the "signature.txt." file is present at the root of the cloned repository.

Check that the signature contained in "signature.txt" is identical to that of the ".vdi" file of the virtual machine to be evaluated.

Should explain

- the basic functioning of its virtual machine.
- the basic differences between Centos and Debian.
- the interest of virtual machine
- the difference between aptitude and apt
- what AppArmor is

Check

- UFW service is started
- SSH service is started

---

# User

Should add the user id to two groups

- sudo
- user42

create a user
create a group named "evaluating"
assign the user to the creatd group
check

explain the advantages of the password policy.

---

# Hostname and partitions

Check

- that the hostname of the machine is user42

Modify the hostname by replacing the login with yours.

- if on restart, the hostname has to be updated.

how to view the partitions for the virtual machine

---

# Sudo

Check that the "sudo" program is properly installed on the vm.

Assign new user to the "sudo" group

Explain the value and operatoin of sudo using examples of their choice.

Verify that the "/var/log/sudo/" folder exists and has at least one file

run a command via sudo

- and see if the "/var/log/sudo/" folder have been updated.

---

# UFW

Check that the UFW program is properly installed on the vm.

Explain about UFW.

List the active rules in UFW

- a rule must exist for port 4242

Add a new rule to open port 8080.

- Check that this one has been added by listing the active rules.
- Finally, delete this new rule.

---

# SSH

Check that the SSH service is properly installed one the vm.

Explain about SSH

Veerify that the SSH service only uses port 4242

The student evaluated should help you use SSH in order to log in with the newly cretedd user.

- to do this, you can use a key or a simple passwd.

You have to make sure that you cannot use SSH with the "root" user.

---

# Script monitoring

What is "cron"

How the evaluated student set up her script so that it runs every 10 mins when the server starts up.

the student should ensure that this script runs every 30s.

the student should make the script stop running when the server starts up.

- but without modifying the script

---

# Bonus

set up partitions
set up WordPress

- only with the services required by the subject
free choic service

>NGINX and Apache2 are prohibited.
