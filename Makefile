.PHONY: clean All

All:
	@echo "----------Building project:[ Challenge-Solution1 - Debug ]----------"
	@cd "Challenge-Solution1" && "$(MAKE)" -f  "Challenge-Solution1.mk"
clean:
	@echo "----------Cleaning project:[ Challenge-Solution1 - Debug ]----------"
	@cd "Challenge-Solution1" && "$(MAKE)" -f  "Challenge-Solution1.mk" clean
