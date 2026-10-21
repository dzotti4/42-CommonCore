#!/bin/sh
set -e

if [ ! -f /var/lib/mysql/.inception_init_done ]; then
	echo "Initializing MariaDB system tables..."
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql

	echo "Starting temporary MariaDB..."
	/usr/sbin/mysqld --user=mysql --skip-networking --socket=/run/mysqld/mysqld.sock &
	pid="$!"

	echo "Waiting for MariaDB..."
	while ! mariadb -u root --socket=/run/mysqld/mysqld.sock -e "SELECT 1;" >/dev/null 2>&1
	do
		sleep 1
	done

	echo "Creating database and user..."
	mariadb -u root --socket=/run/mysqld/mysqld.sock << EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

	touch /var/lib/mysql/.inception_init_done

	echo "Stopping temporary server..."
	mariadb-admin -u root --socket=/run/mysqld/mysqld.sock shutdown
	wait "$pid"
fi

echo "Starting MariaDB..."
exec /usr/sbin/mysqld --user=mysql --bind-address=0.0.0.0
