# DEVELOPER DOCUMENTATION

Purpose

This document explains the internal architecture of the Inception project.

--------------------------------------------------

Architecture

The infrastructure contains three containers:

NGINX → reverse proxy and TLS termination  
WordPress → PHP-FPM application server  
MariaDB → database server

Architecture flow:

Browser
↓
NGINX
↓
WordPress (PHP-FPM)
↓
MariaDB

--------------------------------------------------

Project structure

inception/
├── Makefile
├── README.md
├── USER_DOC.md
├── DEV_DOC.md
└── srcs/
    ├── docker-compose.yml
    ├── .env
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   └── tools/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        └── wordpress/
            ├── Dockerfile
            └── tools/

--------------------------------------------------

Build process

Docker images are built from Dockerfiles located in:

srcs/requirements/

Each service has its own Dockerfile.

--------------------------------------------------

Docker Compose

Services are managed using:

docker-compose -f srcs/docker-compose.yml

Compose manages:

- services
- networks
- volumes

--------------------------------------------------

Persistence

Docker volumes are used to store:

- WordPress website files
- MariaDB database files

This ensures that data persists even if containers are removed.

--------------------------------------------------

Networking

Containers communicate using a dedicated Docker network.

Example:

WordPress connects to MariaDB using:

mariadb:3306

--------------------------------------------------

Security

NGINX provides HTTPS using TLS with a self-signed certificate.

Credentials and sensitive information are stored locally and should never be pushed to Git.

--------------------------------------------------

Setup

git clone <repo> inception
cd inception

Create a .env file in src/

--------------------------------------------------

Run

Make

--------------------------------------------------

Manage containers

docker ps
docker stop <container>
docker start <container>

--------------------------------------------------

Volumes

docker volume ls
docker volume inspect <volume>

--------------------------------------------------

Data location

/home/dzotti/data/docker

Docker volumes ensure persistence.

--------------------------------------------------

Clean

make fclean

This removes:
- containers
- volumes
- images
- data
