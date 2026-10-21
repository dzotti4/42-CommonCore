FROM debian:bookworm

RUN apt-get update && apt-get install -y \
	php-fpm \
	php-mysql \
	curl \
	mariadb-client \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html \
	&& cd /tmp \
	&& curl -O https://wordpress.org/latest.tar.gz \
	&& tar -xzf latest.tar.gz \
	&& cp -r wordpress/* /var/www/html \
	&& rm -rf /tmp/latest.tar.gz /tmp/wordpress

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

RUN sed -i 's|^listen = .*|listen = 9000|' /etc/php/8.2/fpm/pool.d/www.conf

COPY tools/setup.sh /setup.sh
RUN chmod +x /setup.sh

CMD ["/setup.sh"]
