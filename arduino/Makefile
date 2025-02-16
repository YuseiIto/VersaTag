FQBN:=m5stack:esp32:m5stack_stamp_pico:PartitionScheme=default,CPUFreq=240,FlashMode=qio,FlashFreq=80,FlashSize=4M,UploadSpeed=1500000,LoopCore=1,EventsCore=1,DebugLevel=none,EraseFlash=none
ARDUINO_CLI:=arduino-cli
ARDUINO_PORT:=/dev/tty.usbserial-10 # Todo: Auto discovery

check-arduino-cli:
	@which $(ARDUINO_CLI) > /dev/null || (echo "Error: arduino-cli not installed." && exit 1)

.PHONY: compile
compile: check-arduino-cli
	$(ARDUINO_CLI) compile --fqbn=$(FQBN) .


.PHONY: upload
upload: check-arduino-cli
	$(ARDUINO_CLI) upload --fqbn=$(FQBN) -p $(ARDUINO_PORT) .

.PHONY: monitor
monitor: check-arduino-cli
	$(ARDUINO_CLI) monitor -p $(ARDUINO_PORT) --config 115200
