# USER DOCUMENTATION

Purpose

This document explains how to use the Inception infrastructure.

This project runs a website using:
- NGINX
- WordPress
- Mariadb

--------------------------------------------------

Start the infrastructure:

make

--------------------------------------------------

Stop the infrastructure:

make down

--------------------------------------------------

Rebuild everything:

make re

--------------------------------------------------

Access the website:

https://dzotti.42.fr

A browser warning may appear because the TLS certificate is self-signed.

--------------------------------------------------

WordPress admin panel:

https://dzotti.42.fr/wp-admin

--------------------------------------------------

Credentials:

Stored in:
srcs/.env

--------------------------------------------------

Check containers:

docker ps

You should see:

- nginx
- wordpress
- mariadb

--------------------------------------------------

View logs:

docker logs nginx
docker logs wordpress
docker logs mariadb

--------------------------------------------------

Reset project:

make fclean
make
