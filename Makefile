BUILD = DEBUG

all:
	@echo "Building core"
	@$(MAKE) -C core BUILD=$(BUILD)
	@echo "Building client"
	@$(MAKE) -C client BUILD=$(BUILD)
	@echo "Building server"
	@$(MAKE) -C server BUILD=$(BUILD)
	@echo "Building tester"
	@$(MAKE) -C tester BUILD=$(BUILD)

core: FORCE
	@echo "Building core"
	@$(MAKE) -C core BUILD=$(BUILD)

client: FORCE
	@echo "Building client"
	@$(MAKE) -C client BUILD=$(BUILD)

server: FORCE
	@echo "Building server"
	@$(MAKE) -C server BUILD=$(BUILD)

tester: FORCE
	@echo "Building tester"
	@$(MAKE) -C tester BUILD=$(BUILD)

FORCE:

clean:
	@echo "Cleaning core"
	@$(MAKE) -C core clean
	@echo "Cleaning client"
	@$(MAKE) -C client clean
	@echo "Cleaning server"
	@$(MAKE) -C server clean
	@echo "Cleaning tester"
	@$(MAKE) -C tester clean