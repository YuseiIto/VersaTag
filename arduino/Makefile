FQBN:=m5stack:esp32:m5stack_stamp_pico:PartitionScheme=default,CPUFreq=80,FlashMode=qio,FlashFreq=40,FlashSize=4M,UploadSpeed=1500000,LoopCore=1,EventsCore=1,DebugLevel=none,EraseFlash=none
ARDUINO_CLI:=arduino-cli
ARDUINO_PORT_FILE:= .arduino_port
BAUDRATE := 115200

check-arduino-cli:
	@which $(ARDUINO_CLI) > /dev/null || (echo "Error: arduino-cli not installed." && exit 1)

.PHONY: compile
compile: check-arduino-cli
	$(ARDUINO_CLI) compile --fqbn=$(FQBN) .


.PHONY: upload
upload: check-arduino-cli check-port
	$(ARDUINO_CLI) upload --fqbn=$(FQBN) -p $$(cat $(ARDUINO_PORT_FILE)) .

.PHONY: monitor
monitor: check-arduino-cli check-port
	$(ARDUINO_CLI) monitor -p $$(cat $(ARDUINO_PORT_FILE)) --config $(BAUDRATE)

.PHONY: check-port
check-port:
	@if [ ! -f "$(ARDUINO_PORT_FILE)" ]; then \
			echo "Error: $(ARDUINO_PORT_FILE) does not exist. Run \`make set-port\` beforehead."; \
			exit 1;\
	fi
	@echo "File $(ARDUINO_PORT_FILE) exists";
	@if [ ! -s $(ARDUINO_PORT_FILE) ]; then \
		echo "Error: $(ARDUINO_PORT_FILE) is empty. Run \`make set-port\` beforehead."; \
		exit 1;\
	fi
	@PORT=$$(cat $(ARDUINO_PORT_FILE));\
	echo "Checking if $$PORT exists...";\
	if [ ! -e "$$PORT" ]; then \
		echo "Error: Port $$PORT does not exist. Run \`make set-port\` beforehead."; \
		exit 1;\
	fi

.PHONY: set-port
set-port: check-arduino-cli
	@PORT=$$(ls /dev/tty.* | xargs gum choose --header="Select a port:");\
	if([ -z "$$PORT" ]); then \
		echo "Error: No port selected";\
		exit 1;\
	fi;\
	echo "Selected port '$$PORT'";\
	echo $$PORT > $(ARDUINO_PORT_FILE)

