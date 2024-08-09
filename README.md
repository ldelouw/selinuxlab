# selinuxlab

This is an Ansible playbook and related files to set up a SELinux Lab on Redhat Enterprise Linux for educational purposes.

## Authors
- Lukas Vrabec <lvrabec@redhat.com>
- Luc de Louw <ldelouw@redhat.com>

## Cases covered:

- Setting wromg permissions to /etc/shadow and see that SELinux prevents information disclosure by a CGI script trying to read the shadow file
- Setting up an NFS Server with protocol version 4.2 which exports SElinux file contexts
- Setting up a simple SMB Server for two use cases: Home directory mount and mount of a generic share
- Installation of a Tomcat server with a example application to be confined

## Operating Systems
This playbook and lab has been tested with the following Operating Systems:
- RHEL8
- RHEL9
- RHEL10 (actually with CentOS Stream 10 which is the upstream project of the upcomming RHEL10 system)

## Usage:

```bash
ansible-play -u root -k setup-lab.yml
```

## Future development
This repo will be updated as the lab will evolve. We are happy to get input from other contributers.
