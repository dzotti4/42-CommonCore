NAME = inception

COMPOSE = docker-compose -f srcs/docker-compose.yml
DOCKER_DATA = /home/dzotti/data/docker

all: up

up:
	mkdir -p $(DOCKER_DATA)
	$(COMPOSE) up --build -d

down:
	$(COMPOSE) down

build:
	$(COMPOSE) build

start:
	$(COMPOSE) start

stop:
	$(COMPOSE) stop

restart: down up

clean:
	$(COMPOSE) down -v

fclean: clean
	docker system prune -af
	sudo rm -rf $(DOCKER_DATA)/*
	sudo rm -rf $(DOCKER_DATA)/.[!.]*
	sudo rm -rf $(DOCKER_DATA)/..?*

re: fclean up

logs:
	$(COMPOSE) logs

ps:
	$(COMPOSE) ps

.PHONY: all up down build start stop restart clean fclean re logs ps
