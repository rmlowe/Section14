.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge-Solution2 - Debug ]----------"
	@cd "Challenge-Solution2" && "$(MAKE)" -f  "Challenge-Solution2.mk"
clean:
	@echo "----------Cleaning project:[ Challenge-Solution2 - Debug ]----------"
	@cd "Challenge-Solution2" && "$(MAKE)" -f  "Challenge-Solution2.mk" clean
