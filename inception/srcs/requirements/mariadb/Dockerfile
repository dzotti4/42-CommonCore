FROM debian:bookworm

RUN apt-get update && apt-get install -y \
	mariadb-server \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/mysqld \
	&& chown -R mysql:mysql /run/mysqld /var/lib/mysql

COPY tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

EXPOSE 3306

CMD ["/setup.sh"]
