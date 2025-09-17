DC= docker compose -f ./srcs/docker-compose.yml

RM = rm -rf
RMI= docker rmi 

MANDATORY_SERVICES = mariadb wordpress nginx
MANDATORY_SERV_IMG = mariadb:inception wordpress:inception nginx:inception

BONUS_SERVICES = redis ftp adminer pingacont
BONUS_SERV_IMG = redis:inception adminer:incetpion pingacont:inception

mandatory-up:
	$(DC) up -d $(MANDATORY_SERVICES)

mandatory-down:
	$(DC) down $(MANDATORY_SERVICES)

mandatory-start:
	$(DC) start $(MANDATORY_SERVICES)

mandatory-stop:
	$(DC) stop $(MANDATORY_SERVICES)

mandatory-restart:
	$(DC) restart $(MANDATORY_SERVICES)

bonus-up:

	$(DC) up -d $(MANDATORY_SERVICES) $(BONUS_SERVICES)
	docker exec wordpress-container wp plugin activate redis-cache --allow-root
	docker exec wordpress-container wp redis enable --allow-root

bonus-down:

	$(DC) down $(MANDATORY_SERVICES) $(BONUS_SERVICES)

bonus-start:

	$(DC) start $(MANDATORY_SERVICES) $(BONUS_SERVICES)

bonus-stop:

	$(DC) stop $(MANDATORY_SERVICES) $(BONUS_SERVICES)

bonus-restart:

	$(DC) restart $(MANDATORY_SERVICES) $(BONUS_SERVICES)

.PHONY: mandatory-up mandatory-down mandatory-start mandatory-stop mandatory-restart \
		bonus-up bonus-down bonus-start bonus-stop bonus-restart
