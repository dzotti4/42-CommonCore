#!/bin/sh
set -e

mkdir -p /run/php
chown -R www-data:www-data /var/www/html

cd /var/www/html

echo "Waiting for MariaDB..."

while ! mariadb -h mariadb -u"${MYSQL_USER}" -p"${MYSQL_PASSWORD}" "${MYSQL_DATABASE}" -e "SELECT 1;" >/dev/null 2>&1
do
	sleep 1
done

echo "MariaDB is ready."

if [ ! -f /var/www/html/wp-config.php ]; then
	echo "Creating wp-config.php..."
	wp config create \
		--allow-root \
		--dbname="${MYSQL_DATABASE}" \
		--dbuser="${MYSQL_USER}" \
		--dbpass="${MYSQL_PASSWORD}" \
		--dbhost="mariadb:3306"

	echo "Installing WordPress..."
	wp core install \
		--allow-root \
		--url="https://${DOMAIN_NAME}" \
		--title="Inception" \
		--admin_user="${WP_ADMIN_USER}" \
		--admin_password="${WP_ADMIN_PASSWORD}" \
		--admin_email="${WP_ADMIN_EMAIL}"

	echo "Creating normal user..."
	wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
		--allow-root \
		--user_pass="${WP_USER_PASSWORD}"
fi

echo "Starting php-fpm..."
exec php-fpm8.2 -F
