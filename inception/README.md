*This project has been created as part of the 42 curriculum by dzotti.*

# Inception

## Description

Inception is a system administration project from the 42 curriculum.

The goal of this project is to build a small infrastructure using Docker containers.

The infrastructure contains three main services:

- NGINX (reverse proxy + TLS)
- WordPress with PHP-FPM
- MariaDB database

Each service runs inside its own container and they communicate through a Docker network.

Persistent data is stored using Docker volumes.

The website is accessible through HTTPS using a self-signed TLS certificate.

--------------------------------------------------

# Instructions

Requirements:

- Docker
- Docker Compose
- Make
- Linux environment (usually a VM)

--------------------------------------------------

Build and start the project:

make

--------------------------------------------------

Stop the containers:

make down

--------------------------------------------------

Clean everything:

make fclean

--------------------------------------------------

Rebuild everything:

make re

--------------------------------------------------

Access the website:

https://dzotti.42.fr

Your browser may show a security warning because the certificate is self-signed.  
This is expected.

--------------------------------------------------

WordPress admin:

https://dzotti.42.fr/wp-admin

--------------------------------------------------

# Resources

The following documentation was used:

- Docker documentation
- Docker Compose documentation
- NGINX documentation
- MariaDB documentation
- WordPress documentation
- WP-CLI documentation

AI tools were used only for conceptual explanations and debugging assistance.
All configuration and code were reviewed and adapted to satisfy the project requirements.

# Technical choices

- Docker instead of virtual machines (lighter and faster)
- NGINX as reverse proxy with TLS
- PHP-FPM for wordpress
- Mariadb as database
- Custom Docker network
- Docker volumes for persistence

# Comparisons

Virtual Machines vs Docker:
    VMs run a full OS with their own kernel.
    Docker shares the host kernel and is lighter.

Secrets vs Environment Variables:
    Env variables are for configuration.
    Sectrets are for sensitive data.

Docker Network vs Host Network:
    Docker network isolates containers.
    Host network exposes them directly.

Volumes vs Bind Mounts:
    Volumes are managed by Docker.
    Bind mounts depend on the host.
